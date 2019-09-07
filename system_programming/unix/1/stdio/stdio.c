#include <stdio.h>
#include <errno.h>

#if 0
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUF_SIZE		4096

int main(
		void)
{
	int n;
	char buf[BUF_SIZE];

	while ((n = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
	{
		if (write(STDOUT_FILENO, buf, n) != n)
		{
			printf("Failed to write to stdout.\n");
			return -EPERM;
		}
	}

	if (n < 0)
	{
		printf("Failed to read from stdin\n");
		return -EPERM;
	}

	return 0;
}
#else
int main(
		void)
{
	int c;

	while ((c = getc(stdin)) != EOF)
	{
		if (putc(c, stdout) == EOF)
		{
			printf("Failed to write to stdout.\n");
			return -EPERM;
		}
	}

	if (ferror(stdin))
	{
		printf("Failed to read from stdin\n");
		return -EPERM;
	}

	return 0;
}
#endif
