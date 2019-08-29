#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");

	return 0;
}

#if 0
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

#if 0
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
				printf("%d\n", pq.top());
				pq.pop();
			}
			else
				printf("0\n");
		}
		else
			pq.push(data);
	}

	return 0;
}
#endif
