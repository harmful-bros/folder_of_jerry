#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

typedef struct cpu_stat cpu_stat_t;
typedef struct cpu_usage cpu_usage_t;

struct cpu_stat
{
	uint64_t user;
	uint64_t nice;
	uint64_t system;
	uint64_t idle;
	uint64_t iowait;
	uint64_t irq;
	uint64_t softirq;
};

struct cpu_usage
{
	uint8_t num;
	double ratio;
	cpu_stat_t *stat;
};

static int
_get_cpu_usage(cpu_usage_t *usage)
{
	FILE *file = fopen("/proc/stat", "r");
	if (file == NULL)
	{
		printf("Failed to topen the /proc/stat\n");
		return -EPERM;
	}

	cpu_stat_t *st = usage->stat;

	int num;
	char buf[128] = {0, };
	while (fgets(buf, sizeof(buf), file))
	{
		buf[strlen(buf) - 1] = '\0';
		if (strstr(buf, "cpu"))
		{
			sscanf(buf, "cpu%d", &num);
			if (num < usage->num)
			{
//				printf("%s\n", buf);
				sscanf(buf, "cpu%d %lu %lu %lu %lu %lu %lu %lu",
						&num,
						&st[num].user,
						&st[num].nice,
						&st[num].system,
						&st[num].idle,
						&st[num].iowait,
						&st[num].irq,
						&st[num].softirq);
			}
		}
	}

#if 0
	int i;
	printf("\n");
	for (i = 0; i < usage->num; i++)
	{
		printf("cpu%d %lu %lu %lu %lu\n",
				i,
				st[i].user,
				st[i].nice,
				st[i].system,
				st[i].idle);
	}
#endif

	fclose(file);
	return 0;
}

int
main(void)
{
	cpu_usage_t pre_usage, cur_usage;
	memset(&pre_usage, 0x0, sizeof(cpu_usage_t));
	memset(&cur_usage, 0x0, sizeof(cpu_usage_t));

	pre_usage.num = sysconf(_SC_NPROCESSORS_CONF);
	if (pre_usage.num <= 0)
	{
		printf("Failed to get the processor number.\n");
		return -EPERM;
	}
	cur_usage.num = pre_usage.num;

	pre_usage.stat = calloc(1, sizeof(cpu_stat_t) * pre_usage.num);
	cur_usage.stat = calloc(1, sizeof(cpu_stat_t) * cur_usage.num);

	int i;
	double use;
	double idle;
	double ratio;

	_get_cpu_usage(&pre_usage);

	while (1)
	{
		printf("\n");
		usleep(1000000);
		_get_cpu_usage(&cur_usage);

		for (i = 0; i < cur_usage.num; i++)
		{
			use = (cur_usage.stat[i].user - pre_usage.stat[i].user) +
				(cur_usage.stat[i].nice - pre_usage.stat[i].nice) +
				(cur_usage.stat[i].system - pre_usage.stat[i].system) +
				(cur_usage.stat[i].iowait - pre_usage.stat[i].iowait) +
				(cur_usage.stat[i].irq - pre_usage.stat[i].irq) +
				(cur_usage.stat[i].softirq - pre_usage.stat[i].softirq);
			idle = (cur_usage.stat[i].idle - pre_usage.stat[i].idle);
			ratio = use * 100.0 / (use + idle);

			printf("CPU %d : %.2lf %.2lf %.2lf\n", i, use, idle, ratio);
			pre_usage.stat[i] = cur_usage.stat[i];
		}
	}

	free(pre_usage.stat);
	free(cur_usage.stat);
	return 0;
}
