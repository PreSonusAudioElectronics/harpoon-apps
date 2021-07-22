/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _COMMON_COUNTER_H_
#define _COMMON_COUNTER_H_

#include <stdbool.h>
#include <stdint.h>

#include "os.h"

#if defined(OS_ZEPHYR)
  #include "zephyr/os/counter.h"
#elif defined(OS_FREERTOS)
  #include "freertos/os/counter.h"
#endif

int os_counter_start(const void *dev);
int os_counter_stop(const void *dev);
uint8_t os_counter_get_num_of_channels(const void *dev);
int os_counter_get_value(const void *dev, uint32_t *cnt);
bool os_counter_is_counting_up(const void *dev);
uint32_t os_counter_us_to_ticks(const void *dev, uint64_t period_us);
uint64_t os_counter_ticks_to_ns(const void *dev, uint32_t ticks);
uint32_t os_counter_get_top_value(const void *dev);
int os_counter_set_channel_alarm(const void *dev, uint8_t chan_id,
          const struct os_counter_alarm_cfg *alarm_cfg);
int os_counter_reset_channel_alarm(const void *dev, uint8_t chan_id);

#endif /* #ifndef _COMMON_COUNTER_H_ */