#include <iostream>
#include <cstdio>
//#include <algorithm>
//#include <vector>
//#include <cstring>
//#include <string>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");

	return 0;
}

#if 0
int data[20];

int main(void)
{
	int num;
	int ret;

	scanf("%d %d", &num, &ret);
	for (int i = 0; i < num; i++)
		scanf("%d", &data[i]);

	int sum;
	int cnt = 0;
	for (int i = 1; i < (0x1 << num); i++)
	{
		sum = 0;
		for (int j = 0; j < num; j++)
		{
			if (i & (0x1 << j))
				sum += data[j];
		}

		if (sum == ret)
			cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
#endif

#if 0
char data[15];

int main(void)
{
	int r;
	int n;

	scanf("%d %d", &r, &n);

	int i;
	for (i = 0; i < n; i++)
	{
		getchar();
		scanf("%c", &data[i]);
	}

	sort(data, data + n);

	vector<int> permu;
	vector<string> ret;
	for (i = 0; i < n - r; i++)
		permu.push_back(1);

	for (i = 0; i < r; i++)
		permu.push_back(2);

	int vow;
	int con;
	string str;
	do
	{
		con = 0;
		vow = 0;
		str = "";
		for (i = 0; i < n; i++)
		{
			if (permu[i] == 2)
			{
				if (data[i] == 'a' || data[i] == 'e' ||
				    data[i] == 'i' || data[i] == 'o' ||
				    data[i] == 'u')
					vow++;
				else
					con++;

				str += data[i];
			}
		}

		if (vow >= 1 && con >= 2) 
			ret.push_back(str);

	} while (next_permutation(permu.begin(), permu.end()));

	for (unsigned int i = ret.size(); i > 0; i--)
		cout << ret[i - 1] << endl;

	return 0;
}
#endif

#if 0
#define MAX_VAL		10000

typedef struct check_information
{
	int parent;
	char dslr;

}check_t;


bool flag[MAX_VAL + 1];
int cost[MAX_VAL + 1];
check_t check[MAX_VAL + 1];

///////////////////////////////////////////////////////////////////////////////

static inline int _compute_d(int num)
{
	return (num << 1) % MAX_VAL;
}

static inline int _compute_s(int num)
{
	int ret = num - 1;
	return (ret == 0) ? MAX_VAL - 1 : ret;
}

static inline int _compute_l(int num)
{
	return (num % 1000) * 10 + num / 1000;
}

static inline int _compute_r(int num)
{
	return (num / 10) + (num % 10) * 1000;
}

int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;

	int cur;
	int next;

	int idx;
	int data;

	int (*pfunc[4])(int num);
	const char *ptable = "DSLR";

	pfunc[0] = _compute_d;
	pfunc[1] = _compute_s;
	pfunc[2] = _compute_l;
	pfunc[3] = _compute_r;

	for (i = 0; i < num; i++)
	{
		scanf("%d %d", &cur, &next);

		memset((void *)flag, 0x00, sizeof(flag));
		memset((void *)cost, 0x00, sizeof(cost));
		memset((void *)check, 0x00, sizeof(check));

		queue<int> que;

		que.push(cur);
		flag[cur] = true;

		while (!que.empty())
		{
			data = que.front();
			if (data == next)
				break;

			que.pop();

			for (j = 0; j < 4; j++)
			{
				idx = pfunc[j](data);
				if (flag[idx] == false)
				{
					que.push(idx);
					flag[idx] = true;
					cost[idx] = cost[data] + 1;

					check[idx].parent = data;
					check[idx].dslr = ptable[j];
				}
			}
		}

		cur = next;
		string str = "";
		for (j = 0; j < cost[next]; j++)
		{
			str += check[cur].dslr;
			cur = check[cur].parent;
		}

		reverse(str.begin(), str.end());
		cout << str << endl;
	}

	return 0;
}
#endif

#if 0
#define MAX_VAL		10000

int pri[MAX_VAL + 1];

static inline int _change_digit(int num, int idx, int digit)
{
	if (idx == 0 && digit == 0)
		return -1;

	string str = to_string(num);
	str[idx] = digit + '0';
	return stoi(str);
}

int main(void)
{
	int t_case;
	scanf("%d", &t_case);

	int i;
	for (i = 1; i <= MAX_VAL; i++)
		pri[i] = i;

	for (i = 2; i * i <= MAX_VAL; i++)
	{
		if (pri[i] == 0)
			continue;

		for (int j = i + i; j <= MAX_VAL; j += i)
			pri[j] = 0;
	}

	for (i = 0; i < t_case; i++)
	{
		int cur;
		int next;

		scanf("%d %d", &cur, &next);
		if (pri[cur] == 0 || pri[next] == 0)
			printf("Impossible\n");
		else
		{
			queue<int> que;
			int cost[MAX_VAL + 1] = {0, };
			bool flag[MAX_VAL + 1] = {0, };

			que.push(cur);
			flag[cur] = true;
			while (!que.empty())
			{
				int data = que.front();
				que.pop();

				for (int j = 0; j < 4; j++)
				{
					for (int k = 0; k <= 9; k++)
					{
						int idx = _change_digit(data, j, k);
						if (idx != -1)
						{
							if (pri[idx] && flag[idx] == false)
							{
								que.push(idx);
								flag[idx] = true;
								cost[idx] = cost[data] + 1;
							}
						}
					}
				}
			}
			printf("%d\n", cost[next]);
		}
	}

	return 0;
}
#endif

#if 0
queue<int> que;
bool flag[100001];
int cnt[100001];

static inline void _check_to_move(int pre, int idx)
{
	if (idx < 0 || idx > 100000)
		return;

	if (flag[idx] == false)	
	{
		flag[idx] = true;
		que.push(idx);
		cnt[idx] = cnt[pre] + 1;
	}
}

int main(void)
{
	int me;
	int you;

	scanf("%d %d", &me, &you);

	que.push(me);
	flag[me] = true;

	int data;
	while (!que.empty())
	{
		data = que.front();
		if (data == you)
			break;
		que.pop();

		_check_to_move(data, data + 1);
		_check_to_move(data, data - 1);
		_check_to_move(data, data << 1);
	}

	printf("%d\n", cnt[you]);

	return 0;
}
#endif

#if 0
int data[12];

int main(void)
{
	int num;
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
			break;

		for (int i = 0; i < num; i++)
			scanf("%d", &data[i]);

		vector<int> temp;
		for (int i = 0; i < num - 6; i++)
			temp.push_back(0);

		for (int i = 0; i < 6; i++)
			temp.push_back(1);

		vector<vector<int>> ret;
		do
		{
			vector<int> sum;
			for (int i = 0; i < num; i++)
			{
				if (temp[i] == 1)
					sum.push_back(data[i]);
			}
			ret.push_back(sum);

		} while (next_permutation(temp.begin(), temp.end()));

		sort(ret.begin(), ret.end());
		for (auto vec : ret)
		{
			for (unsigned long j = 0; j < vec.size(); j++)
				cout << vec[j] << ' ';
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int cost[11][11];

int main(void)
{
	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			scanf("%d", &cost[i][j]);

	int permu[num];
	for (int i = 0; i < num; i++)
		permu[i] = i + 1;

	long long ret = (unsigned)~0;
	do
	{
		bool flag = true;
		long long sum = 0;
		for (int i = 1; i < num; i++)
		{
			if (cost[permu[i - 1]][permu[i]] == 0)
			{
				flag = false;
				break;
			}
			sum += (cost[permu[i - 1]][permu[i]]);
		}

		if (flag == true && cost[permu[num - 1]][permu[0]] != 0)
		{
			sum += (cost[permu[num - 1]][permu[0]]);
			if (ret > sum)
				ret = sum;
		}

	} while (next_permutation(permu + 1, permu + num));

	printf("%lld\n", ret);

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	int data[num];
	for (int i = 0; i < num; i++)
		scanf("%d", &data[i]);

	sort(data, data + num);

	int max = 0;
	do
	{
		int sum = 0;
		for (int i = 1; i < num; i++)
			sum += abs(data[i - 1] - data[i]);

		if (max < sum)
			max = sum;

	} while (next_permutation(data, data + num));

	printf("%d\n", max);

	return 0;
}
#endif

#if 0
int wrong[11];

static inline bool _check_unuseing_number(string &str, int size)
{
	for (unsigned int i = 0; i < str.size(); i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (str[i] - '0' == wrong[j])
				return false;
		}
	}

	return true;
}

int main(void)
{
	int num;
	scanf("%d", &num);
	string str = to_string(num);

	if (98 <= num && num <= 102)
	{
		const int table[] = {2, 1, 0, 1, 2};
		printf("%d\n", table[num - 98]);

		goto escape;
	}

	int w_num;
	scanf("%d", &w_num);
	for (int i = 0; i < w_num; i++)
		scanf("%d", &wrong[i]);

	if (_check_unuseing_number(str, w_num) == true)
	{
		int sub = 100 - num;
		if (sub < 0)
			sub *= -1;

		printf("%lu\n", min((unsigned long)sub, str.size()));
	}
	else
	{
		printf("####\n");
	}

escape :
	return 0;
}
#endif

#if 0
typedef enum
{
	EARTH_LIMIT = 15,
	SUN_LIMIT = 28,
	MOON_LIMIT = 19

}limit_e;

int main(void)
{
	int earth;	// 15
	int sun;	// 28
	int moon;	// 19

	scanf("%d %d %d", &earth, &sun, &moon);

	int i = 1;
	int j = 1;
	int k = 1;

	int cnt = 1;
	while (1)
	{
		if (i == earth && j == sun && k == moon)
			break;

		i++;
		j++;
		k++;
		cnt++;

		if (i > EARTH_LIMIT)
			i = 1;

		if (j > SUN_LIMIT)
			j = 1;

		if (k > MOON_LIMIT)
			k = 1;
	}

	printf("%d\n", cnt);
	return 0;
}
#endif

#if 0
int data[20];
int temp[20];

int main(void)
{
	int num;
	scanf("%d", &num);

	int menu;
	scanf("%d", &menu);

	int i;
	for (i = 0; i < num; i++)
		data[i] = i + 1;

	if (menu == 1)
	{
		unsigned long long cnt;
		scanf("%llu", &cnt);
		printf("%llu\n", cnt);

		while (--cnt)
			next_permutation(data, data + num);

		for (i = 0; i < num; i++)
			printf("%d ", data[i]);
		printf("\n");
	}
	else
	{
		for (i = 0; i < num; i++)
			scanf("%d", &temp[i]);

		int cnt = 1;
		do
		{
			bool flag = false;
			for (i = 0; i < num; i++)
			{
				if (data[i] != temp[i])
				{
					flag = true;
					break;
				}
			}

			if (flag == true)
				cnt++;
			else
			{
				printf("%d\n", cnt);
				return 0;
			}

		} while (next_permutation(data, data + num));
	}

	return 0;
}
#endif

#if 0
int data[8];

int main(void)
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
		data[i] = i + 1;

	do
	{
		for (int i = 0; i < num; i++)
			printf("%d ", data[i]);
		printf("\n");

	} while (next_permutation(data, data + num));

	return 0;
}
#endif

#if 0
int data[10000];

int main(void)
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
		scanf("%d", &data[i]);

	if (prev_permutation(data, data + num))
	{
		for (int i = 0; i < num; i++)
			printf("%d ", data[i]);
		printf("\n");
	}
	else
		printf("-1\n");

	return 0;
}
#endif

