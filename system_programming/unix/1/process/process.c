#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SIZE		4096

int main(void)
{
	char buf[BUF_SIZE];
	pid_t pid;
	int status;

	printf("%% ");

	while (fgets(buf, sizeof(buf), stdin))
	{
		buf[strlen(buf) - 1] = '\0';

		if ((pid = fork()) < 0)
		{
			printf("Failed to fork.\n");
			return -EPERM;
		}
		else if (pid == 0)
		{
			execlp(buf, buf, NULL);
			printf("Couldn't execute. %s\n", buf);
			return -EPERM;
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
