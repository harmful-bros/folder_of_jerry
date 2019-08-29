#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");

	return 0;
}


#if 0			// search, 1764, 듣보잡
using namespace std;

int main(void)
{
	int n_lis;
	int n_see;

	scanf("%d %d", &n_lis, &n_see);

	string input;
	set<string> l_info;
	for (int i = 0; i < n_lis; i++)
	{
		cin >> input;
		l_info.insert(input);
	}

	set<string> s_info;
	for (int i = 0; i < n_see; i++)
	{
		cin >> input;
		if (l_info.count(input) == true)
			s_info.insert(input);
	}

	cout << s_info.size() << endl;
	for (auto &name : s_info)
		cout << name << endl;

	return 0;
}
#endif

#if 0			// search, 7785, 회사에 있는 사람

// binary search tree는 set을 이용해서 구현한다.
int main(void)
{
	int num;
	scanf("%d", &num);

	string name;
	string check;
	set<string, greater<string>> info;
	for (int i = 0; i < num; i++)
	{
		cin >> name >> check;
		if (check == "enter")
			info.insert(name);
		else
			info.erase(info.find(name));
	}

	for (auto p : info)
		cout << p << endl;

	return 0;
}
#endif

#if 0			// search, 1182, 부분집합의 합
int data[20];

// 부분집합의 경우의 수는 bit mask를 이용해 풀면 편하다.

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

#if 0			// search, 1759, 암호 만들기
char data[15];

// nPr 방식을 활용하여 자음, 모음의 개수가 만족 하는가 확인?

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

#if 0			// search, 1697, 숨바꼭질
queue<int> que;
bool flag[100001];
int cnt[100001];

// queue를 이용해 BFS 방식으로 찾아간다.

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

#if 0			// search, 6603, 로또
int data[12];

// 0과 1을 추가 하여 nPr을 만들어 주는 경우
// 중복 순열은 자동으로 배제 된다.

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

#if 0			// search, 10971, 외판원 순회2
int cost[11][11];

// brute force 방식으로 모든 순열을 다 만들어 보고 최소 값을 찾는 방식

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

#if 0			// search, 10974, 모든 순열
int data[8];

// 작은 수는 가능 하나,,
// 큰 수는 팩토리얼로 늘어나기 때문에 오래 걸림..

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

#if 0			// search, 2805, 나무 자르기
typedef long long ull;

ull data[1000000];

// 범위 체크 함수 만들어서 가능 한지 여부 판단
// 가능한 범위라면 다음 범위를 절반씩 줄여가며 logN으로 접근한다.

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

#if 0			// search, 1654, 랜선 자르기
typedef unsigned long long ull;

int data[10000];

// 범위 체크 함수 만들어서 가능 한지 여부 판단
// 가능한 범위라면 다음 범위를 절반씩 줄여가며 logN으로 접근한다.

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
