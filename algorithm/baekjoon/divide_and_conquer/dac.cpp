#include <iostream>
#include <cstdio>
//#include <algorithm>
//#include <vector>
//#include <cstring>
#include <stack>

using namespace std;

#if 0
int main(void)
{
	printf("leejaeseong\n");

	return 0;
}
#endif

#if 0
int cnt;
int input_y;
int input_x;

static int _compute(int y, int x, int div)
{
	if (div == 1)
	{
		if (y == input_y && x == input_x)
		{
			printf("%d\n", cnt);
			exit(1);
		}
		cnt++;
	}
	else
	{
		div >>= 1;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				_compute(i * div + y, j * div + x, div);
	}

	return 0;
}

int main(void)
{
	int num;
	scanf("%d %d %d", &num, &input_y, &input_x);
//	_compute(0, 0, 0x1 << num);

	int y = 0;
	int x = 0;

	stack<pair<int, int>> st;

	int y_start;
	int x_start;

	num = 0x1 << num;
#if 0
	st.push({0, 0});
	while (!st.empty())
	{
		y_start = st.top().first;
		x_start = st.top().second;
		st.pop();

		for (int i = y_start; i < num; i++)
		{
			for (int j = x_start; j < num; j++)
			{
				st.push({});
			}
		}
	}
#endif

	return 0;
}
#endif

#if 0
char data[3100][3100];

static int _draw_star(int y, int x, int div, bool flag)
{
	

	return 0;
}

int main(void)
{
	int num;
	scanf("%d", &num);

	int sum = 1;
	for (int i = 0; i < num; i++)
		sum <<= 1;
	sum *= 3;

	bool flag = false;
	_draw_star(0, 0, num, flag);

	for (int i = 0; i < sum; i++)
	{
		for (int j = 0; j < sum; j++)
		{
			printf("%c", data[i][j]);
		}
		printf("\n");
	}

	return 0;
}
#endif

#if 0
char data[3000][3000];

static int _draw_star(int y, int x, int div, bool flag)
{
	int i;
	int j;

	if (flag == true)
	{
		for (i = y; i < y + div; i++)
			for (j = x; j < x + div; j++)
				data[i][j] = ' ';
	}
	else
	{
		if (div == 1)
			data[y][x] = '*';
		else
		{
			div /= 3;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					flag = (i == 1 && j == 1) ? 
						true : false;
					_draw_star(i * div + y, 
						   j * div + x, 
						   div, flag);
				}
			}
		}
	}

	return 0;
}

int main(void)
{
	int num;
	scanf("%d", &num);

	if (num == 1)
		printf("*\n");
	else
	{
		bool flag = false;
		_draw_star(0, 0, num, flag);

		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				printf("%c", data[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
#endif

#if 0
int data[64][64];

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

#if 1

#if 0
static int _hanoi(int n, int x, int y)
{
	stack<pair<int, int>> st;

	for (int i = 0; i < n; i++)
	{

	}



	return 0;
}
#else
static int _hanoi(int n, int x, int y)
{
	if (n == 0)
		return 0;

	_hanoi(n - 1, x, 6 - x - y);
	printf("%d @@ %d %d\n", n, x, y);
	_hanoi(n - 1, 6 - x - y, y);

	return 0;
}
#endif

int main(void)
{
	int num;
	scanf("%d", &num);

	printf("%d\n", (0x1 << num) - 1);
	_hanoi(num, 1, 3);

	return 0;
}
#endif

#if 0
int cnt[3];
int data[3000][3000];

static inline int _check(int y_s, int x_s, int add)
{
	int i;
	int j;

	for (i = y_s; i < y_s + add; i++)
	{
		for (j = x_s; j < x_s + add; j++)
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
	{
		cnt[data[y_s][x_s] + 1]++;
		return 0;
	}

	int div = add / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			_compute(i * div + y_s, j * div + x_s, div);

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
			scanf("%d", &data[i][j]);

	_compute(0, 0, num);

	for (i = 0; i < 3; i++)
		printf("%d\n", cnt[i]);

	return 0;
}
#endif

#if 0
int a_arr[1000000];
int b_arr[1000000];
int temp[1000000];

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

#if 0
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

#if 0
int data[500000];

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

#if 0
pair<int, int> data[100001];

int main(void)
{
	int i;
	int total;
	int n_case;	

	scanf("%d %d", &total, &n_case);
	for (i = 1; i <= total; i++)
	{
		scanf("%d", &data[i].first);
		data[i].second = i;
	}

	sort(data + 1, data + total + 1);

	int start;
	int end;
	int idx;
	int cnt = 0;

	for (i = 0; i < n_case; i++)
	{
		scanf("%d %d %d", &start, &end, &idx);
		for (int j = 1; j <= total; j++)
		{
			if (data[j].second >= start && data[j].second <= end)	
				cnt++;

			if (cnt == idx)
			{
				cnt = 0;
				printf("%d\n", data[j].first);
				break;
			}
		}
	}

	return 0;
}
#endif

#if 0
int matrix_1[101][101];
int matrix_2[101][101];

int main(void)
{
	int n;
	int m;
	int k;

	int i;
	int j;
	int l;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &matrix_1[i][j]);

	scanf("%d %d", &m, &k);
	for (i = 0; i < m; i++)
		for (j = 0; j < k; j++)
			scanf("%d", &matrix_2[i][j]);

	int sum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			for (l = 0; l < m; l++)
				sum += (matrix_1[i][l] * matrix_2[l][j]);
			printf("%d ", sum);
			sum = 0;
		}
		printf("\n");
	}

	return 0;
}
#endif