#if 0
int data[10000];

int main(void)
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
		scanf("%d", &data[i]);

	if (next_permutation(data, data + num))
	{
		for (int i = 0; i < num; i++)
			printf("%d ", data[i]);
		printf("\n");
	}
	else
		printf("-1\n");

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	int value;
	char str[8];

	int data = 0;
	for (int i = 0; i < num; i++)
	{
		scanf("%s %d", str, &value);

		if (!strcmp(str, "add"))
			data |= (0x1 << (value - 1));
		else if (!strcmp(str, "check"))
			printf("%d\n", (data >> (value - 1)) & 0x1);
		else if (!strcmp(str, "remove"))
			data &= ~(0x1 << (value - 1));
		else if (!strcmp(str, "toggle"))
			data ^= (0x1 << (value - 1));
		else if (!strcmp(str, "all"))
			data = (0x1 << 20) - 1;
		else if (!strcmp(str, "empty"))
			data = 0;
	}

	return 0;
}
#endif

#if 0
int data[10000];

static inline long long _check_range(int play, long long pivot)
{
	long long cnt = play;
	for (int i = 0; i < play; i++)
		cnt += (pivot / data[i]);

	return cnt;
}

int main(void)
{
	int num;
	int play;

	scanf("%d %d", &num, &play);
	for (int i = 0; i < play; i++)
		scanf("%d", &data[i]);

	
	long long start = 0;
	long long end = 2000000000LL * 1000000LL;
	long long mid;

	while (start <= end)
	{
		mid = (start + end) >> 1;
		if (_check_range(play, mid) >= num)
			end = mid - 1;
		else
			start = mid + 1;
	}

	long long total = _check_range(play, start) - num;
	for (int i = play - 1; i >= 0; i--)
	{
		if (start % data[i] == 0)
		{
			if (total == 0)
			{
				printf("%d\n", data[i]);
				break;
			}
			else
				total--;
		}
	}

	return 0;
}
#endif

