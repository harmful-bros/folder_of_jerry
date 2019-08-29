#include <iostream>
#include <cstdio>
#include <queue>
//#include <string>
//#include <algorithm>

using namespace std;

queue<int> que_arr[2];

static inline int _gcd_while(int num1, int num2, queue<int> &que)
{
	int temp;
	int temp1 = num1;
	int temp2 = num2;

	printf("@@@@ %d %d\n", num1, num2);

	while (num2)
	{
		temp = num1 % num2;		
		num1 = num2;
		num2 = temp;

		if (temp && temp != temp1 && temp != temp2)
			que.push(temp);
	}

	return num1;
}

static inline int _delete_in_que(queue<int> &oldq, queue<int> &newq, int data)
{
	while (!oldq.empty())
	{
//		printf("%d\n", oldq.front());
		_gcd_while(oldq.front(), data, newq);
		oldq.pop();
	}

	return 0;
}

static inline int _print_in_que(queue<int> &que)
{
	while (!que.empty())
	{
		printf("%d ", que.front());
		que.pop();
	}
	printf("\n");

	return 0;
}

int main(void)
{
	int num;
	scanf("%d", &num);

	int first;
	scanf("%d", &first);

	int second;
	scanf("%d", &second);

	bool flag = false;
	_gcd_while(first, second, que_arr[flag]);

	int data;
	for (int i = 0; i < num - 2; i++)
	{
		scanf("%d", &data);
		_delete_in_que(que_arr[flag], que_arr[flag ^ 1], data);
		flag ^= 1;
	}

	_print_in_que(que_arr[0]);
	_print_in_que(que_arr[1]);

	return 0;
}

#if 0
int main(void)
{
	unsigned long long num;
	scanf("%llu", &num);

	for (unsigned long long i = 2; i * i <= num; i++)
	{
		while (num % i == 0)
		{
			printf("%llu\n", i);
			num /= i;
		}
	}

	if (num > 1)
		printf("%llu\n", num);

	return 0;
}
#endif

#if 0
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

#if 0
string str;

int main(void)
{
	long long num;
	scanf("%lld", &num);

	if (num == 0)
		printf("0\n");
	else
	{
		while (num)
		{
			if (num % -2 == 0)
			{
				str += '0';
				num /= -2;
			}
			else
			{
				str += '1';
				num = (num - 1) / -2;
			}
		}

		reverse(str.begin(), str.end());
		cout << str << endl;
	}

	return 0;
}
#endif

#if 0
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

#if 0
int main(void)
{
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

	///////////////////////////////////

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

#if 0
typedef unsigned long long ull;

static inline ull _gcd(ull num_1, ull num_2)
{
	if (num_1 == 0)
		return num_2;

	while (num_2)
	{
		if (num_1 > num_2)
			num_1 -= num_2;
		else
			num_2 -= num_1;
	}

	return num_1;
}

int main(void)
{
	int t_case;

	scanf("%d", &t_case);
	for (int i = 0; i < t_case; i++)
	{
		int n_case;
		ull data[100] = {0, };
		ull sum = 0;

		scanf("%d", &n_case);
		for (int j = 0; j < n_case; j++)
			scanf("%llu", &data[j]);

		for (int j = 0; j < n_case; j++)
			for (int k = 0; k < j; k++)
				sum += _gcd(data[k], data[j]);

		printf("%llu\n", sum);
	}

	return 0;
}
#endif

#if 0
string ret = "";

int main(void)
{
	string str;
	getline(cin, str);

	char idx;
	int size = str.size();

	while (size--)
	{
		idx = str[size] - '0';
		for (int i = 0; i < 3; i++)
		{
			ret += ((idx % 2) + '0');
			idx >>= 1;

			if (size == 0 && idx == 0)
				goto escape;
		}
	}

escape :
	reverse(ret.begin(), ret.end());
	cout << ret << endl;	
	
	return 0;
}
#endif

#if 0
int main(void)
{
	string str;
	getline(cin, str);

	char idx;
	int sum = 0;
	int pow = 1;
	int size = str.size();

	int cnt = 0;
	string ret = "";
	while (size--)
	{
		idx = str[size] - '0';
		sum += (idx * pow);
		pow <<= 1;

		cnt++;
		if (cnt >= 3)
		{
			ret += (sum + '0');
			cnt = 0;
			sum = 0;
			pow = 1;
		}
	}

	if (sum)
		ret += (sum + '0');

	reverse(ret.begin(), ret.end());
	cout << ret << endl;

	return 0;
}
#endif

#if 0
int main(void)
{
	int mul;
	string str;
	cin >> str >> mul;

	char idx;
	int size = str.size();
	unsigned long long sum = 0;
	unsigned long long pow = 1;

	while (size--)
	{
		idx = str[size];
		idx = (idx >= 'A') ? (idx - 'A') + 10 : idx - '0';

		sum += (pow * idx);
		pow *= mul;
	}

	printf("%llu\n", sum);

	return 0;
}
#endif

#if 0
int main(void)
{
	int num;
	int div;

	scanf("%d %d", &num, &div);

	char idx;
	string str = "";

	while (num)
	{
		idx = num % div;	
		idx = (idx >= 10) ? (idx - 10) + 'A' : idx  + '0';
		str += idx;
		num /= div;
	}

	reverse(str.begin(), str.end());
	cout << str << endl;

	return 0;
}
#endif

