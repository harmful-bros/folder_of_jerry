#include <iostream>
#include <deque>
//#include <algorithm>

#include <cstdio>
#include <cmath>
//#include <cstdlib>
//#include <cstring>

using namespace std;

deque<int> deq;

int main(void)
{
	int all;
	int pop;

	scanf("%d %d", &all, &pop);

	for (int i = 0; i < all; i++)
		deq.push_back(i + 1);

	int cnt = 0;
	int front;
	int f_gap;
	int b_gap;
	int data;
	int cpy;
	for (int i = 0; i < pop; i++)
	{
		scanf("%d", &data);
		front = deq.front();

		if (front == data)
			deq.pop_front();
		else
		{
			f_gap = 0;
			for (auto temp : deq)
			{
				if (data == temp)
					break;
				f_gap++;
			}
			b_gap = deq.size() - f_gap;

			if (f_gap > b_gap)
			{
				while (deq.front() != data)
				{
					cpy = deq.back();
					deq.pop_back();
					deq.push_front(cpy);
					cnt++;
				}
				deq.pop_front();
			}
			else
			{
				while (deq.front() != data)
				{
					cpy = deq.front();
					deq.pop_front();
					deq.push_back(cpy);
					cnt++;
				}
				deq.pop_front();
			}
		}
	}
	printf("%d\n", cnt);

	return 0;
}

#if 0
char order[100001];

int main(void)
{
	int t_case;

	scanf("%d", &t_case);
	for (int i = 0; i < t_case; i++)
	{
		int n_case;
		scanf("%s %d\n[", order, &n_case);

		int ch;
		int num = 0;
		deque<int> deq;
		while (1)
		{
			ch = getchar();

			if (ch >= '0' && ch <= '9')
				num = (num * 10) + (ch - '0');
			else
			{
				if (num > 0)
					deq.push_back(num);
				num = 0;

				if (ch == ']')
					break;
			}
		}

		bool flag = true;
		bool toggle = false;
		int len = strlen(order);
		for (int j = 0; j < len; j++)
		{
			if (order[j] == 'R')
				toggle ^= 1;
			else if (order[j] == 'D')
			{
				if (deq.empty())
				{
					flag = false;
					break;
				}

				if (toggle == true)
					deq.pop_back();
				else
					deq.pop_front();
			}
		}

		if (flag == false)
			printf("error\n");
		else
		{
			printf("[");
			if (toggle == true)
				reverse(deq.begin(), deq.end());
			
			int size = (int)deq.size();
			for (int j = 0; j < size; j++)
			{
				printf("%d", deq[j]);
				if (j < size - 1)
					printf(",");
			}
			printf("]\n");
		}
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;

	cin >> num;
	cin.ignore(100, '\n');

	for (int i = 0; i < num; i++)
	{
		getline(cin, str, '\n');

		if (str.find("push_front ", 0) != string::npos)
			deq.push_front(atoi(&str[11]));
		else if (str.find("push_back ", 0) != string::npos)
			deq.push_back(atoi(&str[10]));
		else if (str.find("size", 0) != string::npos)
			cout << deq.size() << endl;
		else if (str.find("empty", 0) != string::npos)
		{
			if (deq.empty())
				cout << "1";
			else
				cout << "0";
			cout << endl;
		}
		else if (str.find("pop_front", 0) != string::npos)
		{
			if (deq.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << deq.front() << endl;
				deq.pop_front();
			}
		}
		else if (str.find("pop_back", 0) != string::npos)
		{
			if (deq.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << deq.back() << endl;
				deq.pop_back();
			}
		}
		else if (str.find("front", 0) != string::npos)
		{
			if (deq.empty())
				cout << "-1" << endl;
			else
				cout << deq.front() << endl;
		}
		else if (str.find("back", 0) != string::npos)
		{
			if (deq.empty())
				cout << "-1" << endl;
			else
				cout << deq.back() << endl;
		}
	}
}
#endif


