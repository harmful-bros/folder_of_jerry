#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUF		4096

int main(void)
{
	int fd[2] = {-1, -1};

	int ret = pipe(fd);
	if (ret < 0)
	{
		printf("Failed to create the pipe.\n");
		return -errno;
	}

	fcntl(fd[1], F_SETFL, O_NONBLOCK);

	int i = 0;
	while (write(fd[1], "x", 1) > 0)
		i++;

	if (errno == EAGAIN)
		printf("Size : %d\n", i);
	else
		printf("Failed to write in pipe.\n");

	if (fd[1] != -1)
		close(fd[1]);

	if (fd[0] != -1)
		close(fd[0]);

	return 0;
}
