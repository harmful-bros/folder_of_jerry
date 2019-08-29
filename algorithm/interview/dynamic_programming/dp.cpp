#include <iostream>
#include <cstdio>

#if 0
1. Overlapping Subproblem
큰 문제를 작은 문제로 나눌 수 있다.
큰 문제를 작은 문제 푸는 방법과 동일하게 풀 수 있다.

2. Optimal Substructure
문제의 정답을 작은 문제의 정답에서 구할 수 있다.

O(N)의 시간 복잡도

#endif

using namespace std;

#if 1
int main(void)
{
	printf("leejaeseong\n");

	return 0;
}
#endif


#if 0			// DP, 1912, 연속합
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

#if 0			// DP, 11055, 가장 큰 증가 부분 수열
int dp[101];
int weight[10001];

int main(void)
{
	int i;
	int j;

	int n_case;
	int value;

	scanf("%d %d", &n_case, &value);
	for (i = 0; i < n_case; i++)
		scanf("%d", &weight[i]);

	dp[0] = 1;
	for (i = 0; i < n_case; i++)
	{
		for (j = 1; j <= value; j++)
		{
			if (j - weight[i] >= 0)
				dp[j] += dp[j - weight[i]];
		}
	}

	printf("%d\n", dp[value]);

	return 0;
}
#endif

#if 0			// DP, 11057, 오르막 수
#define DIV_VAL		10007

// 

unsigned long long dp[1001][10];

int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;
	int k;

	for (i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (i = 2; i <= num; i++)
	{
		for (j = 0; j < 10; j++)
		{
			for (k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= DIV_VAL; 
			}
		}
	}

	unsigned long long sum = 0;
	for (i = 0; i < 10; i++)
		sum += dp[num][i];

	printf("%llu\n", sum % DIV_VAL);

	return 0;
}
#endif

#if 0			// DP, 11052, 붕어빵 판매하기
int dp[1001];
int cost[1001];

// dp[i]가 i개 붕어빵을 팔았을 때 최대 수익 이라고 하면,
// dp[i - j] + cost[j] 중에서 max인 내역이 최대 라고 할 수 있다.

int main(void)
{
	int n_case;
	scanf("%d", &n_case);

	for (int i = 1; i <= n_case; i++)
		scanf("%d", &cost[i]);

	for (int i = 1; i <= n_case; i++)
		for (int j = 1; j <= i; j++)
			if (dp[i] < dp[i - j] + cost[j])
				dp[i] = dp[i - j] + cost[j];

	printf("%d\n", dp[n_case]);

	return 0;
}
#endif

#if 0			// DP, 9096, 1,2,3 더하기
int dp[11];

// dp[x]가 가질 수 있는 숫자 조합의 개수라고 할 때,
// dp[i]가 가질 수 있는 조합은 d[i - 1], d[i - 2], d[i - 3]의 합이 된다.
// dp[1], [2], [3] 을 구해 보면서 증명 해볼 것.

int main(void)
{
	int t_case;

	scanf("%d", &t_case);
	for (int i = 0; i < t_case; i++)
	{
		int num;
		scanf("%d", &num);

		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int j = 4; j <= num; j++)
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];

		printf("%d\n", dp[num]);
	}

	return 0;
}
#endif

#if 0			// DP, 11726, 2 * n 타일링
int dp[1001];

// 경우의 수를 구해보면 해당 점화식을 도출 가능

int main(void)
{
	int num;

	scanf("%d", &num);

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= num; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}

	printf("%d\n", dp[num]);

	return 0;
}
#endif

#if 0			// DP, 1463, 1로 만들기
int d[1000001];

// 나누어 떨어지는 경우의 수를 dp로 놓고,,
// 해당 경우에서 min값이 되는 경우를 찾은 후 + 1 로 횟수를 구한다.

int main(void) 
{
	int n;
	cin >> n;
	d[1] = 0;
	for (int i=2; i<=n; i++) 
	{
		d[i] = d[i - 1] + 1;

		if (i % 2 == 0 && d[i] > d[i / 2] + 1) 
			d[i] = d[i / 2] + 1;

		if (i % 3 == 0 && d[i] > d[i / 3] + 1) 
			d[i] = d[i / 3] + 1;
	}

	cout << d[n] << '\n';
	return 0;
}
#endif
