#include "binary_tree.h"

static int input_binary_tree(bt_t *pbt, int data);
static int output_binary_tree(bt_t *pbt, int data);
static int search_binary_tree(bt_t **ppparent , bt_t **ppchild, int data);
static void printf_all_binary_tree(bt_t *pbt);
static void all_binary_tree_delete(bt_t *pbt);

static int input_binary_tree(bt_t *pbt, int data)
{
	bt_t *pnew;
	bt_t *pparent;
	bt_t *pchild;

	pparent = pchild = pbt->phead;
	if (search_binary_tree(&pparent, &pchild, data) == 0)
	{
		pnew = (bt_t *)malloc(sizeof(bt_t));
		if (pnew == NULL)
		{
			MSG_MEM_ERR;
			goto error;
		}
		memset((void *)pnew, 0x00, sizeof(bt_t));

		pnew->data = data;
		printf("input data : %d\t%p\n", pnew->data, pnew);

		if (pparent)
		{
			(data > pparent->data) ? \
			(pparent->pright = pnew) : \
			(pparent->pleft = pnew); 
		}
		else
			pbt->phead = pnew;
	}
	else
		printf("Existed data is %d\n", data);

	return 0;

error :
	return -1;
}

static int output_binary_tree(bt_t *pbt, int data)
{
	bt_t *ppre;
	bt_t *pdel;
	bt_t *ptemp;
	bt_t **pppre_dir;

	ppre = pbt;
	pdel = ppre->phead;
	if (search_binary_tree(&ppre, &pdel, data) < 0)
	{
		if (pdel->pleft && pdel->pright)	// have two child
		{
			// del node ref, move one right -> move left end,,
			ptemp = ppre = pdel;
			pdel = pdel->pright;

			while (pdel->pleft)
			{
				ppre = pdel;
				pdel = pdel->pleft;
			}
		
			ptemp->data = pdel->data;		
		}

		pppre_dir = (ppre->pleft == pdel) ? \
			    &ppre->pleft : &ppre->pright;

		if (pdel->pleft || pdel->pright) // have one child
		{
			*pppre_dir = (pdel->pleft) ? \
				     pdel->pleft : pdel->pright;
		}
		else				 // don't have child
			*pppre_dir = NULL;

		printf("output data : %d\t%p\n", pdel->data, pdel);
		free((void *)pdel);
		pdel = NULL;
	}
	else
		printf("Don't exist %d data.\n", data);

	return 0;
}

static int search_binary_tree(bt_t **ppparent , bt_t **ppchild, int data)
{
	int ret = 0;

	while (*ppchild)
	{
		if (data == (*ppchild)->data)
		{
			ret = -1;
			break;
		}

		*ppparent = *ppchild;
		*ppchild = (data > (*ppchild)->data) ? 
			(*ppchild)->pright : (*ppchild)->pleft;
	}

	return ret;
}

static void printf_all_binary_tree(bt_t *pbt)
{
	bt_t *ptemp = pbt;

	if (ptemp)
	{
		printf_all_binary_tree(ptemp->pleft);
		printf("%d -> ", ptemp->data);
		printf_all_binary_tree(ptemp->pright);
	}
}

static void all_binary_tree_delete(bt_t *pbt)
{
	bt_t *pdel = pbt;

	if (pdel)
	{
		all_binary_tree_delete(pdel->pleft);
		all_binary_tree_delete(pdel->pright);
	
		printf("free : %d\t%p\n", pdel->data, pdel);
		
		free((void *)pdel);
		pdel = NULL;
	}
}

int main(void)
{
	bt_t *pbt;

	pbt = (bt_t *)malloc(sizeof(bt_t));
	if (pbt == NULL)
	{
		MSG_MEM_ERR;
		goto error;
	}
	memset((void *)pbt, 0x00, sizeof(bt_t));

	printf("\nhead malloc : %p\n\n", pbt);

	///////////////////////////////////////

	if (input_binary_tree(pbt, 2) < 0)
		goto error;
	if (input_binary_tree(pbt, 8) < 0)
		goto error;
	if (input_binary_tree(pbt, 0) < 0)
		goto error;
	if (input_binary_tree(pbt, 6) < 0)
		goto error;
	if (input_binary_tree(pbt, 9) < 0)
		goto error;
	if (input_binary_tree(pbt, 1) < 0)
		goto error;
	if (input_binary_tree(pbt, 5) < 0)
		goto error;
	if (input_binary_tree(pbt, 3) < 0)
		goto error;
	if (input_binary_tree(pbt, 4) < 0)
		goto error;

	if (input_binary_tree(pbt, 4) < 0)
		goto error;

	///////////////////////////////////////
	
	printf("\n");
	printf_all_binary_tree(pbt->phead);
	printf("\n\n");	
	
	///////////////////////////////////////

	output_binary_tree(pbt, 2);
	printf("del 2 : ");
	printf_all_binary_tree(pbt->phead);
	printf("\n");

	output_binary_tree(pbt, 4);
	printf("del 4 : ");
	printf_all_binary_tree(pbt->phead);
	printf("\n");

	output_binary_tree(pbt, 4);

	output_binary_tree(pbt, 8);
	printf("del 8 : ");
	printf_all_binary_tree(pbt->phead);
	printf("\n");

	output_binary_tree(pbt, 6);
	printf("del 6 : ");
	printf_all_binary_tree(pbt->phead);
	printf("\n\n");

	///////////////////////////////////////
error :
	all_binary_tree_delete(pbt->phead);
	if (pbt)
	{
		printf("\nhead free : %p\n\n", pbt);
		free((void *)pbt);
		pbt = NULL;
	}

	return 0;
}
