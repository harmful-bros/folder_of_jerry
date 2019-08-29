#include <stdio.h>
#include <stdlib.h>

static int _compare(const void *pnum_1, const void *pnum_2)
{
	return *(long long *)pnum_1 - *(long long *)pnum_2;
}

long long arr[10000000] = {0, };

int main(void)
{
	int num;

	int i;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
		scanf("%lld", &arr[i]);

	qsort(arr, num, sizeof(long long), _compare);

	for (i = 0; i < num; i++)
		printf("%lld\n", arr[i]);

	return 0;
}
