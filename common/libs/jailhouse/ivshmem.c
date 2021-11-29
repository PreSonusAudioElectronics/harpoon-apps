/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>

#include "ivshmem.h"

#include <memory.h>

#include "os/stdio.h"

/* Jailhouse COMM */
struct jailhouse_console {
	uint64_t address;
	uint32_t size;
	uint16_t type;
	uint16_t flags;
	uint32_t divider;
	uint32_t gate_nr;
	uint64_t clock_reg;
} __attribute__((packed));

/* from include/jailhouse/hypercall.h */
struct comm_region {
	/** Communication region magic JHCOMM */
	char signature[6];
	/** Communication region ABI revision */
	uint16_t revision;
	/** Cell state, initialized by hypervisor, updated by cell. */
	volatile uint32_t cell_state;
	/** Message code sent from hypervisor to cell. */
	volatile uint32_t msg_to_cell;
	/** Reply code sent from cell to hypervisor. */
	volatile uint32_t reply_from_cell;
	/** Holds static flags, see JAILHOUSE_COMM_FLAG_*. */
	uint32_t flags;
	/** Debug console that may be accessed by the inmate. */
	struct jailhouse_console console;
	/** Base address of PCI memory mapped config. */
	uint64_t pci_mmconfig_base;
};

/* IVSHMEM PCI definitions */
/* PCI Type 0 header */
#define PCI_CFG_VENDOR_ID	0x0
#define PCI_CFG_DEVICE_ID	0x2
#define PCI_CFG_CMD		0x4
#define PCI_CFG_STATUS		0x6

#define PCI_CFG_BAR0		0x10
#define PCI_CFG_CAP		0x34

/* PCI CMD */
#define PCI_CMD_MEM		0x2

/* IVSHMEM Capility */
#define PCI_CAP_IVSHMEM		0x9

#define IVSHMEM_CAP_STATE_SIZE	4
#define IVSHMEM_CAP_RW_SIZE	8
#define IVSHMEM_CAP_OUT_SIZE	16
#define IVSHMEM_CAP_ADDR	24

/* MMIO registers */
#define IVSHMEM_REG_ID                  0x00
#define IVSHMEM_REG_MAX_PEERS           0x04
#define IVSHMEM_REG_INT_CTRL            0x08
#define IVSHMEM_REG_DOORBELL            0x0c
#define IVSHMEM_REG_STATE               0x10

static uint32_t mmio_read32(void *base, unsigned int offset)
{
	return *((volatile uint32_t *)(base + offset));
}

static uint16_t mmio_read16(void *base, unsigned int offset)
{
	return *((volatile uint16_t *)(base + offset));
}

static uint8_t mmio_read8(void *base, unsigned int offset)
{
	return *((volatile uint8_t *)(base + offset));
}

static void mmio_write32(void *base, unsigned int offset, uint32_t val)
{
	*((volatile uint32_t *)(base + offset)) = val;
}

static void mmio_write16(void *base, unsigned int offset, uint16_t val)
{
	*((volatile uint16_t *)(base + offset)) = val;
}

static void mmio_write8(void *base, unsigned int offset, uint8_t val)
{
	*((volatile uint8_t *)(base + offset)) = val;
}

static uint32_t pci_read_config(void *addr, unsigned int offset, unsigned int size)
{
	switch (size) {
	case 1:
		return mmio_read8(addr, offset);
	case 2:
		return mmio_read16(addr, offset);
	case 4:
	default:
		return mmio_read32(addr, offset);
	}
}

static void pci_write_config(void *addr, unsigned int offset, uint32_t val, unsigned int size)
{
	switch (size) {
	case 1:
		mmio_write8(addr, offset, val);
		break;
	case 2:
		mmio_write16(addr, offset, val);
		break;
	case 4:
	default:
		mmio_write32(addr, offset, val);
		break;
	}
}

static uint64_t pci_read_config64(void *addr, unsigned int offset)
{
	return pci_read_config(addr, offset, 4) | ((uint64_t)pci_read_config(addr, offset + 4, 4) << 32);
}

static void *pci_get_device(void *cfg_base, unsigned int bfd)
{
	return cfg_base + (bfd << 12);
}

static void *pci_find_cap(void *base, uint8_t next, uint8_t id)
{
	while (next) {
		if (pci_read_config(base, next, 1) == id)
			return base + next;

		next = pci_read_config(base, next + 1, 1);
	}

	return NULL;
}

