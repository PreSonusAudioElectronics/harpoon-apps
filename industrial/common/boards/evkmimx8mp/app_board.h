/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _APP_BOARD_H_
#define _APP_BOARD_H_

#include "fsl_enet_qos.h"
#include "fsl_gpt.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_NET_TX_CACHEABLE
#define BOARD_NET_RX_CACHEABLE

/* PHY configuration */
#define BOARD_NUM_PHY        1

/* PHY 0 is RTL8211FDI phy */
#define BOARD_PHY0_ADDRESS      (0x01U)           /* Phy address of enet port 1. */
#define BOARD_PHY0_MDIO_BASE    ENET_QOS_BASE     /* MDIO MAC controller base address. */
#define BOARD_PHY0_MDIO_OPS     &enet_qos_ops     /* MDIO MAC controller operations. */
#define BOARD_PHY0_OPS          &phyrtl8211f_ops  /* PHY operations. */

#define BOARD_PHY0_TX_LATENCY_100M (650) /* FIXME - Needs calibration, comes from RT1170 which has same phy */
#define BOARD_PHY0_RX_LATENCY_100M (650) /* FIXME - Needs calibration, comes from RT1170 which has same phy */
#define BOARD_PHY0_TX_LATENCY_1G   (184)
#define BOARD_PHY0_RX_LATENCY_1G   (569)

/* Network Port configuration */
#define BOARD_NUM_PORTS                1
#define BOARD_NUM_ENET_QOS_PORTS       1

#define BOARD_NET_PORT0_MII_MODE    kENET_QOS_RgmiiMode
#define BOARD_NET_PORT0_DRV_TYPE    ENET_QOS_t
#define BOARD_NET_PORT0_DRV_BASE    ENET_QOS_BASE
#define BOARD_NET_PORT0_DRV_INDEX	(0)
#define BOARD_NET_PORT0_DRV_IRQ0     ENET_QOS_IRQn
#define BOARD_NET_PORT0_DRV_IRQ0_HND ENET_QOS_DriverIRQHandler

#define BOARD_NET_PORT0_1588_TIMER_CHANNEL_0      kENET_QOS_PtpPpsIstance0
#define BOARD_NET_PORT0_1588_TIMER_CHANNEL_1      kENET_QOS_PtpPpsIstance2
#define BOARD_NET_PORT0_1588_TIMER_CHANNEL_2      kENET_QOS_PtpPpsIstance3
#define BOARD_NET_PORT0_1588_TIMER_EVENT_CHANNEL  kENET_QOS_PtpPpsIstance1

#define BOARD_NET_PORT0_1588_TIMER_PPS            kENET_QOS_PtpPpsIstance3 /* FIXME - Need to identify timer channel with PPS output */

#define BOARD_NET_PORT0_PHY_INDEX   (0)

#define BOARD_GPT_0_BASE        GPT2
#define BOARD_GPT_0_IRQ         GPT2_IRQn

#define BOARD_GPT_1_BASE        GPT1
#define BOARD_GPT_1_IRQ         GPT1_IRQn

#define BOARD_GPT_1_CHANNEL          kGPT_InputCapture_Channel2
#define BOARD_GPT_1_INTERRUPT_MASK   kGPT_InputCapture2InterruptEnable
#define BOARD_GPT_1_STATUS_FLAG_MASK kGPT_InputCapture2Flag

#define BOARD_GPT_1_CLK_EXT_FREQ    24000000U
#define BOARD_GPT_1_CLK_SOURCE_TYPE kGPT_ClockSource_Periph

unsigned int BOARD_GPT_clk_src(void *base);
unsigned int BOARD_GPT_clk_freq(void *base);
int BOARD_NetPort_Get_MAC(unsigned int port, uint8_t *mac);

#define EXAMPLE_ENET_QOS_BASE   ENET_QOS
#define EXAMPLE_PHY_ADDR        0x01U
#define EXAMPLE_ENET_QOS_OPS    enet_qos_ops
#define EXAMPLE_PHY             phyrtl8211f_ops
#define EXAMPLE_ENET_QOS_IRQ    ENET_QOS_IRQn

#endif /* _APP_BOARD_H_ */
