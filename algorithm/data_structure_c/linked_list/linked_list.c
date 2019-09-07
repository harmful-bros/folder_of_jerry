#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "./linked_list.h"

static int _insert_list(list_t *head, int in_data);
static int _desert_list(list_t *head, int out_data);
static int _print_list(const list_t *head);
static int _delete_all_list(list_t *head);

list_t *
init_list(void)
{
	list_t *new = (list_t *)calloc(1, sizeof(list_t));
	if (unlikely(new == NULL))
	{
		ERR_MSG("Failed to create head list.\n");
		return NULL;
	}

	DEBUG_MSG("[Head] %p\n", new);

	return new;
}

int
clear_list(list_t *head)
{
	if (unlikely(head == NULL))
	{
		printf("Invalild parameters.\n");
		return -EPERM;
	}

	DEBUG_MSG("[Head] %p\n", head);

	free(head);
	head = NULL;

	return 0;
}

static int
_insert_list(list_t *head, int in_data)
{
	if (unlikely(head == NULL))
	{
		ERR_MSG("Invalild parameters.\n");
		return -EPERM;
	}

	/* new list */
	list_t *new = (list_t *)malloc(sizeof(list_t));
	if (new == NULL)
	{
		ERR_MSG("Failed to create list.\n");
		return -errno;
	}

	new->data = in_data;
	new->ptr = NULL;

	DEBUG_MSG("[New] %p\n", new);

	/* insert */
	if (head->ptr)
		new->ptr = head->ptr;
	head->ptr = new;

	return 0;
}

static int
_desert_list(list_t *head, int out_data)
{
	if (unlikely(head == NULL))
	{
		ERR_MSG("Invalid parameters.\n");
		return -EPERM;
	}

	list_t *pre = head;
	list_t *del = head->ptr;
	for (; del; pre = del, del = del->ptr)
	{
		if (del->data == out_data)
			break;
	}

	if (del == NULL)
	{
		ERR_MSG("Not matched the data.\n");
		return -EPERM;
	}

	pre->ptr = del->ptr;
	DEBUG_MSG("[Del] %p\n", del);

	del->ptr = NULL;
	free(del);

	return 0;
}

static int
_print_list(const list_t *head)
{
	int i;
	head = head->ptr;
	for (i = 0; head; head = head->ptr, i++)
		printf("[%d] %d\n", i, head->data);

	return 0;
}

static int
_delete_all_list(list_t *head)
{
	if (unlikely(head == NULL))
	{
		ERR_MSG("Invalild parameters.\n");
		return -EPERM;
	}

	list_t *pre;
	list_t *del = head->ptr;
	while (del)
	{
		pre = del;
		del = del->ptr;
		DEBUG_MSG("[Del] %p\n", pre);
		free(pre);
	}

	return 0;
}

int
main(void)
{
	list_t *head = init_list();
	if (head == NULL)
		return -EPERM;

	int i;
	int ret;
	for (i = 0; i < 10; i++)
	{
		ret = _insert_list(head, i + 1);
		if (ret < 0)
			goto escape;
	}

	_print_list(head);

	ret = _desert_list(head, 3);
	if (ret < 0)
		goto escape;

	ret = _desert_list(head, 5);
	if (ret < 0)
		goto escape;

	ret = _desert_list(head, 7);
	if (ret < 0)
		goto escape;

	printf("\n");
	_print_list(head);

escape:
	_delete_all_list(head);
	clear_list(head);

	return 0;
}
