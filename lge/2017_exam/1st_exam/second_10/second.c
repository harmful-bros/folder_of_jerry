/*	다음프로그램의 오류를 정정하시오.	*/
#include <stdio.h>

int N;
int main(void)
{
	int i, j;
	int a[24][24];		// 일별(행) 시간별(열) 미세먼지 변화량을 저장하기 위한 배열
	int max_row = 0;	// 미세먼지 변화량의 합계가 가장 컷던 날(행)을 저장하기 위한 변수
	int min_col = 0;	// 미세먼지 변화량의 합계가 가장 작았던 시간(열)을 저장하기 위한 변수
	long long sum = 0;			// 미세먼지 변화량의 합을 저장하기 위한 변수
	long long max_sum = 0;	// 미세먼지 변화량의 가장 큰 합계를 저장하기 위한 변수
	long long min_sum = 0;	// 미세먼지 변화량의 가장 작은 합계를 저장하기 위한 변수

	scanf("%d", &N);

	// N일동안 N시간 마다 미세먼지 변화량을 입력 받는 부분
	for (i = 0; i < N; i++) 
	{
		for (j = 0; j < N; j++) 
		{
			scanf("%d", &a[i][j]);
		}
	}


	min_sum = 100000000;
	max_sum = -100000000;

	// 어떤 시간대(열)가 가장 적은 미세먼지 변화량 합을 가지는지 계산하는 부분
	for (j = 0; j < N; j++)	{


		sum = 0;
		// j시간대(열)의 N일동안 미세먼지 변화량 합을 구함
		for (i = 0; i < N; i++) {
			sum += a[i][j];
		}

		printf("%3d %10lld\n", j, sum);

		// 각 시간대(열)의 미세먼지 변화량 합이 가장 작은 시간(열)을 구하는 부분
		if (sum < min_sum) {
			min_sum = sum;
			min_col = j;
		}
	}

	printf("\n");

	// 어떤 날(행)이 가장 많은 미세먼지 변화량 합을 가지는지 계산하는 부분
	for (i = 0; i < N; i++) {

		sum = 0;
		// i일(행)의 N시간 동안 미세먼지 변화량 합을 구함
		for (j = 0; j < N; j++) {
			sum += a[i][j];
		}

		printf("%3d %10lld %10lld\n", i, sum, max_sum);

		// 각 일(행)의 미세먼지 변화량 합이 가장 큰 날(행)을 구하는 부분
		if (sum > max_sum){
			max_sum = sum;
			max_row = i;
		}
	}

	printf("%d %d\n", max_row+1, min_col+1);

	return 0;
}

