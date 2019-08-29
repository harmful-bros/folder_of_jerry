#include "linked_list.h"

static list_t *search_node( list_t *phead , list_t *ptarget );
static int push_node( list_t *phead );
static void all_node_delete( list_t *phead );

static int push_node( list_t *phead )
{
	int data;
	list_t *ptemp = NULL;
	list_t *pnew = create_node();
	
	printf("input data : ");
	scanf("%d" , &data);

	pnew->data = data;
	if( search_node( phead , pnew ) )
	{
		printf("Data is exist already.\n");
		goto error;
	}

	ptemp = phead;
	while( ptemp->pnext )
		ptemp = ptemp->pnext;

	ptemp->pnext = pnew;
	return 0;

error :
	remove_node( pnew );
	return -1;
}

static void pop_node( list_t *phead , list_t *ptarget )
{
	list_t *ppre = phead;;
	list_t *ptemp = phead->pnext;

	while( ptemp )
	{
		if( ptemp->data == ptarget->data )
		{
			ppre->pnext = ptemp->pnext;
			break;
		}
		
		ppre = ptemp;
		ptemp = ptemp->pnext;
	}

	remove_node( ptemp );
}

static void all_node_delete( list_t *phead )
{
	list_t *pdel;
	list_t *ptemp;

	pdel = ptemp = phead;
	while( ptemp )
	{
		pdel = ptemp;
		remove_node( pdel );
		ptemp = ptemp->pnext;
	}
}

static list_t *search_node( list_t *phead , list_t *ptarget )
{
	list_t *ptemp = phead->pnext;

	while( ptemp )
	{
		if( ptarget->data == ptemp->data )
			break;

		ptemp = ptemp->pnext;
	}

	return ptemp;
}

int main( void )
{
	int cnt = 0;
	list_t *phead = NULL;

	phead = create_node();
	if( phead == NULL )
		goto error;

	do
	{
		if( push_node( phead ) < 0 )
			goto error;

		cnt++;
	}while( cnt < 5 );

	pop_node( phead , phead->pnext->pnext );
	pop_node( phead , phead->pnext->pnext );
	pop_node( phead , phead->pnext->pnext );

	printf("Test End!!\n");

error :
	all_node_delete( phead );
	return 0;
}
