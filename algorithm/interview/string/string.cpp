#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");
	return 0;
}

#if 0			// string 11656 접미사 배열
string input;
string str[1001];

int main(void)
{
	getline(cin, input);

	// to_string, stoi

	// 접미사
	for (unsigned int i = 0; i < input.size(); i++)
		str[i] = input.substr(i, input.size());

	sort(str, str + input.size());

	for (unsigned int i = 0; i < input.size(); i++)
		cout << str[i] << endl;

	return 0;
}
#endif

#if 0			// string 11655 ROT13
string str;

int main(void)
{
	char lower[] = "nopqrstuvwxyzabcdefghijklm";
	char upper[] = "NOPQRSTUVWXYZABCDEFGHIJKLM";

	getline(cin, str);

	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (isupper(str[i]))
			printf("%c", upper[str[i] - 'A']);
		else if (islower(str[i]))
			printf("%c", lower[str[i] - 'a']);
		else 
			printf("%c", str[i]);
	}
	printf("\n");

	return 0;
}
#endif

#if 0			// string, 9935, 문자열 폭발
char str[1000001];
bool del[1000001];
char bomb[37];

// 해당 하는 문자열을 제거하기 위해 스택의 성질을 이용한다.

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
