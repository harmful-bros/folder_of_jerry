#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define unlikely(x)     __builtin_expect(!!(x), 0)

//#define STANDALONE_DEBUG

#define ERR_MSG(fmt, ...)													\
	do {																	\
			printf("[ERR] " fmt " / func : %s, line : %d\n",					\
				##__VA_ARGS__, __func__, __LINE__);							\
	} while(0)

#ifdef STANDALONE_DEBUG
#define DEBUG_MSG(fmt, ...)													\
	do {																	\
		printf("[DEBUG] " fmt, ##__VA_ARGS__);								\
	} while(0)
#else
#define DEBUG_MSG(...)
#endif

typedef struct linked_list
{
	int data;
	struct linked_list *ptr;
}list_t;

extern list_t *create_list(void);
extern int destroy_list(list_t *del);

#endif
