#include <stdio.h>

static inline int _get_lcm(int x, int y)
{
	int temp;
	int mul = x * y;

	if (x < y)
	{
		temp = x;
		x = y;
		y = temp;
	}

	while (y != 0)
	{
		temp = x % y;
		x = y;
		y = temp;
	}

	return mul / x;
}

int main(void)
{
	int i;
	int t_case;

	int m;
	int n;
	int x;
	int y;

	int lcm;

	scanf("%d", &t_case);
	for (i = 0; i < t_case; i++)
	{
		scanf("%d %d %d %d", &m, &n, &x, &y);

		lcm = _get_lcm(m, n);
		while (x != y && x <= lcm)
		{
			if (x < y) 
				x += m;
			else	
				y += n;

		}
		
		(x == y) ? printf("%d\n", x) : printf("-1\n");
	}

	return 0;
}

#if 0
#include <math.h>

int main(void)
{
	int num;
	double euclid;
	double taxi;

	scanf("%d", &num);

	euclid = num * num * (double)3.14159265358979323846;
	taxi = pow(sqrt(pow(num, 2) * 2), 2);

	printf("%.6lf\n", euclid);
	printf("%.6lf\n", taxi);

	return 0;
}
#endif

#if 0
int main(void)
{
	int num_1;
	int num_2;
	int num_3;
	int num_4;

	int i;
	int arr[2];
	const char *pstr = "EABCD";

	for (i = 0; i < 3; i++)
	{
		arr[0] = arr[1] = 0;
		scanf("%d %d %d %d", &num_1, &num_2, &num_3, &num_4);

		arr[num_1]++;
		arr[num_2]++;
		arr[num_3]++;
		arr[num_4]++;

		printf("%c\n", pstr[arr[0]]);
	}

	return 0;
}
#endif

#if 0
int main(void)
{
	int i;
	int num;
	int val;

	scanf("%d", &num);

	val = num;
	for (i = 1; i <= num; i++)
	{
		if (val <= i)
			break;
		val -= i;
	}

	(i & 0x1) ? 
		printf("%d/%d\n", i - val + 1, val) :
		printf("%d/%d\n", val, i - val + 1);

	return 0;
}
#endif
