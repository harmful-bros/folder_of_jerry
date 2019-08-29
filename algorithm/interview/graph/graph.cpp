#include <iostream>
#include <queue>
#include <stack>
#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");

	return 0;
}

#if 0			// graph, 2178, 미로 탐색
int maze[101][101];
queue<pair<int, int>> que;

int main(void)
{
	int row;
	int col;

	scanf("%d %d", &col, &row);
	for (int i = 1; i <= col; i++)
		for (int j = 1; j <= row; j++)
			scanf("%1d", &maze[i][j]);

	int y;
	int x;

	int y_new;
	int x_new;

	int cordi_y[] = {-1, 1, 0, 0};
	int cordi_x[] = {0, 0, -1, 1};

	que.push({1, 1});
	maze[1][1] = 2;

	// 배열을 하나 더 써서 다음 배열 값 = 이전 배열 값 + 1 이용
	// 최저 경로 경우의 수를 출력
	while (!que.empty())
	{
		y = que.front().first;
		x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			y_new = y + cordi_y[i];
			x_new = x + cordi_x[i];

			if ((y_new >= 1 && y_new <= col) &&
					(x_new >= 1 && x_new <= row))
			{
				if (maze[y_new][x_new] == 1) 
				{
					que.push({y_new, x_new});
					maze[y_new][x_new] = maze[y][x] + 1;
				}
			}
		}
	}

	printf("%d\n", maze[col][row] - 1);

	return 0;
}
#endif

#if 0			// graph, 2667, 단지번호붙이기
int maze[26][26];
bool flag[26][26];
int cnt_table[26];

queue<pair<int, int>> que;

int main(void)
{
	int total;

	scanf("%d", &total);

	for (int i = 0; i < total; i++)
		for (int j = 0; j < total; j++)
			scanf("%1d", &maze[i][j]);

	int room_cnt = 0;
	int total_cnt = 0;

	int y;
	int x;

	int y_new;
	int x_new;

	int cordi_y[] = {-1, 1, 0, 0};
	int cordi_x[] = {0, 0, -1, 1};

	// 전체 검색
	// 전형적인 좌표 이용한 미로 이동 -> BFS를 쓸 것!!

	for (int i = 0; i < total; i++)
	{
		for (int j = 0; j < total; j++)
		{
			if (maze[i][j] == 1 && flag[i][j] == false)
			{
				que.push({i, j});
				flag[i][j] = true;

				while (!que.empty())
				{
					room_cnt++;

					y = que.front().first;
					x = que.front().second;
					que.pop();

					for (int k = 0; k < 4; k++)
					{
						y_new = y + cordi_y[k];
						x_new = x + cordi_x[k];

						if (maze[y_new][x_new] == 1 &&
								flag[y_new][x_new] == false)
						{
							que.push({y_new, x_new});
							flag[y_new][x_new] = true;
						}
					}

				}

				cnt_table[total_cnt++] = room_cnt;
				room_cnt = 0;
			}
		}
	}

	sort(cnt_table, cnt_table + total_cnt);

	printf("%d\n", total_cnt);
	for (int i = 0; i < total_cnt; i++)
		printf("%d\n", cnt_table[i]);

	return 0;
}
#endif

#if 0			// graph, 10451, 순열 사이클
vector<int> vec[1001];
stack<int> st;
bool flag[1001];

int main(void)
{
	int t_case;
	int n_case;

	int num;
	int data;
	int idx;
	int size;

	int cnt = 0;

	scanf("%d", &t_case);
	for (int i = 0; i < t_case; i++)
	{
		memset(vec, 0x00, sizeof(vec));
		memset(flag, 0x00, sizeof(flag));

		scanf("%d", &n_case);
		for (int j = 1; j <= n_case; j++)
		{
			scanf("%d", &num);
			vec[j].push_back(num);
			vec[num].push_back(j);
		}

		// 전체를 돌리면서 방문하지 않은 정점을 기준으로 DFS 한다.
		// DFS는 재귀 대신 반복문과 스택을 이용해 구현한다.
		for (int j = 1; j <= n_case; j++)
		{
			if (flag[j] == false)
			{
				st.push(j);
				flag[j] = true;
				cnt++;

				while (!st.empty())
				{
					data = st.top();
					st.pop();

					size = vec[data].size();
					for (int k = 0; k < size; k++)
					{
						idx = vec[data][k];
						if (flag[idx] == false)
						{
							st.push(idx);
							flag[idx] = true;
						}
					}
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}

	return 0;
}
#endif

#if 0			// graph, 1260, DFS와 BFS

// 인접 리스트 사용시 시간 복잡도 O(v + e)
int graph[1001][1001];
bool flag[1001];
int cur_index[1001];

stack<int> st;
queue<int> que;

static int _depth_first_search(int node, int start)
{
	printf("%d ", start);
	flag[start] = true;
	for (int i = 1; i <= node; i++)
	{
		if (graph[start][i] == 1 && flag[i] == false)		
			_depth_first_search(node, i);
	}

	return 0;
}

static int _breadth_first_search(int node, int start)
{
	int data;

	flag[start] = true;
	que.push(start);
	printf("%d ", start);

	while (!que.empty())
	{
		data = que.front();
		que.pop();

		for (int i = 1; i <= node; i++)
		{
			if (graph[data][i] == 1 && flag[i] == false)
			{
				flag[i] = true;
				que.push(i);
				printf("%d ", i);
			}
		}
	}
	printf("\n");

	return 0;
}

int main(void)
{
	int node;
	int edge;
	int start;

	int s_idx;
	int e_idx;

	scanf("%d %d %d", &node, &edge, &start);
	for (int i = 1; i <= edge; i++)
	{
		scanf("%d %d", &s_idx, &e_idx);
		graph[s_idx][e_idx] = 1;
		graph[e_idx][s_idx] = 1;
	}

	/* DFS */
	_depth_first_search(node, start);
	printf("\n");

	/* init */
	memset((void *)flag, false, sizeof(flag));

	/* BFS */
	_breadth_first_search(node, start);

	return 0;
}
#endif
