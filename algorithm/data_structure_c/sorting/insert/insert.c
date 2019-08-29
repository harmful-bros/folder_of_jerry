#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM		128

static int _create_random_number(int *pnum);
static int _print_array(const int *pnum);
static int _insertion_sort(int *pnum);

static int _create_random_number(int *pnum)
{
	int i;

	srand(time(NULL));
	for (i = 0; i < MAX_NUM; i++)
		pnum[i] = rand() % 1000;

	return 0;
}

static int _print_array(const int *pnum)
{
	int i;

	for (i = 0; i < MAX_NUM; i++)
	{
		printf("%3d\t", pnum[i]);

		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	printf("\n");

	return 0;
}

static int _insertion_sort(int *pnum)
{
	int i;
	int j;
	int temp;

	for (i = 0; i < MAX_NUM; i++)
	{
		for (j = i + 1; j; j--)
		{
			if (pnum[j - 1] > pnum[j])
			{
				temp = pnum[j];
				pnum[j] = pnum[j - 1];
				pnum[j - 1] = temp;
			}
		}
	}

	return 0;
}

int main(void)
{
	int num[MAX_NUM] = {0, };

	if (_create_random_number(num) < 0)
		goto error;

	printf("\n----------------- before ----------------\n\n");
	if (_print_array(num) < 0)
		goto error;

	// insertion sort
	if (_insertion_sort(num) < 0)
		goto error;

	printf("\n----------------- after ----------------\n\n");
	if (_print_array(num) < 0)
		goto error;

	return 0;

error :
	return -1;
}
