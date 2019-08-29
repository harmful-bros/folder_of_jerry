#include "queue.h"

static int _enqueue_func(que_t *pque, int data);
static int _dequeue_func(que_t *pque);
static int _queue_create(que_t **ppque);
static int _queue_destory(que_t **ppque);

///////////////////////////////////////////////////////////////////////////////

static list_t *_create_node(void)
{
	list_t *pnew = (list_t *)malloc(sizeof(list_t));
	if (pnew == NULL)
	{
		MEM_ERR_QUEUE_MSG;
		goto error;
	}

	memset((void *)pnew, 0x00, sizeof(list_t));

error :
	return pnew;
}

static int _destroy_node(list_t **ppdel)
{
	if (ppdel == NULL)
	{
		QUE_MEM_ERR_STA;
		goto error;
	}

	if (*ppdel)
	{
		free((void *)*ppdel);
		*ppdel = NULL;
	}

	return 0;

error :
	return -1;
}

static int _enqueue_func(que_t *pque, int data)
{
	list_t *pnew;

	pnew = _create_node();
	if (pnew == NULL)
		goto error;

	pnew->data = data;

	if (pque->phead)
	{
		pque->phead->pnext = pnew;
		pque->phead = pnew;
	}
	else
	{
		pque->phead = pnew;
		pque->prear = pnew;
	}

	return 0;

error :
	return -1;
}

static int _dequeue_func(que_t *pque)
{
	int ret = -1;
	list_t *pdel;

	pdel = pque->prear;
	if (pdel)
	{
		ret = pdel->data;
		pque->prear = pdel->pnext;
		if (pque->prear == NULL)
			pque->phead = NULL;
	
		QUE_DATA_MSG(pdel->data);
		_destroy_node(&pdel);
	}
	else
		QUE_EMPTY_MSG;

	return ret;
}

static int _queue_create(que_t **ppque)
{
	if (ppque == NULL)
	{
		MEM_ERR_QUEUE_MSG;
		goto error;
	}

	*ppque = (que_t *)malloc(sizeof(que_t));
	if (*ppque == NULL)
	{
		MEM_ERR_QUEUE_MSG;
		goto error;
	}

	CONFIRM_ADDRESS("que head", *ppque);
	memset((void *)*ppque, 0x00, sizeof(que_t));

	return 0;

error :
	return -1;
}

static int _queue_destory(que_t **ppque)
{
	if (ppque == NULL)
	{
		MEM_ERR_QUEUE_MSG;
		goto error;
	}

	if (*ppque)
	{
		CONFIRM_ADDRESS("que head", *ppque);
		free((void *)*ppque);
		*ppque = NULL;
	}

	return 0;

error :
	return -1;
}

int main(void)
{
	que_t *pque = NULL;

	if (_queue_create(&pque) < 0)
		goto error;

	if (_enqueue_func(pque, 1) < 0)
		goto error;

	if (_enqueue_func(pque, 2) < 0)
		goto error;

	if (_enqueue_func(pque, 3) < 0)
		goto error;

	if (_enqueue_func(pque, 4) < 0)
		goto error;

	if (_enqueue_func(pque, 5) < 0)
		goto error;

#if 0
	_dequeue_func(pque);
	_dequeue_func(pque);
	_dequeue_func(pque);
	_dequeue_func(pque);
	_dequeue_func(pque);
#endif
	_dequeue_func(pque);
	_dequeue_func(pque);

error :
	while (_dequeue_func(pque) != QUEUE_EMPTY_DATA);
	_queue_destory(&pque);
	return 0;
}
