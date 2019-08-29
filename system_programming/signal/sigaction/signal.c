#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <errno.h>
#include <signal.h>

static void _signal_handler(int sig_num)
{
	(void) sig_num;
	printf("Sigint!!\n");
}

int main(void)
{
	struct sigaction sigact;
	memset(&sigact, 0x00, sizeof(struct sigaction));

	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigact.sa_handler = _signal_handler;

	int ret = sigaction(SIGINT, &sigact, NULL);
	if (ret < 0)
	{
		printf("Failed to create signal handler.\n");
		return -EPERM;
	}

	while (1)
	{
		usleep(1000);
	}

	return 0;
}
