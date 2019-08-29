#include <stdio.h>
#include <stdlib.h>

//#define AUTO_OPERATION
static int _compare(const void *pnum_1, const void *pnum_2);

#define MAX_PROJECT (15) 
typedef struct{
	int sub;
	int flag;

	int start_date; // 시작일 
	int end_date; // 종료일

}DATA;

int     N; // 프로젝트 수
DATA    project_info[MAX_PROJECT]; // 프로젝트 정보

void Data_Input(void){
	int i;
	scanf("%d", &N); // 프로젝트 수 입력

	// 프로젝트 정보 입력
	for (i = 0; i < N; i++){
		scanf("%d %d", &project_info[i].start_date, &project_info[i].end_date);
		project_info[i].sub = 
			project_info[i].end_date - project_info[i].start_date;

//		printf("%d\n", project_info[i].sub);
	}
}

#ifdef AUTO_OPERATION
int main(int argc, char *argv[]){
	/* File that test case open */
	FILE *pread = freopen(argv[1], "r", stdin);
	if (pread == NULL)
		return -1;
#else
int main(void) {
#endif

	int sol=0;

	int i;
	int j;
	DATA *pdata;

	Data_Input(); // 입력함수 호출

	qsort(project_info, N, sizeof(DATA), _compare);

#if 0
	for (i = 0; i < N; i++)
	{
		printf("%3d %3d %3d\n", 
				project_info[i].start_date,
				project_info[i].end_date,
				project_info[i].sub);
	}
	printf("\n");
#endif

	pdata = project_info;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (pdata[j].flag)
				continue;

			if (!(pdata[i].end_date < pdata[j].start_date ||
			    pdata[i].start_date > pdata[j].end_date))
			{
				pdata[i].flag = 1;
//				printf("@@@@ %d %d\n", i, j);
				break;
			}
		}

		if (i == j)
			sol++;
	}

	printf("%d\n", sol); // 결과 출력

#ifdef AUTO_OPERATION
	if (pread)
	{
		fclose(pread);
		pread = NULL;
	}
#endif

	return 0;
}

static int _compare(const void *pnum_1, const void *pnum_2)
{
	return *(int *)pnum_1 - *(int *)pnum_2;
}
