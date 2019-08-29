#include <iostream>
using namespace std;

#define JERRY_CODES

#ifdef JERRY_CODES
#include <cmath>
#endif

int N;			// 이동정보의 개수를 저장하기 위한 변수
double M;		// 배터리 용량을 저장하기 위한 변수
int S[10010]; 		// 이동속도를 저장하기 위한 배열
double T[10010];	// 이동시간을 저장하기 위한 배열
int L[10010]; 		// 이동거리를 저장하기 위한 배열
double P[10010];	// 배터리 소모량을 저장하기 위한 배열
double R;		// 배터리 잔량을 저장하기 위한 변수

void InputData(void){
	int i;

	// 이동정보의 개수와 배터리 용량을 입력 받는 부분
	cin >> N >> M;

	// N 개의 이동속도와 이동시간을 입력 받는 부분
	for (i = 1; i <= N; i++) {
		cin >> S[i] >> T[i];
	}
}

int main(void){
	int i;

	InputData();

	// 이동속도와 이동시간을 이용하여 이동거리를 계산
	for (i = 1; i <= N; i++) {
#ifdef JERRY_CODES
		L[i] = (int)(S[i] * T[i] + 0.5);
#else
		L[i] = (int)(S[i] * T[i]);
#endif
	}

	// 이동거리와 속도팩터를 이용하여 배터리 소모량을 계산
	for (i = 1; i <= N; i++) {
#ifdef JERRY_CODES
		P[i] = L[i] * ((abs(S[i] - S[i - 1]) + 1) / 2.0);
#else
		P[i] = L[i] * (S[i] - S[i - 1] + 1) / 2;
#endif
	}

	// 배터리 소모량을 이용하여 배터리 잔량의 변화를 계산
	R = M;
	for (i = 1; i <= N; i++) {
		R -= P[i];
	}

	// 배터리 잔량의 최종값을 출력
	cout.setf(ios::fixed);
	cout.precision(1);
	cout << R << endl;

	return 0;
}
