
// 분할 정복 : 문제가 겹치지 않음
// DP : 겹치는 문제를 memoization을 이용해 중복을 없앤다.

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");

	return 0;
}

#if 0			// dac, 1992, 쿼드 트리
int data[64][64];

// 압축할 부분을 체크
// 불가능이면 나눠 들어가면서 구간을 재 체크

static inline int _check(int y_s, int x_s, int add)
{
	for (int i = y_s; i < y_s + add; i++)
	{
		for (int j = x_s; j < x_s + add; j++)
		{
			if (data[y_s][x_s] != data[i][j])
				return -1;
		}
	}
	return 0;
}

static int _compute(int y_s, int x_s, int add)
{
	if (_check(y_s, x_s, add) == 0)
		printf("%d", data[y_s][x_s]);
	else
	{
		printf("(");

		int div = add >> 1;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				_compute(i * div + y_s, j * div + x_s, div);

		printf(")");
	}

	return 0;
}

int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;

	for (i = 0; i < num; i++)
		for (j = 0; j < num; j++)
			scanf("%1d", &data[i][j]);

	_compute(0, 0, num);
	printf("\n");

	return 0;
}
#endif

#if 0			// dac, 11729, 하노이 탑 이동 순서

// 1 - 2 - 3 이동 이므로 6 - x - y가 다른 이동 좌표가 됨
// divide를 재귀로 구현
static int _hanoi(int n, int x, int y)
{
	if (n == 0)
		return 0;

	_hanoi(n - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	_hanoi(n - 1, 6 - x - y, y);

	return 0;
}

int main(void)
{
	int num;
	scanf("%d", &num);

	printf("%d\n", (0x1 << num) - 1);
	_hanoi(num, 1, 3);

	return 0;
}
#endif

#if 0			// dac, 11728, 배열 합치기
int a_arr[1000000];
int b_arr[1000000];
int temp[1000000];

// merge_sort 하듯이 합치는 과정

int main(void)
{
	int a;
	int b;
	scanf("%d %d", &a, &b);

	int i;
	for (i = 0; i < a; i++)
		scanf("%d", &a_arr[i]);

	for (i = 0; i < b; i++)
		scanf("%d", &b_arr[i]);

	i = 0;
	int j = 0;
	int k = 0;

	while (i < a && j < b)
		temp[k++] = (a_arr[i] < b_arr[j]) ? a_arr[i++] : b_arr[j++];

	while (i < a)
		temp[k++] = a_arr[i++];

	while (j < b)
		temp[k++] = b_arr[j++];

	for (i = 0; i < k; i++)
		printf("%d ", temp[i]);
	printf("\n");

	return 0;
}
#endif

#if 0			// dac, 10816, 숫자 카드2

// equal_range를 이용해 범위를 찾아서 카운트를 리턴한다.
// binary_search는 bool로 return 하기 때문에 중복 값은 알 수 없음,,

int main(void)
{
	int total;
	scanf("%d", &total);
	vector<int> vec(total);

	for (int i = 0; i < total; i++)
		scanf("%d", &vec[i]);

	sort(vec.begin(), vec.end());

	int num;
	scanf("%d", &num);

	int check;
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &check);
		auto ret = equal_range(vec.begin(), vec.end(), check);
		printf("%ld ", ret.second - ret.first);
	}
	printf("\n");

	return 0;
}
#endif

#if 0			// dac, 10815, 숫자 카드
int data[500000];

// 정렬 후 이분 탐색을 통해 해당 숫자를 찾는다.
// O(logN)

int main(void)
{
	int total;
	scanf("%d", &total);

	for (int i = 0; i < total; i++)
		scanf("%d", &data[i]);

	sort(data, data + total);

	int num;
	int find;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &find);

		// binary search
		int left = 0;
		int right = total - 1;
		bool flag = false;

		while (left <= right)
		{
			int mid = (left + right) >> 1;

			if (find == data[mid])
			{
				flag = true;
				break;
			}

			if (find > data[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		printf("%d ", flag == false ? 0 : 1);
	}
	printf("\n");

	return 0;
}
#endif
