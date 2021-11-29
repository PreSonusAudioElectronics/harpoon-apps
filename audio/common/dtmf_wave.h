/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SAI_DTMF_WAVE_H_
#define _SAI_DTMF_WAVE_H_

void generate_dtmf_tone(uint32_t *buf, char lkey, char rkey, int sample_rate,
		uint32_t duration_us, uint32_t *phase);

#endif /* _SAI_DTMF_WAVE_H_ */