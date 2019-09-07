#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <linked_list.h>

list_t *
create_list(void)
{
	list_t *new = (list_t *)calloc(1, sizeof(list_t));
	if (unlikely(new == NULL))
	{
		ERR_MSG("Failed to create new list.");
		return NULL;
	}

	DEBUG_MSG("[New] %p\n", new);

	return new;
}

int
destroy_list(list_t *del)
{
	if (unlikely(del == NULL))
	{
		ERR_MSG("Invalild parameters.");
		return -EPERM;
	}

	DEBUG_MSG("[Del] %p\n", del);

	free(del);
	del = NULL;

	return 0;
}
