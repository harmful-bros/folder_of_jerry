#include <iostream>

#define JERRY_CODES

using namespace std;
int H;//세로크기
int W;//가로크기
char map[500][510];//지도

#ifdef JERRY_CODES
#include <queue>
#define MAX_CORDI	500
int weight[500][510];
static int _bfs_in_maze(const int row, const int col, const char pmap[][510]);
#endif

void input_data(){
	int i;
	cin >> H >> W;
	for(i=0 ; i<H ; i++){
		cin >> map[i];
	}
}

int main(){
	int ans = 0;
	input_data();
	//	코드를 작성하세요

#ifdef JERRY_CODES
	ans = _bfs_in_maze(W, H, map);
#endif
	cout << ans << endl;
	return 0;
}

#ifdef JERRY_CODES
static int _bfs_in_maze(const int row, const int col, const char pmap[][510])
{
	const int cordi_x[] = {1, 0, -1, 0}; // E, S, W, N
	const int cordi_y[] = {0, 1, 0, -1};

	queue<pair<int, int>> que;

	int x;
	int y;
	int new_x;
	int new_y;

	bool goal_flag = false;

	int ret = -1;
	
	que.push({0, 0});
	while (!que.empty())
	{
		y = que.front().first;
		x = que.front().second;
		que.pop();

		if (y == col - 1 && x == row - 1)
			goal_flag = true;

		for (int i = 0; i < 4; i ++)
		{
			new_y = y + cordi_y[i];
			new_x = x + cordi_x[i];

			if (new_y < 0 || new_x < 0)
				continue;

			if (new_y >= col || new_x >= row)
				continue;

			if (pmap[new_y][new_x] != 'X' && 
			    weight[new_y][new_x] == 0)
			{
				que.push({new_y, new_x});
				weight[new_y][new_x] = weight[y][x] + 1;
			}
		}
	}

	if (goal_flag == true)
		ret = weight[col - 1][row - 1];

	return ret;
}
#endif
