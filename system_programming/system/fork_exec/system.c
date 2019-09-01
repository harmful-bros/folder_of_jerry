#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <errno.h>

static int
_set_environment_variable(void)
{
	const char *set_env = 
		"/bin:/sbin:/usr/bin:/usr/local/bin:/usr/local/sbin:/usr/sbin";

	char buf[512] = {0, };
	char *env = getenv("PATH");
	if (env == NULL)
		snprintf(buf, sizeof(buf), "%s", set_env);
	else
		snprintf(buf, sizeof(buf), "%s:%s", env, set_env);

	int ret = setenv("PATH", buf, 1);
	if (ret < 0)
	{
		printf("Failed to set environment variables.\n");
		return errno;
	}

	return 0;
}

static int
_cmd_write(const char *cmd)
{
	if (cmd == NULL)
	{
		printf("Invalid parameters.\n");
		return -EPERM;
	}

	int ret;
	pid_t pid = fork();
	if (pid < 0)
	{
		printf("Failed to execute fork.");
		return pid;
	}

	if (pid == 0)
	{
		/* child */
		ret = execlp("sh", "sh", "-c", cmd, NULL);
		if (ret < 0)
		{
			printf("Failed to call exec.\n");
			return -errno;
		}

		return 0;
	}
	else
	{
		/* parent */
		int status;
		waitpid(pid, &status, 0);
		if (WEXITSTATUS(status) < 0)
		{
			/* error state */
		}
	}

	return 0;
}

int
main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Invalid parameters.\n");
		goto escape;
	}

	int ret = _set_environment_variable();
	if (ret < 0)
		goto escape;

	ret = _cmd_write(argv[1]);
	if (ret < 0)
		goto escape;

	return 0;

escape:
	return -EPERM;
}
