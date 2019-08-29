#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <pthread.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void *_thread_handler(void *arg);

static int count = 0;
static pthread_mutex_t g_sync_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t g_sync_cond = PTHREAD_COND_INITIALIZER;

const char *str_table[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

static void *
_thread_handler(void *arg)
{
	(void) arg;

	pthread_mutex_lock(&g_sync_mutex);

	/* init variables */
	int fd;
	int ret;
	int cnt = 100;
	const char *pstr = str_table[count++ % 10];
	struct flock file_lock;
	memset(&file_lock, 0x00, sizeof(struct flock));

	/* set variables */
	file_lock.l_type = F_WRLCK;
	file_lock.l_whence = SEEK_SET;

	usleep(50000);

	pthread_cond_signal(&g_sync_cond);
	pthread_mutex_unlock(&g_sync_mutex);

	fd = open("file.txt", O_CREAT | O_RDWR | O_SYNC | O_APPEND, 0666);
	if (fd < 0)
	{
		printf("Failed to open file.\n");
		return NULL;
	}

	ret = fcntl(fd, F_SETLKW, &file_lock);
	if (ret < 0)
	{
		printf("Failed to lock the file.\n");
		goto escape;
	}

	while (cnt--)
		write(fd, pstr, strlen(pstr));

escape:
	close(fd);
	return NULL;
}

int
main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Forget parameters,,\n");
		return -EPERM;
	}

	int thread_num = strtoul(argv[1], NULL, 10);
	if (thread_num <= 0)
	{
		printf("Invalid parameters,,\n");
		return -EPERM;
	}

	pthread_t *thread = malloc(sizeof(pthread_t) * thread_num);
	if (thread == NULL)
	{
		printf("Failed to allocate the memory for pthread.\n");
		return -EPERM;
	}

	int i;
	int ret = -1;
	for (i = 0; i < thread_num; i++)
	{
		pthread_mutex_lock(&g_sync_mutex);
		ret = pthread_create(&thread[i], NULL, _thread_handler, &i);
		if (ret < 0)
		{
			pthread_mutex_unlock(&g_sync_mutex);
			printf("Failed to create pthread.\n");
			goto escape;
		}

		pthread_cond_wait(&g_sync_cond, &g_sync_mutex);
		pthread_mutex_unlock(&g_sync_mutex);
	}

	for (i = 0; i < thread_num; i++)
	{
		pthread_join(thread[i], NULL);
	}

escape:
	free(thread);
	return 0;
}
