#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <mpc_pipe.h>

#define PIPE_PATH "../out/"

#define PIPE_GUIRD \
	do { \
		if (unlikely(pipe == NULL)) { \
			ERR_MSG("Invalid parameters."); \
			return -EPERM; \
		} \
	} while (0)

#define PIPE_FD_GUIRD \
	do { \
		if (unlikely(pipe->fd < 0)) { \
			ERR_MSG("Invalid parameters.");	\
			return -EPERM; \
		} \
	} while (0)

typedef struct pipe_information pipe_t;

enum
{
	KEY_TO_TIMER,
	KEY_TO_DB,
	TIMER_TO_DB,
	TOTAL_PIPE
};

struct pipe_information
{
	int fd;
	char *path;
	char buf[MAX_BUF];

	sync_t sync;
};

static pipe_t *_mpc_pipe_create(const char *path);
static int _mpc_pipe_destroy(pipe_t *pipe);

static int _mpc_pipe_open(pipe_t *pipe);
static int _mpc_pipe_close(pipe_t *pipe);
static int _mpc_pipe_write(pipe_t *pipe);
static int _mpc_pipe_read(pipe_t *pipe);

static inline int _mpc_pipe_check(pipe_t *pipe);
static inline int _mpc_pipe_write_wrapper(pipe_t *pipe, const char *wdata);
static inline int _mpc_pipe_read_wrapper(pipe_t *pipe, char *rdata);

static pipe_t *g_pipe[TOTAL_PIPE];

int
mpc_pipe_init(void)
{
	const char *pipe_name[] =
	{
		PIPE_PATH "pipe_key_to_timer",
		PIPE_PATH "pipe_key_to_db",
		PIPE_PATH "pipe_timer_to_db"
	};

	int i;
	int ret;
	for (i = 0; i < TOTAL_PIPE; i++)
	{
		g_pipe[i] = _mpc_pipe_create(pipe_name[i]);
		if (g_pipe[i] == NULL)
			goto error;

		ret = _mpc_pipe_open(g_pipe[i]);
		if (ret < 0)
			goto error;
	}
	return 0;

error:
	mpc_pipe_exit();
	return -EPERM;
}

int
mpc_pipe_exit(void)
{
	int i;
	for (i = 0; i < TOTAL_PIPE; i++)
	{
		_mpc_pipe_close(g_pipe[i]);
		_mpc_pipe_destroy(g_pipe[i]);
	}

	return 0;
}

int
mpc_pipe_key_to_timer_write(char *wdata)
{
	return _mpc_pipe_write_wrapper(g_pipe[KEY_TO_TIMER], wdata);
}

int
mpc_pipe_key_to_timer_read(char *rdata)
{
	return _mpc_pipe_read_wrapper(g_pipe[KEY_TO_TIMER], rdata);
}

int
mpc_pipe_key_to_db_write(char *wdata)
{
	return _mpc_pipe_write_wrapper(g_pipe[KEY_TO_DB], wdata);
}

int
mpc_pipe_key_to_db_read(char *rdata)
{
	return _mpc_pipe_read_wrapper(g_pipe[KEY_TO_DB], rdata);
}

int
mpc_pipe_timer_to_db_write(char *wdata)
{
	return _mpc_pipe_write_wrapper(g_pipe[TIMER_TO_DB], wdata);
}

int
mpc_pipe_timer_to_db_read(char *rdata)
{
	return _mpc_pipe_read_wrapper(g_pipe[TIMER_TO_DB], rdata);
}

static pipe_t *
_mpc_pipe_create(const char *path)
{
	pipe_t *pipe = calloc(1, sizeof(pipe_t));
	if (pipe == NULL)
	{
		ERR_MSG("Failed to allocate the memory.");
		return NULL;
	}

	pipe->path = (char *)path;

	if (_mpc_pipe_check(pipe) == 0)
		unlink(pipe->path);

	int ret = mkfifo(pipe->path, 0666);
	if (ret < 0)
	{
		ERR_MSG("Failed to create the pipe. %s", pipe->path);
		goto error;
	}
	printf("Craete the new pipe %s\n", pipe->path);

	pthread_cond_init(&pipe->sync.cv, NULL);
	pthread_mutex_init(&pipe->sync.lock, NULL);

	return pipe;

error:
	_mpc_pipe_destroy(pipe);
	return NULL;
}

static int
_mpc_pipe_destroy(pipe_t *pipe)
{
	PIPE_GUIRD;

	if (_mpc_pipe_check(pipe) == 0)
		unlink(pipe->path);

	pthread_cond_destroy(&pipe->sync.cv);
	pthread_mutex_destroy(&pipe->sync.lock);

	free(pipe);
	return 0;
}

static int
_mpc_pipe_open(pipe_t *pipe)
{
	PIPE_GUIRD;

	if (_mpc_pipe_check(pipe) < 0)
		return -EPERM;

    pipe->fd = open(pipe->path, O_RDWR | O_SYNC);
    if (pipe->fd < 0)
    {
        ERR_MSG("Failed to open the pipe.");
        return -EPERM;
    }

	return 0;
}

static int
_mpc_pipe_close(pipe_t *pipe)
{
	PIPE_GUIRD;
	PIPE_FD_GUIRD;

	if (_mpc_pipe_check(pipe) < 0)
		return -EPERM;

    close(pipe->fd);
    return 0;
}

static int
_mpc_pipe_write(pipe_t *pipe)
{
	PIPE_GUIRD;
	PIPE_FD_GUIRD;

	if (_mpc_pipe_check(pipe) < 0)
		return -EPERM;

	pthread_mutex_lock(&pipe->sync.lock);
	int ret = write(pipe->fd, pipe->buf, strlen(pipe->buf));
	pthread_cond_signal(&pipe->sync.cv);
	pthread_mutex_unlock(&pipe->sync.lock);

	return ret;
}

static int
_mpc_pipe_read(pipe_t *pipe)
{
	PIPE_GUIRD;
	PIPE_FD_GUIRD;

	if (_mpc_pipe_check(pipe) < 0)
		return -EPERM;

	pthread_mutex_lock(&pipe->sync.lock);
	pthread_cond_wait(&pipe->sync.cv, &pipe->sync.lock);
    int ret = read(pipe->fd, pipe->buf, sizeof(pipe->buf));
	pthread_mutex_unlock(&pipe->sync.lock);

	return ret;
}

static inline int
_mpc_pipe_check(pipe_t *pipe)
{
	int ret = access(pipe->path, F_OK);
	if (ret < 0)
	{
		ERR_MSG("Not exist the pipe. %s", pipe->path);
		return -EPERM;
	}

	return 0;
}

static inline int
_mpc_pipe_write_wrapper(pipe_t *pipe, const char *wdata)
{
	PIPE_GUIRD;

	if (strlen(wdata) == 0)
		return 0;

	snprintf(pipe->buf, sizeof(pipe->buf), "%s", wdata);
	return _mpc_pipe_write(pipe);
}

static inline int
_mpc_pipe_read_wrapper(pipe_t *pipe, char *rdata)
{
	PIPE_GUIRD;

	int ret = _mpc_pipe_read(pipe);
	if (ret < 0)
		return -EPERM;

	snprintf(rdata, sizeof(pipe->buf), "%s", pipe->buf);
	return ret;
}
