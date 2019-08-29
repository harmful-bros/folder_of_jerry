#include <iostream>
#include <cstdio>
//#include <cstring>
#include <queue>
//#include <stack>
//#include <vector>

//#define JSLEE_DEBUG

using namespace std;


int main(void)
{
	int cnt;
	scanf("%d", &cnt);

	int y_max;
	int x_max;
	int num;

	int y;
	int x;
	int new_y;
	int new_x;

	const int cordi_y[] = {-1, 1, 0, 0};
	const int cordi_x[] = {0, 0, -1, 1};

	for (int i = 0; i < cnt; i++)
	{
		int data[50][50] = {{0,}, };
		int flag[50][50] = {{0,}, };
		queue<pair<int, int>> que;

		scanf("%d %d %d", &y_max, &x_max, &num);
		for (int j = 0; j < num; j++)
		{
			scanf("%d %d", &y, &x);
			data[y][x] = 1;
		}

		int cnt = 1;
		for (int k = 0; k < y_max; k++)
		{
			for (int l = 0; l < x_max; l++)
			{
				if (data[k][l] == 1 && flag[k][l] == 0)
				{
					flag[k][l] = cnt;
					que.push({k, l});

					while (!que.empty())
					{
						y = que.front().first;
						x = que.front().second;
						que.pop();

						for (int n = 0; n < 4; n++)
						{
							new_y = y + cordi_y[n];
							new_x = x + cordi_x[n];

							if (data[new_y][new_x] == 1 &&
							    flag[new_y][new_x] == 0)
							{
								que.push({new_y, new_x});
								flag[new_y][new_x] = cnt;
							}
						}
					}
					cnt++;
				}
			}
		}
		printf("%d\n", cnt - 1);
	}

	return 0;
}

#if 0
int data[100][100];
bool flag[100][100];
queue<pair<int, int>> que;

int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;

	for (i = 0; i < num; i++)
		for (j = 0; j < num; j++)
			scanf("%d", &data[i][j]);

	int y;
	int x;
	int new_y;
	int new_x;
	unsigned long long cnt = 0;

	que.push({0, 0});
	flag[0][0] = true;

	while (!que.empty())
	{
		y = que.front().first;
		x = que.front().second;

		new_y = y + data[y][x];
		new_x = x + data[y][x];

		que.pop();

		if (new_y < num)
		{
			if (data[new_y][x] == 0)
				cnt++;
			else
				que.push({new_y, x});
		}

		if (new_x < num)
		{
			if (data[y][new_x] == 0)
				cnt++;
			else
				que.push({y, new_x});
		}
	}

	printf("%llu\n", cnt);

	return 0;
}
#endif



#if 0
int data[101][101];
int flag[101][101];
int cost[101][101];

queue<pair<int, int>> que;

int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;
	int k;

	const int cordi_y[] = {-1, 1, 0, 0};
	const int cordi_x[] = {0, 0, -1, 1};

	for (i = 0; i < num; i++)
		for (j = 0; j < num; j++)
			scanf("%d", &data[i][j]);

	int y;
	int x;
	int new_y;
	int new_x;

	int cnt = 1;

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (flag[i][j] == false && data[i][j] == 1)
			{
				que.push({i, j});
				flag[i][j] = cnt;

				while (!que.empty())
				{
					y = que.front().first;
					x = que.front().second;
					que.pop();

					for (k = 0; k < 4; k++)
					{
						new_y = y + cordi_y[k];
						new_x = x + cordi_x[k];

						if (new_y < 0 || new_x < 0)
							continue;

						if (new_y >= num || new_x >= num)
							continue;

						if (flag[new_y][new_x] == false &&
						    data[new_y][new_x] == 1)
						{
							flag[new_y][new_x] = cnt;
							que.push({new_y, new_x});
						}
					}
				}
				cnt++;
			}
		}
	}

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			cost[i][j] = -1;
			if (data[i][j] == 1)
			{
				cost[i][j] = 0;
				que.push({i, j});
			}
		}
	}

	while (!que.empty())
	{
		y = que.front().first;
		x = que.front().second;
		que.pop();

		for (k = 0; k < 4; k++)
		{
			new_y = y + cordi_y[k];
			new_x = x + cordi_x[k];

			if (new_y < 0 || new_x < 0)
				continue;

			if (new_y >= num || new_x >= num)
				continue;

			if (cost[new_y][new_x] == -1)
			{
				cost[new_y][new_x] = cost[y][x] + 1;
				flag[new_y][new_x] = flag[y][x];
				que.push({new_y, new_x});
			}
		}
	}
	
#ifdef JSLEE_DEBUG
	printf("\n");
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			printf("%d ", flag[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			printf("%d ", cost[i][j]);
		}
		printf("\n");
	}
	printf("\n");
#endif

	int min = -1;
	for (i = 0; i < num ; i++)
	{
		for (j = 0; j < num; j++)
		{
			for (k = 0; k < 4; k++)
			{
				new_y = i + cordi_y[k];
				new_x = j + cordi_x[k];

				if (new_y < 0 || new_x < 0)
					continue;

				if (new_y >= num || new_x >= num)
					continue;
				
				if (flag[i][j] != flag[new_y][new_x])
				{
					if (min == -1 || min > cost[i][j] + cost[new_y][new_x])
					{
#ifdef JSLEE_DEBUG
						printf("@@@@ %d %d %d %d\n", i, j, new_y, new_x);
#endif
						min = cost[i][j] + cost[new_y][new_x];
					}
				}
			}
		}
	}

	printf("%d\n", min);

	return 0;
}
#endif

