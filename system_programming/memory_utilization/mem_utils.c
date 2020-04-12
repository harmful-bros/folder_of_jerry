#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>

typedef struct memory_stat mem_stat_t;

struct memory_stat
{
	uint64_t total;
	uint64_t free;
};

static int
_get_memory_usage(mem_stat_t *mem)
{
	FILE *file = fopen("/proc/meminfo", "r");
	if (file == NULL)
	{
		printf("Failed to open the /proc/meminfo.\n");
		return -EPERM;
	}

	char buf[128] = {0, };
	while (fgets(buf, sizeof(buf), file))
	{
		buf[strlen(buf) - 1] = '\0';
		printf("%s\n", buf);
		if (strstr(buf, "MemTotal"))
			sscanf(buf, "MemTotal: %lu kB", &mem->total);
		else if (strstr(buf, "MemFree"))
		{
			sscanf(buf, "MemFree: %lu kB", &mem->free);
			break;
		}
	}

	fclose(file);
	return 0;
}

int main(void)
{
	mem_stat_t mem;
	memset(&mem, 0x0, sizeof(mem_stat_t));

	while (1)
	{
		_get_memory_usage(&mem);
		printf("%lu %lu %.2lf\n",
				mem.total,
				mem.free,
				(double)mem.free * 100.0 / (double)mem.total);
		sleep(1);
	}

	return 0;
}
