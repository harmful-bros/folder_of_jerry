#include "linked_list.h"

/*
 * create node func,,
 */
list_t *create_node( void )
{
	list_t *pnew = NULL;

	pnew = ( list_t * )malloc( sizeof( list_t ) );
	if( pnew == NULL )
	{
		MSG_MEM_ERR;
		goto error;
	}
		
	memset( ( void * )pnew , 0x00 ,sizeof( list_t ) );
	CONFIRM_ADDRESS( "malloc" , pnew );

	return pnew;

error :
	remove_node( pnew );
	return NULL;
}


/*
 * remove node func,,
 */
int remove_node( list_t *pdel )
{
	if( pdel )
	{
		CONFIRM_ADDRESS( "free" , pdel );
		free( ( void * )pdel );
		pdel = NULL;
	}

	return 0;
}
