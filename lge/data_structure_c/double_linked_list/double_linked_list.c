#include "../single_linked_list/linked_list.h"

static int push_node( list_t *phead );
static int pop_node( list_t *phead , list_t *ptarget );

static list_t *search_node( list_t *phead , list_t *ptarget );
static void all_node_delete( list_t *phead );

static int push_node( list_t *phead )
{
	int data;
	list_t *pnew;
	list_t *ptemp;

	printf("input data : ");
	scanf("%d" , &data);

	pnew = create_node();
	if( pnew == NULL )
		goto error;

	pnew->data = data;

	if( search_node( phead , pnew ) )
	{
		printf("Data exist already.\n");
		goto error;
	}

	ptemp = phead;
	while( ptemp->pnext )
		ptemp = ptemp->pnext;

	ptemp->pnext = pnew;
	pnew->ppre = ptemp;

	return 0;

error :
	remove_node( pnew );
	return -1;
}

static int pop_node( list_t *phead , list_t *ptarget )
{
	list_t *pdel;

	if( search_node( phead , ptarget ) == NULL )
	{
		printf("Data don't exist.\n");
		goto error;
	}

	pdel = phead->pnext;
	while( pdel->pnext )
	{
		if( pdel == ptarget )
			break;
	
		pdel = pdel->pnext;
	}

	pdel->ppre->pnext = pdel->pnext;
	pdel->pnext->ppre = pdel->ppre;

	remove_node( pdel );

	return 0;

error :
	return -1;
}

static list_t *search_node( list_t *phead , list_t *ptarget )
{
	list_t *ptemp = phead;

	while( ptemp )
	{
		if( ptemp->data == ptarget->data )
			break;

		ptemp = ptemp->pnext;
	}

	return ptemp;
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

	printf("\n-----\n\n");

	pop_node( phead , phead->pnext );
	pop_node( phead , phead->pnext );
	pop_node( phead , phead->pnext );
	
	printf("Double Linked List Test End!!\n");

error :
	all_node_delete( phead );
	return 0;
}
