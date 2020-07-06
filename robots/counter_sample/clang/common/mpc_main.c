#include <signal.h>

#include <mpc_common.h>
#include <mpc_main.h>
#include <mpc_pipe.h>

static void _mpc_ctrl_c(int signo);

static int _mpc_main_init(void);
static int _mpc_main_exit(void);

static int g_escape_flag = 1;

static void
_mpc_ctrl_c(int signo)
{
	(void)signo;

	ERR_MSG("Input the \"Ctrl+C\".");
	g_escape_flag = 0;
}

static int
_mpc_main_init(void)
{
	int ret = mpc_pipe_init();
	if (ret < 0)
		return -EPERM;

	/* TODO: Write '*_init' functions here */

	return 0;
}

static int
_mpc_main_exit(void)
{
	mpc_pipe_exit();

	/* TODO: Write '*_exit' functions here */

	return 0;
}

int
main(void)
{
	struct sigaction sig_act = {
		.sa_handler = _mpc_ctrl_c,
		.sa_flags = 0,
	};
	sigemptyset(&sig_act.sa_mask);
	sigaction(SIGINT, &sig_act, NULL);

	int ret = _mpc_main_init();
	if (ret < 0)
		goto error;

	while (g_escape_flag)
	{
		sleep(1);
	}

	ret = _mpc_main_exit();
	if (ret < 0)
		goto error;

	return 0;

error :
	return -EPERM;
}
