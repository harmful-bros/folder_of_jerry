#include <iostream>

#define JERRY_CODES

using namespace std;

const int MAX=50000;
const int MOD=10000;

class S{
	int sp;
	int data[MAX];
	public:
	S(){
		sp = 0;
	}

	void Push(int d){
		if (sp >= MAX) return;
		data[sp++] = d;
	}

	int Pop(void){
//	Pop함수를 완성하세요
//	스택에서 데이터를 Pop하여 리턴
//	Pop 시킬 데이터가 없을 경우 -1을 리턴
#ifdef JERRY_CODES
		sp--;
		if (sp < 0)
		{
			sp = 0;
			goto escape;
		}

		return data[sp];
escape :
#endif
		return -1;
	}
};

class A{
	int N;
	int a[MAX];
	char op[MAX];

	public:
	void Input_Data(void){
		int i;
		cin >> N;
		cin >> a[0];
		for (i = 1; i < N; i++){
			cin >> op[i];
			cin >> a[i];
		}
	}
	int Multiply(int a, int b){
		return (a*b) % MOD;
	}
	int Solve(void){
		int i, d;
		int sol = 0;
		S S;

		S.Push(a[0]);
		for (i = 1; i < N; i++){
			switch (op[i]){
			case '*':
				d = S.Pop();
				S.Push(Multiply(d, a[i]));
				break;
			case '+':
				S.Push(a[i]);
				break;
			}
		}

		// 최종 계산 값이 sol에 저장될 수 있도록 완성하세요.
#ifdef JERRY_CODES
		int ret;
		while (1)
		{
			ret = S.Pop();
			if (ret == -1)
				break;
		
			sol += ret;
			sol %= 10000;
		}
#endif
		return sol;
	}
};

int main(){
	A aa;
	aa.Input_Data();
	cout << aa.Solve() << endl;
	return 0;
}
