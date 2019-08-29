#include <iostream>
#include "./lib/maze.h"

// [문제 1] 미로의 행동 패턴 수, 행동 패턴 예상하기 
int expected_pattern_cnt[3] = {
	7, // 문제1 예시 - 행동 패턴 수
		0, // TODO: 문제 (1-1) [미로1]
		0, // TODO: 문제 (1-2) [미로2]
};
int expected_pattern[3][100] = {
	{1,2,1,3,1,2,1}, // 문제1 예시 - 행동패턴
	{  }, // TODO: 문제 1-1 [미로1]
	{  }, // TODO: 문제 1-2 [미로2]
};


// [문제 2] 각 문제 행동패턴을 테스트 하기 위한 미로를 설계하시오.

// 북:DIR_N ,동:DIR_E ,남:DIR_S ,서:DIR_W
// 
int tc_sdir[] = {
	DIR_E, // 예시 미로 시작방향
	0, // TODO:  문제(2-1) 시작방향
	0, // TODO:  문제(2-2) 시작방향
	0, // TODO:  문제(2-3) 시작방향
};

char tc_maze[][MAZE_SIZE][MAZE_SIZE+1] = {
	{
		"############",
		"#S....######",
		"#####.######",
		"#####.######",
		"#####.######",
		"#####......#",
		"##########.#",
		"##########.#",
		"##########.#",
		"##########.#",
		"##########E#",
		"############"
	}, // 문제2 예시 미로

	// TODO: 문제 2-1에서 요구하는 테스트 입력(미로)를 아래에 배열로 입력하시오.
	{
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############"
	}, // 문제(2-1)

	// TODO: 문제 2-2에서 요구하는 테스트 입력(미로)를 아래에 배열로 입력하시오.
	{
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############"
	},// 문제(2-2)

	// TODO: 문제 2-3에서 요구하는 테스트 입력(미로)를 아래에 배열로 입력하시오.
	{
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############",
		"############"
	} // 문제(2-3)
};

int tc_sdir_all = 0; 								// TODO: 문제3 시작방향 (초기값 대입으로 시작방향 설정)
char tc_maze_all[MAZE_SIZE][MAZE_SIZE+1] = {	// TODO: 문제3 테스트 미로
	"############",
	"############",
	"############",
	"############",
	"############",
	"############",
	"############",
	"############",
	"############",
	"############",
	"############",
	"############"
};

int main()
{
	for (int i=0;i<sizeof(tc_sdir)/sizeof(tc_sdir[0]);i++)
	{
		std::cout << "[" << i << "] : " << message[Enhanced_Right_Hand_Rule(tc_sdir[i], tc_maze[i])] << std::endl;
	}

	std::cout << "[All Check] : " << message[Enhanced_Right_Hand_Rule(tc_sdir_all, tc_maze_all)] << std::endl;

	return 0;
}