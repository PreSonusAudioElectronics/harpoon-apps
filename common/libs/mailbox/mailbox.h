/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _MAILBOX_H_
#define _MAILBOX_H_

#include <stdbool.h>

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
};

int mailbox_cmd_send(struct mailbox *mbox, void *data, unsigned int len);
int mailbox_cmd_recv(struct mailbox *mbox, void *data, unsigned int *len);
int mailbox_resp_send(struct mailbox *mbox, void *data, unsigned int len);
int mailbox_resp_recv(struct mailbox *mbox, void *data, unsigned int *len);

int mailbox_init(struct mailbox *mbox, void *cmd, void *resp, bool dir, 
	void *tp, bool enforce_cmd_match_on_rx);

#endif /* _MAILBOX_H_ */
