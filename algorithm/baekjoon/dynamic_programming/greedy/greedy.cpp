#include <iostream>
#include <cstdio>
//#include <algorithm>
//#include <string>
//#include <cstring>
//#include <vector>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");

	return 0;
}

#if 0
int a_mat[50][50];
int b_mat[50][50];

int main(void)
{
	int col;
	int row;

	int i;
	int j;

	scanf("%d %d", &col, &row);
	for (i = 0; i < col; i++)
		for (j = 0; j < row; j++)
			scanf("%1d", &a_mat[i][j]);

	for (i = 0; i < col; i++)
		for (j = 0; j < row; j++)
			scanf("%1d", &b_mat[i][j]);

	int cnt = 0;
	for (i = 0; i < col - 2; i++)
	{
		for (j = 0; j < row - 2; j++)
		{
			if (a_mat[i][j] != b_mat[i][j])
			{
				cnt++;
				for (int k = i; k < i + 3; k++)
					for (int l = j; l < j + 3; l++)
						a_mat[k][l] ^= 1;
			}
		}
	}

	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (a_mat[i][j] != b_mat[i][j])
			{
				printf("-1\n");
				return 0;
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}
#endif

#if 0
bool flag[501];
vector<int> pos[501];
vector<int> neg;

int main(void)
{
	int n;
	int m;
	int k;

	scanf("%d %d %d", &n, &m, &k);

	if (m + k - 1 <= n && n <= m * k)
	{
		for (int i = k; i < k + k; i++)
		{
			flag[i] = true;
			neg.push_back(i);
		}

		int idx = 0;
		for (int i = 1; i <= n; i++)
		{
			if (flag[i] == true)
				continue;

			idx++;
			(idx != m) ? pos[idx].push_back(i) : pos[idx--].push_back(i);
		}

		sort(neg.begin(), neg.end(), greater<int>());
		sort(pos[idx].begin(), pos[idx].end(), greater<int>());

		idx = 0;
		for (int i = 1; i <= n; i++)
		{
			if (flag[i] == true)
				printf("%d ", neg[i - k]);
			else
			{
				idx++;
				if (idx != m)
					printf("%d ", pos[idx][0]);
				else
				{
					for (unsigned int j = 0; j < pos[idx].size(); j++)
						printf("%d ", pos[idx][j]);
					break;
				}
			}
		}
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
	int height;
	int width;

	scanf("%d %d", &height, &width);

	if (height == 1)
		printf("1\n");
	else if (height == 2)
	{
		int ret = (width & 0x1) ? (width + 1) >> 1 : width >> 1;
		if (ret > 4)
			ret = 4;
		printf("%d\n", ret);
	}
	else
		printf("%d\n", (width >= 7) ? width - 2 : min(4, width));

	return 0;
}
#endif

#if 0
int main(void)
{
	string str;
	getline(cin, str);
	sort(str.begin(), str.end(), greater<int>());

	int sum = 0;
	bool z_flag = false;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (z_flag == false && str[i] == '0')
			z_flag = true;

		sum += (str[i] - '0');
	}

	cout << ((z_flag == true && (sum % 3) == 0) ? str : "-1") << endl;

	return 0;
}
#endif

#if 0
int main(void)
{
	int n;
	int m;
	int k;

	scanf("%d %d %d", &n, &m, &k);

	int cnt = 0;
	while (1)
	{
		if (n >= 2 && m >= 1 && n + m >= k + 3)
		{
			n -= 2;
			m -= 1;
			cnt++;
		}
		else
			break;
	}

	printf("%d\n", cnt);

	return 0;
}
#endif

#if 0
vector<int> pos;
vector<int> neg;

int main(void)
{
	unsigned int num;
	scanf("%u", &num);

	int input;
	int z_cnt = 0;
	int o_cnt = 0;
	unsigned int i;
	for (i = 0; i < num; i++)
	{
		scanf("%d", &input);
		if (input == 0)
			z_cnt++;
		else if (input == 1)
			o_cnt++;
		else
			input > 0 ? pos.push_back(input) : neg.push_back(input);
	}

	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end());

	if (pos.size() & 0x1)
		pos.push_back(1);

	if (neg.size() & 0x1)
		neg.push_back(z_cnt ? 0 : 1);

#if 0
	printf("%d %d\n", z_cnt, o_cnt);

	for (i = 0; i < pos.size(); i++)
		printf("%d\n", pos[i]);

	for (i = 0; i < neg.size(); i++)
		printf("%d\n", neg[i]);
#endif

	int sum = 0;
	for (i = 0; i < pos.size(); i += 2)
		sum += (pos[i] * pos[i + 1]);

	for (i = 0; i < neg.size(); i += 2)
		sum += (neg[i] * neg[i + 1]);

	sum += o_cnt;
	printf("%d\n", sum);

	return 0;
}
#endif

#if 0
vector<int> vec;

int main(void)
{
	string str;
	getline(cin, str);

	int num = 0;
	int cnt = 1;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			vec.push_back(num);
			if (str[i] == '-')
				vec.push_back(-1);

			num = 0;
			cnt = 1;
		}
		else
		{
			num *= 10;
			num += (str[i] - '0');
		}
	}

	vec.push_back(num);

	int sum = 0;
	bool m_flag = false;
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == -1)
			m_flag = true;
		else
		{
			if (m_flag == false)
				sum += vec[i];
			else 
				sum -= vec[i];
		}
	}
	printf("%d\n", sum);

	return 0;
}
#endif

#if 0
int data[1000];

int main(void)
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
		scanf("%d", &data[i]);

	sort(data, data + num);

	int sum = 0;
	int ret = 0;
	for (int i = 0; i < num; i++)
	{
		sum = sum + data[i];
		ret = ret + sum;
	}

	printf("%d\n", ret);

	return 0;
}
#endif

#if 0
pair<int, int> t_data[100000];

int main(void)
{
	int num;
	
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d %d", &t_data[i].second, &t_data[i].first);

	sort(t_data, t_data + num);

	int cnt = 0;
	int end = 0;
	for (int i = 0; i < num; i++)
	{
		if (end <= t_data[i].second)
		{
			cnt++;
			end = t_data[i].first;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
#endif

#if 0
int cost[10];

int main(void)
{
	int n;
	int k;
	int i;

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &cost[i]);

	int cnt = 0;
	for (i = n - 1; i >= 0; i--)
	{
		while (k >= cost[i])
		{
			cnt++;
			k -= cost[i];
		}
	}

	printf("%d\n", cnt);

	return 0;
}
#endif
