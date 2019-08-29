#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(void)
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		string str;
		stack<int> st_r;
		stack<int> st_l;

		cin >> str;
		for (unsigned int j = 0; j < str.size(); j++)
		{
			if (str[j] == '<')
			{
				if (!st_r.empty())
				{
					st_l.push(st_r.top());
					st_r.pop();
				}
			}
			else if (str[j] == '>')
			{
				if (!st_l.empty())
				{
					st_r.push(st_l.top());
					st_l.pop();
				}
			}
			else if (str[j] == '-')
			{
				if (!st_r.empty())
					st_r.pop();
			}
			else
				st_r.push(str[j]);
		}

		while (!st_r.empty())
		{
			st_l.push(st_r.top());
			st_r.pop();
		}

		while (!st_l.empty())
		{
			printf("%c", st_l.top());
			st_l.pop();
		}
		printf("\n");
	}

	return 0;
}
