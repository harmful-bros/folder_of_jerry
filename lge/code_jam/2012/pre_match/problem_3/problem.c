#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define GRAPH_DEBUG

#define MAX_EDGE_NUM		6

#ifdef GRAPH_DEBUG
#define MSG_MEM_ERR							\
	printf("[GRAPH] Memory shortage. %s %s %d\n",			\
			__FILE__, __func__, __LINE__)

#define MSG_MEM_EMPTY							\
	printf("[GRAPH] Memory points NULL status already. %s %s %d",	\
			__FILE__, __func__, __LINE__)

#define MSG_MEM(msg, pgph)						\
	printf("[GRAPH] %s : %p\n", msg, pgph)

#define MSG_MEM_DATA(msg, data, pgph)					\
	printf("[GRAPH] %s : %3d %p\n", msg, data, pgph)

#else
#define MSG_MEM_ERR							
#define MSG_MEM_EMPTY					
#define MSG_MEM(msg, pgph)						
#define MSG_MEM_DATA(msg, data, pgph)					
#endif

typedef struct linked_list
{
	int data;
	int weight;
	struct linked_list *pnext;
		
}list_t;

typedef struct graph_information
{
	int *pflag;
	list_t **ppnext;

}graph_t;

typedef enum
{
	EMPTY = -1,
	OFF,
	ON

}flag_e;

typedef struct queue_information
{
	int data;
	list_t *phead;
	list_t *prear;
}que_t;

/* for linked list */
static void *_create_node(size_t size);
static int _destroy_node(void **ppdel);

/* for graph */
static int _init_graph(graph_t *pgph, int edge_cnt);
static int _insert_node_in_graph(graph_t *pgph, int cur_n, int to_n);
static int _delete_all_graph_data(graph_t *pgph, int edge_cnt);

static int _breath_first_search_in_graph(graph_t *pgph, int data, int weight);

/* for queue */
static int _insert_data_in_queue(que_t *pque , int data, int weight);
static int _desert_data_by_queue(que_t *pque);

///////////////////////////////////////////////////////////////////////////////

static void *_create_node(size_t size)
{
	void *pnew = malloc(size);
	if (pnew == NULL)
	{
		MSG_MEM_ERR;
		goto error;
	}

	memset(pnew, 0x00, size);

error :
	return pnew;
}

