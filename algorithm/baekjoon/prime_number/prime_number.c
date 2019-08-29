#include <stdio.h>

#define MAX_VALUE	10001
int arr[MAX_VALUE];

static inline int _find_plus_index(const int *parr, const int num, 
		const int start)
{
	int i;
	for (i = start; i <= num; i++)
	{
		if (parr[i])
			return i;
	}

	return 0;
}

static inline int _find_minus_index(const int *parr, const int num)
{
	int i;
	for (i = num; i >= 2; i--)
	{
		if (parr[i])
			return i;
	}

	return 0;
}

int main(void)
{
	int i;
	int j;

	int t_case;
	int num;

	int m_idx;
	int p_idx;

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
		m_idx = p_idx = num >> 1;

		m_idx = _find_minus_index(arr, num >> 1);
		p_idx = _find_plus_index(arr, num, num >> 1);

loop :
		if (p_idx + m_idx > num)
		{
			m_idx = _find_minus_index(arr, m_idx - 1);
			goto loop;
		}
		else if (p_idx + m_idx < num)
		{
			p_idx = _find_plus_index(arr, num, p_idx + 1);
			goto loop;
		}
		else
			printf("%d %d\n", m_idx, p_idx);
	}

	return 0;
}

#if 0
#define MAX_VALUE	(123456 << 1) + 1
int arr[MAX_VALUE];

int main(void)
{
	int i;
	int j;

	int num;
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

	while (1)
	{
		scanf("%d", &num);	
		if (num == 0)
			break;

		for (i = num + 1; i <= (num << 1); i++)
		{
			if (arr[i])
				cnt++;
		}
		printf("%d\n", cnt);
		cnt = 0;
	}

	return 0;
}
#endif
