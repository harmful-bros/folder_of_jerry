#include <stdio.h>

#define MOD	1000000
#define COUNT	1500000 // if M = 10^k, k > 2,,  P = 15 * 10 ^ (k - 1) 

int data[COUNT];

int main(void)
{
	unsigned long long input;
	scanf("%llu", &input);

	data[0] = 0;
	data[1] = 1;

	int i;
	for (i = 2; i < COUNT; i++)
	{
		data[i] = data[i - 1] + data[i - 2];
		data[i] %= MOD;
	}

	printf("%d\n", data[input % COUNT]);

	return 0;
}

#if 0
unsigned long long fibonacci_func(int num)
{
	int i;
	unsigned long long fir = 0;
	unsigned long long sec = 1;
	unsigned long long sum;

	if (num)
	{
		if (num != 1)
		{
			for (i = 2; i <= num; i++)
			{
				sum = fir + sec;
				fir = sec;
				sec = sum;
			}

			return sum;
		}
		else
			return 1ULL;
	}
	else
		return 0ULL;
}

int main(void)
{
	int num;
	scanf("%d", &num);

	printf("%llu\n", fibonacci_func(num));
	return 0;
}

#endif