#if 0
long long data[200000];

static inline bool _check_range(int home, int wifi, long long cmp)
{
	long long cnt = 0;
	for (int i = 1; i < home; i++)
	{
		printf("## %lld %lld %lld\n", data[i], data[i - 1], cmp);
		if (cmp <= data[i] - data[i - 1])
		{
			cnt++;
		}
	}

	printf("@@ %lld\n", cnt);
		
	return cnt >= wifi;
}

int main(void)
{
	int home;
	int wifi;
	scanf("%d %d", &home, &wifi);

	for (int i = 0; i < home; i++)
		scanf("%lld", &data[i]);

	sort(data, data + home);

	long long start = data[0];
	long long end = data[home - 1];
	long long mid;

	long long ret = 0;
//	while (start <= end)

	for (int i = 0; i < 3; i++)
	{
		mid = (start + end) >> 1;
		if (_check_range(home, wifi, mid) == true)
		{
			if (ret < mid)
				ret = mid;

			start = mid + 1;
		}
		else
			end = mid - 1;

		printf("%lld %lld\n", start, end);
	}

//	printf("%lld\n", ret);
	return 0;
}
#endif

#if 0
typedef long long ull;

ull data[1000000];

static inline bool _check_range(ull tree, ull len, ull div)
{
	ull remain = 0;
	for (ull i = 0; i < tree; i++)
	{
		if (data[i] - div > 0)
			remain += (data[i] - div);
	}

	return remain >= len;
}

