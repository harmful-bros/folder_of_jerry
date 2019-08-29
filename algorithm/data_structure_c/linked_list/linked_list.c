#include "linked_list.h"

static list_t *_create_node(void);
static int _destroy_node(list_t **ppdel);

static int _insert_linked_list(list_t *phead, int data);
static int _desert_linked_list(list_t *phead, int data);
static list_t *_search_data_in_list(list_t *phead, list_t **pppre, int data);
static int _delete_all_linked_list(list_t *phead);

///////////////////////////////////////////////////////////////////////////////

static list_t *_create_node(void)
{
	list_t *pnew = NULL;
	
	pnew = (list_t *)malloc(sizeof(list_t));
	if (pnew == NULL)
	{
		MEM_SHORTAGE_MSG;
		goto error;
	}
	memset((void *)pnew, 0x00, sizeof(list_t));

	CONFIRM_ADDRESS("malloc", pnew);

	return pnew;

error :
	return NULL;
}

static int _destroy_node(list_t **ppdel)
{
	if (*ppdel)
	{
		CONFIRM_ADDRESS("free", *ppdel);

		free((void *)*ppdel);
		*ppdel = NULL;
	}

	return 0;
}

static int _insert_linked_list(list_t *phead, int data)
{
	if (phead == NULL)
	{
		LIST_MEM_ERR_STA;
		goto error;
	}

	list_t *ptemp = phead;
	list_t *pnew = _create_node();
	if (pnew == NULL)
		goto error;

	pnew->data = data;
	pnew->pnext = NULL;

	while (ptemp->pnext)
		ptemp = ptemp->pnext;

	ptemp->pnext = pnew;

	printf("input : %10d %p\n", pnew->data, pnew);

	return 0;
error :
	return -1;
}

static int _desert_linked_list(list_t *phead, int data)
{
	if (phead == NULL)
	{
		LIST_MEM_ERR_STA;
		goto error;
	}

	list_t *ppre = phead;
	list_t *pdel = _search_data_in_list(phead, &ppre, data);
	if (pdel)
	{
		ppre->pnext = pdel->pnext;
		_destroy_node(&pdel);
	}
	else
		printf("There is not matching data.\n");

	return 0;

error :
	return -1;
}

static list_t *_search_data_in_list(list_t *phead, list_t **pppre, int data)
{
	if (phead == NULL || pppre == NULL)
	{
		LIST_MEM_ERR_STA;
		goto error;
	}

	list_t *ptemp = phead;

	while (ptemp)
	{
		if (ptemp->data == data)
		{
			printf("Search : %10d %p\n", data, ptemp);
			break;
		}

		*pppre = ptemp;		
		ptemp = ptemp->pnext;
	}

	return ptemp;
error :
	return NULL;
}

static int _delete_all_linked_list(list_t *phead)
{
	if (phead == NULL)
	{
		LIST_MEM_ERR_STA;
		goto error;
	}

	list_t *pdel;
	list_t *ptemp = phead->pnext;

	while (ptemp)
	{
		pdel = ptemp;
		phead->pnext = ptemp->pnext;

		_destroy_node(&pdel);
		ptemp = ptemp->pnext;
	}

	return 0;

error : 
	return -1;
}

int main(void)
{
	list_t *phead = _create_node();
	if (phead == NULL)
		goto error;
	printf("\n");

	if (_insert_linked_list(phead, 1) < 0)
		goto error;

	if (_insert_linked_list(phead, 111) < 0)
		goto error;

	if (_insert_linked_list(phead, 333) < 0)
		goto error;

	if (_insert_linked_list(phead, 444) < 0)
		goto error;

	if (_insert_linked_list(phead, 999999) < 0)
		goto error;

	printf("\n");
	_desert_linked_list(phead, 1);
	_desert_linked_list(phead, 444);
	_desert_linked_list(phead, 333);
	printf("\n");

error :
	_delete_all_linked_list(phead);
	printf("\n");
	_destroy_node(&phead);

	return 0;
}
