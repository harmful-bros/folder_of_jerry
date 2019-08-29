#include <iostream>
#include <cstdio>
using namespace std;

int N, M;
int TV[100000 + 10];    // 판매된 TV 모델
int sold[100000 + 10];  // 판매수량
int score[100000 + 10]; // 인기도
int sequence[100000 + 10]; // 연속성

int main(void) {
	int i, max;

	int num = 0;
	int cnt = 0;

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> TV[i];
	}

	// 모델 별 판매수량을 카운트
	for (i = 0; i < N; i++) {

		if (num != TV[i])			
		{
			num = TV[i];
			cnt = 1;
		}
		else
			cnt++;

		sold[TV[i]]++;
		if (sequence[TV[i]] < cnt)
			sequence[TV[i]] = cnt;
	}

	// 기존 방법에 의한 인기도 계산 (인기도 = 판매수량)
	for (i = 1; i <= M; i++) {
		score[i] = sold[i] * sequence[i];
	}

	// 인기도가 가장 높은 모델번호 찾기
	max = 1;
	for (i = 2; i <= M; i++) {
		if (score[i] > score[max]) max = i;
	}

	// 정답 출력
	cout << max << endl;

	return 0;
}


