#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include "../single_linked_list/linked_list.h"

typedef struct binary_tree_information bt_t;

struct binary_tree_information
{
	int data;
	bt_t *pleft;
	bt_t *pright;

	bt_t *phead;
};

#endif
