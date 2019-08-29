#include <iostream>
using namespace std;

#define JERRY_CODES

int N;		//	시험 일수
int h[31];	//	시험 시간
int sol;	

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> h[i];
	}
}

int main(){

#ifdef JERRY_CODES
	int temp = 0;
#endif

	InputData();	//	입력 함수

	//	최종 계산값이 sol 에 저장될 수 있도록 완성하세요
	for (int i = 0; i < N; i++){
#ifdef JERRY_CODES
		if (h[i] < 3)
		{
		}
		else if (h[i] >= 3 && h[i] <= 6)
		{
			temp += 100;
		}
		else if (h[i] > 6)
		{
			temp += 100;
			temp += (50 * (h[i] - 6));
		}

		if (temp > 500)
			temp = 500;

		sol += temp;
		temp = 0;
#endif
	}

#ifdef JERRY_CODES
	if (sol >= 10000)
		sol *= 0.9;
#endif

	cout << sol << endl; 		// 정답 출력
	return 0;
}
