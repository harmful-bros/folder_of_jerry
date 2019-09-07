#include <stdio.h>
#include <string.h>

#include <errno.h>
#include <unistd.h>
#include <dirent.h>

#include <sys/types.h>

#define unlikely(x)		__builtin_expect((x), 0)

#define USER_INFO		"/etc/passwd"

static int handle_directory(const char *path);

static int handle_user_information(
		void)
{
	return 0;
}

static int handle_directory(
		const char *path)
{
	if (unlikely(path == NULL))
	{
		printf("Invalid parameters.\n");
		return -EINVAL;
	}

	DIR *dir = opendir(path);
	if (dir == NULL)
	{
		printf("Failed to open directory %s\n", path);
		return -errno;
	}

	struct dirent *dirent;
	while ((dirent = readdir(dir)))
	{
		if (!strcmp(dirent->d_name, ".") || !strcmp(dirent->d_name, ".."))
			continue;

		printf("%s\n", dirent->d_name);
	}

	closedir(dir);
	return 0;
}

int main(
		int argc,
		char *argv[])
{
	if (argc != 2)
	{
		printf("Invalid parameters.\n");
		return -EINVAL;
	}

	int ret = access(argv[1], F_OK);
	if (ret < 0)
	{
		printf("Failed to access %s\n", argv[1]);
		return -errno;
	}

	ret = handle_directory(argv[1]);
	if (ret < 0)
		return -EPERM;

	return 0;
}
