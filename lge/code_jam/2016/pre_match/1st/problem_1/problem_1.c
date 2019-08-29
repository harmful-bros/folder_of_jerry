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

enum
{
	FALSE = -1,
	TRUE
};

typedef enum
{
	T_MAX = 45,
	N_MAX = 50000, 

}overflow_e;

typedef struct linked_list
{
	int data;
	struct linked_list *plink;

}list_t;

static void *_allocate_memory(size_t size);
static int _free_memory(void **ppdel);
static int _free_all_list(list_t ***pppdel, int node);

static list_t **_input_parent_child_node(int node);
static int _check_high_max_in_graph(list_t **pptree, int node, int *pmax);

static inline int _input_case(int *pcase, overflow_e mode);
static inline int _check_overflow(int data, int min, int max);

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

static int _free_all_list(list_t ***pppdel, int node)
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
		// for node
		for (i = 0; i < node; i++)
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

static list_t **_input_parent_child_node(int node)
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

	for (i = 0; i < node - 1; i++)
	{
		scanf("%d %d", &pa_node, &ch_node);
		
		/* overflow check,, */
		if (_check_overflow(pa_node, 1, node) < 0)
		{
			MSG_OVERFLOW("Parent Node");
			goto error;
		}

		if (_check_overflow(ch_node, 1, node) < 0)
		{
			MSG_OVERFLOW("Child Node");
			goto error;
		}

		if (ch_node == pa_node)
		{
			MSG_OVERFLOW("Input Error");
			goto error;
		}

		pa_node--;
		ch_node--;

		/* create graph */
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
	_free_all_list(&ppnew, node);
	return NULL;
}

static int _check_high_max_in_graph(list_t **pptree, int node, int *pmax)
{
	int i;
	int cnt = 1;

	list_t *pbfs;
	list_t *pdfs;

	if (pptree == NULL || pmax == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* all node */
	for (i = 0; i < node; i++)
	{
		/* breath method */
		for (pbfs = pptree[i]; pbfs; pbfs = pbfs->plink)
		{
			cnt++;

			/* depth method */
			for (pdfs = pptree[pbfs->data]; pdfs;)
			{
				pdfs = pptree[pdfs->data];
				cnt++;
			}

			/* max value update */
			if (*pmax < cnt)
				*pmax = cnt;

			/* variable init */
			cnt = 1;
		}
	}

	return 0;
error :
	return -1;
}

int main(void)
{
	int i;
	int max[64] = {0, };

	int t_case = 0;
	int n_case = 0;

	list_t **pplist = NULL;

	/* input T case */
	if (_input_case(&t_case, T_MAX) < 0)
		goto error;

	for (i = 0; i < t_case; i++)
	{
		/* input N case */
		if (_input_case(&n_case, N_MAX) < 0)
			goto error;

		/* create graph */
		pplist = _input_parent_child_node(n_case);
		if (pplist == NULL)
			goto error;

		/* find max height */
		max[i] = 1;
		if (_check_high_max_in_graph(pplist, n_case, &max[i]) < 0)
			goto error;

		/* all memory delete */
		_free_all_list(&pplist, n_case);
	}

	/* print result */
	printf("\n");
	for (i = 0; i < t_case; i++)
		printf("%d\n", max[i]);

error :
	return 0;
}

static inline int _input_case(int *pcase, overflow_e mode)
{
	if (pcase == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	scanf("%d", pcase);
	if (_check_overflow(*pcase, 1, (mode == T_MAX) ? T_MAX : N_MAX) < 0)
	{
		MSG_OVERFLOW("T Case");
		goto error;
	}

	return 0;
error :
	return -1;
}

static inline int _check_overflow(int data, int min, int max)
{
	return (data < min || data > max) ? FALSE : TRUE;
}
