#include <stdio.h>
#include <errno.h>

#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	const char buf1[] = "abcdefghij";
	const char buf2[] = "ABCDEFGHIJ";

	int fd = creat("file.hole", FILESEC_MODE);
	if (fd < 0)
	{
		printf("Failed to create file.\n");
		return errno;
	}

	size_t size = sizeof(buf1);
	int ret = write(fd, buf1, size);
	if (ret != (int)size)
	{
		printf("Failed to write data.\n");
		return errno;
	}
	
	/* Now, offset value is 10 */

	ret = lseek(fd, 16384, SEEK_SET);
	if (ret < 0)
	{
		printf("Failed to seek file offset.\n");
		return errno;
	}

	/* Now, offset value is 16384 */

	ret = write(fd, buf2, size);
	if (ret != (int)size)
	{
		printf("Failed to write data.\n");
		return errno;
	}

	/* Now, offset value is 16394 */

	return 0;
}
