#include <iostream>

#include <cstdio>
#include <cstring>

#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");
	return 0;
}

#if 0			// heap, 1927, 최소 힙

// 우선순위 큐의 특징을 이용한다.
// 최소 힙은 저장할 때 음수로 저장하면 된다.
int main(void)
{
	int num;
	scanf("%d", &num);

	int data;
	priority_queue<int> pq;
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		if (data == 0)
		{
			if (!pq.empty())
			{
				printf("%d\n", -pq.top());
				pq.pop();
			}
			else
				printf("0\n");
		}
		else
			pq.push(-data);
	}

	return 0;
}
#endif

#if 0			// stack, 3015, 오아시스 재결합
int data[500000];

// 키 순서를 비교 하면서 볼 수 있는 경우와 볼 수 없는 경우를 각각 확인 후,
// 스택에 해당 내역을 남겨서 비교하는 방법

int main(void)
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
		scanf("%d", &data[i]);

	long long ret = 0;
	stack<pair<int, int>> st;
	for (int i = 0; i < num; i++)
	{
		pair<int, int> pa = {data[i], 1};
		while (!st.empty())
		{
			if (st.top().first <= data[i])
			{
				ret += st.top().second;
				if (st.top().first == data[i])
					pa.second += st.top().second;
				st.pop();					
			}
			else
				break;
		}

		if (!st.empty())
			ret++;
		st.push(pa);
	}

	printf("%lld\n", ret);

	return 0;
}
#endif

#if 0			// stack, 6549, 히스토그램에서 가장 큰 직사각형
int data[100000];

// 스택에 값을 넣고 빼고를 활용해 가장 큰 넓이만을 남기고 O(N)만에 해결 방법

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

		stack<int> st;

		int height;
		int width;

		long long temp;
		long long ret = 0;

		for (int i = 0; i < num; i++)
		{
			while (!st.empty() && data[st.top()] > data[i])
			{
				height = data[st.top()];
				st.pop();

				width = i;
				if (!st.empty())
					width = i - st.top() - 1;

				temp = (long long)height * (long long)width;
				if (ret < temp)
					ret = temp;				
			}
			st.push(i);
		}

		while (!st.empty())
		{
			height = data[st.top()];
			st.pop();

			width = num;
			if (!st.empty())
				width = num - st.top() - 1;

			temp = (long long)height * (long long)width;
			if (ret < temp)
				ret = temp;				
		}

		printf("%lld\n", ret);
	}

	return 0;
}
#endif

#if 0			// stack 1406 에디터
string str;
stack<char> left_st;
stack<char> right_st;

int main(void)
{
	getline(cin, str);
	int len = str.size();
	for (int i = 0; i < len; i++)
		left_st.push((char)str[i]);

	int n_case;
	scanf("%d\n", &n_case);

	for (int i = 0; i < n_case; i++)
	{
		getline(cin, str);
		if (str[0] == 'P')
			left_st.push((char)str[2]);
		else if (str[0] == 'L')
		{
			if (!left_st.empty())
			{
				right_st.push(left_st.top());
				left_st.pop();
			}
		}
		else if (str[0] == 'D')
		{
			if (!right_st.empty())
			{
				left_st.push(right_st.top());
				right_st.pop();
			}
		}
		else if (str[0] == 'B')
		{
			if (!left_st.empty())
				left_st.pop();
		}
	}

	while (!left_st.empty())
	{
		right_st.push(left_st.top());
		left_st.pop();
	}

	while (!right_st.empty())
	{
		printf("%c", right_st.top());
		right_st.pop();
	}
	printf("\n");

	return 0;
}
#endif

#if 0			// stack 10799 쇠막대기
string str;
stack<int> st;

int main(void)
{
	getline(cin, str);
	int len = str.size();
	int cnt = 0;
	int sum = 0;

	int idx;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
		{
			st.push(i);
			cnt++;
		}
		else
		{
			idx = st.top();
			st.pop();
			cnt--;

			if (idx + 1 == i)
				sum += cnt;
			else
				sum += 1;
		}
	}
	printf("%d\n", sum);

	return 0;
}
#endif

#if 0			// stack 9012 괄호
int main(void)
{
	int num;
	char str[64];

	int cnt;
	int len;
	stack<int> stack;


	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++)
	{
		fgets(str, sizeof(str), stdin);
		len = strlen(str) - 1;
		str[len] = '\0';

		cnt = 0;
		for (int j = 0; j < len; j++)
		{
			if (str[j] == '(')
			{
				cnt++;
				stack.push(1);
			}
			else 
			{
				cnt--;
				if (cnt < 0)
					break;

				stack.pop();
			}
		}

		(cnt != 0) ? printf("NO\n") : printf("YES\n");

		while (!stack.empty())
			stack.pop();
	}

	return 0;
}
#endif
