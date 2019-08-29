#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM		128

static int _create_random_number(int *pnum);
static int _print_array(const int *pnum);

static int _down_heap(int *pnum, int cur, int max);
static int _heapify(int *pnum, int size);
static int _heap_sort(int *pnum, int size);

///////////////////////////////////////////////////////////////////////////////

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

static int _down_heap(int *pnum, int cur, int max)
{
	int idx;
	int left;
	int right;
	int temp;

	while (cur < max)
	{
		left = (cur << 1) + 1;
		right = left + 1;

		idx = cur;
		if (left <= max && pnum[idx] < pnum[left])
			idx = left;

		if (right <= max && pnum[idx] < pnum[right])
			idx = right;

		if (idx == cur)
			break;
	
		temp = pnum[idx];
		pnum[idx] = pnum[cur];
		pnum[cur] = temp;

		cur = idx;
	}

	return 0;
}

static int _heapify(int *pnum, int size)
{
	int i = (size - 1) >> 1;
	for ( ; i >= 0; i--)
		_down_heap(pnum, i, MAX_NUM);

	return 0;
}

static int _heap_sort(int *pnum, int size)
{
	int i;
	int temp;

	_heapify(pnum, size);

	for (i = MAX_NUM - 1; i; )
	{
		temp = pnum[0];
		pnum[0] = pnum[i];
		pnum[i] = temp;

		i--;
		_down_heap(pnum, 0 , i);
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

	/* heap sort algorithm */
	if (_heap_sort(num, MAX_NUM) < 0)
		goto error;

	printf("\n----------------- after ----------------\n\n");
	if (_print_array(num) < 0)
		goto error;

	return 0;

error :
	return -1;
}
