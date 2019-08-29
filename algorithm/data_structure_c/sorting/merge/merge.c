#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM		128

static int _create_random_number(int *pnum);
static int _print_array(const int *pnum);
static int _merge_sort(int *pnum, int low, int high);
static int _merge_func(int *pnum, int low, int mid, int high);

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

static int _merge_sort(int *pnum, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) >> 1;
		_merge_sort(pnum, low, mid);
		_merge_sort(pnum, mid + 1, high);
		_merge_func(pnum, low, mid, high);
	}

	return 0;
}

static int _merge_func(int *pnum, int low, int mid, int high)
{
	int idx;

	int left_s = low;
	int left_e = mid;

	int right_s = mid + 1;
	int right_e = high;

	int *ptemp = (int *)malloc(sizeof(int) * (high - low + 1));
	if (ptemp == NULL)
	{
		printf("Memory shortage.\n");
		goto error;
	}

	idx = 0;
	while (left_s <= left_e && right_s <= right_e)
	{
		ptemp[idx++] = pnum[left_s] > pnum[right_s] ?
			pnum[right_s++] : pnum[left_s++];
	}

	if (left_s > left_e)
	{
		memmove((void *)&ptemp[idx], 
				(const void *)&pnum[right_s], 
				sizeof(int) * (right_e - right_s + 1));
	}
	else
	{
		memmove((void *)&ptemp[idx], 
				(const void *)&pnum[left_s], 
				sizeof(int) * (left_e - left_s + 1));
	}

	memmove((void *)&pnum[low], 
			(const void *)ptemp, 
			sizeof(int) * (high - low +1));

	if (ptemp)
	{
		free((void *)ptemp);
		ptemp = NULL;
	}

	return 0;

error :
	return -1;
}

int main(void)
{
	int num[MAX_NUM] = {0, };

	if (_create_random_number(num) < 0)
		goto error;

	printf("\n----------------- before ----------------\n\n");
	if (_print_array(num) < 0)
		goto error;

	// merge sort
	if (_merge_sort(num, 0, MAX_NUM - 1) < 0)
		goto error;

	printf("\n----------------- after ----------------\n\n");
	if (_print_array(num) < 0)
		goto error;

	return 0;

error :
	return -1;
}
