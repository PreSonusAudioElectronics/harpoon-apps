/*
 * Copyright 2026 Fender Musical Instruments Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _IVSHMEM_REGS_H_
#define _IVSHMEM_REGS_H_

/*
 * ivshmem BAR0 register layout, shared by both sides of the link.
 */

/* MMIO registers */
#define IVSHMEM_REG_ID			0x00
#define IVSHMEM_REG_MAX_PEERS		0x04
#define IVSHMEM_REG_INT_CTRL		0x08
#define IVSHMEM_REG_DOORBELL		0x0c
#define IVSHMEM_REG_STATE		0x10

/* A doorbell write is (target peer id << shift) | vector */
#define IVSHMEM_DOORBELL_PEER_SHIFT	16

#endif /* _IVSHMEM_REGS_H_ */