#if 0
int data[51][51];
bool flag[51][51];

int main(void)
{
	int w;
	int h;

	const int cordi_y[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	const int cordi_x[] = {0, 1, 1, 1, 0, -1, -1, -1};

	while (1)
	{
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;

		int i;
		int j;
		for (i = 1; i <= h; i++)
		{
			for (j = 1; j <= w; j++)
			{
				scanf("%d", &data[i][j]);
				flag[i][j] = false;
			}
		}

		int y;
		int x;
		int new_y;
		int new_x;

		int cnt = 0;
		queue<pair<int, int>> que;

		for (i = 1; i <= h; i++)
		{
			for (j = 1; j <= w; j++)
			{
				if (flag[i][j] == false && data[i][j] == 1)
				{
					flag[i][j] = true;
					que.push({i, j});

					cnt++;
					while (!que.empty())
					{
						y = que.front().first;
						x = que.front().second;
						que.pop();

						for (int k = 0; k < 8; k++)
						{
							new_y = y + cordi_y[k];
							new_x = x + cordi_x[k];

							if (new_y < 0 || new_x < 0)
								continue;

							if (new_y > h || new_x > w)
								continue;
							
							if (flag[new_y][new_x] == false &&
							    data[new_y][new_x] == 1)
							{
								flag[new_y][new_x] = true;
								que.push({new_y, new_x});
							}
						}
					}
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}
#endif

#if 0
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

#if 0
bool flag[101];
vector<int> data[101];
stack<int> st;

int main(void)
{


	int total;
	int connect;

	int first;
	int second;

	scanf("%d", &total);
	scanf("%d", &connect);
	for (int i = 0; i < connect; i++)
	{
		scanf("%d %d", &first, &second);
		data[first].push_back(second);
	}

	int idx;
	int size;
	int flag_idx;

	st.push(1);
	flag[1] = true;
	while (!st.empty())
	{
		idx = st.top();
		st.pop();

		printf("%d\n", idx);
		
		size = data[idx].size();
		for (int i = 0; i < size; i++)
		{
			flag_idx = data[idx][i];
			if (flag[flag_idx] == false)
			{
				st.push(flag_idx);
				flag[flag_idx] = true;
			}
		}

	}

	return 0;
}
#endif

#if 0
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

#if 0
int box[101][101][101];
int check[101][101][101];
queue <pair<pair<int, int>, int>> que;

int main(void)
{
	int row;
	int col;
	int height;

	scanf("%d %d %d", &row, &col, &height);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < row; k++)
			{
				scanf("%d", &box[i][j][k]);
				check[i][j][k] = box[i][j][k];
				if (box[i][j][k] == 1)
					que.push({{i, j}, k});
			}
		}
	}

	int z;
	int y;
	int x;

	int z_new;
	int y_new;
	int x_new;

	int cordi_z[] = {0, 0, 0, 0, -1, 1};
	int cordi_y[] = {-1, 1, 0, 0, 0, 0};
	int cordi_x[] = {0, 0, -1, 1, 0, 0};

	while (!que.empty())
	{
		z = que.front().first.first;
		y = que.front().first.second;
		x = que.front().second;
		que.pop();

		for (int i = 0; i < 6; i++)
		{
			z_new = z + cordi_z[i];
			y_new = y + cordi_y[i];
			x_new = x + cordi_x[i];

			if ((z_new >= 0 && z_new < height) &&
			    (y_new >= 0 && y_new < col) && 
			    (x_new >= 0 && x_new < row))
			{
				if (box[z_new][y_new][x_new] == 0 && 
				    check[z_new][y_new][x_new] == 0)
				{
					check[z_new][y_new][x_new] = 
						check[z][y][x] + 1;
					que.push({{z_new, y_new}, x_new});
				}
			}
		}
	}

	int max = 0;
	bool flag = true;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < row; k++)
			{
				if (box[i][j][k] == 0 && check[i][j][k] == 0)
				{
					flag = false;
					goto escape;
				}

				if (max < check[i][j][k])
					max = check[i][j][k];
			}
		}
	}

escape :
	flag == false ? printf("-1\n") : printf("%d\n", max - 1);
	return 0;
}
#endif

#if 0
int box[1001][1001];
int check[1001][1001];
queue <pair<int, int>> que;

int main(void)
{
	int row;
	int col;

	scanf("%d %d", &row, &col);
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			scanf("%d", &box[i][j]);
			check[i][j] = box[i][j];
			if (box[i][j] == 1)
				que.push({i, j});
		}
	}

	int y;
	int x;
	int y_new;
	int x_new;
	int cordi_y[4] = {-1, 1, 0, 0};
	int cordi_x[4] = {0, 0, -1, 1};

	while (!que.empty())
	{
		y = que.front().first;
		x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			y_new = y + cordi_y[i];
			x_new = x + cordi_x[i];
			if (box[y_new][x_new] == 0 && check[y_new][x_new] == 0)
			{
				if ((y_new >= 0 && y_new < col) && 
				    (x_new >= 0 && x_new < row))
				{
					check[y_new][x_new] = check[y][x] + 1;
					que.push({y_new, x_new});
				}
			}
		}
	}

	int max = 0;
	bool flag = true;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (box[i][j] == 0 && check[i][j] == 0)
			{
				flag = false;
				goto escape;
			}

			if (max < check[i][j])
				max = check[i][j];
		}
	}

escape :
	flag == false ? printf("-1\n") : printf("%d\n", max - 1);

	return 0;
}
#endif
