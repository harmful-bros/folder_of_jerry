#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct linked_list
{
	int data;
	struct linked_list *plink;

}list_t;

typedef struct stack
{
	list_t *psp;

}st_t;

int main(void)
{
	int i

	return 0;
}

#if 0
int main(void)
{
	int i;
	int num;
	char str[32];

	int size = 0;

	st_t *pst = (st_t *)malloc(sizeof(st_t));
	pst->psp = NULL;

	scanf("%d", &num);
	getchar();
	for (i = 0; i < num; i++)
	{
		fgets(str, sizeof(str), stdin);
		str[strlen(str) - 1] = '\0';

		if (strstr(str, "push "))
		{
			list_t *pnew = (list_t *)malloc(sizeof(list_t));
			pnew->data = atoi(&str[5]);
			pnew->plink = pst->psp;
			pst->psp = pnew;
			size++;
		}
		else if (strstr(str, "pop"))
		{
			if (pst->psp)
			{
				size--;
				list_t *pdel = pst->psp;
				pst->psp = pst->psp->plink;

				printf("%d\n", pdel->data);
				free((void *)pdel);
			}
			else
				printf("-1\n");
		}
		else if (strstr(str, "size"))
		{
			printf("%d\n", size);
		}
		else if (strstr(str, "empty"))
		{
			pst->psp ? printf("0\n") : printf("1\n");
		}
		else if (strstr(str, "top"))
		{
			pst->psp ? 
				printf("%d\n", pst->psp->data) : printf("-1\n");
		}
	}

	while (pst->psp)
	{
		list_t *pdel = pst->psp;
		pst->psp = pst->psp->plink;
		free((void *)pdel);
	}

	free((void *)pst);

	return 0;
}
#endif
