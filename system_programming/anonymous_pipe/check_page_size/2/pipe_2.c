#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#define MAX_BUF		((1024 * 1024) << 2)

int main(void)
{
//	int fd = open("../pipe", O_RDONLY);
	int fd = open("../pipe", O_RDWR);
	if (fd < 0)
	{
		printf("Failed to open the pipe.\n");
		return -1;
	}

	pause();

#if 0
	while (1)
	{
		sleep(1);
	}
#endif

	int len;
	char buf[MAX_BUF];	

	printf("Read Pipe!!\n");
	len = read(fd, buf, MAX_BUF);

//	while ((len = read(fd, buf, MAX_BUF)) > 0)
	{
		buf[len] = '\0';
		printf("pipe_2 : %d\n", len);
	}

	close(fd);

	return 0;
}
