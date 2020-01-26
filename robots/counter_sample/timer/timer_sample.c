#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>

#ifndef unlikely
#define unlikely(x)			__builtin_expect((x), 0)
#endif

typedef struct timer_information timer_info_t;

struct timer_information
{
	uint8_t index;

	timer_t id;
	void (*handler)(int sig, siginfo_t *info, void *ucontext);
};

static void _timer_five_min(int sig, siginfo_t *info, void *ucontext);
static void _timer_counter(int sig, siginfo_t *info, void *ucontext);
static int _timer_create(timer_info_t *timer, int sec, int msec);

static void
_timer_five_min(int sig, siginfo_t *info, void *ucontext)
{
	(void) sig;
	(void) ucontext;

	if (unlikely(info == NULL) || unlikely(info->si_value.sival_ptr == NULL))
	{
		printf("[-] Invalid parameters. %s\n", __func__);
		return;
	}

//	timer_t *id = (void **)info->si_value.sival_ptr;

	static int min = 5;
	static int sec = 0;

	/* TODO: key interrupt */

	/* 5 min timer */
	sec--;
	if (sec < 0)
	{
		sec = 59;
		min--;
	}

	if (min < 0)
		return;

	printf("%02d:%02d\n", min, sec);
}

static void
_timer_counter(int sig, siginfo_t *info, void *ucontext)
{
	(void) sig;
	(void) ucontext;

	if (unlikely(info == NULL) || unlikely(info->si_value.sival_ptr == NULL))
	{
		printf("[-] Invalid parameters. %s\n", __func__);
		return;
	}

//	timer_t *id = (void **)info->si_value.sival_ptr;

	static int msec = 0;
	static int sec = 0;
	static int min = 0;

	/* TODO:
	 * key interrupt
	 * sensor interrupt
	 */

	msec++;
	if (msec > 999)
	{
		msec = 0;
		sec++;
	}

	if (sec > 59)
	{
		sec = 0;
		min++;
	}

	printf("\t\t\t %02d:%02d:%03d\n", min, sec, msec);
}

static
int _timer_create(timer_info_t *timer, int sec, int msec)
{
	if (unlikely(timer == NULL) || unlikely(sec < 0) || unlikely(msec < 0))
	{
		printf("[-] Invalid parameters. %s\n", __func__);
		return -EPERM;
	}

	if (SIGRTMIN + timer->index > SIGRTMAX)
	{
		printf("[-] Overflow the signal number!!\n");
		return -EPERM;
	}

	/* init the signal */
	struct sigaction sig_act =
	{
		.sa_flags = SA_SIGINFO,
		.sa_sigaction = timer->handler
	};
	sigemptyset(&sig_act.sa_mask);

	int ret = sigaction(SIGRTMIN + timer->index, &sig_act, NULL);
	if (ret < 0)
	{
		printf("[-] Failed to set the sigaction struct.\n");
		return -errno;
	}

	/* create the timer */
	struct sigevent sig_event =
	{
		.sigev_notify = SIGEV_SIGNAL,
		.sigev_signo = SIGRTMIN + timer->index,
		.sigev_value.sival_ptr = &timer->id
	};

	ret = timer_create(CLOCK_REALTIME, &sig_event, &timer->id);
	if (ret < 0)
	{
		printf("[-] Failed to create the timer.\n");
		return -errno;
	}

	/* set the timer */
	struct itimerspec it_spec =
	{
		.it_interval.tv_sec = sec,
		.it_interval.tv_nsec = msec * 1000000,
		.it_value.tv_sec = sec,
		.it_value.tv_nsec = msec * 1000000,
	};

	ret = timer_settime(timer->id, 0, &it_spec, NULL);
	if (ret < 0)
	{
		printf("[-] Failed to set the timer.\n");
		return -errno;
	}

	return 0;
}

int
main(void)
{
	/*
	 * not nessary the timer_t id variable
	 * it make by pthread information such as cv, lock, pthread_t..
	 */

	timer_info_t maze_timer[2] =
	{
		{
			.index = 0,
			.handler = _timer_five_min
		},
		{
			.index = 1,
			.handler = _timer_counter
		}
	};

	/* create the 1sec timer */
	int ret = _timer_create(&maze_timer[0], 1, 0);
	if (ret < 0)
		return ret;

	/* create the 1msec timer */
	ret = _timer_create(&maze_timer[1], 0, 1);
	if (ret < 0)
		return ret;

	while (1)
	{
		sleep(1);
//		printf("Main!\n");
	}

	return 0;
}
