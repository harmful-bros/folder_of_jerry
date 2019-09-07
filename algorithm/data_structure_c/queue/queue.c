#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <linked_list.h>

#define CHECK_QUEUE(que)													\
	do {																	\
		if (unlikely(que == NULL)) {										\
			ERR_MSG("Invaild paramters.");									\
			return -EPERM;													\
		}																	\
	} while(0)

typedef struct queue
{
	list_t *front;
	list_t *rear;
}que_t;

static que_t *_init_queue(void);
static int _clear_queue(que_t *que);
static int _enqueue_func(que_t *que, int data);
static int _dequeue_func(que_t *que);

static que_t *
_init_queue(void)
{
	que_t *new = calloc(1, sizeof(que_t));
	if (unlikely(new == NULL))
		ERR_MSG("Failed to create queue pointer.");

	return new;
}

static int
_clear_queue(que_t *que)
{
	CHECK_QUEUE(que);

	free(que);
	que = NULL;

	return 0;
}

static int
_enqueue_func(que_t *que, int data)
{
	CHECK_QUEUE(que);

	list_t *new = create_list();
	if (unlikely(new == NULL))
		return -EPERM;

	new->data = data;

	/* increase queue */
	if (que->rear)
		que->rear->ptr = new;
	else
		que->front = new;		/* empty status in queue */

	que->rear = new;

	printf("[En] %d\n", que->rear->data);

	return 0;
}

static int
_dequeue_func(que_t *que)
{
	CHECK_QUEUE(que);

	list_t *del = que->front;
	if (del == NULL)
	{
		ERR_MSG("Empty status in the queue.");
		return -EPERM;
	}

	/* decreate queue */
	que->front = que->front->ptr;
	if (que->front == NULL)
		que->rear = NULL;

	printf("[De] %d\n", del->data);

	free(del);

	return 0;
}

int
main(void)
{
	que_t *que = _init_queue();
	if (unlikely(que == NULL))
		return -EPERM;

	int i;
	int ret;
	for (i = 0; i < 10; i++)
	{
		ret = _enqueue_func(que, i + 1);
		if (ret < 0)
			goto escape;
	}
	printf("\n");

escape:
	while ((ret = _dequeue_func(que)) >= 0);
	_clear_queue(que);

	return 0;
}
