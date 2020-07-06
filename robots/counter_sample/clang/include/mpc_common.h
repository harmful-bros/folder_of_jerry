/* vim: set tabstop=4:softtabstop=4:shiftwidth=4:ffs=unix */
#ifndef __MPC_COMMON_H__
#define __MPC_COMMON_H__

#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUF 128

#define ERR_MSG(fmt, ...)                                                      \
    do                                                                         \
    {                                                                          \
        fprintf(stderr, "[err] " fmt " / func : %s, line : %d\n",              \
                ##__VA_ARGS__, __func__, __LINE__);                            \
    } while (0)

#define unlikely(x) __builtin_expect(!!(x), 0)

typedef struct sync sync_t;

struct sync
{
    pthread_cond_t cv;
    pthread_mutex_t lock;
};

#endif /* __MPC_COMMON_H__ */
