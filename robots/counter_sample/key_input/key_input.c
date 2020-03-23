#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#ifndef unlikely
#define unlikely(x)			__builtin_expect((x), 0)
#endif

#define PTHREAD_MAX			2
#define BUFFER_MAX			1024

typedef struct sync sync_t;
typedef struct thread_information th_info_t;

struct sync
{
	pthread_cond_t cv;
	pthread_mutex_t lock;

	uint8_t data;
};

struct thread_information
{
	pthread_t *th;
	uint8_t th_num;

	sync_t sync;
};

static th_info_t *_key_input_init(void);
static int _key_input_destory(th_info_t **th_info);

static int _key_input_start_thread(th_info_t *th_info);
static int _key_input_stop_thread(th_info_t *th_info);

static void *_key_input_thread(void *arg);
static void *_key_input_send_thread(void *arg);

static th_info_t *
_key_input_init(void)
{
	th_info_t *th_info = malloc(sizeof(th_info_t));
	if (th_info == NULL)
	{
		printf("[-] Failed to allocate the memory for the th_info_t.\n");
		return NULL;
	}

	th_info->th_num = PTHREAD_MAX;
	th_info->th = malloc(sizeof(pthread_t) * th_info->th_num);
	if (th_info->th == NULL)
	{
		printf("[-] Failed to allocate the memory for the pthread.\n");
		goto error;
	}

	int ret = pthread_cond_init(&th_info->sync.cv, NULL);
	if (ret < 0)
	{
		printf("[-] Failed to init the condition variable.\n");
		goto error;
	}

	ret = pthread_mutex_init(&th_info->sync.lock, NULL);
	if (ret < 0)
	{
		printf("[-] Failed to init the mutex.\n");
		goto error;
	}

	return th_info;

error:
	_key_input_destory(&th_info);
	return NULL;
}

static int
_key_input_destory(th_info_t **th_info)
{
	if (unlikely(th_info == NULL) || unlikely(*th_info == NULL))
	{
		printf("[-] Invalid parameters.\n");
		return -EPERM;
	}

	if ((*th_info)->th)
	{
		free((*th_info)->th);
		(*th_info)->th = NULL;
	}

	if (*th_info)
	{
		free(*th_info);
		*th_info = NULL;
	}

	return 0;
}

static int
_key_input_start_thread(th_info_t *th_info)
{
	if (unlikely(th_info == NULL))
	{
		printf("[-] Invalid parameters.\n");
		return -EPERM;
	}

	void *(*pfunc[PTHREAD_MAX])(void *) = 
	{
		_key_input_thread,
		_key_input_send_thread
	};

	int i;
	int ret;
	for (i = 0; i < th_info->th_num; i++)
	{
		pthread_mutex_lock(&th_info->sync.lock);
		ret = pthread_create(&th_info->th[i], NULL, pfunc[i], &th_info->sync);
		if (ret < 0)
		{
			printf("[-] Failed to create the thread.\n");

			pthread_mutex_unlock(&th_info->sync.lock);
			goto error;
		}
		pthread_cond_wait(&th_info->sync.cv, &th_info->sync.lock);
		pthread_mutex_unlock(&th_info->sync.lock);
	}
	
	return 0;

error :
	return -EPERM;
}

static int
_key_input_stop_thread(th_info_t *th_info)
{
	if (unlikely(th_info == NULL))
	{
		printf("[-] Invalid parameters.\n");
		return -EPERM;
	}

	int i;
	int ret;
	for (i = 0; i < th_info->th_num; i++)
	{
		ret = pthread_join(th_info->th[i], NULL);
		if (ret < 0)
			printf("[-] Failed to destroy the pthread %d.\n", i);
	}

	pthread_cond_destroy(&th_info->sync.cv);
	pthread_mutex_destroy(&th_info->sync.lock);

	return 0;
}

static void *
_key_input_thread(void *arg)
{
	sync_t *sync = (sync_t *)arg;

	pthread_mutex_lock(&sync->lock);
	sync->data = 'a';

	pthread_cond_signal(&sync->cv);
	pthread_mutex_unlock(&sync->lock);

	char buf[BUFFER_MAX] = {0, };
	while (1)
	{
		fgets(buf, sizeof(buf), stdin);
		buf[strlen(buf) - 1] = '\0';

		if (!strcmp(buf, "s"))
		{
			pthread_mutex_lock(&sync->lock);
			sync->data++;
			if (sync->data > 'z')
				sync->data = 'a';

			pthread_cond_signal(&sync->cv);
			pthread_mutex_unlock(&sync->lock);
		}
		else if (!strcmp(buf, "q"))
		{
			/* quit */
			pthread_mutex_lock(&sync->lock);
			sync->data = '@';
			pthread_cond_signal(&sync->cv);
			pthread_mutex_unlock(&sync->lock);
			break;
		}
	}

	return NULL;
}

static void *
_key_input_send_thread(void *arg)
{
	sync_t *sync = (sync_t *)arg;

	pthread_mutex_lock(&sync->lock);
	pthread_cond_signal(&sync->cv);
	pthread_mutex_unlock(&sync->lock);

	while (1)
	{
		pthread_mutex_lock(&sync->lock);
		pthread_cond_wait(&sync->cv, &sync->lock);

		/* quit */
		if (sync->data == '@')
		{
			pthread_mutex_unlock(&sync->lock);
			break;
		}

		printf("get thread : %c\n", sync->data);
		pthread_mutex_unlock(&sync->lock);
	}

	return NULL;
}

int
main(void)
{
	th_info_t *th_info = _key_input_init();
	if (th_info == NULL)
		goto error;

	int ret = _key_input_start_thread(th_info);
	if (ret < 0)
		goto error;

	ret = _key_input_stop_thread(th_info);
	if (ret < 0)
		goto error;

	ret = _key_input_destory(&th_info);
	if (ret < 0)
		goto error;

	return 0;

error :
	return -EPERM;
}
