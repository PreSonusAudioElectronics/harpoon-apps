/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "ivshmem.h"
#include "mailbox.h"

#include "hrpn_ctrl.h"

#ifdef MBOX_TRANSPORT_RPMSG
#include "rpmsg.h"
#endif

#include "common.h"

int audio_element_routing_main(int argc, char *argv[], struct mailbox *m);
int audio_element_main(int argc, char *argv[], struct mailbox *m);
int audio_pipeline_main(int argc, char *argv[], struct mailbox *m);
void audio_pipeline_usage(void);
void audio_element_routing_usage(void);
void audio_element_usage(void);

int can_main(int argc, char *argv[], struct mailbox *m);
int ethernet_main(int argc, char *argv[], struct mailbox *m);
void can_usage(void);
void ethernet_usage(void);

static void latency_usage(void)
{
	printf(
		"\nLatency options:\n"
		"\t-r <id>        run latency test case id\n"
		"\t-s             stop running test case\n"
	);
}

static void audio_usage(void)
{
	printf(
		"\nAudio options:\n"
		"\t-f <frequency> audio clock frequency (in Hz)\n"
		"\t               Supporting 44100, 48000, 88200, 176400, 96000, 192000 Hz\n"
		"\t               Will use default frequency 48000Hz if not specified\n"
		"\t-p <frames>    audio processing period (in frames)\n"
		"\t               Supporting 2, 4, 8, 16, 32 frames\n"
		"\t               Will use default period 8 frames if not specified\n"
		"\t-r <id>        run audio mode id:\n"
		"\t               0 - dtmf playback\n"
		"\t               1 - sine wave playback\n"
		"\t               2 - playback & recording (loopback)\n"
		"\t               3 - audio pipeline\n"
		"\t               4 - AVB audio pipeline\n"
		"\t               5 - SMP audio pipeline\n"
		"\t-s             stop running audio mode\n"
	);
}

static int audio_run(struct mailbox *m, unsigned int id, unsigned int frequency, unsigned int period)
{
	struct hrpn_cmd_audio_run run;
	struct hrpn_response resp;
	unsigned int len;

	run.type = HRPN_CMD_TYPE_AUDIO_RUN;
	run.id = id;
	run.frequency = frequency;
	run.period = period;

	len = sizeof(resp);

	return command(m, &run, sizeof(run), HRPN_RESP_TYPE_AUDIO, &resp, &len, COMMAND_TIMEOUT);
}

static int audio_stop(struct mailbox *m)
{
	struct hrpn_cmd_audio_stop stop;
	struct hrpn_response resp;
	unsigned int len;

	stop.type = HRPN_CMD_TYPE_AUDIO_STOP;

	len = sizeof(resp);

	return command(m, &stop, sizeof(stop), HRPN_RESP_TYPE_AUDIO, &resp, &len, COMMAND_TIMEOUT);
}

static int audio_main(int argc, char *argv[], struct mailbox *m)
{
	int option;
	unsigned int id;
	int rc = 0;
	unsigned int frequency = 0;
	unsigned int period = 0;
	bool is_run_cmd = false;

	while ((option = getopt(argc, argv, "f:p:r:sv")) != -1) {
		switch (option) {
		case 'f':
			if (strtoul_check(optarg, NULL, 0, &frequency) < 0) {
				printf("Invalid frequency\n");
				rc = -1;
				goto out;
			}

			break;

		case 'p':
			if (strtoul_check(optarg, NULL, 0, &period) < 0) {
				printf("Invalid period\n");
				rc = -1;
				goto out;
			}

			break;

		case 'r':
			if (strtoul_check(optarg, NULL, 0, &id) < 0) {
				printf("Invalid id\n");
				rc = -1;
				goto out;
			}

			is_run_cmd = true;
			break;

		case 's':
			rc = audio_stop(m);
			break;

		default:
			common_main(option, optarg);
			break;
		}
	}
	/* Run the case after we get all parameters */
	if (is_run_cmd)
		rc = audio_run(m, id, frequency, period);

out:
	return rc;
}

