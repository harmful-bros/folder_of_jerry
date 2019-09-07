#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>

#define RWRWRW		(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void)
{
	umask(0);
	int ret = creat("foo", RWRWRW);
	if (ret < 0)
	{
		printf("Failed to create file.\n");
		return errno;
	}

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	ret = creat("boo", RWRWRW);
	if (ret < 0)
	{
		printf("Failed to create file.\n");
		return errno;
	}

	return 0;
}
