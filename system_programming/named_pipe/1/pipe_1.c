#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#define MAX_BUF		1024

int main(void)
{
	int fd = open("../pipe", O_WRONLY);
	if (fd < 0)
	{
		printf("Failed to open the pipe.\n");
		return -1;
	}

	int len;
	char buf[MAX_BUF];	

	while (1)
	{
		printf("pipe_1 : ");
		fgets(buf, sizeof(buf), stdin);

		if (strstr(buf, "quit"))
			break;

		len = strlen(buf);
		write(fd, buf, len);
	}

	close(fd);

	return 0;
}
