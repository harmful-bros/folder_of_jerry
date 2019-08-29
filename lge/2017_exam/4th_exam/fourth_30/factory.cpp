#include <iostream>
using namespace std;

int N; //일
int S; //보관비용
int C[50010]; //가격
int Y[50010]; //용량

void Input_Data(void){
	cin >> N >> S;
	for (int i = 0; i < N; i++){
		cin >> C[i] >> Y[i];
	}
}

int main(){
	long long ans = -1;
	Input_Data();		// 입력 함수

	// TODO : 코드를 작성하세요
	long long sum = 0;
	long long price = C[0];
	
	sum = (long long)(C[0] * Y[0]);
	for (int i = 1; i < N; i++)
	{	
		price += S;

		if (price > C[i])
			price = C[i];

		sum += (price * Y[i]);
	}

	ans = sum;
	cout << ans << endl;	// 정답 출력
	return 0;
}