static int latency_run(struct mailbox *m, unsigned int id)
{
	struct hrpn_cmd_latency_run run;
	struct hrpn_response resp;
	unsigned int len;

	run.type = HRPN_CMD_TYPE_LATENCY_RUN;
	run.id = id;

	len = sizeof(resp);

	return command(m, &run, sizeof(run), HRPN_RESP_TYPE_LATENCY, &resp, &len, COMMAND_TIMEOUT);
}

static int latency_stop(struct mailbox *m)
{
	struct hrpn_cmd_latency_stop stop;
	struct hrpn_response resp;
	unsigned int len;

	stop.type = HRPN_CMD_TYPE_LATENCY_STOP;

	len = sizeof(resp);

	return command(m, &stop, sizeof(stop), HRPN_RESP_TYPE_LATENCY, &resp, &len, COMMAND_TIMEOUT);
}

static int latency_main(int argc, char *argv[], struct mailbox *m)
{
	int option;
	unsigned int id;
	int rc = 0;

	while ((option = getopt(argc, argv, "r:sv")) != -1) {
		/* common options */
		switch (option) {
		case 'r':
			if (strtoul_check(optarg, NULL, 0, &id) < 0) {
				printf("Invalid id\n");
				rc = -1;
				goto out;
			}

			rc = latency_run(m, id);

			break;

		case 's':
			rc = latency_stop(m);
			break;

		default:
			common_main(option, optarg);
			break;
		}
	}

out:
	return rc;
}

const struct cmd_handler command_handler[] = {
	{ "audio", audio_main, audio_usage },
	{ "latency", latency_main, latency_usage },
	{ "pipeline", audio_pipeline_main, audio_pipeline_usage },
	{ "element", audio_element_main, audio_element_usage },
	{ "routing", audio_element_routing_main, audio_element_routing_usage },

	{ "can", can_main, can_usage },
	{ "ethernet", ethernet_main, ethernet_usage },
};

int main(int argc, char *argv[])
{
	struct ivshmem mem;
	struct mailbox m;
	unsigned int uio_id = 0;
	int fd, i;
	int rc = 0;
	void *cmd, *resp;
	unsigned int dst = 30;
	void *tp = NULL;

	if (argc < 2) {
		usage();
		goto err;
	}

#ifdef MBOX_TRANSPORT_RPMSG
	fd = rpmsg_init(dst);
	if (fd < 0)
		goto err_rpmsg;
	cmd = malloc(4 * 4096);
	if (!cmd)
		goto err_malloc;
	resp = cmd + 2 * 4096;
	memset(cmd, 0, 4 * 4096);
	tp = (void *)(uintptr_t)fd;
#else /* IVSHMEM */
	if (ivshmem_init(&mem, uio_id) < 0)
		goto err_ivshmem;
	cmd = mem.out;
	resp = mem.in + 2 * 4096;
#endif

	if (mailbox_init(&m, cmd, resp, true, tp) < 0)
		goto err_mailbox;

	for (i = 0; i < sizeof(command_handler) / sizeof(struct cmd_handler); i++)
		if (!strcmp(command_handler[i].name, argv[1])) {
			rc = command_handler[i].main(argc - 1, argv + 1, &m);
			goto exit;
		}

	usage();

exit:
#ifdef MBOX_TRANSPORT_RPMSG
	rpmsg_deinit(fd);
	free(cmd);
#else /* IVSHMEM */
	ivshmem_exit(&mem);
#endif

	return rc;

err_mailbox:
	printf("%s: err_mailbox\n", __func__);
#ifdef MBOX_TRANSPORT_RPMSG
	free(cmd);
err_malloc:
	rpmsg_deinit(fd);
err_rpmsg:
	printf("%s: err_rpmsg\n", __func__);
#else /* IVSHMEM */
	ivshmem_exit(&mem);
err_ivshmem:
#endif

err:
	return -1;
}
