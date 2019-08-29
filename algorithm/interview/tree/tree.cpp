#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#if 1
int main(void)
{
	printf("leejaeseong\n");

	return 0;
}
#endif

#if 0			// tree, 1167, 트리의 지름
bool flag_f[100001];
bool flag_s[100001];
int root_cnt[100001];

stack<pair<int,int>> st;
vector<pair<int, int>> tree[100001];

static inline int _depth_first_search(int start_idx, bool *pflag, int *pmax);


// DFS를 이용해 루트레이서 제일 먼 노드를 검색
// 그 노드를 기준으로 다시 제일 먼 노드를 검색하면 트리의 지름이 된다.
static inline int _depth_first_search(int start_idx, bool *pflag, int *pmax)
{
	int first_size;
	pair<int, int> bt;

	int check_idx;
	int check_size;

	int end_idx = -1;

	pflag[start_idx] = true;
	first_size = tree[start_idx].size();
	for (int j = 0; j < first_size; j++)
	{
		st.push(make_pair(tree[start_idx][j].first, tree[start_idx][j].second));
		while (!st.empty())
		{
			bt = st.top();
			st.pop();

			if (*pmax < bt.second)
			{
				*pmax = bt.second;
				end_idx = bt.first;
			}

			pflag[bt.first] = true;
			check_size = tree[bt.first].size();
			for (int k = 0; k < check_size; k++)
			{
				check_idx = tree[bt.first][k].first;
				if (pflag[check_idx] == false)
				{
					pflag[check_idx] = true;
					st.push(make_pair(check_idx,
								bt.second + tree[bt.first][k].second));
				}
			}
		}
	}

	return end_idx;
}

int main(void)
{
	int t_case;

	int s_node;
	int e_node;
	int dist;

	scanf("%d", &t_case);
	for (int i = 0; i < t_case; i++)
	{
		scanf("%d", &s_node);
		while (1)
		{
			scanf("%d", &e_node);
			if (e_node == -1)
				break;

			scanf("%d", &dist);
			tree[s_node].push_back(make_pair(e_node, dist));
		}
	}

	int idx;
	int max = 0;

	idx = _depth_first_search(1, flag_f, &max);
	if (idx < 0)
		goto error;

	max = 0;
	if (_depth_first_search(idx, flag_s, &max) < 0)
		goto error;

	printf("%d\n", max);

	return 0;

error :
	return -1;
}
#endif

#if 0			// tree, 11725, 트리의 부모 찾기
queue<int> que;
vector<int> manage[100001];

// BFS를 하면서 que에 push하기 전에 부모를 남기는 방식으로 계산
// 최종적으로 모든 배열을 출력.
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
			if (parent[manage[idx][i]] == 0)
			{
				que.push(manage[idx][i]);
				parent[manage[idx][i]] = idx;
			}
		}
	}

	for (int i = 2; i <= t_case; i++)
		printf("%d\n", parent[i]);

	return 0;
}
#endif

#if 0			// tree, 1991, 트리 순회
int tree[26][2];


// 재귀 함수를 이용 print를 root로 놓고 계산한다.
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
