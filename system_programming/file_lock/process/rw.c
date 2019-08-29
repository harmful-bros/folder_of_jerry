#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Invaild parameters.\n");
		return -EPERM;
	}

	char buf[512];
	int len = snprintf(buf, sizeof(buf), "%s\n", argv[1]);

	int fd = open("file.txt", O_CREAT | O_RDWR | O_SYNC | O_APPEND, 0666);
	if (fd < 0)
	{
		printf("Failed to create file.txt\n");
		return -EPERM;
	}

	struct flock file_lock;
	memset(&file_lock, 0x00, sizeof(struct flock));

	/* set variables */
	file_lock.l_type = F_WRLCK;
	file_lock.l_whence = SEEK_SET;

	fcntl(fd, F_SETLKW, &file_lock);

	int i;
	for (i = 0; i < 1000; i++)
		write(fd, buf, len);

	close(fd);

	return 0;
}
