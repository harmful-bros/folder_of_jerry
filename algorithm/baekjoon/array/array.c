#include <stdio.h>
#include <string.h>
#include <ctype.h>

#if 0
int main(void)
{
	int i;
	int num[5];
	int sum = 0;

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &num[i]);
		if (num[i] < 40)
			num[i] = 40;

		sum += num[i];
	}

	printf("%d\n", sum / 5);

	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int num[8];

	char str[16] = {0,};

	for (i = 0; i < 8; i++)
		scanf("%d", &num[i]);

	snprintf(str, sizeof(str), "%d%d%d%d%d%d%d%d", 
			num[0],	num[1],	num[2],	num[3],
			num[4],	num[5],	num[6],	num[7]);

	if (!strcmp(str, "12345678"))
		printf("ascending\n");
	else if (!strcmp(str, "87654321"))
		printf("descending\n");
	else
		printf("mixed\n");

	return 0;
}
#endif

#if 0
int main(void)
{
	int t_case;
	int len;
	char str[128] = {0, };

	int i;
	int j;
	int cnt;
	int sum;

	scanf("%d", &t_case);
	getchar();

	for (i = 0; i < t_case; i++)
	{
		sum = cnt = 0;

		fgets(str, sizeof(str), stdin);
		str[strlen(str) - 1] = '\0';

		len = strlen(str);
		for (j = 0; j < len; j++)
		{
			cnt = (str[j] == 'O') ? cnt + 1 : 0;
			sum += cnt;
		}

		printf("%d\n", sum);
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int num_1;
	int num_2;
	int num_3;

	int arr[10] = {0,};
	char str[32] = {0,};

	int i;
	int len;

	scanf("%d %d %d", &num_1, &num_2, &num_3);
	snprintf(str, sizeof(str), "%d", num_1 * num_2 * num_3);

	len = strlen(str);
	for (i = 0; i < len; i++)
		arr[str[i] - '0']++;

	for (i = 0; i < 10; i ++)
		printf("%d\n", arr[i]);

	return 0;
}
#endif

#if 1
int main(void)
{
	int i;
	int len;
	int cnt = 0;
	int flag = 0;

	char str[1000001] = {0, };

	fgets(str, sizeof(str), stdin);
	len = strlen(str) - 1;
	str[len] = '\0';

	for (i = 0; i < len; i++)
	{
		if (str[i] > 0x20)
		{
			if (flag == 0)
			{
				cnt++;
				flag = 1;
			}
		}
		else
			flag = 0;
	}

	printf("%d\n", cnt);
	return 0;
}
#endif
