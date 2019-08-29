#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
//#include <cstring>
//#include <algorithm>
#include <vector>

using namespace std;

static inline bool _push_in_stack(stack<unsigned int> &st, 
		unsigned char e1, unsigned char e2, unsigned int val)
{
	unsigned int top;
	unsigned int ret = 0;

	while (!st.empty())
	{
		top = st.top();

		if (top == e1)
			goto error;
		else if (top == e2)
		{
			st.pop();
			ret *= val;
			st.push(ret);
			break;
		}
		else
		{
			ret += top;
			st.pop();
		}
	}
	return true;

error :
	return false;
}

int main(void)
{
	string str;
	getline(cin, str);

	int idx = 0;
	unsigned int data = 0;
	stack<unsigned int> st;
	while (str[idx])
	{
		if (str[idx] == '(' || str[idx] == '[')	
			st.push(str[idx]);
		else if (str[idx] == ')')
		{
			if (st.top() == '(')
			{
				st.pop();
				st.push(2);
			}
			else
			{
				if (_push_in_stack(st, '[', '(', 2) == false)
					goto error;
			}
		}
		else if (str[idx] == ']')
		{
			if (st.top() == '[')
			{
				st.pop();
				st.push(3);
			}
			else
			{
				if (_push_in_stack(st, '(', '[', 3) == false)
					goto error;
			}
		}
		idx++;
	}

	while (!st.empty())
	{
		if (st.top() == '(' || st.top() == ')' || 
				st.top() == '[' || st.top() == ']')
			goto error;

		data += st.top();
		st.pop();
	}
	printf("%u\n", data);

	return 0;

error :
	printf("0\n");
	return -1;
}

#if 0
using namespace std;

int main(void)
{
	int num;
	scanf("%d", &num);

	int data[num];
	for (int i = 0; i < num; i++)
		scanf("%d", &data[i]);

	int idx = 0;
	stack<int> st;
	vector<char> vec;
	for (int i = 1; i <= num; i++)
	{
		st.push(i);
		vec.push_back('+');

		while (!st.empty() && st.top() == data[idx])
		{
			idx++;
			st.pop();
			vec.push_back('-');
		}
	}

	if (!st.empty())
		printf("NO\n");
	else
	{
		for (unsigned int i = 0; i < vec.size(); i++)
			printf("%c\n", vec[i]);
	}

	return 0;
}
#endif

#if 0
int data[500000];

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

#if 0
int data[100000];

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

#if 0
char str[1000001];
bool del[1000001];
char bomb[37];

int main(void)
{
	scanf("%s", str);
	scanf("%s", bomb);

	int str_len = strlen(str);
	int bomb_len = strlen(bomb);

	if (bomb_len == 1)
	{
		for (int i = 0; i < str_len; i++)
		{
			if (str[i] == bomb[0])
				del[i] = true;
		}
	}
	else
	{
		stack<pair<int, int>> st;
		for (int i = 0; i < str_len; i++)
		{
			if (str[i] == bomb[0])
				st.push({i, 0});
			else if (!st.empty())
			{
				int idx = st.top().second + 1;
				if (str[i] == bomb[idx])
				{
					st.push({i, idx});
					if (st.top().second == bomb_len - 1)
					{
						for (int j = 0; j < bomb_len; j++)
						{
							idx = st.top().first;
							del[idx] = true;
							st.pop();
						}
					}
				}
				else
				{
					while (!st.empty())
						st.pop();
				}
			}
		}
	}

	bool flag = false;
	for (int i = 0; i < str_len; i++)
	{
		if (del[i] == true)
			continue;

		flag = true;
		printf("%c", str[i]);
	}

	(flag == false) ? printf("FRULA\n") : printf("\n");

	return 0;
}
#endif
#if 0
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

#if 0
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

#if 0

#define JSLEE_DEBUG
stack<int> st;
int num[100001];

int main(void)
{
	int t_case;
	scanf("%d", &t_case);
	for (int i = 1; i <= t_case; i++)
		scanf("%d", &num[i]);

	int idx = 1;
	int data = 1;

//	int i = 1;
//	for (int i = 1; i <= t_case; i++, idx++)
	for (int i = 1; ; )
	{
		while (i < num[idx])
		{
#ifdef JSLEE_DEBUG
			printf("@@ %d %d %d\n", i, idx, num[idx]);
#else
			printf("+\n");
#endif
			st.push(i);
			i++;
			data = i;
		}

		while (data > num[idx])
		{
			if (st.empty())
			{
				printf("-1\n");
				break;
			}

			data = st.top();
#ifdef JSLEE_DEBUG
//			printf("## %d %d %d\n", data, idx, num[idx]);
#else
			printf("-\n");
#endif
			st.pop();
		}

		if (data == num[idx])
		{
			printf("$$ %d %d %d %d\n", i, idx, num[idx], data);

//			printf("+\n");
			st.push(data);

//			printf("-\n");
			st.pop();

			if (idx == t_case)
				break;

			i++;
			idx++;
//			printf("^^^^ %d %d %d %d\n", i, idx, num[idx], data);
		}
	}

	return 0;
}
#endif

#if 0
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

#if 0
int main(void)
{
	int num;
	string str;
	stack<int> st;
	ssize_t pos;

	cin >> num;
	cin.ignore(100, '\n');

	for (int i = 0; i < num; i++)
	{
		getline(cin, str, '\n');
		
		if ((pos = str.find("push ", 0)) != string::npos)
			st.push(atoi(&str[5]));
		else if ((pos = str.find("size", 0)) != string::npos)
			cout << st.size() << endl;
		else if ((pos = str.find("top", 0)) != string::npos)
			cout << st.top() << endl;
		else if ((pos = str.find("empty", 0)) != string::npos)
		{
			if (st.empty())
				cout << "1";
			else
				cout << "0";
			cout << endl;
		}
		else if ((pos = str.find("pop", 0)) != string::npos)
		{
			if (st.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << st.top() << endl;
				st.pop();
			}
		}
	}

	return 0;
}
#endif