int ivshmem_init(unsigned int bfd, struct ivshmem *ivshmem)
{
	struct comm_region *comm;
	void *cfg_base;
	void *pci;
	void *cap;
	void *mmio = (void *)PCI_MMIO_BASE;
	uint8_t next_cap;
	void *next;
	uintptr_t addr;
	int ret, i;

	/* Get PCI configuration base address from COMM region */
	comm = (struct comm_region *)HYPERVISOR_COMM_BASE;

	ret = ARM_MMU_AddMap("jh communication", (uintptr_t)HYPERVISOR_COMM_BASE, (uintptr_t)HYPERVISOR_COMM_BASE, KB(4), MT_NORMAL | MT_P_RW_U_RW | MT_NS);
	if (ret < 0)
		goto err;

	cfg_base = (void *)comm->pci_mmconfig_base;

	ret = ARM_MMU_AddMap("pci cfg", (uintptr_t)cfg_base, (uintptr_t)cfg_base, KB(1024), MT_NORMAL | MT_P_RW_U_RW | MT_NS);
	if (ret < 0)
		goto err;

	pci = pci_get_device(cfg_base, bfd);

	next_cap = pci_read_config(pci, PCI_CFG_CAP, 1);
	cap = pci_find_cap(pci, next_cap, PCI_CAP_IVSHMEM);
	if (!cap)
		goto err;

	/* Update device BAR0 with our MMIO address */
	pci_write_config(pci, PCI_CFG_BAR0, PCI_MMIO_BASE, 4);

	ret = ARM_MMU_AddMap("pci mmio", (uintptr_t)PCI_MMIO_BASE, (uintptr_t)PCI_MMIO_BASE, KB(4), MT_NORMAL | MT_P_RW_U_RW | MT_NS);
	if (ret < 0)
		goto err;

	/* Tell hypervisor to update */
	pci_write_config(pci, PCI_CFG_CMD, PCI_CMD_MEM, 2);

	/* Find device in PCI configuration */
	ivshmem->id = mmio_read32(mmio, IVSHMEM_REG_ID);
	ivshmem->peers = mmio_read32(mmio, IVSHMEM_REG_MAX_PEERS);
	ivshmem->state_size = pci_read_config(cap, IVSHMEM_CAP_STATE_SIZE, 4);
	ivshmem->rw_size = pci_read_config64(cap, IVSHMEM_CAP_RW_SIZE);
	ivshmem->out_size = pci_read_config64(cap, IVSHMEM_CAP_OUT_SIZE);

	ivshmem->state = (void *)pci_read_config64(cap, IVSHMEM_CAP_ADDR);
	next = ivshmem->state + ivshmem->state_size;

	ret = ARM_MMU_AddMap("ivshmem state", (uintptr_t)ivshmem->state, (uintptr_t)ivshmem->state, ivshmem->state_size, MT_NORMAL | MT_P_RO_U_RO | MT_NS);
	if (ret < 0)
		goto err;

	if (ivshmem->rw_size) {
		ivshmem->rw = next;

		ret = ARM_MMU_AddMap("ivshmem rw", (uintptr_t)ivshmem->rw, (uintptr_t)ivshmem->rw, ivshmem->state_size, MT_NORMAL | MT_P_RW_U_RW | MT_NS);
		if (ret < 0)
			goto err;

		next = ivshmem->rw + ivshmem->rw_size;
	} else {
		ivshmem->rw = NULL;
	}

	if (ivshmem->out_size) {
		ivshmem->out = next;

		for (i = 0; i < ivshmem->peers; i++) {
			addr = (uintptr_t)(ivshmem->out + i * ivshmem->out_size);

			if (i == ivshmem->id)
				ret = ARM_MMU_AddMap("ivshmem out", addr, addr, ivshmem->out_size, MT_NORMAL | MT_P_RW_U_RW | MT_NS);
			else
				ret = ARM_MMU_AddMap("ivshmem in", addr, addr, ivshmem->out_size, MT_NORMAL | MT_P_RO_U_RO | MT_NS);

			if (ret < 0)
				goto err;
		}
	} else {
		ivshmem->out = NULL;
	}

	os_printf("ivshmem init done\r\n");

	return 0;

err:
	os_printf("ivshmem init failed\r\n");

	return -1;
}