int main(void)
{
	ull tree;
	ull len;
	ull max = 0;

	scanf("%lld %lld", &tree, &len);
	for (ull i = 0; i < tree; i++)
	{
		scanf("%lld", &data[i]);
		if (max < data[i])
			max = data[i];
	}

	ull start = 0;
	ull end = max;
	ull mid;
	ull ret = 0;

	while (start <= end)
	for (int i = 0; i < 3; i++)
	{
		mid = (start + end) >> 1;
		if (_check_range(tree, len, mid) == true)
		{
			if (ret < mid)
				ret = mid;

			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	printf("%lld\n", ret);

	return 0;
}
#endif

#if 0
typedef unsigned long long ull;

int data[10000];

static int _check_range(int cur, ull ret, ull mid)
{
	ull cnt = 0;
	for (int i = 0; i < cur; i++)
		cnt += (data[i] / mid);

	return (cnt >= ret);
}

int main(void)
{
	int n;
	int k;
	scanf("%d %d", &n, &k);

	ull max = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
		if (max < (ull)data[i])
			max = data[i];
	}

	ull start = 0;
	ull end = max;
	ull mid;
	ull ret = 0;
	while (start <= end)
	{
		mid = (start + end) >> 1;
		if (_check_range(n, (ull)k, mid))
		{
			if (ret < mid)
				ret = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	printf("%llu\n", ret);

	return 0;
}
#endif
