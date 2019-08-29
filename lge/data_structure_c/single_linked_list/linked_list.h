#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSLEE_DEBUG

#define MSG_MEM_ERR	printf("[%s/%s/%d] memory shortage.\n" , __FILE__ , __func__ , __LINE__)

#ifdef JSLEE_DEBUG
#define	CONFIRM_ADDRESS( str , node )	printf(str": %p\n" , node)	
#else
#define	CONFIRM_ADDRESS( str , node )	printf("")
#endif

typedef struct linked_list
{
	int data;
	struct linked_list *pnext;
	struct linked_list *ppre;

}list_t;

extern list_t *create_node( void );
extern int remove_node( list_t *pdel );

#endif
