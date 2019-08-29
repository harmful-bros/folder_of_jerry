#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define LINKED_LIST_DEBUG

#ifdef LINKED_LIST_DEBUG
#define	MEM_SHORTAGE_MSG						\
	printf("[ERR] Memory shortage. [File : %s, Func : %s, Line : %d]\n", \
			__FILE__, __func__, __LINE__)

#define	CONFIRM_ADDRESS( str , node )	printf(str": %p\n" , node)	
#define LIST_MEM_ERR_STA						\
	printf("[LIST ERR] Memory points NULL status already. %s %s %d\n", \
			__FILE__, __func__, __LINE__)
#else
#define	MEM_SHORTAGE_MSG
#define	CONFIRM_ADDRESS( str , node )
#define LIST_MEM_ERR_STA
#endif

typedef struct linked_list
{
	int data;
	struct linked_list *pnext;

}list_t;

#endif
