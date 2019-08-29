#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define GRAPH_DEBUG
//#define BREATH_FIRST_SEARCH

#ifdef BREATH_FIRST_SEARCH
#define MAX_EDGE_NUM		6
#else
#define MAX_EDGE_NUM		8
#endif

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
	struct linked_list *pnext;
		
}list_t;

typedef struct graph_information
{
	int *pflag;
	list_t **pplink;

}graph_t;

typedef enum
{
	EMPTY = -1,
	OFF,
	ON

}flag_e;

#ifdef BREATH_FIRST_SEARCH
typedef struct queue_information
{
	int data;
	list_t *phead;
	list_t *prear;
}que_t;
#endif

/* for linked list */
static void *_create_node(size_t size);
static int _destroy_node(void **ppdel);

/* for graph */
static int _init_graph(graph_t *pgph, int edge_cnt);
static int _insert_node_in_graph(graph_t *pgph, int cur_n, int to_n);
static int _delete_all_graph_data(graph_t *pgph, int edge_cnt);

#ifdef BREATH_FIRST_SEARCH
static int _breath_first_search_in_graph(graph_t *pgph, int idx);
#else
static int _depth_first_search_in_graph(graph_t *pgph, int idx);
#endif

/* for queue */
#ifdef BREATH_FIRST_SEARCH
static int _insert_queue(que_t *pque, int data);
static int _desert_queue(que_t *pque);
#endif

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

	pgph->pplink = (list_t **)_create_node(sizeof(list_t *) * edge_cnt);
	if (pgph->pplink == NULL)
	{
		MSG_MEM_ERR;
		goto error;
	}
	memset((void *)pgph->pplink, 0x00, sizeof(list_t *) * edge_cnt);
	MSG_MEM("ARRAY", pgph->pplink);

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

	ptemp = pgph->pplink[cur_n];
	if (ptemp)
	{
		while (ptemp->pnext)
			ptemp = ptemp->pnext;
		ptemp->pnext = pnew;
	}
	else
		pgph->pplink[cur_n] = pnew;

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
		ptemp = pgph->pplink[i];
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

#ifdef BREATH_FIRST_SEARCH
static int _breath_first_search_in_graph(graph_t *pgph, int idx)
{
	list_t *ptemp;
	que_t *pque;

	if (pgph == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	pque = _create_node(sizeof(que_t));
	if (pque == NULL)
	{
		MSG_MEM_ERR;
		goto error;
	}

	if (_insert_queue(pque, idx) < 0)
		goto error;
	pgph->pflag[idx] = ON;
	printf("Visit Edge : %d\n", idx + 1);

	while ((idx = _desert_queue(pque)) != EMPTY)
	{
		for (ptemp = pgph->pplink[idx]; ptemp; ptemp = ptemp->pnext)
		{
			idx = ptemp->data;
			if (pgph->pflag[idx] == OFF)
			{
				printf("Visit Edge : %d\n", idx + 1);
				pgph->pflag[idx] = ON;
				_insert_queue(pque, idx);
			}
		}
	}

	_destroy_node((void **)&pque);

	return 0;

error :
	return -1;
}
#else
static int _depth_first_search_in_graph(graph_t *pgph, int idx)
{
	list_t *ptemp;

	if (pgph == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	pgph->pflag[idx] = ON;
	printf("Visit Edge : %d\n", idx + 1);

	for (ptemp = pgph->pplink[idx]; ptemp; ptemp = ptemp->pnext)
	{
		idx = ptemp->data;
		if (pgph->pflag[idx] == OFF)
			_depth_first_search_in_graph(pgph, idx);
	}

	return 0;

error :
	return -1;
}
#endif

#ifdef BREATH_FIRST_SEARCH
static int _insert_queue(que_t *pque, int data)
{
	list_t **pplist;
	list_t *pnew;

	if (pque == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	pnew = (list_t *)_create_node(sizeof(list_t));
	if (pnew == NULL)
	{
		MSG_MEM_ERR;
		goto error;
	}

	pnew->data = data;
	pplist = pque->phead ? &pque->phead->pnext : &pque->prear;
	*pplist = pnew;
	pque->phead = pnew;
	
	return 0;

error :
	return -1;
}

static int _desert_queue(que_t *pque)
{
	int ret = -1;
	list_t *pdel;

	if (pque == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	pdel = pque->prear;
	if (pdel)
	{
		ret = pdel->data;
		pque->prear = pque->prear->pnext;
		if (pque->prear == NULL)
			pque->phead = NULL;

		_destroy_node((void **)&pdel);
	}
	else
		printf("Que is empty.\n");

error :
	return ret;
}
#endif

int main(void)
{
	graph_t *pgph = (graph_t *)_create_node(sizeof(graph_t));
	if (pgph == NULL)
		goto error;

	MSG_MEM("HEAD", pgph);

	if (_init_graph(pgph, MAX_EDGE_NUM) < 0)
		goto error;

	printf("\n");
#ifdef BREATH_FIRST_SEARCH
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
#else
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
	if (_insert_node_in_graph(pgph, 3, 6) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 3, 7) < 0)
		goto error;

	/* for vertex 4 */
	if (_insert_node_in_graph(pgph, 4, 2) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 4, 8) < 0)
		goto error;

	/* for vertex 5 */
	if (_insert_node_in_graph(pgph, 5, 2) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 5, 8) < 0)
		goto error;

	/* for vertex 6 */
	if (_insert_node_in_graph(pgph, 6, 3) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 6, 8) < 0)
		goto error;

	/* for vertex 7 */
	if (_insert_node_in_graph(pgph, 7, 3) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 7, 8) < 0)
		goto error;

	/* for vertex 8 */
	if (_insert_node_in_graph(pgph, 8, 4) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 8, 5) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 8, 6) < 0)
		goto error;
	if (_insert_node_in_graph(pgph, 8, 7) < 0)
		goto error;
#endif
	printf("\n");

#ifdef BREATH_FIRST_SEARCH
	if (_breath_first_search_in_graph(pgph, 0) < 0)
		goto error;
#else
	if (_depth_first_search_in_graph(pgph, 0) < 0)
		goto error;
#endif

error:
	_delete_all_graph_data(pgph, MAX_EDGE_NUM);

	printf("\n");
	MSG_MEM("Flag", pgph->pflag);
	_destroy_node((void *)&pgph->pflag);

	MSG_MEM("ARRAY", pgph->pplink);
	_destroy_node((void **)&pgph->pplink);
	
	MSG_MEM("HEAD", pgph);
	_destroy_node((void **)&pgph);

	return 0;
}
