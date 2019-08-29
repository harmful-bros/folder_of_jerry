#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	int len;
	char temp[11] = {0, };
	char str[128] = {0, };

	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';

	while (1)
	{
		snprintf(temp, sizeof(temp), "%s", str);
		printf("%s\n", temp);
		memmove(&str[0], &str[10], strlen(str));

		if (strlen(str) <= 10)
		{
			printf("%s\n", str);
			break;
		}
	}
		
	return 0;
}

#if 0
int main(void)
{
	int i;

	int num;
	int sum = 0;
	char arr[128] = {0, };

	scanf("%d", &num);
	scanf("%s", arr);

	for (i = 0; i < num; i++)
		sum += (arr[i] - '0');

	printf("%d\n", sum);

	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int num;
	unsigned long long sum = 0;

	scanf("%d", &num);
	for (i = 1; i <= num; i++)
		sum += (unsigned long long)i;

	printf("%llu\n", sum);

	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int idx;

	int mon;
	int day;
	int sum = 0;

	const char *pday[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	const int end[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	scanf("%d %d", &mon, &day);
	for (i = 0; i < mon; i++)
		sum += end[i];

	idx = ((sum % 7) + (day - 1)) % 7;
	printf("%s\n", pday[idx]);

	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int j;
	int num;

	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < i; j++)
			printf(" ");

		for (j = num - i; j > 0; j--)
			printf("*");

		printf("\n");
	}
		
	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int j;
	int num;

	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		for (j = num - i; j > 0; j--)
			printf("*");
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int j;
	int num;

	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		for (j = num - i - 1; j > 0; j--)
			printf(" ");

		for (j = 0; j < i + 1; j++)
			printf("*");

		printf("\n");
	}
		
	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int j;
	int num;

	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < i + 1; j++)
			printf("*");
		printf("\n");
	}
		
	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int num;

	scanf("%d", &num);
	for (i = 1; i <= 9; i++)
		printf("%d * %d = %d\n", num, i, num * i);

	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int num;

	scanf("%d", &num);
	for (i = num; i; i--)
		printf("%d\n", i);

	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int num;

	scanf("%d", &num);
	for (i = 0; i < num; i++)
		printf("%d\n", i + 1);

	return 0;
}
#endif
