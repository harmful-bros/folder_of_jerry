#include <stdio.h>

int
main(void)
{
	FILE *file = popen("./script.sh", "r");
	if (file == NULL)
	{
		printf("Failed to execute the commands.\n");
		return -1;
	}

	char buf[512];
	while (fgets(buf, sizeof(buf), file))
	{
		printf("%s", buf);
	}

	pclose(file);

	return 0;
}
