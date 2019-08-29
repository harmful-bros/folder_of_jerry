#include <stdio.h>

int main(void)
{
	int num;
	int compute;

	int first;
	int cnt = 0;

	scanf("%d", &num);

	first = num;
	compute = ((num / 10) + (num % 10)) % 10;
	num = (num % 10) * 10 + compute;
	cnt++;

	while (first != num)
	{
		cnt++;
		compute = ((num / 10) + (num % 10)) % 10;
		num = (num % 10) * 10 + compute;
	}

	printf("%d\n", cnt);
	return 0;
}

#if 0
//#define AUTO_OPERATION

int main(void)
{
#ifdef AUTO_OPERATION
	/* File that test case open */
	FILE *pread = freopen("tc.txt", "r", stdin);
	if (pread == NULL)
		return -1;
#endif

	int i;
	int j;

	int t_case;
	int stu_num;
	int student[1000];
	
	int cnt;
	double sum;

	scanf("%d", &t_case);
	i = 0;
	for (i = 0; i < t_case; i++)
	{
		cnt = 0;
		sum = 0;
		memset((void *)student, 0x00, sizeof(student));

		scanf("%d", &stu_num);
		for (j = 0; j < stu_num; j++)
		{
			scanf("%d", &student[j]);
			sum += (double)student[j];
		}

		sum /= stu_num;
		for (j = 0; j < stu_num; j++)
		{
			if (student[j] > sum)
				cnt++;
		}
		printf("%.3lf%%\n", cnt / (double)stu_num * 100.0);
	}

#ifdef AUTO_OPERATION
	if (pread)
	{
		fclose(pread);
		pread = NULL;
	}
#endif
	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int t_case;

	double sum = 0.0;
	double max = 0.0;
	double num[1000];

	scanf("%d", &t_case);
	for (i = 0; i < t_case; i++)
	{
		scanf("%lf", &num[i]);
		if (max < num[i])
			max = num[i];
	}

	for (i = 0; i < t_case; i++)
		sum += (num[i] * 100.0 / max);

	printf("%.2lf\n", sum / t_case);


	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int total;
	int num;
	int input;

	scanf("%d %d", &total, &num);

	for (i = 0; i < total; i++)
	{
		scanf("%d", &input);
		if (input < num)
			printf("%d ", input);
	}
	printf("\n");

	return 0;
}
#endif

#if 0
int main(void)
{
	int num_1;
	int num_2;
	int num_3;

	int sel_1;
	int sel_2;
	int sel_3;

	scanf("%d %d %d", &num_1, &num_2, &num_3);

	sel_1 = num_1 > num_2 ? num_1 : num_2;
	sel_2 = num_2 > num_3 ? num_2 : num_3;
	sel_3 = num_3 > num_1 ? num_3 : num_1;

	if (sel_1 == sel_2)
		printf("%d\n", sel_3);
	else if (sel_2 == sel_3)
		printf("%d\n", sel_1);
	else
		printf("%d\n", sel_2);

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;

	scanf("%d", &num);

	if (num >= 90)
		printf("A\n");
	else if (num >= 80)
		printf("B\n");
	else if (num >= 70)
		printf("C\n");
	else if (num >= 60)
		printf("D\n");
	else
		printf("F\n");

	return 0;
}
#endif
