#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(void)
{
	int all;
	int start;

	vector<int> que;

	scanf("%d %d", &all, &start);
	for (int i = 1; i <= all; i++)
		que.push_back(i);

//	printf("%d\n", que.at(que.begin() + 2));
#if 0
	while (!que.empty())
	{
			
	}
#endif

	return 0;
}

#if 0
int main(void)
{
	int num;
	char str[32];

	queue<int> que;

	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++)
	{
		fgets(str, sizeof(str), stdin);
		str[strlen(str) - 1] = '\0';

		if (strstr(str, "push "))
			que.push(atoi(&str[5]));
		else if (strstr(str, "pop"))
		{
			if (!que.empty())
			{
				printf("%d\n", que.front());
				que.pop();
			}
			else
				printf("-1\n");
		}
		else if (strstr(str, "size"))
			printf("%d\n", (int)que.size());
		else if (strstr(str, "empty"))
			printf("%d\n", que.empty());
		else if (strstr(str, "front"))
			que.empty() ? 
				printf("-1\n") : printf("%d\n", que.front());
		else if (strstr(str, "back"))
			que.empty() ? 
				printf("-1\n") : printf("%d\n", que.back());
	}

	return 0;
}
#endif
