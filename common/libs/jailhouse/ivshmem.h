/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _IVSHMEM_H_
#define _IVSHMEM_H_

#include "ivshmem-regs.h"

#define MAX_IV_PEERS	8

struct ivshmem {
	unsigned int peers;
	unsigned int id;
	void *mmio;
	void *state;
	unsigned int state_size;
	void *rw;
	unsigned int rw_size;
	void *out[MAX_IV_PEERS]; /* array of equal size blocks, one per peer */
	unsigned int out_size;
};

int ivshmem_init(unsigned int bfd, struct ivshmem *ivshmem);

void ivshmem_ring_doorbell(struct ivshmem *ivshmem, unsigned int peer_id,
		unsigned int vector);

void ivshmem_enable_interrupts(struct ivshmem *ivshmem, int enable);

#endif /* _IVSHMEM_H_ */
