#include <iostream>

#include <cstdio>
#include <cstring>

#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");

	return 0;
}


#if 0			// combination, 2004, 조합0의 개수
int main(void)
{
	// 팩토리얼 과는 다르게 순서가 섞일 수 있으므로 2와 5의 개수를 따로 센다.

	unsigned long long n;
	unsigned long long m;

	scanf("%llu %llu", &n, &m);

	unsigned long long i;
	unsigned long long two = 0;
	unsigned long long five = 0;

	// n! / (m! * (n - m)!)

	for (i = 2; i <= n; i <<= 1)
		two += (n / i);

	for (i = 2; i <= n - m; i <<= 1)
		two -= ((n - m) / i);

	for (i = 2; i <= m; i <<= 1)
		two -= (m / i);

	/////////////////////////////////////
	for (i = 5; i <= n; i *= 5)
		five += (n / i);

	for (i = 5; i <= n - m; i *= 5)
		five -= ((n - m) / i);

	for (i = 5; i <= m; i *= 5)
		five -= (m / i);

	printf("%llu\n", min(two, five));
	return 0;
}
#endif

#if 0			// factorial, 1676, 팩토리얼 0의 개수
int main(void)
{
	// 소인수 분해 했을 시, 2 * 5의 개수를 세면 0이 몇번 나오는지 알 수 있음

	int i;
	int num;
	int five = 0;

	scanf("%d", &num);
	for (i = 5; i <= num; i *= 5)
		five += (num / i);

	printf("%d\n", five);

	return 0;
}
#endif

#if 0			// prime number, 6588, 골든 바흐의 추측
#define MAX_VAL		1000000

int idx;
int data[MAX_VAL + 1];
bool flag[MAX_VAL + 1];

int main(void)
{
	int num;

	/* Eratosthenes' sieve */
	for (int i = 2; i <= MAX_VAL; i++)
	{
		if (flag[i] == false)
		{
			data[idx++] = i;
			for (int j = i << 1; j <= MAX_VAL; j += i)
				flag[j] = true;
		}
	}

	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
			break;

		int check = false;
		for (int i = 0; i < idx && num >= data[i]; i++)
		{
			if (flag[num - data[i]] == false)
			{
				check = true;
				printf("%d = %d + %d\n", 
						num, 
						data[i],
						num - data[i]);
				break;
			}
		}

		if (check == false)
			printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}
#endif

#if 0			// 1978 prime number, 소수 찾기, 에라토스테네스의 체

#if 0
bool prime_num(int num)
{
	if (num < 2)
		return false;

	bool flag = false;
	for (int i = 2; i * i <= num; i++) // a * b = num
	{
		if (num % i == 0)
		{
			flag = true;
			break;
		}
	}

	return flag;
}
#endif

#define MAX_VALUE	1001
int arr[MAX_VALUE];

int main(void)
{
	int i;
	int j;

	int num;
	int t_case;

	int cnt = 0;

	for (i = 2; i < MAX_VALUE; i++)
		arr[i] = i;

	for (i = 2; i * i < MAX_VALUE; i++)
	{
		if (arr[i] == 0)
			continue;

		for (j = i << 1; j <= MAX_VALUE; j += i)
			arr[j] = 0;
	}

	scanf("%d", &t_case);
	for (i = 0; i < t_case; i++)
	{
		scanf("%d", &num);
		if (arr[num] && arr[num] == num)
			cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
#endif

#if 0			// 11576 base conversion, 진법변환
int main(void)
{
	int from;
	int to;

	scanf("%d %d", &from, &to);

	int len;
	scanf("%d", &len);

	int num;
	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &num);
		ret = ret * from + num;
	}

	string str = "";
	while (ret)
	{
		str = to_string(ret % to) + " " + str;
		ret /= to;
	}

	cout << str << endl;

	return 0;
}
#endif

#if 0			// gcd / lcm, 2609 최대공약수, 최소공배수

#if 0
int ret = 1;
for (int i = 2; i <= min(num1, num2); i++)
{
	if (num1 % i == 0 && num2 % i == 0)
		ret = i;
}
#endif

#if 0
int _gcd_recursive(int num1, int num2)
{
	if (num2 == 0)
		return num1;

	_gcd_recursive(num2, num1 % num2);
}
#endif

#if 0
int _gcd_while(int num1, int num2)
{
	int temp;
	while (num2)
	{
		temp = num1 % num2;		
		num1 = num2;
		num2 = temp;
	}

	return num1;
}
#endif

static inline int _gcd_func(int num1, int num2)
{
	// gcd : Greatest Common Divisior
	// using Euclidean Algorithm
	// GCD(a, b) == GCD(b, r), when r is 0, b is gcd value.
	// lcm : Least Common Multiple
	// LCM = a * b / GCD(a,b)

	if (num1 == 0)
		return num2;

	while (num2)
	{
		if (num1 > num2)
			num1 -= num2;
		else
			num2 -= num1;
	}

	return num1;
}

int main(void)
{
	int num1;
	int num2;

	int gcd;

	scanf("%d %d", &num1, &num2);

	gcd = _gcd_func(num1, num2);
	printf("%d\n", gcd);
	printf("%d\n", (num1 * num2) / gcd);

	return 0;
}
#endif
