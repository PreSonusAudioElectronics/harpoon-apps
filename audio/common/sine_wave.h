/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SAI_SINE_WAVE_H_
#define _SAI_SINE_WAVE_H_

static uint16_t sine_wave[] =
{
  0x0000, 0x0000, 0x03ec, 0x03ec, 0x07d5, 0x07d5, 0x0bb6, 0x0bb6, 0x0f8c, 0x0f8c, 0x1353, 0x1353, 0x1708, 0x1708, 0x1aa6, 0x1aa6,
  0x1e2b, 0x1e2b, 0x2192, 0x2192, 0x24d9, 0x24d9, 0x27fd, 0x27fd, 0x2afa, 0x2afa, 0x2dce, 0x2dce, 0x3075, 0x3075, 0x32ee, 0x32ee,
  0x3536, 0x3536, 0x374a, 0x374a, 0x392a, 0x392a, 0x3ad2, 0x3ad2, 0x3c41, 0x3c41, 0x3d77, 0x3d77, 0x3e71, 0x3e71, 0x3f2f, 0x3f2f,
  0x3fb0, 0x3fb0, 0x3ff4, 0x3ff4, 0x3ffa, 0x3ffa, 0x3fc3, 0x3fc3, 0x3f4e, 0x3f4e, 0x3e9c, 0x3e9c, 0x3dae, 0x3dae, 0x3c84, 0x3c84,
  0x3b20, 0x3b20, 0x3983, 0x3983, 0x37af, 0x37af, 0x35a5, 0x35a5, 0x3367, 0x3367, 0x30f8, 0x30f8, 0x2e59, 0x2e59, 0x2b8e, 0x2b8e,
  0x2899, 0x2899, 0x257d, 0x257d, 0x223d, 0x223d, 0x1edb, 0x1edb, 0x1b5c, 0x1b5c, 0x17c3, 0x17c3, 0x1413, 0x1413, 0x104f, 0x104f,
  0x0c7c, 0x0c7c, 0x089c, 0x089c, 0x04b5, 0x04b5, 0x00c9, 0x00c9, 0xfcdd, 0xfcdd, 0xf8f3, 0xf8f3, 0xf510, 0xf510, 0xf137, 0xf137,
  0xed6d, 0xed6d, 0xe9b4, 0xe9b4, 0xe611, 0xe611, 0xe287, 0xe287, 0xdf1a, 0xdf1a, 0xdbcc, 0xdbcc, 0xd8a1, 0xd8a1, 0xd59c, 0xd59c,
  0xd2c0, 0xd2c0, 0xd00f, 0xd00f, 0xcd8d, 0xcd8d, 0xcb3b, 0xcb3b, 0xc91c, 0xc91c, 0xc732, 0xc732, 0xc57f, 0xc57f, 0xc404, 0xc404,
  0xc2c2, 0xc2c2, 0xc1bc, 0xc1bc, 0xc0f2, 0xc0f2, 0xc065, 0xc065, 0xc015, 0xc015, 0xc002, 0xc002, 0xc02d, 0xc02d, 0xc096, 0xc096,
  0xc13c, 0xc13c, 0xc21e, 0xc21e, 0xc33c, 0xc33c, 0xc494, 0xc494, 0xc626, 0xc626, 0xc7ef, 0xc7ef, 0xc9ef, 0xc9ef, 0xcc22, 0xcc22,
  0xce88, 0xce88, 0xd11d, 0xd11d, 0xd3df, 0xd3df, 0xd6cc, 0xd6cc, 0xd9e1, 0xd9e1, 0xdd1a, 0xdd1a, 0xe075, 0xe075, 0xe3ee, 0xe3ee,
  0xe783, 0xe783, 0xeb2f, 0xeb2f, 0xeeef, 0xeeef, 0xf2bf, 0xf2bf, 0xf69d, 0xf69d, 0xfa83, 0xfa83, 0xfe6e, 0xfe6e, 0x025b, 0x025b,
  0x0645, 0x0645, 0x0a2a, 0x0a2a, 0x0e05, 0x0e05, 0x11d3, 0x11d3, 0x158f, 0x158f, 0x1936, 0x1936, 0x1cc6, 0x1cc6, 0x2039, 0x2039,
  0x238e, 0x238e, 0x26c0, 0x26c0, 0x29cd, 0x29cd, 0x2cb1, 0x2cb1, 0x2f6b, 0x2f6b, 0x31f7, 0x31f7, 0x3452, 0x3452, 0x367c, 0x367c,
  0x3870, 0x3870, 0x3a2f, 0x3a2f, 0x3bb5, 0x3bb5, 0x3d02, 0x3d02, 0x3e14, 0x3e14, 0x3eea, 0x3eea, 0x3f84, 0x3f84, 0x3fe0, 0x3fe0,
  0x3fff, 0x3fff, 0x3fe0, 0x3fe0, 0x3f84, 0x3f84, 0x3eea, 0x3eea, 0x3e14, 0x3e14, 0x3d02, 0x3d02, 0x3bb5, 0x3bb5, 0x3a2f, 0x3a2f,
  0x3870, 0x3870, 0x367c, 0x367c, 0x3452, 0x3452, 0x31f7, 0x31f7, 0x2f6b, 0x2f6b, 0x2cb1, 0x2cb1, 0x29cd, 0x29cd, 0x26c0, 0x26c0,
  0x238e, 0x238e, 0x2039, 0x2039, 0x1cc6, 0x1cc6, 0x1936, 0x1936, 0x158f, 0x158f, 0x11d3, 0x11d3, 0x0e05, 0x0e05, 0x0a2a, 0x0a2a,
  0x0645, 0x0645, 0x025b, 0x025b, 0xfe6e, 0xfe6e, 0xfa83, 0xfa83, 0xf69d, 0xf69d, 0xf2bf, 0xf2bf, 0xeeef, 0xeeef, 0xeb2f, 0xeb2f,
  0xe783, 0xe783, 0xe3ee, 0xe3ee, 0xe075, 0xe075, 0xdd1a, 0xdd1a, 0xd9e1, 0xd9e1, 0xd6cc, 0xd6cc, 0xd3df, 0xd3df, 0xd11d, 0xd11d,
  0xce88, 0xce88, 0xcc22, 0xcc22, 0xc9ef, 0xc9ef, 0xc7ef, 0xc7ef, 0xc626, 0xc626, 0xc494, 0xc494, 0xc33c, 0xc33c, 0xc21e, 0xc21e,
  0xc13c, 0xc13c, 0xc096, 0xc096, 0xc02d, 0xc02d, 0xc002, 0xc002, 0xc015, 0xc015, 0xc065, 0xc065, 0xc0f2, 0xc0f2, 0xc1bc, 0xc1bc,
  0xc2c2, 0xc2c2, 0xc404, 0xc404, 0xc57f, 0xc57f, 0xc732, 0xc732, 0xc91c, 0xc91c, 0xcb3b, 0xcb3b, 0xcd8d, 0xcd8d, 0xd00f, 0xd00f,
  0xd2c0, 0xd2c0, 0xd59c, 0xd59c, 0xd8a1, 0xd8a1, 0xdbcc, 0xdbcc, 0xdf1a, 0xdf1a, 0xe287, 0xe287, 0xe611, 0xe611, 0xe9b4, 0xe9b4,
  0xed6d, 0xed6d, 0xf137, 0xf137, 0xf510, 0xf510, 0xf8f3, 0xf8f3, 0xfcdd, 0xfcdd, 0x00c9, 0x00c9, 0x04b5, 0x04b5, 0x089c, 0x089c,
  0x0c7c, 0x0c7c, 0x104f, 0x104f, 0x1413, 0x1413, 0x17c3, 0x17c3, 0x1b5c, 0x1b5c, 0x1edb, 0x1edb, 0x223d, 0x223d, 0x257d, 0x257d,
  0x2899, 0x2899, 0x2b8e, 0x2b8e, 0x2e59, 0x2e59, 0x30f8, 0x30f8, 0x3367, 0x3367, 0x35a5, 0x35a5, 0x37af, 0x37af, 0x3983, 0x3983,
  0x3b20, 0x3b20, 0x3c84, 0x3c84, 0x3dae, 0x3dae, 0x3e9c, 0x3e9c, 0x3f4e, 0x3f4e, 0x3fc3, 0x3fc3, 0x3ffa, 0x3ffa, 0x3ff4, 0x3ff4,
  0x3fb0, 0x3fb0, 0x3f2f, 0x3f2f, 0x3e71, 0x3e71, 0x3d77, 0x3d77, 0x3c41, 0x3c41, 0x3ad2, 0x3ad2, 0x392a, 0x392a, 0x374a, 0x374a,
  0x3536, 0x3536, 0x32ee, 0x32ee, 0x3075, 0x3075, 0x2dce, 0x2dce, 0x2afa, 0x2afa, 0x27fd, 0x27fd, 0x24d9, 0x24d9, 0x2192, 0x2192,
  0x1e2b, 0x1e2b, 0x1aa6, 0x1aa6, 0x1708, 0x1708, 0x1353, 0x1353, 0x0f8c, 0x0f8c, 0x0bb6, 0x0bb6, 0x07d5, 0x07d5, 0x03ec, 0x03ec,
  0x0000, 0x0000, 0xfc14, 0xfc14, 0xf82b, 0xf82b, 0xf44a, 0xf44a, 0xf074, 0xf074, 0xecad, 0xecad, 0xe8f8, 0xe8f8, 0xe55a, 0xe55a,
  0xe1d5, 0xe1d5, 0xde6e, 0xde6e, 0xdb27, 0xdb27, 0xd803, 0xd803, 0xd506, 0xd506, 0xd232, 0xd232, 0xcf8b, 0xcf8b, 0xcd12, 0xcd12,
  0xcaca, 0xcaca, 0xc8b6, 0xc8b6, 0xc6d6, 0xc6d6, 0xc52e, 0xc52e, 0xc3bf, 0xc3bf, 0xc289, 0xc289, 0xc18f, 0xc18f, 0xc0d1, 0xc0d1,
  0xc050, 0xc050, 0xc00c, 0xc00c, 0xc006, 0xc006, 0xc03d, 0xc03d, 0xc0b2, 0xc0b2, 0xc164, 0xc164, 0xc252, 0xc252, 0xc37c, 0xc37c,
  0xc4e0, 0xc4e0, 0xc67d, 0xc67d, 0xc851, 0xc851, 0xca5b, 0xca5b, 0xcc99, 0xcc99, 0xcf08, 0xcf08, 0xd1a7, 0xd1a7, 0xd472, 0xd472,
  0xd767, 0xd767, 0xda83, 0xda83, 0xddc3, 0xddc3, 0xe125, 0xe125, 0xe4a4, 0xe4a4, 0xe83d, 0xe83d, 0xebed, 0xebed, 0xefb1, 0xefb1,
  0xf384, 0xf384, 0xf764, 0xf764, 0xfb4b, 0xfb4b, 0xff37, 0xff37, 0x0323, 0x0323, 0x070d, 0x070d, 0x0af0, 0x0af0, 0x0ec9, 0x0ec9,
  0x1293, 0x1293, 0x164c, 0x164c, 0x19ef, 0x19ef, 0x1d79, 0x1d79, 0x20e6, 0x20e6, 0x2434, 0x2434, 0x275f, 0x275f, 0x2a64, 0x2a64,
  0x2d40, 0x2d40, 0x2ff1, 0x2ff1, 0x3273, 0x3273, 0x34c5, 0x34c5, 0x36e4, 0x36e4, 0x38ce, 0x38ce, 0x3a81, 0x3a81, 0x3bfc, 0x3bfc,
  0x3d3e, 0x3d3e, 0x3e44, 0x3e44, 0x3f0e, 0x3f0e, 0x3f9b, 0x3f9b, 0x3feb, 0x3feb, 0x3ffe, 0x3ffe, 0x3fd3, 0x3fd3, 0x3f6a, 0x3f6a,
  0x3ec4, 0x3ec4, 0x3de2, 0x3de2, 0x3cc4, 0x3cc4, 0x3b6c, 0x3b6c, 0x39da, 0x39da, 0x3811, 0x3811, 0x3611, 0x3611, 0x33de, 0x33de,
  0x3178, 0x3178, 0x2ee3, 0x2ee3, 0x2c21, 0x2c21, 0x2934, 0x2934, 0x261f, 0x261f, 0x22e6, 0x22e6, 0x1f8b, 0x1f8b, 0x1c12, 0x1c12,
  0x187d, 0x187d, 0x14d1, 0x14d1, 0x1111, 0x1111, 0x0d41, 0x0d41, 0x0963, 0x0963, 0x057d, 0x057d, 0x0192, 0x0192, 0xfda5, 0xfda5,
  0xf9bb, 0xf9bb, 0xf5d6, 0xf5d6, 0xf1fb, 0xf1fb, 0xee2d, 0xee2d, 0xea71, 0xea71, 0xe6ca, 0xe6ca, 0xe33a, 0xe33a, 0xdfc7, 0xdfc7,
  0xdc72, 0xdc72, 0xd940, 0xd940, 0xd633, 0xd633, 0xd34f, 0xd34f, 0xd095, 0xd095, 0xce09, 0xce09, 0xcbae, 0xcbae, 0xc984, 0xc984,
  0xc790, 0xc790, 0xc5d1, 0xc5d1, 0xc44b, 0xc44b, 0xc2fe, 0xc2fe, 0xc1ec, 0xc1ec, 0xc116, 0xc116, 0xc07c, 0xc07c, 0xc020, 0xc020,
  0xc001, 0xc001, 0xc020, 0xc020, 0xc07c, 0xc07c, 0xc116, 0xc116, 0xc1ec, 0xc1ec, 0xc2fe, 0xc2fe, 0xc44b, 0xc44b, 0xc5d1, 0xc5d1,
  0xc790, 0xc790, 0xc984, 0xc984, 0xcbae, 0xcbae, 0xce09, 0xce09, 0xd095, 0xd095, 0xd34f, 0xd34f, 0xd633, 0xd633, 0xd940, 0xd940,
  0xdc72, 0xdc72, 0xdfc7, 0xdfc7, 0xe33a, 0xe33a, 0xe6ca, 0xe6ca, 0xea71, 0xea71, 0xee2d, 0xee2d, 0xf1fb, 0xf1fb, 0xf5d6, 0xf5d6,
  0xf9bb, 0xf9bb, 0xfda5, 0xfda5, 0x0192, 0x0192, 0x057d, 0x057d, 0x0963, 0x0963, 0x0d41, 0x0d41, 0x1111, 0x1111, 0x14d1, 0x14d1,
  0x187d, 0x187d, 0x1c12, 0x1c12, 0x1f8b, 0x1f8b, 0x22e6, 0x22e6, 0x261f, 0x261f, 0x2934, 0x2934, 0x2c21, 0x2c21, 0x2ee3, 0x2ee3,
  0x3178, 0x3178, 0x33de, 0x33de, 0x3611, 0x3611, 0x3811, 0x3811, 0x39da, 0x39da, 0x3b6c, 0x3b6c, 0x3cc4, 0x3cc4, 0x3de2, 0x3de2,
  0x3ec4, 0x3ec4, 0x3f6a, 0x3f6a, 0x3fd3, 0x3fd3, 0x3ffe, 0x3ffe, 0x3feb, 0x3feb, 0x3f9b, 0x3f9b, 0x3f0e, 0x3f0e, 0x3e44, 0x3e44,
  0x3d3e, 0x3d3e, 0x3bfc, 0x3bfc, 0x3a81, 0x3a81, 0x38ce, 0x38ce, 0x36e4, 0x36e4, 0x34c5, 0x34c5, 0x3273, 0x3273, 0x2ff1, 0x2ff1,
  0x2d40, 0x2d40, 0x2a64, 0x2a64, 0x275f, 0x275f, 0x2434, 0x2434, 0x20e6, 0x20e6, 0x1d79, 0x1d79, 0x19ef, 0x19ef, 0x164c, 0x164c,
  0x1293, 0x1293, 0x0ec9, 0x0ec9, 0x0af0, 0x0af0, 0x070d, 0x070d, 0x0323, 0x0323, 0xff37, 0xff37, 0xfb4b, 0xfb4b, 0xf764, 0xf764,
  0xf384, 0xf384, 0xefb1, 0xefb1, 0xebed, 0xebed, 0xe83d, 0xe83d, 0xe4a4, 0xe4a4, 0xe125, 0xe125, 0xddc3, 0xddc3, 0xda83, 0xda83,
  0xd767, 0xd767, 0xd472, 0xd472, 0xd1a7, 0xd1a7, 0xcf08, 0xcf08, 0xcc99, 0xcc99, 0xca5b, 0xca5b, 0xc851, 0xc851, 0xc67d, 0xc67d,
  0xc4e0, 0xc4e0, 0xc37c, 0xc37c, 0xc252, 0xc252, 0xc164, 0xc164, 0xc0b2, 0xc0b2, 0xc03d, 0xc03d, 0xc006, 0xc006, 0xc00c, 0xc00c,
  0xc050, 0xc050, 0xc0d1, 0xc0d1, 0xc18f, 0xc18f, 0xc289, 0xc289, 0xc3bf, 0xc3bf, 0xc52e, 0xc52e, 0xc6d6, 0xc6d6, 0xc8b6, 0xc8b6,
  0xcaca, 0xcaca, 0xcd12, 0xcd12, 0xcf8b, 0xcf8b, 0xd232, 0xd232, 0xd506, 0xd506, 0xd803, 0xd803, 0xdb27, 0xdb27, 0xde6e, 0xde6e,
  0xe1d5, 0xe1d5, 0xe55a, 0xe55a, 0xe8f8, 0xe8f8, 0xecad, 0xecad, 0xf074, 0xf074, 0xf44a, 0xf44a, 0xf82b, 0xf82b, 0xfc14, 0xfc14,
  0x0000, 0x0000, 0x03ec, 0x03ec, 0x07d5, 0x07d5, 0x0bb6, 0x0bb6, 0x0f8c, 0x0f8c, 0x1353, 0x1353, 0x1708, 0x1708, 0x1aa6, 0x1aa6,
  0x1e2b, 0x1e2b, 0x2192, 0x2192, 0x24d9, 0x24d9, 0x27fd, 0x27fd, 0x2afa, 0x2afa, 0x2dce, 0x2dce, 0x3075, 0x3075, 0x32ee, 0x32ee,
  0x3536, 0x3536, 0x374a, 0x374a, 0x392a, 0x392a, 0x3ad2, 0x3ad2, 0x3c41, 0x3c41, 0x3d77, 0x3d77, 0x3e71, 0x3e71, 0x3f2f, 0x3f2f,
  0x3fb0, 0x3fb0, 0x3ff4, 0x3ff4, 0x3ffa, 0x3ffa, 0x3fc3, 0x3fc3, 0x3f4e, 0x3f4e, 0x3e9c, 0x3e9c, 0x3dae, 0x3dae, 0x3c84, 0x3c84,
  0x3b20, 0x3b20, 0x3983, 0x3983, 0x37af, 0x37af, 0x35a5, 0x35a5, 0x3367, 0x3367, 0x30f8, 0x30f8, 0x2e59, 0x2e59, 0x2b8e, 0x2b8e,
  0x2899, 0x2899, 0x257d, 0x257d, 0x223d, 0x223d, 0x1edb, 0x1edb, 0x1b5c, 0x1b5c, 0x17c3, 0x17c3, 0x1413, 0x1413, 0x104f, 0x104f,
  0x0c7c, 0x0c7c, 0x089c, 0x089c, 0x04b5, 0x04b5, 0x00c9, 0x00c9, 0xfcdd, 0xfcdd, 0xf8f3, 0xf8f3, 0xf510, 0xf510, 0xf137, 0xf137,
  0xed6d, 0xed6d, 0xe9b4, 0xe9b4, 0xe611, 0xe611, 0xe287, 0xe287, 0xdf1a, 0xdf1a, 0xdbcc, 0xdbcc, 0xd8a1, 0xd8a1, 0xd59c, 0xd59c,
  0xd2c0, 0xd2c0, 0xd00f, 0xd00f, 0xcd8d, 0xcd8d, 0xcb3b, 0xcb3b, 0xc91c, 0xc91c, 0xc732, 0xc732, 0xc57f, 0xc57f, 0xc404, 0xc404,
  0xc2c2, 0xc2c2, 0xc1bc, 0xc1bc, 0xc0f2, 0xc0f2, 0xc065, 0xc065, 0xc015, 0xc015, 0xc002, 0xc002, 0xc02d, 0xc02d, 0xc096, 0xc096,
  0xc13c, 0xc13c, 0xc21e, 0xc21e, 0xc33c, 0xc33c, 0xc494, 0xc494, 0xc626, 0xc626, 0xc7ef, 0xc7ef, 0xc9ef, 0xc9ef, 0xcc22, 0xcc22,
  0xce88, 0xce88, 0xd11d, 0xd11d, 0xd3df, 0xd3df, 0xd6cc, 0xd6cc, 0xd9e1, 0xd9e1, 0xdd1a, 0xdd1a, 0xe075, 0xe075, 0xe3ee, 0xe3ee,
  0xe783, 0xe783, 0xeb2f, 0xeb2f, 0xeeef, 0xeeef, 0xf2bf, 0xf2bf, 0xf69d, 0xf69d, 0xfa83, 0xfa83, 0xfe6e, 0xfe6e, 0x025b, 0x025b,
  0x0645, 0x0645, 0x0a2a, 0x0a2a, 0x0e05, 0x0e05, 0x11d3, 0x11d3, 0x158f, 0x158f, 0x1936, 0x1936, 0x1cc6, 0x1cc6, 0x2039, 0x2039,
  0x238e, 0x238e, 0x26c0, 0x26c0, 0x29cd, 0x29cd, 0x2cb1, 0x2cb1, 0x2f6b, 0x2f6b, 0x31f7, 0x31f7, 0x3452, 0x3452, 0x367c, 0x367c,
  0x3870, 0x3870, 0x3a2f, 0x3a2f, 0x3bb5, 0x3bb5, 0x3d02, 0x3d02, 0x3e14, 0x3e14, 0x3eea, 0x3eea, 0x3f84, 0x3f84, 0x3fe0, 0x3fe0,
  0x3fff, 0x3fff, 0x3fe0, 0x3fe0, 0x3f84, 0x3f84, 0x3eea, 0x3eea, 0x3e14, 0x3e14, 0x3d02, 0x3d02, 0x3bb5, 0x3bb5, 0x3a2f, 0x3a2f,
  0x3870, 0x3870, 0x367c, 0x367c, 0x3452, 0x3452, 0x31f7, 0x31f7, 0x2f6b, 0x2f6b, 0x2cb1, 0x2cb1, 0x29cd, 0x29cd, 0x26c0, 0x26c0,
  0x238e, 0x238e, 0x2039, 0x2039, 0x1cc6, 0x1cc6, 0x1936, 0x1936, 0x158f, 0x158f, 0x11d3, 0x11d3, 0x0e05, 0x0e05, 0x0a2a, 0x0a2a,
  0x0645, 0x0645, 0x025b, 0x025b, 0xfe6e, 0xfe6e, 0xfa83, 0xfa83, 0xf69d, 0xf69d, 0xf2bf, 0xf2bf, 0xeeef, 0xeeef, 0xeb2f, 0xeb2f,
  0xe783, 0xe783, 0xe3ee, 0xe3ee, 0xe075, 0xe075, 0xdd1a, 0xdd1a, 0xd9e1, 0xd9e1, 0xd6cc, 0xd6cc, 0xd3df, 0xd3df, 0xd11d, 0xd11d,
  0xce88, 0xce88, 0xcc22, 0xcc22, 0xc9ef, 0xc9ef, 0xc7ef, 0xc7ef, 0xc626, 0xc626, 0xc494, 0xc494, 0xc33c, 0xc33c, 0xc21e, 0xc21e,
  0xc13c, 0xc13c, 0xc096, 0xc096, 0xc02d, 0xc02d, 0xc002, 0xc002, 0xc015, 0xc015, 0xc065, 0xc065, 0xc0f2, 0xc0f2, 0xc1bc, 0xc1bc,
  0xc2c2, 0xc2c2, 0xc404, 0xc404, 0xc57f, 0xc57f, 0xc732, 0xc732, 0xc91c, 0xc91c, 0xcb3b, 0xcb3b, 0xcd8d, 0xcd8d, 0xd00f, 0xd00f,
  0xd2c0, 0xd2c0, 0xd59c, 0xd59c, 0xd8a1, 0xd8a1, 0xdbcc, 0xdbcc, 0xdf1a, 0xdf1a, 0xe287, 0xe287, 0xe611, 0xe611, 0xe9b4, 0xe9b4,
  0xed6d, 0xed6d, 0xf137, 0xf137, 0xf510, 0xf510, 0xf8f3, 0xf8f3, 0xfcdd, 0xfcdd, 0x00c9, 0x00c9, 0x04b5, 0x04b5, 0x089c, 0x089c,
  0x0c7c, 0x0c7c, 0x104f, 0x104f, 0x1413, 0x1413, 0x17c3, 0x17c3, 0x1b5c, 0x1b5c, 0x1edb, 0x1edb, 0x223d, 0x223d, 0x257d, 0x257d,
  0x2899, 0x2899, 0x2b8e, 0x2b8e, 0x2e59, 0x2e59, 0x30f8, 0x30f8, 0x3367, 0x3367, 0x35a5, 0x35a5, 0x37af, 0x37af, 0x3983, 0x3983,
  0x3b20, 0x3b20, 0x3c84, 0x3c84, 0x3dae, 0x3dae, 0x3e9c, 0x3e9c, 0x3f4e, 0x3f4e, 0x3fc3, 0x3fc3, 0x3ffa, 0x3ffa, 0x3ff4, 0x3ff4,
  0x3fb0, 0x3fb0, 0x3f2f, 0x3f2f, 0x3e71, 0x3e71, 0x3d77, 0x3d77, 0x3c41, 0x3c41, 0x3ad2, 0x3ad2, 0x392a, 0x392a, 0x374a, 0x374a,
  0x3536, 0x3536, 0x32ee, 0x32ee, 0x3075, 0x3075, 0x2dce, 0x2dce, 0x2afa, 0x2afa, 0x27fd, 0x27fd, 0x24d9, 0x24d9, 0x2192, 0x2192,
  0x1e2b, 0x1e2b, 0x1aa6, 0x1aa6, 0x1708, 0x1708, 0x1353, 0x1353, 0x0f8c, 0x0f8c, 0x0bb6, 0x0bb6, 0x07d5, 0x07d5, 0x03ec, 0x03ec,
  0x0000, 0x0000, 0xfc14, 0xfc14, 0xf82b, 0xf82b, 0xf44a, 0xf44a, 0xf074, 0xf074, 0xecad, 0xecad, 0xe8f8, 0xe8f8, 0xe55a, 0xe55a,
  0xe1d5, 0xe1d5, 0xde6e, 0xde6e, 0xdb27, 0xdb27, 0xd803, 0xd803, 0xd506, 0xd506, 0xd232, 0xd232, 0xcf8b, 0xcf8b, 0xcd12, 0xcd12,
  0xcaca, 0xcaca, 0xc8b6, 0xc8b6, 0xc6d6, 0xc6d6, 0xc52e, 0xc52e, 0xc3bf, 0xc3bf, 0xc289, 0xc289, 0xc18f, 0xc18f, 0xc0d1, 0xc0d1,
  0xc050, 0xc050, 0xc00c, 0xc00c, 0xc006, 0xc006, 0xc03d, 0xc03d, 0xc0b2, 0xc0b2, 0xc164, 0xc164, 0xc252, 0xc252, 0xc37c, 0xc37c,
  0xc4e0, 0xc4e0, 0xc67d, 0xc67d, 0xc851, 0xc851, 0xca5b, 0xca5b, 0xcc99, 0xcc99, 0xcf08, 0xcf08, 0xd1a7, 0xd1a7, 0xd472, 0xd472,
  0xd767, 0xd767, 0xda83, 0xda83, 0xddc3, 0xddc3, 0xe125, 0xe125, 0xe4a4, 0xe4a4, 0xe83d, 0xe83d, 0xebed, 0xebed, 0xefb1, 0xefb1,
  0xf384, 0xf384, 0xf764, 0xf764, 0xfb4b, 0xfb4b, 0xff37, 0xff37, 0x0323, 0x0323, 0x070d, 0x070d, 0x0af0, 0x0af0, 0x0ec9, 0x0ec9,
  0x1293, 0x1293, 0x164c, 0x164c, 0x19ef, 0x19ef, 0x1d79, 0x1d79, 0x20e6, 0x20e6, 0x2434, 0x2434, 0x275f, 0x275f, 0x2a64, 0x2a64,
  0x2d40, 0x2d40, 0x2ff1, 0x2ff1, 0x3273, 0x3273, 0x34c5, 0x34c5, 0x36e4, 0x36e4, 0x38ce, 0x38ce, 0x3a81, 0x3a81, 0x3bfc, 0x3bfc,
  0x3d3e, 0x3d3e, 0x3e44, 0x3e44, 0x3f0e, 0x3f0e, 0x3f9b, 0x3f9b, 0x3feb, 0x3feb, 0x3ffe, 0x3ffe, 0x3fd3, 0x3fd3, 0x3f6a, 0x3f6a,
  0x3ec4, 0x3ec4, 0x3de2, 0x3de2, 0x3cc4, 0x3cc4, 0x3b6c, 0x3b6c, 0x39da, 0x39da, 0x3811, 0x3811, 0x3611, 0x3611, 0x33de, 0x33de,
  0x3178, 0x3178, 0x2ee3, 0x2ee3, 0x2c21, 0x2c21, 0x2934, 0x2934, 0x261f, 0x261f, 0x22e6, 0x22e6, 0x1f8b, 0x1f8b, 0x1c12, 0x1c12,
  0x187d, 0x187d, 0x14d1, 0x14d1, 0x1111, 0x1111, 0x0d41, 0x0d41, 0x0963, 0x0963, 0x057d, 0x057d, 0x0192, 0x0192, 0xfda5, 0xfda5,
  0xf9bb, 0xf9bb, 0xf5d6, 0xf5d6, 0xf1fb, 0xf1fb, 0xee2d, 0xee2d, 0xea71, 0xea71, 0xe6ca, 0xe6ca, 0xe33a, 0xe33a, 0xdfc7, 0xdfc7,
  0xdc72, 0xdc72, 0xd940, 0xd940, 0xd633, 0xd633, 0xd34f, 0xd34f, 0xd095, 0xd095, 0xce09, 0xce09, 0xcbae, 0xcbae, 0xc984, 0xc984,
  0xc790, 0xc790, 0xc5d1, 0xc5d1, 0xc44b, 0xc44b, 0xc2fe, 0xc2fe, 0xc1ec, 0xc1ec, 0xc116, 0xc116, 0xc07c, 0xc07c, 0xc020, 0xc020,
  0xc001, 0xc001, 0xc020, 0xc020, 0xc07c, 0xc07c, 0xc116, 0xc116, 0xc1ec, 0xc1ec, 0xc2fe, 0xc2fe, 0xc44b, 0xc44b, 0xc5d1, 0xc5d1,
  0xc790, 0xc790, 0xc984, 0xc984, 0xcbae, 0xcbae, 0xce09, 0xce09, 0xd095, 0xd095, 0xd34f, 0xd34f, 0xd633, 0xd633, 0xd940, 0xd940,
  0xdc72, 0xdc72, 0xdfc7, 0xdfc7, 0xe33a, 0xe33a, 0xe6ca, 0xe6ca, 0xea71, 0xea71, 0xee2d, 0xee2d, 0xf1fb, 0xf1fb, 0xf5d6, 0xf5d6,
  0xf9bb, 0xf9bb, 0xfda5, 0xfda5, 0x0192, 0x0192, 0x057d, 0x057d, 0x0963, 0x0963, 0x0d41, 0x0d41, 0x1111, 0x1111, 0x14d1, 0x14d1,
  0x187d, 0x187d, 0x1c12, 0x1c12, 0x1f8b, 0x1f8b, 0x22e6, 0x22e6, 0x261f, 0x261f, 0x2934, 0x2934, 0x2c21, 0x2c21, 0x2ee3, 0x2ee3,
  0x3178, 0x3178, 0x33de, 0x33de, 0x3611, 0x3611, 0x3811, 0x3811, 0x39da, 0x39da, 0x3b6c, 0x3b6c, 0x3cc4, 0x3cc4, 0x3de2, 0x3de2,
  0x3ec4, 0x3ec4, 0x3f6a, 0x3f6a, 0x3fd3, 0x3fd3, 0x3ffe, 0x3ffe, 0x3feb, 0x3feb, 0x3f9b, 0x3f9b, 0x3f0e, 0x3f0e, 0x3e44, 0x3e44,
  0x3d3e, 0x3d3e, 0x3bfc, 0x3bfc, 0x3a81, 0x3a81, 0x38ce, 0x38ce, 0x36e4, 0x36e4, 0x34c5, 0x34c5, 0x3273, 0x3273, 0x2ff1, 0x2ff1,
  0x2d40, 0x2d40, 0x2a64, 0x2a64, 0x275f, 0x275f, 0x2434, 0x2434, 0x20e6, 0x20e6, 0x1d79, 0x1d79, 0x19ef, 0x19ef, 0x164c, 0x164c,
  0x1293, 0x1293, 0x0ec9, 0x0ec9, 0x0af0, 0x0af0, 0x070d, 0x070d, 0x0323, 0x0323, 0xff37, 0xff37, 0xfb4b, 0xfb4b, 0xf764, 0xf764,
  0xf384, 0xf384, 0xefb1, 0xefb1, 0xebed, 0xebed, 0xe83d, 0xe83d, 0xe4a4, 0xe4a4, 0xe125, 0xe125, 0xddc3, 0xddc3, 0xda83, 0xda83,
  0xd767, 0xd767, 0xd472, 0xd472, 0xd1a7, 0xd1a7, 0xcf08, 0xcf08, 0xcc99, 0xcc99, 0xca5b, 0xca5b, 0xc851, 0xc851, 0xc67d, 0xc67d,
  0xc4e0, 0xc4e0, 0xc37c, 0xc37c, 0xc252, 0xc252, 0xc164, 0xc164, 0xc0b2, 0xc0b2, 0xc03d, 0xc03d, 0xc006, 0xc006, 0xc00c, 0xc00c,
  0xc050, 0xc050, 0xc0d1, 0xc0d1, 0xc18f, 0xc18f, 0xc289, 0xc289, 0xc3bf, 0xc3bf, 0xc52e, 0xc52e, 0xc6d6, 0xc6d6, 0xc8b6, 0xc8b6,
  0xcaca, 0xcaca, 0xcd12, 0xcd12, 0xcf8b, 0xcf8b, 0xd232, 0xd232, 0xd506, 0xd506, 0xd803, 0xd803, 0xdb27, 0xdb27, 0xde6e, 0xde6e,
  0xe1d5, 0xe1d5, 0xe55a, 0xe55a, 0xe8f8, 0xe8f8, 0xecad, 0xecad, 0xf074, 0xf074, 0xf44a, 0xf44a, 0xf82b, 0xf82b, 0xfc14, 0xfc14
};

#endif /* _SAI_SINE_WAVE_H_ */