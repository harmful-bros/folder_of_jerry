#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

static void my_exit1(void)
{
	printf("%s\n", __func__);
}

static void my_exit2(void)
{
	printf("%s\n", __func__);
}

int main(void)
{
	int ret = atexit(my_exit1);
	if (ret < 0)
	{
		printf("Failed to register exit function.\n");
		return errno;
	}

	ret = atexit(my_exit2);
	if (ret < 0)
	{
		printf("Failed to register exit function.\n");
		return errno;
	}

	printf("Done\n");

	return 0;
}
