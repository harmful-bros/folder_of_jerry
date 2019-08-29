#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#define QUEUE_DEBUG
#define QUEUE_EMPTY_DATA	-1

#ifdef QUEUE_DEBUG
#define	MEM_ERR_QUEUE_MSG						\
	printf("[QUEUE ERR] Memory shortage. %s %s %d\n", 		\
			__FILE__, __func__, __LINE__)

#define QUE_DATA_MSG(data)						\
	printf("[QUEUE] DATA : %d\n", data)

#define QUE_EMPTY_MSG							\
	printf("[QUEUE] EMpty!!\n")

#define QUE_MEM_ERR_STA							\
	printf("[QUEUE ERR] Memory points NULL status already. %s %s %d\n", \
			__FILE__, __func__, __LINE__)

#define	CONFIRM_ADDRESS( str , node )	printf(str": %p\n" , node)	
#else
#define	MEM_ERR_QUEUE_MSG						
#define QUE_DATA_MSG(data)						
#define QUE_EMPTY_MSG
#define QUE_MEM_ERR_STA
#define	CONFIRM_ADDRESS( str , node )
#endif

typedef struct linked_list
{
	int data;
	struct linked_list *pnext;

}list_t;

typedef struct queue_information
{
	list_t *phead;
	list_t *prear;
}que_t;

#endif
