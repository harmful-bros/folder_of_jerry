#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include <linked_list.h>

typedef struct stack
{
	list_t *top;
}stack_t;

static stack_t *_init_stack(void);
static int _clear_stack(stack_t *sp);
static int _push_stack(stack_t *sp, int data);
static int _pop_stack(stack_t *sp);

static stack_t *
_init_stack(void)
{
	stack_t *new = calloc(1, sizeof(stack_t));
	if (unlikely(new == NULL))
		ERR_MSG("Failed to create top in stack.");

	return new;
}

static int
_clear_stack(stack_t *sp)
{
	if (unlikely(sp == NULL))
	{
		ERR_MSG("Invaild parameters.");
		return -EPERM;
	}

	free(sp);
	sp = NULL;

	return 0;
}

static int
_push_stack(stack_t *sp, int data)
{
	if (unlikely(sp == NULL))
	{
		ERR_MSG("Invaild parameters.");
		return -EPERM;
	}

	/* create new list */
	list_t *new = create_list();
	if (unlikely(new == NULL))
		return -EPERM;

	/* set data */
	new->data = data;

	/* push to top */
	if (sp->top)
		new->ptr = sp->top;

	/* set top */
	sp->top = new;

	printf("[Push] %d\n", sp->top->data);

	return 0;
}

static int
_pop_stack(stack_t *sp)
{
	if (unlikely(sp == NULL))
	{
		ERR_MSG("Invaild parameters.");
		return -EPERM;
	}

	list_t *del = sp->top;
	if (del == NULL)
	{
		ERR_MSG("Empty status in the stack.");
		return -EPERM;
	}

	/* pop from top */
	sp->top = del->ptr;

	printf("[Pop] %d\n", del->data);

	int ret = destroy_list(del);
	if (ret < 0)
		return -EPERM;

	return 0;
}

int
main(void)
{	
	stack_t *sp = _init_stack();
	if (unlikely(sp == NULL))
		return -EPERM;

	int i;
	int ret;
	for (i = 0; i < 10; i++)
	{
		ret = _push_stack(sp, i + 1);
		if (ret < 0)
			goto escape;
	}
	printf("\n");

escape:
	while ((ret = _pop_stack(sp)) >= 0);
	_clear_stack(sp);

	return 0;
}
