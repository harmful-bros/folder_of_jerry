#include <iostream>
#include <vector>
#include <queue>

#include <cstdio>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");

	return 0;
}

#if 0
queue<int> que;
vector<int> manage[100001];

int parent[100001];

int main(void)
{
	int t_case;

	int first;
	int second;

	int idx;

	scanf("%d", &t_case);
	for (int i = 0; i < t_case; i++)
	{
		scanf("%d %d", &first, &second);
		manage[first].push_back(second);
		manage[second].push_back(first);
	}

	que.push(1);
	while (!que.empty())
	{
		idx = que.front();
		que.pop();

		for (int i = 0; i < (int)manage[idx].size(); i++)
		{
			if (parent[manage[idx].at(i)] == 0)
			{
				que.push(manage[idx].at(i));
				parent[manage[idx].at(i)] = idx;
			}
		}
	}

	for (int i = 2; i <= t_case; i++)
		printf("%d\n", parent[i]);

	return 0;
}
#endif

#if 0
int tree[26][2];

static int _pre_order(int idx)
{
	printf("%c", idx + 'A');

	if (tree[idx][0])
		_pre_order(tree[idx][0]);

	if (tree[idx][1])
		_pre_order(tree[idx][1]);

	return 0;
}

static int _in_order(int idx)
{
	if (tree[idx][0])
		_in_order(tree[idx][0]);

	printf("%c", idx + 'A');

	if (tree[idx][1])
		_in_order(tree[idx][1]);

	return 0;
}

static int _post_order(int idx)
{
	if (tree[idx][0])
		_post_order(tree[idx][0]);

	if (tree[idx][1])
		_post_order(tree[idx][1]);

	printf("%c", idx + 'A');

	return 0;
}

int main(void)
{
	int t_case;

	char input[3];

	scanf("%d", &t_case);
	for (int i = 0; i < t_case; i++)
	{
		scanf(" %c", &input[0]);
		scanf(" %c", &input[1]);
		scanf(" %c", &input[2]);

		if (input[1] != '.')
			tree[input[0] - 'A'][0] = input[1] - 'A';

		if (input[2] != '.')
			tree[input[0] - 'A'][1] = input[2] - 'A';
	}

	_pre_order(0);
	printf("\n");

	_in_order(0);
	printf("\n");

	_post_order(0);
	printf("\n");
		
	return 0;
}
#endif
