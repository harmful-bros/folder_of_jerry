#include <stdio.h>

#include <errno.h>
#include <unistd.h>
#include <signal.h>

static void _handler(int signo);

static void _handler(int signo)
{
	(void) signo;

	printf("[Sinal] Call the handler\n");
}

int main(void)
{
	__sighandler_t ret = signal(SIGINT, _handler);
//	__sighandler_t ret = signal(SIGINT, SIG_DFL);
//	__sighandler_t ret = signal(SIGSEGV, SIG_IGN);
	if (ret == SIG_ERR)
	{
		printf("Failed to set handler of the signal.\n");
		return -errno;
	}

	int *ptr;
	while (1)
	{
		printf("Signal Test\n");
		sleep(2);
		ptr = (int *)1524831;
		printf("%d\n", *ptr);
	}

	return 0;
}

