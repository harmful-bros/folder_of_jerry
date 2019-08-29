#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");

	return 0;
}

#if 0			// greedy, 1783, 병든 나이트

// height에 따라서 경우의 수를 나눈 후 계산 규칙 찾기
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

#if 0			// greedy, 10610, 30

// 2*3*5 = 30 이므로 이를 하나씩 포함 하는지 체크,,
// 2*5 = 10 이므로 0이 있는지를 확인
// 3의 배수들은 그 자릿수의 합이 3으로 나눠떨어지므로 %3 == 0인지 확인

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

#if 0			// greedy, 2875, 대회 or 인턴

// 참가 조건을 수식화 후 코드화

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

#if 0			// greedy, 1744, 수 묶기
vector<int> pos;
vector<int> neg;

// 최대값 끼리 묶으면 커짐
// 음수 끼리 묶으면 +로 바뀜(곱하기)
// 남은 음수는 0이랑 묶기
// 1은 묶지 말고 남겨 두기 -> 곱하는 것 보단 더하는게 나으므로,,

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

#if 0			// greedy, 1541, 잃어버린 괄호
vector<int> vec;

// - 뒤의 값은 +라도 괄호로 묶어서 -로 만들 수 있으므로,,
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

#if 0			// greedy, 11399, ATM
int data[1000];

// 대기 시간이 짦은 순서일 때가 가장 적은 합이 되므로,,
// 정렬 한다.

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

#if 0			// greedy, 1931, 회의실 배정
pair<int, int> t_data[100000];

// 끝나는 시간이 짦은 순서로 정렬한다.
// 그러면 겹치는 회의를 제외하고 가장 많이 회의를 잡을 수 있는 경우가 됨.

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
