/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _IVSHMEM_H_
#define _IVSHMEM_H_

#define MAX_IV_PEERS	8

/* MMIO registers */
#define IVSHMEM_REG_ID                  0x00
#define IVSHMEM_REG_MAX_PEERS           0x04
#define IVSHMEM_REG_INT_CTRL            0x08
#define IVSHMEM_REG_DOORBELL            0x0c
#define IVSHMEM_REG_STATE               0x10

struct ivshmem {
	unsigned int peers;
	unsigned int id;
	/*
	 * BAR0 register window, retained so the peer's doorbell can be rung
	 * after init. Mapped read/write.
	 */
	void *mmio;
	void *state;
	unsigned int state_size;
	void *rw;
	unsigned int rw_size;
	void *out[MAX_IV_PEERS]; /* array of equal size blocks, one per peer */
	unsigned int out_size;
};

/* A doorbell write is (target peer id << shift) | vector */
#define IVSHMEM_DOORBELL_PEER_SHIFT	16

int ivshmem_init(unsigned int bfd, struct ivshmem *ivshmem);

/*
 * Ring peer_id's doorbell, which the hypervisor turns into an interrupt on
 * that peer. No-op if the peer has no vector configured for it.
 */
void ivshmem_ring_doorbell(struct ivshmem *ivshmem, unsigned int peer_id,
		unsigned int vector);

#endif /* _IVSHMEM_H_ */
