/* vim: set tabstop=4:softtabstop=4:shiftwidth=4:ffs=unix */
#ifndef __MPC_PIPE_H__
#define __MPC_PIPE_H__

#include <mpc_common.h>

/*
 * PIPE function to create and destory
 */
int mpc_pipe_init(void);
int mpc_pipe_exit(void);

/*
 * When writing or reading through KEY_TO_TIMER pipe,
 * have to use that wrapper APIs
 */
int mpc_pipe_key_to_timer_write(char *wdata);
int mpc_pipe_key_to_timer_read(char *rdata);

/*
 * When writing or reading through KEY_TO_DB pipe,
 * have to use that wrapper APIs
 */
int mpc_pipe_key_to_db_write(char *wdata);
int mpc_pipe_key_to_db_read(char *rdata);

/*
 * When writing or reading through TIMER_TO_DB pipe,
 * have to use that wrapper APIs
 */
int mpc_pipe_timer_to_db_write(char *wdata);
int mpc_pipe_timer_to_db_read(char *rdata);

#endif /* __MPC_PIPE_H__ */
