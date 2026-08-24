/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _MAILBOX_H_
#define _MAILBOX_H_

#include <stdbool.h>
#include <stdint.h>

enum mailbox_ret_codes
{
	kMailboxWrongDirection = -16,
	kMailboxMsgTooBig,
	kMailboxNoNewResponse,
	kMailboxOutOfSequence,
	kMailboxBadArgument,
	kMailboxNoNewCommand,
	kMailboxBufferTooSmall,
	kMailboxPrevMsgNotYetRead,
	kMailboxOtherSideNotInitialized,
	kMailboxSuccess = 0
};

struct mailbox {
	bool dir;
	unsigned int last_cmd;
	unsigned int last_resp;
	void *cmd;
	void *resp;
	void *transport;
	bool enforce_cmd_match_on_rx;
	uint32_t magic;
};

int mailbox_cmd_send(struct mailbox *mbox, void *data, unsigned int len);
int mailbox_cmd_recv(struct mailbox *mbox, void *data, unsigned int *len);
int mailbox_resp_send(struct mailbox *mbox, void *data, unsigned int len);
int mailbox_resp_recv(struct mailbox *mbox, void *data, unsigned int *len);

int mailbox_init(struct mailbox *mbox, void *cmd, void *resp, bool dir,
	void *tp, bool enforce_cmd_match_on_rx);

/*
 * Snapshot of the handshake counters living in shared memory, for diagnostics.
 * The cmd/resp layouts are private to mailbox.c, so this is the only way for a
 * caller to see why a send is being refused.
 */
struct mailbox_state {
	bool cmd_initialized;		/* cmd side magic is present */
	uint32_t cmd_seq;
	uint32_t cmd_last_resp;
	bool resp_initialized;		/* resp side magic is present */
	uint32_t resp_seq;
	uint32_t resp_last_cmd;
	uint32_t local_last_cmd;	/* this side's private counters */
	uint32_t local_last_resp;
};

int mailbox_get_state(struct mailbox *mbox, struct mailbox_state *out);

#endif /* _MAILBOX_H_ */
