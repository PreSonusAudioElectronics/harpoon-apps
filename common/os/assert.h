/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _COMMON_ASSERT_H_
#define _COMMON_ASSERT_H_

#include "os.h"

#if defined(OS_ZEPHYR)
  #include "zephyr/os/assert.h"
#elif defined(OS_FREERTOS)
  #include "freertos/os/assert.h"
#endif

#endif /* #ifndef _COMMON_ASSERT_H_ */