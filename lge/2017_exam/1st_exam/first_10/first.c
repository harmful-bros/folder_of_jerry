#include <stdio.h>

#define MAX   (50000)
#define MOD   (10000)

int N;
int stack[MAX];
int sp = 0;
int a[MAX];
char op[MAX];

void Push(int d){
	if (sp >= MAX) return;
	stack[sp++] = d;
}


int Pop(void){

//	Pop함수를 완성하세요
//	스택에서 데이터를 Pop하여 리턴
//	Pop 시킬 데이터가 없을 경우 -1을 리턴
	int idx = sp - 1;
	if (idx < 0)
		return -1;

	return stack[--sp];
}

void Input_Data(void){
	int i;
	scanf("%d", &N);
	scanf("%d", &a[0]);
	for (i = 1; i < N; i++){
		scanf(" %c %d", &op[i], &a[i]);
	}
}

int Multiply(int a, int b){
	return (a*b) % MOD;
}

int Solve(void){
	int i, d;
	int sol = 0;

	Push(a[0]);
	for (i = 1; i < N; i++){
		switch (op[i]){
		case '*':
			d = Pop();
			Push(Multiply(d, a[i]));
			break;
		case '+':
			Push(a[i]);
			break;
		}
	}

	// 최종 계산 값이 sol에 저장될 수 있도록 완성하세요.
	while ((d = Pop()) != -1)
		sol += d;

	sol %= 10000;

	return sol;
}


int main(void){
	Input_Data();

	printf("%d\n", Solve());

	return 0;
}
