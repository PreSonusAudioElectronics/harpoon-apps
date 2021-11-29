/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _APP_BOARD_H_
#define _APP_BOARD_H_

/* Codec for EVK onboard */
#ifdef CODEC_WM8960

#define DEMO_SAI			(I2S3)

/* IMX8MP is master, codec is slave */
#define DEMO_SAI_MASTER_SLAVE		kSAI_Master

#define DEMO_SAI_CLK_FREQ				\
    (CLOCK_GetPllFreq(kCLOCK_AudioPll1Ctrl)		\
     / (CLOCK_GetRootPreDivider(kCLOCK_RootSai3))	\
     / (CLOCK_GetRootPostDivider(kCLOCK_RootSai3)))

/* Codec for HifiBerry */
#elif defined(CODEC_HIFIBERRY)

#define DEMO_SAI			(I2S5)

/* IMX8MP is slave, codec is master */
#define DEMO_SAI_MASTER_SLAVE		kSAI_Slave

#define DEMO_SAI_CLK_FREQ				\
    (CLOCK_GetPllFreq(kCLOCK_AudioPll1Ctrl)		\
     / (CLOCK_GetRootPreDivider(kCLOCK_RootSai5))	\
     / (CLOCK_GetRootPostDivider(kCLOCK_RootSai5)))

#define PCM512X_I2C_ADDR                (0x4D)
#define PCM512X_GPIO_LED                (4U)
#define PCM512X_GPIO_OSC44              (6U)
#define PCM512X_GPIO_OSC48              (3U)

#define PCM186X_I2C_ADDR		(0x4A)
#define PCM186X_GPIO_LED		(2U)

#endif /* CODEC_HIFIBERRY */

#define BOARD_CODEC_I2C			(I2C3)
#define BOARD_CODEC_I2C_INSTANCE	(3U)
#define BOARD_CODEC_I2C_CLOCK_FREQ	(16000000U)


#define DEMO_SAI_CHANNEL		(0)

#define I2C_RELEASE_SDA_GPIO		GPIO5
#define I2C_RELEASE_SDA_PIN		19U
#define I2C_RELEASE_SCL_GPIO		GPIO5
#define I2C_RELEASE_SCL_PIN		18U
#define I2C_RELEASE_BUS_COUNT		100U
/*set Bclk source to Mclk clock*/
#define DEMO_SAI_CLOCK_SOURCE		(1U)

#define DEMO_SAI_TX_SYNC_MODE		kSAI_ModeAsync
#define DEMO_SAI_RX_SYNC_MODE		kSAI_ModeSync
#define DEMO_SAI_MCLK_OUTPUT		true

#define DEMO_AUDIO_DATA_CHANNEL		(2U)
#define DEMO_AUDIO_BIT_WIDTH		kSAI_WordWidth32bits
#define DEMO_AUDIO_SAMPLE_RATE		(kSAI_SampleRate44100Hz)
#define DEMO_AUDIO_MASTER_CLOCK		DEMO_SAI_CLK_FREQ

#define PLAT_WITH_AUDIOMIX

#endif /* _APP_BOARD_H_ */