#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");

	return 0;
}

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;
	int cpt = 1;

	for (i = 0; i < num; i++)
	{
		for (j = num - cpt; j; j--)
			printf(" ");

		printf("*");

		for (j = 0; j < ((i - 1) << 1) + 1; j++)
		{
			i == (num - 1) ? printf("*") : printf(" ");
		}

		if (i)
			printf("*");

		cpt++;
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;
	int cpt = 1;

	for (i = 0; i < num; i++)
	{
		for (j = num - cpt; j; j--)
			printf(" ");

		for (j = 0; j <= i; j++)
			printf("* ");

		cpt++;
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;
	int cpt = 1;

	for (i = 0; i < num; i++)
	{
		for (j = num - cpt; j; j--)
			printf(" ");

		for (j = 0; j <= i; j++)
			printf("*");

		cpt++;
		printf("\n");
	}

	cpt = 1;
	for (i = 1; i < num; i++)
	{
		for (j = 0; j < i; j++)
			printf(" ");

		for (j = num - cpt; j; j--)
			printf("*");

		cpt++;
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;
	int cpt = 1;

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < i; j++)
			printf(" ");

		for (j = (num - cpt) << 1; j >= 0; j--)
			printf("*");

		cpt++;
		printf("\n");
	}

	cpt = 2;
	for (i = 1; i < num; i++)
	{
		for (j = num - cpt; j; j--)
			printf(" ");

		for (j = 0; j < (i << 1) + 1; j++)
			printf("*");

		cpt++;
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;

	int cpt = 1;
	for (i = 1; i <= num; i++)
	{
		for (j = 0; j < i; j++)
			printf("*");

		for (j = (num - cpt) << 1; j; j--)
			printf(" ");

		for (j = 0; j < i; j++)
			printf("*");

		cpt++;
		printf("\n");
	}


	cpt = 1;
	for (i = 1; i < num; i++)
	{
		for (j = num - cpt; j; j--)
			printf("*");

		for (j = 0; j < (i << 1); j++)
			printf(" ");

		for (j = num - cpt; j; j--)
			printf("*");

		cpt++;
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;
	int blank = 1;
	for (i = 0; i < num; i++)
	{
		for (j = num - blank; j; j--)
			printf(" ");
		blank++;

		for (j = 0; j < (i << 1) + 1; j++)
			printf("*");
		printf("\n");
	}

	blank = 1;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j <= i; j++)
			printf(" ");

		for (j = 0; j < ((num - blank) << 1) - 1; j++)
			printf("*");

		blank++;
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;
	int star = 1;

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < i; j++)
			printf(" ");

		for(j = 0; j < ((num - star) << 1) + 1; j++)
			printf("*");

		star++;
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int j;
	int blank = 1;
	for (i = 0; i < num; i++)
	{
		for (j = num - blank; j; j--)
			printf(" ");
		blank++;

		for (j = 0; j < (i << 1) + 1; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}
#endif

#if 0
int data[1000000];

int main(void)
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
		scanf("%d", &data[i]);

	sort(data, data + num);
	printf("%d %d\n", data[0], data[num - 1]);

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	int fir;
	int sec;

	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &fir, &sec);
		printf("Case #%d: %d + %d = %d\n", 
				i + 1, 
				fir,
				sec,
				fir + sec);
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	scanf("%d", &num);

	int fir;
	int sec;

	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &fir, &sec);
		printf("Case #%d: %d\n", i + 1, fir + sec);
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int fir;
	int sec;

	while (1)
	{
		scanf("%d %d", &fir, &sec);

		if (fir == 0 && sec == 0)
			break;

		printf("%d\n", fir + sec);
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int fir;
	int sec;

	while (cin >> fir >> sec)
		printf("%d\n", fir + sec);
		
	return 0;
}
#endif

#if 0
int main(void)
{
	int num;

	int fir;
	int sec;

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &fir, &sec);
		printf("%d\n", fir + sec);
	}

	return 0;
}
#endif
