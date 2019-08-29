#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/wait.h>

int
main(void)
{
	int fd = fork();
	if (fd < 0)
	{
		printf("Failed to create new process.\n");
		return -EPERM;
	}

	if (fd == 0)
	{
		printf("Child\n");
		exit(1);
	}
	else
	{
		printf("Parent\n");
		wait(NULL);
	}

	printf("Done\n");

	return 0;
}
