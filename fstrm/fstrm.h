/*
 * Copyright (c) 2013-2014 by Farsight Security, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FSTRM_H
#define FSTRM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#define FSTRM_CONTROL_ACCEPT	0x01
#define FSTRM_CONTROL_START	0x02
#define FSTRM_CONTROL_STOP	0x03

struct fstrm_io;
struct fstrm_io_options;
struct fstrm_queue;
struct fstrm_writer;
struct fstrm_writer_options;

/* fstrm_io */

struct fstrm_io *
fstrm_io_init(const struct fstrm_io_options *, char **err);

void
fstrm_io_destroy(struct fstrm_io **);

struct fstrm_queue *
fstrm_io_get_queue(struct fstrm_io *);

int
fstrm_io_submit(struct fstrm_io *, struct fstrm_queue *,
		void *buf, size_t len,
		void (*free_func)(void *buf, void *free_data),
		void *free_data);

/* fstrm_io_options */

struct fstrm_io_options *
fstrm_io_options_init(void);

void
fstrm_io_options_destroy(struct fstrm_io_options **);

void
fstrm_io_options_set_buffer_hint(
	struct fstrm_io_options *,
	unsigned buffer_hint);

void
fstrm_io_options_set_content_type(
	struct fstrm_io_options *,
	const void *buf, size_t len);

void
fstrm_io_options_set_flush_timeout(
	struct fstrm_io_options *,
	unsigned flush_timeout);

void
fstrm_io_options_set_iovec_size(
	struct fstrm_io_options *,
	unsigned iovec_size);

void
fstrm_io_options_set_num_queues(
	struct fstrm_io_options *,
	unsigned num_queues);

void
fstrm_io_options_set_queue_length(
	struct fstrm_io_options *,
	unsigned queue_length);

void
fstrm_io_options_set_queue_notify_threshold(
	struct fstrm_io_options *,
	unsigned queue_notify_threshold);

void
fstrm_io_options_set_reconnect_interval(
	struct fstrm_io_options *,
	unsigned reconnect_interval);

void
fstrm_io_options_set_writer(
	struct fstrm_io_options *,
	const struct fstrm_writer *,
	const void *writer_options);

/* fstrm_unix_writer, fstrm_unix_writer_options */

extern const struct fstrm_writer *fstrm_unix_writer;

struct fstrm_unix_writer_options *
fstrm_unix_writer_options_init(void);

void
fstrm_unix_writer_options_destroy(
	struct fstrm_unix_writer_options **);

void
fstrm_unix_writer_options_set_socket_path(
	struct fstrm_unix_writer_options *,
	const char *socket_path);

#ifdef __cplusplus
}
#endif

#endif /* FSTRM_H */
