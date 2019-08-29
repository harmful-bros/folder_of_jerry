#include <iostream>
#include <algorithm>
using namespace std;

int N;				//	계단의 개수
int P[310];			//	P[i]: i 계단을 밟았을 때 얻는 점수

int dp[310];

int Solve(){
	int sol=0;

	//	코드를 작성하세요
	dp[0] = P[0];
	dp[1] = max(P[0] + P[1], P[1]);
	dp[2] = max(P[0] + P[2], P[1] + P[2]);
	for (int i = 3; i < N; i++)
		dp[i] = max(P[i] + P[i - 1] + dp[i - 3], P[i] + dp[i - 2]);
	
	sol = dp[N - 1];
	return sol;
}

void InputData(){
	cin >> N;
	for(int i=0 ; i<N ; i++){
		cin >> P[i];
	}
}

int main(){

	InputData();			//	입력 함수

	int sol = Solve();

	cout << sol << endl;		//	정답 출력
	return 0;
}


