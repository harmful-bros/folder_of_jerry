#include <stdio.h>
#include <errno.h>

#include <sys/stat.h>

int main(
		int argc,
		char *argv[])
{
	if (argc < 2)
	{
		printf("Forget parameters!!.\n");
		return -EINVAL;
	}

	int i;
	int ret;
	char *ptr;
	struct stat buf;

	for (i = 1; i < argc; i++)
	{
		printf("%s: ", argv[i]);
		
		ret = lstat(argv[i], &buf);
		if (ret < 0)
		{
			printf("Failed to get stat from %s\n", argv[i]);
			continue;
		}
		
		if (S_ISREG(buf.st_mode))
			ptr = "regular";
		else if (S_ISDIR(buf.st_mode))
			ptr = "directory";
		else if (S_ISCHR(buf.st_mode))
			ptr = "character special";
		else if (S_ISBLK(buf.st_mode))
			ptr = "block special";
		else if (S_ISFIFO(buf.st_mode))
			ptr = "fifo";
		else if (S_ISLNK(buf.st_mode))
			ptr = "symbolic link";
		else if (S_ISSOCK(buf.st_mode))
			ptr = "socket";
		else
			ptr = "unknown mode,,";

		printf("%s\n", ptr);	
	}

	return 0;
}
