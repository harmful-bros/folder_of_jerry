#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/sem.h>

#define KEY_VALUE		(key_t)1524
#define MAX_BUF			4096

#define TEST_NUM		500ULL

#define CAL_SEMA_P		(-1)
#define CAL_SEMA_V		1

#define SEMAPHORE_COUNT	1

static inline int _calculate_semaphore(int sem_id, int cal);

static inline int
_calculate_semaphore(int sem_id, int cal)
{
	struct sembuf buf = {
		.sem_num = 0,
		.sem_op = cal,
		.sem_flg = SEM_UNDO
	};

	int ret = semop(sem_id, &buf, 1);
	if (ret < 0)
	{
		printf("Failed to set configuration for semaphore.\n");
		return -errno;
	}

	return 0;
}

int
main(void)
{
	/* create shared memory */
	int shm_id = shmget(KEY_VALUE, MAX_BUF, IPC_CREAT | 0666);
	if (shm_id < 0)
	{
		printf("Failed to create shared memory.\n");
		return -errno;
	}

	/* attaching shared memory */
	int ret = -1;
	void *shm_addr = shmat(shm_id, NULL, 0);
	if (shm_addr == (void *)-1)
	{
		printf("Failed to attached to the virtual address.\n");
		goto escape;
	}

	/* create semaphore */
	int sem_id = semget(KEY_VALUE, SEMAPHORE_COUNT, IPC_CREAT | 0666);
	if (sem_id < 0)
	{
		printf("Failed to create semaphore. %d\n", -errno);
		goto escape;
	}

	/* set semaphore */
	union semun {
		int              val;    /* Value for SETVAL */
		struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
		unsigned short  *array;  /* Array for GETALL, SETALL */
		struct seminfo  *__buf;  /* Buffer for IPC_INFO
									(Linux-specific) */
	}sem_conf;

	sem_conf.val = 1;
	ret = semctl(sem_id, 0, SETVAL, sem_conf);
	if (ret < 0)
	{
		printf("Failed to set semaphore. %d\n", -errno);
		goto escape;
	}

	unsigned long long i;
	for (i = 0; i < TEST_NUM; i++)
	{
		_calculate_semaphore(sem_id, CAL_SEMA_P);	
		snprintf(shm_addr, MAX_BUF, "%d", getpid());
		int j;
		for (j = 0; j < 5000000; j++);
		getpid() == atoi((char*)shm_addr) ? printf("O") : printf("X");
		_calculate_semaphore(sem_id, CAL_SEMA_V);
		usleep(1000);
	}
	printf("\n");

	ret = shmdt(shm_addr);
	if (ret < 0)
	{
		printf("Failed to detach from the virtual address.\n");
		return -errno;
	}

escape:
	ret = semctl(sem_id, 0, IPC_RMID);
	if (ret < 0)
		printf("Failed to destory semaphore. %d\n", -errno);

	ret = shmctl(shm_id, IPC_RMID, NULL);
	if (ret < 0)
	{
		printf("Failed to destory shared memory.\n");
		return -errno;
	}
	return 0;
}
