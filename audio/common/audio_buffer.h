/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _AUDIO_BUFFER_H_
#define _AUDIO_BUFFER_H_

#include "os/stdint.h"
#include "os/stdbool.h"
#include "os/stdio.h"

/* Configuration */
struct audio_buffer_config {
	unsigned int storage;	/* storage array index */
};

struct audio_buffer_storage_config {
	int32_t *base;		/* if NULL allocate on init */
	unsigned int periods;	/* used to determine the size */
};

/* Run Time */
struct audio_buffer {
	int32_t *base;		/* always 32bit per sample, S32_LE format */
	unsigned int read;	/* in units of samples */
	unsigned int write;	/* in units of samples */
	unsigned int size;	/* in units of samples */
	unsigned int size_mask;
};

void audio_buf_init(struct audio_buffer *buf, int32_t *base, unsigned int size);
unsigned int audio_buf_avail(struct audio_buffer *buf);
unsigned int audio_buf_free(struct audio_buffer *buf);
bool audio_buf_full(struct audio_buffer *buf);
bool audio_buf_empty(struct audio_buffer *buf);
void audio_buf_write(struct audio_buffer *buf, int32_t *samples, unsigned int len);
void audio_buf_read(struct audio_buffer *buf, int32_t *samples, unsigned int len);
void audio_buf_dump(struct audio_buffer *buf);

static inline void __audio_memcpy(int32_t *dst, int32_t *src, unsigned int len)
{
	int i;

	switch (len) {
	case 1:
		dst[0] = src[0];
		break;

	case 2:
		dst[0] = src[0];
		dst[1] = src[1];
		break;

	case 4:
		dst[0] = src[0];
		dst[1] = src[1];
		dst[2] = src[2];
		dst[3] = src[3];
		break;

	case 8:
		dst[0] = src[0];
		dst[1] = src[1];
		dst[2] = src[2];
		dst[3] = src[3];
		dst[4] = src[4];
		dst[5] = src[5];
		dst[6] = src[6];
		dst[7] = src[7];
		break;

	default:
		for (i = 0; i < len; i++)
			dst[i] = src[i];

		break;
	}
}

static inline void __audio_buf_write(struct audio_buffer *buf, unsigned int offset, int32_t *samples, unsigned int len)
{
	__audio_memcpy(&buf->base[buf->write + offset], samples, len);
}

static inline void __audio_buf_read(struct audio_buffer *buf, unsigned int offset, int32_t *samples, unsigned int len)
{
	__audio_memcpy(samples, &buf->base[buf->read + offset], len);
}

static inline void __audio_buf_copy(struct audio_buffer *dst, struct audio_buffer *src, unsigned int len)
{
	__audio_memcpy(&dst->base[dst->write], &src->base[src->read], len);
}

static inline void audio_buf_write_update(struct audio_buffer *buf, unsigned int len)
{
	unsigned int write = buf->write;

	write = (write + len) & buf->size_mask;

	buf->write = write;
}

static inline void audio_buf_read_update(struct audio_buffer *buf, unsigned int len)
{
	unsigned int read = buf->read;

	read = (read + len) & buf->size_mask;

	buf->read = read;
}

#endif /* _AUDIO_BUFFER_H_ */