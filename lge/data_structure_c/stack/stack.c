#include "stack.h"

static int push( stack_info_t *psp , int data );
static int pop( stack_info_t *psp );

static int push( stack_info_t *psp , int data )
{
	list_t *pnew = ( list_t * )malloc( sizeof( list_t ) );
	if( pnew == NULL )
	{
		MSG_MEM_ERR;
		goto error;
	}

	pnew->data = data;
	pnew->pnext = psp->plist;
	psp->plist = pnew;

	printf("push data : %d\t%p\n" , pnew->data , pnew);

	return 0;

error :
	return -1;
}

static int pop( stack_info_t *psp )
{
	list_t *pdel;

	if( psp->plist == NULL )
	{
		printf("Data don't exist.\n");
		goto error;
	}

	pdel = psp->plist;
	psp->plist = psp->plist->pnext;

	printf("pop data : %d\t%p\n" , pdel->data , pdel);

	free( ( void * )pdel );
	pdel = NULL;

	return 0;

error :
	return -1;
}

int main( void )
{
	list_t *pdel;
	list_t *ptemp;

	stack_info_t *psp;
	psp = ( stack_info_t * )malloc( sizeof( stack_info_t ) );
	if( psp == NULL )
	{
		MSG_MEM_ERR;
		goto error;
	}
	memset( ( void * )psp , 0x00 , sizeof( stack_info_t ) );
	printf("malloc : %p\n\n" , psp);

	/////////////////////////////////

	if (push( psp , 2 ) < 0)
		goto error;
	if (push( psp , 8 ) < 0)
		goto error;
	if (push( psp , 0 ) < 0)
		goto error;
	if (push( psp , 6 ) < 0)
		goto error;
	if (push( psp , 9 ) < 0)
		goto error;

	if (push( psp , 1 ) < 0)
		goto error;
	if (push( psp , 5 ) < 0)
		goto error;
	if (push( psp , 2 ) < 0)
		goto error;
	if (push( psp , 4 ) < 0)
		goto error;
	
	printf("\n");
	/////////////////////////////////	

	pop( psp );
	pop( psp );
	pop( psp );
	pop( psp );
	pop( psp );
#if 0
	pop( psp );
	pop( psp );
	pop( psp );
	pop( psp );
	pop( psp );

	pop( psp );
#endif
	printf("\n");
	//////////////////////////////////

error :
		
	ptemp = psp->plist;
	while( ptemp )
	{
		pdel = ptemp;
		ptemp = ptemp->pnext;

		printf("del : %d %p\n" , pdel->data , pdel);
		free( ( void * )pdel );
		pdel = NULL;
	}

	if( psp )
	{
		printf("free : %p\n" , psp);
		free( ( void * )psp );
		psp = NULL;
	}

	return 0;

}
