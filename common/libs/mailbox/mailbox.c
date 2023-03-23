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


#define MAX_PAYLOAD	255

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

/* Command Sender */
int mailbox_cmd_send(struct mailbox *mbox, void *data, unsigned int len)
{
	struct cmd *c = (struct cmd *)mbox->cmd;
	struct resp *r = (struct resp *)mbox->resp;

	if (!mbox->dir)
		return kMailboxWrongDirection;

	if (len > MAX_PAYLOAD)
		return kMailboxMsgTooBig;
	
	if (r->last_cmd != mbox->last_cmd)
		return kMailboxPrevMsgNotYetRead;

	/* write new command */
	c->len = len;
	memcpy(c->data, data, len);

#ifndef MBOX_TRANSPORT_RPMSG
	mbox->last_cmd += 1;

	c->seq = mbox->last_cmd;

	__DSB();
#else
	if (rpmsg_send(mbox->transport, c, sizeof(*c)))
		return -3;
#endif

	return kMailboxSuccess;
}

int mailbox_resp_recv(struct mailbox *mbox, void *data, unsigned int *len)
{
	struct resp *r = mbox->resp;
	struct cmd *c = mbox->cmd;
	unsigned int resp_len;

	if (!mbox->dir)
		return kMailboxWrongDirection;

#ifdef MBOX_TRANSPORT_RPMSG
	if (rpmsg_recv(mbox->transport, r, sizeof(*r)))
		return -3;
#else
	if (r->magic != MAILBOX_MAGIC)
		return kMailboxOtherSideNotInitialized;

	/* check if new response */
	if (r->seq == mbox->last_resp)
		return kMailboxNoNewResponse;

	mbox->last_resp = r->seq;

	if (mbox->enforce_cmd_match_on_rx)
	{
		/* check if it matches command */
		if (r->seq != mbox->last_cmd)
			return kMailboxOutOfSequence;
	}

#endif

	resp_len = r->len;

	if (resp_len <= *len)
		*len = resp_len;

	memcpy(data, r->data, *len);

	c->last_resp = mbox->last_resp;

#ifndef MBOX_TRANSPORT_RPMSG
	__DSB ();
#endif

	return kMailboxSuccess;
}

/* Command Receiver */
int mailbox_cmd_recv(struct mailbox *mbox, void *data, unsigned int *len)
{
	struct cmd *c = mbox->cmd;
	struct resp *r = mbox->resp;
	unsigned int cmd_len;

	if ((!len) || (!data) || (!mbox))
		return kMailboxBadArgument;

	if (mbox->dir)
		return kMailboxWrongDirection;
	
	if (c->magic != MAILBOX_MAGIC)
		return kMailboxOtherSideNotInitialized;

#ifdef MBOX_TRANSPORT_RPMSG
	if (rpmsg_recv(mbox->transport, c, sizeof(*c)))
		return -3;
#else
	/* check if new command */
	if (c->seq == mbox->last_cmd)
	{
		return kMailboxNoNewCommand;
	}

	mbox->last_cmd = c->seq;

#endif

	cmd_len = c->len;

	if (cmd_len <= *len)
		*len = cmd_len;
	
	if (cmd_len > *len)
		return kMailboxBufferTooSmall;

	memcpy(data, c->data, *len);

	r->last_cmd = mbox->last_cmd;

#ifndef MBOX_TRANSPORT_RPMSG
	__DSB();
#endif

	return kMailboxSuccess;
}

int mailbox_resp_send(struct mailbox *mbox, void *data, unsigned int len)
{
	struct resp *r = mbox->resp;
	struct cmd *c = mbox->cmd;

	if (mbox->dir)
		return kMailboxWrongDirection;

	if (len > MAX_PAYLOAD)
		return kMailboxMsgTooBig;

	if (c->magic != MAILBOX_MAGIC)
	{
		return kMailboxOtherSideNotInitialized;
	}

	if (c->last_resp != r->seq)
		return kMailboxPrevMsgNotYetRead;

	/* write new response */
	r->len = len;
	memcpy(r->data, data, len);

#ifndef MBOX_TRANSPORT_RPMSG
	__DSB();

	r->seq = mbox->last_cmd;
#else
	if (rpmsg_send(mbox->transport, r, sizeof(*r)))
		return -3;
#endif

	return kMailboxSuccess;
}

int mailbox_init(struct mailbox *mbox, void *cmd, void *resp, bool dir, 
	void *tp, bool enforce_cmd_match_on_rx)
{
	struct resp *r;
	struct cmd *c;

	mbox->transport = tp;
	mbox->dir = dir;
	mbox->cmd = cmd;
	mbox->resp = resp;
	mbox->enforce_cmd_match_on_rx = enforce_cmd_match_on_rx;

	c = cmd;
	r = resp;

	if (dir) {
		
		/* command sender */

		/* If the other side is initialized, sync with it */
		if (r->magic == MAILBOX_MAGIC)
		{
			mbox->last_cmd = r->last_cmd;
			c->seq = r->last_cmd;
			mbox->last_resp = r->seq;
		}
		else
		{
			memset (c, 0, sizeof (struct cmd));
			/* just initialize with current state */
			mbox->last_cmd = c->seq;
		}

		c->magic = MAILBOX_MAGIC;
	} else {
		/* command receiver */
		memset (r, 0, sizeof (struct resp));

		if (c->magic == MAILBOX_MAGIC)
		{
			/* always ignore first pending command */
			mbox->last_cmd = c->seq;
			r->seq = c->last_resp;
		}
		else
		{
			mbox->last_cmd = 0;
		}

		/* always update response, making sure it changes and
		 * doesn't match current command */
		mbox->last_resp = r->seq + 1;

		if (mbox->last_resp == mbox->last_cmd)
			mbox->last_resp++;
		
		r->magic = MAILBOX_MAGIC;
	}

	mbox->magic = MAILBOX_MAGIC;

	return kMailboxSuccess;
}


