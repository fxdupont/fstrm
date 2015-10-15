#ifndef MY_COMPAT_H
#define MY_COMPAT_H

#ifndef HAVE_CLOCK_GETTIME

#include <stdint.h>

typedef int32_t clockid_t;

#define CLOCK_REALTIME	0
#define CLOCK_MONOTONIC	4

int clock_gettime(clockid_t, struct timespec *);

#endif

#endif /* MY_COMPAT_H */
