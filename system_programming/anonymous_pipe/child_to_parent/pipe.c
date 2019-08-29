#include <stdio.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUF		(4096 << 4)
#define TEST_CNT	1000

int
main(void)
{
	int fd[4] = {-1, -1};
	int ret;

	ret = pipe(fd);
	if (ret < 0)
	{
		printf("Failed to create pipe.\n");
		return -errno;
	}

	int i;
	int len;
	char msg[MAX_BUF];

	pid_t pid = fork();
	if (pid < 0)
	{
		printf("Failed to create process.\n");
		goto escape;
	}

	if (pid == 0)
	{
		printf("Child !!\n");

		/* close the stdin */
		close(fd[0]);
		fd[0] = -1;

		/* to parent */
		for (i = 0; i < TEST_CNT; i++)
		{
			len = snprintf(msg, sizeof(msg), "This is pipe test. %d\n", i);
			write(fd[1], msg, len);
		}
	}
	else
	{
		printf("Parent !!\n");

		/* close the stdout */
		close(fd[1]);
		fd[1] = -1;
	
		/* wait until child die */
		ret = waitpid(pid, NULL, 0);
		if (ret < 0)
		{
			printf("Failed to wait the child process.\n");
			goto escape;
		}

		/* from child */
		read(fd[0], msg, MAX_BUF);
		printf("%s", msg);
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
