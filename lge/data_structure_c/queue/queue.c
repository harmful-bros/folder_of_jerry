#include "queue.h"

int enqueue(que_t *pque, int data)
{
	list_t *pnew = (list_t *)malloc(sizeof(list_t));
	if (pnew == NULL)
	{
		MSG_MEM_ERR;
		goto error;
	}
	memset((void *)pnew, 0x00, sizeof(list_t));

	printf("enqueue : %d\t%p\n" , data , pnew);

	pnew->data = data;
	if (pque->prear == NULL)
	{
		pque->prear = pnew;
		pque->phead = pnew;
	}
	else
	{
		pque->prear->pnext = pnew;
		pque->prear = pnew;
	}
	
	return 0;

error :
	return -1;
}

int dequeue(que_t *pque)
{
	list_t *pdel;

	if (pque->phead == NULL)
	{
		printf("Data don't exist.\n");
		goto error;
	}

	pdel = pque->phead;
	if (pque->phead == pque->prear)
		pque->prear = NULL;

	pque->phead = pque->phead->pnext;

	printf("dequeue : %d\t%p\n" , pdel->data , pdel);

	free((void *)pdel);
	pdel = NULL;

	return 0;

error :
	return -1;
}

int main(void)
{
	list_t *pdel;
	list_t *ptemp;

	que_t *pque = (que_t *)malloc(sizeof(que_t));
	if (pque == NULL)
	{
		MSG_MEM_ERR;
		goto error;
	}
	memset((void *)pque, 0x00, sizeof(que_t));
	
	printf("malloc : %p\n\n", pque);

	//////////////////////////////////////////
	
	if (enqueue(pque, 2) < 0)
		goto error;
	if (enqueue(pque, 8) < 0)
		goto error;
	if (enqueue(pque, 0) < 0)
		goto error;
	if (enqueue(pque, 6) < 0)
		goto error;
	if (enqueue(pque, 9) < 0)
		goto error;

	if (enqueue(pque, 1) < 0)
		goto error;
	if (enqueue(pque, 5) < 0)
		goto error;
	if (enqueue(pque, 2) < 0)
		goto error;
	if (enqueue(pque, 4) < 0)
		goto error;

	printf("\n");
	//////////////////////////////////////////

	dequeue(pque);
	dequeue(pque);
	dequeue(pque);
	dequeue(pque);
	dequeue(pque);

#if 0
	dequeue(pque);
	dequeue(pque);
	dequeue(pque);
	dequeue(pque);
	dequeue(pque);

	dequeue(pque);
#endif	
	printf("\n");
	//////////////////////////////////////////

error :

	ptemp = pque->phead;
	while (ptemp)
	{
		pdel = ptemp;
		ptemp = ptemp->pnext;

		printf("free : %d\t%p\n" , pdel->data , pdel);

		free((void *)pdel);
		pdel = NULL;
	}

	if (pque)
	{
		printf("free : %p\n", pque);
		free((void *)pque);
		pque = NULL;
	}

	return 0;
}
