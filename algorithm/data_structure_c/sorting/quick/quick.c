#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM		128

static int _create_random_number(int *pnum);
static int _print_array(const int *pnum);
static int _quick_sort(int *pnum, int low, int high);

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

static int _quick_sort(int *pnum, int low, int high)
{
	if (pnum == NULL)
	{
		printf("Memory points NULL status already.\n");
		goto error;
	}

	int pivot = pnum[low];

	int left = low + 1;
	int right = high;

	int temp;

	if (left <= right)
	{
		while (left <= right)
		{
			while (left <= right && pivot > pnum[left])
				left++;

			while (left <= right && pivot < pnum[right])
				right--;

			if (left <= right)
			{
				temp = pnum[left];
				pnum[left] = pnum[right];
				pnum[right] = temp;

				left++;
				right--;
			}
		}
//		printf("@@ %d %d\n", left, right);

		temp = pnum[low];
		pnum[low] = pnum[right];
		pnum[right] = temp;

		_quick_sort(pnum, low, right - 1);
		_quick_sort(pnum, right + 1, high);
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

	/* quick sort algorithm */
	if (_quick_sort(num, 0, MAX_NUM - 1) < 0)
		goto error;

	printf("\n----------------- after ----------------\n\n");
	if (_print_array(num) < 0)
		goto error;

	return 0;

error :
	return -1;
}
