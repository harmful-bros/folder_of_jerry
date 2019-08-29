#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <sys/select.h>
#include <sys/time.h>

#define MAX_BUF		(4096 << 4)
#define TEST_CNT	1000

typedef struct read_buffer_information
{
	int fd;
	void *buf;
	size_t count;

}rbuf_info_t;

static void _signal_handler(int sig_num);

static int g_fd;

int
main(void)
{
	int fd[4] = {-1, -1};
	int ret;

	/* create pipe */
	ret = pipe(fd);
	if (ret < 0)
	{
		printf("Failed to create pipe.\n");
		return -errno;
	}

	/* create process */
	pid_t pid = fork();
	if (pid < 0)
	{
		printf("Failed to create process.\n");
		goto escape;
	}

	if (pid == 0)
	{
		printf("Child !!\n");

		/* close the stdout */
		close(fd[1]);
		fd[1] = -1;

		/* from parent */
		printf("Wait from parent.\n");
		g_fd = fd[0];

		/* handler set */
		struct sigaction sigact;
		memset(&sigact, 0x00, sizeof(struct sigaction));
		sigemptyset(&sigact.sa_mask);
		sigact.sa_flags = 0;
		sigact.sa_handler = _signal_handler;

		ret = sigaction(SIGUSR1, &sigact, NULL);
		if (ret < 0)
			printf("Failed to create signal handler.\n");

		while (1);
	}
	else
	{
		printf("Parent !!\n");

		/* close the stdin */
		close(fd[0]);
		fd[0] = -1;

		int i;
		int len;
		char msg[MAX_BUF];

		/* to child */
		for (i = 0; i < TEST_CNT; i++)
		{
			len = snprintf(msg, sizeof(msg), "This is pipe test. %d\n", i);
			write(fd[1], msg, len);
		}

		printf("Done to writing to pipe.\n");

		/* done writing and send signal to child */
		ret = kill(pid, SIGUSR1);
		if (ret < 0)
		{
			printf("Failed to send signal. %d\n", -errno);
			goto escape;
		}

		printf("Send the signal to child.\n");

		/* wait until child die */
		ret = waitpid(pid, NULL, 0);
		if (ret < 0)
		{
			printf("Failed to wait the child process.\n");
			goto escape;
		}
	}

escape:
	if (fd[0] != -1)
	{
		printf("close the stdin\n");
		close(fd[0]);
	}

	if (fd[1] != -1)
	{
		printf("close the stdout\n");
		close(fd[1]);
	}

	return 0;
}

static void
_signal_handler(int sig_num)
{
	(void) sig_num;

	char msg[MAX_BUF];
	read(g_fd, msg, MAX_BUF);
	printf("%s\n", msg);

	exit(1);
}
