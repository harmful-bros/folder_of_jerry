#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#define MAX_BUF		((1024) << 7)

int main(void)
{
//	int fd = open("../pipe", O_WRONLY);
	int fd = open("../pipe", O_RDWR);
	if (fd < 0)
	{
		printf("Failed to open the pipe.\n");
		return -1;
	}

	int len;
	char buf[MAX_BUF];	

	int i;
	for (i = 0; i < MAX_BUF; i++)
		buf[i] = 'a';

	write(fd, buf, MAX_BUF);

	close(fd);

	return 0;
}


#if 0
	while (1)
	{
		printf("pipe_1 : ");
		fgets(buf, sizeof(buf), stdin);

		if (strstr(buf, "quit"))
			break;

		len = strlen(buf);
		write(fd, buf, len);
	}
#endif
