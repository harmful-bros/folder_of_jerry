#include <stdio.h>
#include <errno.h>

#include <fcntl.h>
#include <sys/stat.h>

int main(
		void)
{
	struct stat stat_buf;

	int ret = stat("foo", &stat_buf);
	if (ret < 0)
	{
		printf("Failed to get information from foo\n");
		return -errno;
	}

	ret = chmod("foo", (stat_buf.st_mode & ~S_IXUSR) | S_ISGID);
	if (ret < 0)
	{
		printf("Failed to change mode.\n");
		return -errno;
	}

	ret = chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (ret < 0)
	{
		printf("Failed to change mode.\n");
		return -errno;
	}

	return 0;
}
