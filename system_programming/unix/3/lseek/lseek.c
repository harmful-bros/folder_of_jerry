#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int ret = lseek(STDIN_FILENO, 0, SEEK_CUR);
	if (ret < 0)
	{
		printf("Can't seek.\n");
		return -1;
	}

	printf("Seek OK!\n");
	return 0;
}
