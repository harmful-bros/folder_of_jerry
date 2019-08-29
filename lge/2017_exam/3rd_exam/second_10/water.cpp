#include <iostream>
using namespace std;

int M;    // 측정데이터의 크기
int P;    // 불순물데이터의 크기
int SI;   // 확대 영역의 시작 행
int SJ;   // 확대 영역의 시작 열
int L;    // 확대 영역의 크기

int a[100][100]; // 측정데이터 저장
int b[100][100]; // 불순물데이터 저장
int sol;          // 정답

int check_pattern(int si, int sj) {
	int i, j;

	// 측정데이터와 불순물데이터를 비교
	for (i = 0; i < P; i++) {
		for (j = 0; j < P; j++) {
			if (a[si + i][sj + j] != b[i + 1][j + 1]) 
				return 0;
		}
	}

	return 1;
}

int main(void) {
	int i, j;

	// 측정데이터 읽기
	cin >> M;
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	// 불순물데이터 읽기
	cin >> P;
	for (i = 1; i <= P; i++) {
		for (j = 1; j <= P; j++) {
			scanf("%1d", &b[i][j]);
		}
	}

	// 확대영역 정보 읽기
	cin >> SI >> SJ >> L;

	// 확대영역 내의 불순물 개수 세기
	for (i = SI; i <= SI + L - P; i++) {
		for (j = SJ; j <= SJ + L - P; j++) {
			sol += check_pattern(i, j);
		}
	}

	// 정답 출력
	cout << sol << endl;

	return 0;
}
