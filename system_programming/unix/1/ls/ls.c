#include <stdio.h>
#include <errno.h>

#include <dirent.h>

int main(
		int argc,
		char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if (argc != 2)
	{
		printf("usage: ls directory_name\n");
		return -EINVAL;
	}

	dp = opendir(argv[1]);
	if (dp == NULL)
	{
		printf("Failed to open directory %s\n", argv[1]);
		return -ENOENT;
	}

	while ((dirp = readdir(dp)))
		printf("%s\n", dirp->d_name);

	closedir(dp);

	return 0;
}
