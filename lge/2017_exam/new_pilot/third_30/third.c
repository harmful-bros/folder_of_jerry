#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define JSLEE_DEBUG

#ifdef JSLEE_DEBUG
#define	MSG_MEM_SHORTAGE						\
	printf("[ERR] Memory shortage. %s %s %d\n",			\
			__FILE__, __func__, __LINE__)

#define MSG_MEM_EMPTY							\
	printf("[ERR] Memory points NULL status already. %s %s %d\n",	\
			__FILE__, __func__, __LINE__)

#define MSG_OVERFLOW(pstr)						\
	printf("[ERR] %s is overflow!! %s %s %d\n", 			\
			pstr, __FILE__, __func__, __LINE__)

#define MSG_CHECK_MEM(pstr, ptr)					\
	printf("%s : %p\n", pstr, ptr)
#else
#define	MSG_MEM_SHORTAGE				
#define MSG_MEM_EMPTY					
#define MSG_OVERFLOW(pstr)						
#define MSG_CHECK_MEM(pstr, ptr)					
#endif

typedef enum
{
	MAX_NODE = 1000

}overflow_e;

typedef struct linked_list
{
	int data;
	struct linked_list *plink;

}list_t;

static void *_allocate_memory(size_t size);
static int _free_memory(void **ppdel);
static int _free_all_list(list_t ***pppdel, int edge);

static int _input_node_and_edge(int *pnode, int *pedge);
static list_t **_input_parent_child_node(int node, int edge);
static int _check_high_max_min_in_tree(list_t **pptree, int idx, 
		int *pmax, int *pmin);

///////////////////////////////////////////////////////////////////////////////

static void *_allocate_memory(size_t size)
{
	void *pnew = malloc(size);
	if (pnew == NULL)
		goto error;

	MSG_CHECK_MEM("Malloc", pnew);
	memset(pnew, 0x00, size);

error :
	return pnew;
}

static int _free_memory(void **ppdel)
{
	if (ppdel == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	if (*ppdel)
	{
		MSG_CHECK_MEM("Free", *ppdel);
		free((void *)*ppdel);
		*ppdel = NULL;
	}

	return 0;

error :
	return -1;
}

static int _free_all_list(list_t ***pppdel, int edge)
{
	int i;
	list_t *ptemp = NULL;
	list_t **ppdel = NULL;

	if (pppdel == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	ppdel = *pppdel;
	if (ppdel)
	{
		// for edge
		for (i = 0; i < edge; i++)
		{
			while (ppdel[i])
			{
				ptemp = ppdel[i];
				ppdel[i] = ppdel[i]->plink;
				_free_memory((void *)&ptemp);
			}

		}

		MSG_CHECK_MEM("Free", *pppdel);
		free((void *)*pppdel);
		*pppdel = NULL;
	}

	return 0;
error :
	return -1;
}

static int _input_node_and_edge(int *pnode, int *pedge)
{
	if (pnode == NULL || pedge == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	scanf("%d %d", pnode, pedge);
	if (*pnode < 1 || *pnode > MAX_NODE)
	{
		MSG_OVERFLOW("Node");
		goto error;
	}

	if (*pnode != *pedge + 1)
	{
		MSG_OVERFLOW("Edge");
		goto error;
	}

	return 0;

error :
	return -1;
}

static list_t **_input_parent_child_node(int node, int edge)
{
	int i;

	int pa_node;
	int ch_node;

	list_t *pnew = NULL;
	list_t *ptemp = NULL;

	list_t **ppnew = (list_t **)_allocate_memory(sizeof(list_t *) * node);
	if (ppnew == NULL)
	{
		MSG_MEM_SHORTAGE;
		goto error;
	}

	for (i = 0; i < edge; i++)
	{
		scanf("%d %d", &pa_node, &ch_node);
		if (pa_node < 0 || pa_node > edge)
		{
			MSG_OVERFLOW("Parent Node");
			goto error;
		}

		if (ch_node < 0 || node <= ch_node)
		{
			MSG_OVERFLOW("Child Node");
			goto error;
		}

		pnew = (list_t *)_allocate_memory(sizeof(list_t));
		if (pnew == NULL)
		{
			MSG_MEM_SHORTAGE;
			goto error;
		}
		pnew->data = ch_node;

		ptemp = ppnew[pa_node];
		if (ptemp)
		{
			while (ptemp->plink)
				ptemp = ptemp->plink;
			ptemp->plink = pnew;
		}
		else
			ppnew[pa_node] = pnew;
	}

	return ppnew;
error :
	_free_all_list(&ppnew, edge);
	return NULL;
}

static int _check_high_max_min_in_tree(list_t **pptree, int idx, 
		int *pmax, int *pmin)
{
	list_t *ptemp;
	static int cnt = 0;

	if (pptree == NULL || pmax == NULL || pmin == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	if (pptree[idx] == NULL)
	{
		if (*pmax < cnt)
			*pmax = cnt;

		if (*pmin > cnt)
			*pmin = cnt;
	}

	cnt++;
	for (ptemp = pptree[idx]; ptemp; ptemp = ptemp->plink)
	{
		idx = ptemp->data;
		_check_high_max_min_in_tree(pptree, idx, pmax, pmin);
	}
	cnt--;

	return 0;
error :
	return -1;
}

int main(void)
{
	int node;
	int edge;

	int max;
	int min;

	list_t **pplist = NULL;

	if (_input_node_and_edge(&node, &edge) < 0)
		goto error;

	pplist = _input_parent_child_node(node, edge);
	if (pplist == NULL)
		goto error;

	max = 0;
	min = node;
	if (_check_high_max_min_in_tree(pplist, 0, &max,  &min) < 0)
		goto error;

	printf("%d\n", max - min);

error :
	_free_all_list(&pplist, edge);
	return 0;
}
