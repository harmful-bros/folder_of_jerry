#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define KEY_VALUE		(key_t)1524
#define MAX_BUF			4096

#define TEST_NUM		1000000ULL

int
main(void)
{
	int shm_id = shmget(KEY_VALUE, MAX_BUF, IPC_CREAT | 0666);
	if (shm_id < 0)
	{
		printf("Failed to create shared memory.\n");
		return -errno;
	}

	int ret = -1;
	void *shm_addr = shmat(shm_id, NULL, 0);
	if (shm_addr == (void *)-1)
	{
		printf("Failed to attached to the virtual address.\n");
		goto escape;
	}

	unsigned long long i;
	for (i = 0; i < TEST_NUM; i++)
	{
		snprintf(shm_addr, MAX_BUF, "%d", getpid());
		getpid() == atoi((char*)shm_addr) ? printf("O") : printf("X");
	}
	printf("\n");

	ret = shmdt(shm_addr);
	if (ret < 0)
	{
		printf("Failed to detach from the virtual address.\n");
		return -errno;
	}

escape:
	ret = shmctl(shm_id, IPC_RMID, NULL);
	if (ret < 0)
	{
		printf("Failed to destory shared memory.\n");
		return -errno;
	}
	return 0;
}
