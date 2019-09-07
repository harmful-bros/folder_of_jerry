#include <stdio.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(
		int argc,
		char *argv[])
{
	if (argc != 2)
	{
		printf("Parameters error.\n");
		return -EINVAL;
	}

	int ret = access(argv[1], R_OK);
	if (ret < 0)
	{
		printf("Failed to get accessing information from %s\n", argv[1]);
		return errno;
	}

	printf("read access OK.\n");

	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Failed to open the file %s\n", argv[1]);
		return errno;
	}

	printf("open for reading OK\n");

	close(fd);

	return 0;
}