static int _destroy_node(void **ppdel)
{
	if (ppdel == NULL)
	{
		MSG_MEM_EMPTY;
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

static int _init_graph(graph_t *pgph, int edge_cnt)
{
	if (pgph == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	pgph->pflag = (int *)_create_node(sizeof(int) * edge_cnt);
	if (pgph->pflag == NULL)
	{
		MSG_MEM_ERR;
		goto error;
	}
	memset((void *)pgph->pflag, 0x00, sizeof(int) * edge_cnt);
	MSG_MEM("Flag", pgph->pflag);

	pgph->ppnext = (list_t **)_create_node(sizeof(list_t *) * edge_cnt);
	if (pgph->ppnext == NULL)
	{
		MSG_MEM_ERR;
		goto error;
	}
	memset((void *)pgph->ppnext, 0x00, sizeof(list_t *) * edge_cnt);
	MSG_MEM("ARRAY", pgph->ppnext);

	return 0;

error :
	return -1;
}

static int _insert_node_in_graph(graph_t *pgph, int cur_n, int to_n)
{
	list_t *pnew;
	list_t *ptemp;

	if (pgph == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	pnew = (list_t *)_create_node(sizeof(list_t));
	if (pnew == NULL)
		goto error;

	cur_n--;
	to_n--;
	
	MSG_MEM_DATA("New", to_n, pnew);

	pnew->data = to_n;

	ptemp = pgph->ppnext[cur_n];
	if (ptemp)
	{
		while (ptemp->pnext)
			ptemp = ptemp->pnext;
		ptemp->pnext = pnew;
	}
	else
		pgph->ppnext[cur_n] = pnew;

	return 0;

error :
	return -1;
}

static int _delete_all_graph_data(graph_t *pgph, int edge_cnt)
{
	int i;
	list_t *pdel;
	list_t *ptemp;

	if (pgph == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	for (i = 0; i < edge_cnt; i++)
	{
		ptemp = pgph->ppnext[i];
		while (ptemp)
		{
			pdel = ptemp;
			ptemp = ptemp->pnext;

			MSG_MEM_DATA("Del", pdel->data, pdel);
			_destroy_node((void **)&pdel);
		}
	}

	return 0;

error :
	return -1;
}

static int _breath_first_search_in_graph(graph_t *pgph, int data, int weight)
{
	list_t *ptemp;
	que_t *pque;

	if (pgph == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	pque = (que_t *)_create_node(sizeof(que_t));
	if (pque == NULL)
	{
		MSG_MEM_ERR;
		goto error;
	}

	if (_insert_data_in_queue(pque, data, weight) < 0)
		goto error;

	pgph->pflag[data] = ON;
	printf("Visit Edge : %d\n", data + 1);

	while ((data = _desert_data_by_queue(pque)) != EMPTY)
	{
		for (ptemp = pgph->ppnext[data]; ptemp; ptemp = ptemp->pnext)
		{
			data = ptemp->data;
			if (pgph->pflag[data] == OFF)
			{
				printf("Visit Edge : %d\n", data + 1);
				pgph->pflag[data] = ON;
				_insert_data_in_queue(pque, data, weight);
			}
		}
	}

	_destroy_node((void **)&pque);

	return 0;

error :
	return -1;
}

static int _insert_data_in_queue(que_t *pque , int data, int weight)
{
	list_t *pnew = NULL;
	list_t *pcur = NULL;
	list_t *pnext = NULL;

	pnew = (list_t *)_create_node(sizeof(list_t));
	if (pnew == NULL)
	{
		MSG_MEM_ERR;
		goto error;
	}

	pnew->data = data;
	pnew->weight = weight;
	pnew->pnext = NULL;

	if (pque->phead == NULL) //시작점 인 경우.
	{
		pque->phead = pnew;
		pque->prear = pnew;	
	}
	else
	{
		pcur = pque->phead;
		pnext = pque->phead->pnext;

		while (pnext) //무게값 보고 우선순위로 정렬되게 만듬.
		{
			if (pnext->weight > weight)
				break;		

			pcur = pnext;
			pnext = pnext->pnext;
		}

		if (pnext == NULL)
		{
			pque->prear->pnext = pnew;
			pque->prear = pnew;
		}
		else
		{
			pnew->pnext = pnext;
			pcur->pnext = pnew;
		}
	}

	return 0;
error :
	return -1;
}


static int _desert_data_by_queue(que_t *pque) //queue by linked list.
{
	int ret = -1;
	list_t *pdel = pque->phead;

	if (pdel)
	{
		ret = pdel->data;

		pque->phead = pque->phead->pnext;
		if (pque->phead == NULL)
			pque->prear = NULL;

		_destroy_node((void **)&pdel);
	}

	return ret;
}

int main(void)
{
	graph_t *pgph = (graph_t *)_create_node(sizeof(graph_t));
	if (pgph == NULL)
		goto error;

	MSG_MEM("HEAD", pgph);

	if (_init_graph(pgph, MAX_EDGE_NUM) < 0)
		goto error;

	if (_breath_first_search_in_graph(pgph, 0, 0) < 0)
		goto error;
error:
	_delete_all_graph_data(pgph, MAX_EDGE_NUM);

	printf("\n");
	MSG_MEM("Flag", pgph->pflag);
	_destroy_node((void *)&pgph->pflag);

	MSG_MEM("ARRAY", pgph->ppnext);
	_destroy_node((void **)&pgph->ppnext);
	
	MSG_MEM("HEAD", pgph);
	_destroy_node((void **)&pgph);

	return 0;
}

#if 0
	printf("\n");

	/* for vertex 1 */
	if (_insert_node_in_graph(pgph, 1, 2) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 1, 3) < 0)
		goto error;

	/* for vertex 2 */
	if (_insert_node_in_graph(pgph, 2, 1) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 2, 4) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 2, 5) < 0)
		goto error;

	/* for vertex 3 */
	if (_insert_node_in_graph(pgph, 3, 1) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 3, 4) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 3, 6) < 0)
		goto error;

	/* for vertex 4 */
	if (_insert_node_in_graph(pgph, 4, 2) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 4, 3) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 4, 5) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 4, 6) < 0)
		goto error;

	/* for vertex 5 */
	if (_insert_node_in_graph(pgph, 5, 2) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 5, 4) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 5, 6) < 0)
		goto error;

	/* for vertex 6 */
	if (_insert_node_in_graph(pgph, 6, 3) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 6, 4) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 6, 5) < 0)
		goto error;

	printf("\n");
#endif
