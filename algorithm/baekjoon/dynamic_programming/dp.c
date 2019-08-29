#include <stdio.h>
#include <string.h>

int sum[501];
int cost[501];
unsigned int dp[501][501];

static inline unsigned int _min(unsigned int num_1, unsigned int num_2)
{
	return (num_1 > num_2) ? num_2 : num_1;
}

int main(void)
{
	int i;
	int j;
	int k;

	int t_case;
	int n_case;

	scanf("%d", &t_case);
	for (i = 0; i < t_case; i++)
	{
		printf("@@@ leejaeseong\n");
		memset(dp, 0x00, sizeof(dp));
		memset(sum, 0x00, sizeof(sum));

#if 1
		scanf("%d", &n_case);
		for (j = 1; j <= n_case; j++)
		{
			scanf("%d", &cost[j]);
			sum[j] += (sum[j - 1] + cost[j]);
		}

		
		for (i = 1; i <= n_case; i++)
		{
			for (j = 1; j <= n_case; j++)
			{
				if (i == j)
					continue;

				dp[i][j] = ~0;
//				printf("%u\n", dp[i][j]);
#if 1
				for (k = i; k < j; k++)
				{
					dp[i][j] = _min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
				}
#endif
			}
		}

		for (i = 1; i <= n_case; i++)
		{
			for (j = 1; j <= n_case; j++)
			{
				printf("%3d\t", dp[i][j]);
			}
			printf("\n");
		}

		printf("%d\n", sum[n_case]);
#endif

	}
		
	return 0;
}

#if 0
int arr[501][501];
int dp[501][501];

int idx_x[] = {1, 0, -1, 0};
int idx_y[] = {0, 1, 0, -1};

int row;
int col;

int _compute_path(int y, int x)
{
	if (x == row && y == col)
		return 1;

	if (dp[y][x] == -1)
		dp[y][x] = 0;

	int x_idx;
	int y_idx;

	for (int i = 0; i < 4; i++)
	{
		x_idx = x + idx_x[i];
		y_idx = y + idx_y[i];


		if (x_idx < 1 || x_idx > row || y_idx < 1 || y_idx > col)
			continue;

		if (arr[y][x] > arr[y_idx][x_idx])
		{
			if (dp[y_idx][x_idx] == -1)
				dp[y][x] += _compute_path(y_idx, x_idx);
			else
				dp[y][x] += dp[y_idx][x_idx];
		}
	}

	return dp[y][x];
}

int main(void)
{
	scanf("%d %d", &col, &row);
	for (int i = 1; i <= col; i++)
	{
		for (int j = 1; j <= row; j++)
		{
			scanf("%d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}

	printf("%d\n", _compute_path(1, 1));

	return 0;
}
#endif

#if 0
int num[100001];
int max[100001];

static inline int _max(int num_1, int num_2)
{
	return num_1 > num_2 ? num_1 : num_2;
}

int main(void)
{
	int i;
	int t_case;
	int max_val;

	scanf("%d", &t_case);
	for (i = 1; i <= t_case; i++)
	{
		scanf("%d", &num[i]);
		max[i] = _max(max[i - 1] + num[i], num[i]);

		if (i == 1)
			max_val = num[1];

		if (max_val < max[i])
			max_val = max[i];
	}

	printf("%d\n", max_val);

	return 0;
}
#endif

#if 0
int main(void)
{
	int num_1;
	int num_2;
	int num_3;

	scanf("%d %d %d", &num_1, &num_2, &num_3);
	printf("%d\n", 
			(num_3 - num_2) > (num_2 - num_1) ? 
			(num_3 - num_2 - 1) : 
			(num_2 - num_1 - 1));

	return 0;
}
#endif

#if 0
int dp[10001];
int weight[10001];

static inline int _max(int num_1, int num_2)
{
	return num_1 > num_2 ? num_1 : num_2;
}

int main(void)
{
	int i;
	int num;

	scanf("%d", &num);
	for (i = 1; i <= num; i++)
		scanf("%d", &weight[i]);

	dp[1] = weight[1];
	dp[2] = weight[2] + dp[1];
	for (i = 3; i <= num; i++)
	{
		dp[i] += _max(_max(dp[i - 3] + weight[i - 1] + weight[i],
				   dp[i - 1]),
				   dp[i - 2] + weight[i]);
	}

	printf("%d\n", dp[num]);

	return 0;
}
#endif

#if 0
int dp[101];
int weight[10001];

int main(void)
{
	int i;
	int j;

	int n_case;
	int value;

	scanf("%d %d", &n_case, &value);
	for (i = 1; i <= n_case; i++)
		scanf("%d", &weight[i]);

	dp[0] = 1;
	for (i = 1; i <= n_case; i++)
	{
		for (j = weight[i]; j <= value; j++)
		{
			dp[j] += dp[j - weight[i]];
		}
	}

	printf("%d\n", dp[value]);

	return 0;
}
#endif

#if 0
static inline int _max(int num_1, int num_2)
{
	return num_1 > num_2 ? num_1 : num_2;
}

int main(void)
{
	int i;
	int j;

	int num;
	int max = 0;
	int tri[501][501] = {{0, }, };
	int dp[501][501] = {{0, }, };

	scanf("%d", &num);
	for (i = 1; i <= num; i++)
		for (j = 1; j <= i; j++)
			scanf("%d", &tri[i][j]);

	i = j = 1;
	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (j == 1)
				dp[i][j] += (dp[i - 1][1] + tri[i][1]);
			else if (j == i)
				dp[i][j] += 
					(dp[i - 1][j - 1] + tri[i][j]);
			else
				dp[i][j] = _max(tri[i][j] + dp[i - 1][j - 1], 
						tri[i][j] + dp[i - 1][j]);
		}
	}

	for (i = 1; i <= num; i++)
	{
		if (dp[num][i] > max)
			max = dp[num][i];
	}

	printf("%d\n", max);
	

	return 0;
}
#endif

#if 0
int arr[1001][3];
int dp[1001][3];

static inline int _min(int num_1, int num_2)
{
	return num_1 > num_2 ? num_2 : num_1;
}

int main(void)
{
	int i;
	int num;

	int red;
	int green;
	int blue;

	scanf("%d", &num);
	for (i = 1; i <= num; i++)
	{
		scanf("%d %d %d", &red, &green, &blue);
		arr[i][0] = red;
		arr[i][1] = green;
		arr[i][2] = blue;
	}

	for (i = 1; i <= num; i++)
	{
		dp[i][0] = _min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = _min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = _min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	printf("%d\n", _min(_min(dp[num][0], dp[num][1]), dp[num][2]));
	return 0;
}
#endif
