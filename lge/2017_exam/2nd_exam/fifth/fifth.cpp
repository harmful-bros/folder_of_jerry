#include <iostream>

#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

int H;		// 세로 크기
int W;		// 가로 크기
int map[50][50];	//지도
bool flag[50][50];

struct ANS{
	int count;	// room 개수
	int area;		// 가장 넓은 room 넓이
};

typedef enum direction_information
{
	WEST = 1,
	NORTH = 2,
	EAST = 4,
	SOURTH = 8
}dir_e;

static inline bool _check_block(int map, dir_e dir);
static int _breath_first_search(ANS &nAns);

///////////////////////////////////////////////////////////////////////////////

void InputData(){
	int i, j;
	cin >> H;
	cin >> W;
	for(i=0 ; i<H ; i++){
		for(j=0 ; j<W ; j++){
			cin >> map[i][j];
		}
	}
}

int main(){
	ANS ans = {0, 0};

	InputData();			//	입력 함수

	//	코드를 작성하세요

	_breath_first_search(ans);

	cout << ans.count << endl;	//	정답 출력
	cout << ans.area << endl;		//	정답 출력
	return 0;
}

static inline bool _check_block(int map, dir_e dir)
{
	return ((map >> dir) & 0x1) ? false : true;
}

static int _breath_first_search(ANS &nAns)
{
	pair<int, int> coordi;
	queue<pair<int, int>> que;

	int x;
	int y;
	int temp_x;
	int temp_y;

	int cnt;
	int max = 0;
	int room_cnt = 0;
	int index[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (flag[i][j] == true)
				continue;

			cnt = 0;
			coordi.first = i;
			coordi.second = j;
			que.push(coordi);

			while (!que.empty())
			{
				coordi = que.front();
				y = coordi.first;
				x = coordi.second;

				que.pop();
				flag[y][x] = true;
				cnt++;

				for (int k = 0; k < 4; k++)
				{
					if (_check_block(map[y][x], (dir_e)k) == true)
					{
						temp_y = coordi.first + index[k][1];
						temp_x = coordi.second + index[k][0];
						if (flag[temp_y][temp_x] == false)
						{
							flag[temp_y][temp_x] = true;
							que.push(make_pair(temp_y, temp_x));
						}
					}
				}
			}

			room_cnt++;
			if (max < cnt)
				max = cnt;
		}
	}

	nAns.area = max;
	nAns.count = room_cnt;

	return 0;
}
