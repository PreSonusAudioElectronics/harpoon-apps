/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <string.h>

#ifdef MBOX_TRANSPORT_RPMSG
#include "rpmsg.h"
#endif

#include "mailbox.h"

#ifndef MAX_PAYLOAD
#define MAX_PAYLOAD	255
#endif

#define MAILBOX_MAGIC 0xDAFABEFA

#ifndef __DSB
#define __DSB()	__asm volatile ("dsb sy")
#endif

struct cmd {
	volatile uint32_t seq;
	volatile uint32_t last_resp;
	uint32_t magic;
	uint32_t len;
	uint8_t data[MAX_PAYLOAD];
};

struct resp {
	volatile uint32_t seq;
	volatile uint32_t last_cmd;
	uint32_t magic;
	uint32_t len;
	uint8_t data[MAX_PAYLOAD];
};

struct cmd *g_cmd;
struct resp *g_resp;

/* Command Sender */
int mailbox_cmd_send(struct mailbox *mbox, void *data, unsigned int len)
{
	struct cmd *l_cmd = (struct cmd *)mbox->cmd;
	struct resp *l_resp = (struct resp *)mbox->resp;

	if (!mbox->dir)
		return kMailboxWrongDirection;

	if (len > MAX_PAYLOAD)
		return kMailboxMsgTooBig;
	
	if (l_resp->last_cmd != mbox->last_cmd)
		return kMailboxPrevMsgNotYetRead;

	/* write new command */
	l_cmd->len = len;
	memcpy(l_cmd->data, data, len);

#ifndef MBOX_TRANSPORT_RPMSG
	mbox->last_cmd += 1;

	l_cmd->seq = mbox->last_cmd;

	__DSB();
#else
	if (rpmsg_send(mbox->transport, c, sizeof(*c)))
		return -3;
#endif

	return kMailboxSuccess;
}

int mailbox_resp_recv(struct mailbox *mbox, void *data, unsigned int *len)
{
	struct resp *l_resp = mbox->resp;
	struct cmd *l_cmd = mbox->cmd;
	unsigned int resp_len;

	if (!mbox->dir)
		return kMailboxWrongDirection;

#ifdef MBOX_TRANSPORT_RPMSG
	if (rpmsg_recv(mbox->transport, r, sizeof(*r)))
		return -3;
#else
	if (l_resp->magic != MAILBOX_MAGIC)
		return kMailboxOtherSideNotInitialized;

	/* check if new response */
	if (l_resp->seq == mbox->last_resp)
		return kMailboxNoNewResponse;

	mbox->last_resp = l_resp->seq;

	if (mbox->enforce_cmd_match_on_rx)
	{
		/* check if it matches command */
		if (l_resp->seq != mbox->last_cmd)
			return kMailboxOutOfSequence;
	}

#endif

	resp_len = l_resp->len;

	if (resp_len <= *len)
		*len = resp_len;

	memcpy(data, l_resp->data, *len);

	l_cmd->last_resp = mbox->last_resp;

#ifndef MBOX_TRANSPORT_RPMSG
	__DSB ();
#endif

	return kMailboxSuccess;
}

/* Command Receiver */
int mailbox_cmd_recv(struct mailbox *mbox, void *data, unsigned int *len)
{
	struct cmd *l_cmd = mbox->cmd;
	struct resp *l_resp = mbox->resp;
	unsigned int cmd_len;

	if ((!len) || (!data) || (!mbox))
		return kMailboxBadArgument;

	if (mbox->dir)
		return kMailboxWrongDirection;
	
	if (l_cmd->magic != MAILBOX_MAGIC)
		return kMailboxOtherSideNotInitialized;

#ifdef MBOX_TRANSPORT_RPMSG
	if (rpmsg_recv(mbox->transport, c, sizeof(*c)))
		return -3;
#else
	/* check if new command */
	if (l_cmd->seq == mbox->last_cmd)
	{
		return kMailboxNoNewCommand;
	}

	mbox->last_cmd = l_cmd->seq;

#endif

	cmd_len = l_cmd->len;

	if (cmd_len <= *len)
		*len = cmd_len;
	
	if (cmd_len > *len)
		return kMailboxBufferTooSmall;

	memcpy(data, l_cmd->data, *len);

	l_resp->last_cmd = mbox->last_cmd;

#ifndef MBOX_TRANSPORT_RPMSG
	__DSB();
#endif

	return kMailboxSuccess;
}

int mailbox_resp_send(struct mailbox *mbox, void *data, unsigned int len)
{
	struct resp *l_resp = mbox->resp;
	struct cmd *l_cmd = mbox->cmd;

	if (mbox->dir)
		return kMailboxWrongDirection;

	if (len > MAX_PAYLOAD)
		return kMailboxMsgTooBig;

	if (l_cmd->magic != MAILBOX_MAGIC)
	{
		return kMailboxOtherSideNotInitialized;
	}

	if (l_cmd->last_resp != l_resp->seq)
		return kMailboxPrevMsgNotYetRead;

	/* write new response */
	l_resp->len = len;
	memcpy(l_resp->data, data, len);

#ifndef MBOX_TRANSPORT_RPMSG
	__DSB();

	l_resp->seq = mbox->last_cmd;
#else
	if (rpmsg_send(mbox->transport, r, sizeof(*r)))
		return -3;
#endif

	return kMailboxSuccess;
}

int mailbox_init(struct mailbox *mbox, void *cmd, void *resp, bool dir, 
	void *tp, bool enforce_cmd_match_on_rx)
{
	struct resp *l_resp;
	struct cmd *l_cmd;

	mbox->transport = tp;
	mbox->dir = dir;
	mbox->cmd = cmd;
	mbox->resp = resp;
	mbox->enforce_cmd_match_on_rx = enforce_cmd_match_on_rx;

	l_cmd = cmd;
	l_resp = resp;

	g_cmd = l_cmd;
	g_resp = l_resp;

	if (dir) {
		
		/* command sender */

		/* If the other side is initialized, sync with it */
		if (l_resp->magic == MAILBOX_MAGIC)
		{
			mbox->last_cmd = l_resp->last_cmd;
			l_cmd->seq = l_resp->last_cmd;
			mbox->last_resp = l_resp->seq;
			l_cmd->last_resp = l_resp->seq;
		}
		else
		{
			memset (l_cmd, 0, sizeof (struct cmd));
			/* just initialize with current state */
			mbox->last_cmd = l_cmd->seq;
		}


		l_cmd->magic = MAILBOX_MAGIC;

		__asm ("nop");
	} else {
		/* command receiver */

		if (l_cmd->magic == MAILBOX_MAGIC)
		{
			/* always ignore first pending command */
			mbox->last_cmd = l_cmd->seq;
			l_resp->seq = l_cmd->last_resp;
			l_resp->last_cmd = mbox->last_cmd;
		}
		else
		{
			memset (l_resp, 0, sizeof (struct resp));
			mbox->last_cmd = 0;
		}

		/* always update response, making sure it changes and
		 * doesn't match current command */
		mbox->last_resp = l_resp->seq + 1;

		if (mbox->last_resp == mbox->last_cmd)
			mbox->last_resp++;
		

		l_resp->magic = MAILBOX_MAGIC;

		__asm ("nop");
	}

	mbox->magic = MAILBOX_MAGIC;

	return kMailboxSuccess;
}


