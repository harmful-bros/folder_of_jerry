#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <sys/wait.h>

static void sig_int(int sig_no)
{
	(void)sig_no;

	printf("interrupt\n");
}

int main(void)
{
	if (signal(SIGINT, sig_int) == SIG_ERR)
	{
		printf("Failed to register signal method.\n");
		return -EPERM;
	}

	pid_t pid;
	int ret;
	int status;
	char buf[1024];

	printf("%% ");
	while (fgets(buf, sizeof(buf), stdin))
	{
		buf[strlen(buf) - 1] = '\0';
		
		if ((pid = fork()) < 0)
		{
			printf("Failed to fork child process.\n");
			return -EPERM;
		}
		else if (pid == 0)
		{
			ret = execlp(buf, buf, NULL);
			if (ret < 0)
			{
				printf("Failed to exchange another process.\n");
				return -EPERM;
			}
		}

		pid = waitpid(pid, &status, 0);
		if (pid < 0)
		{
			printf("Failed to wait child process.\n");
			return -EPERM;
		}

		printf("%% ");
	}

	return 0;
}
