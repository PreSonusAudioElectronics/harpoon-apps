/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _HRPN_CTRL_H_
#define _HRPN_CTRL_H_

#include <stdint.h>

enum {
	HRPN_CMD_TYPE_LATENCY_RUN = 0x0000,
	HRPN_CMD_TYPE_LATENCY_STOP,
	HRPN_RESP_TYPE_LATENCY = 0x0010,
};

enum {
	HRPN_RESP_STATUS_SUCCESS = 0,
	HRPN_RESP_STATUS_ERROR = 1,
};

struct hrpn_cmd_latency_run {
	uint32_t type;
	uint32_t id;
};

struct hrpn_cmd_latency_stop {
	uint32_t type;
};

struct hrpn_resp_latency {
	uint32_t type;
	uint32_t status;
};

struct hrpn_cmd {
	uint32_t type;
};

struct hrpn_resp {
	uint32_t type;
	uint32_t status;
};

struct hrpn_command {
	union {
		struct hrpn_cmd cmd;
		struct hrpn_cmd_latency_run latency_run;
		struct hrpn_cmd_latency_stop latency_stop;
	} u;
};

struct hrpn_response {
	union {
		struct hrpn_resp resp;
		struct hrpn_resp_latency latency;
	} u;
};

#endif /* _HRPN_CTRL_H_ */