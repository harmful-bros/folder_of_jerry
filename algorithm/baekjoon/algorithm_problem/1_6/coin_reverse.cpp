#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int num;
	scanf("%d", &num);

	vector<string> vec(num);
	for (int i = 0; i < num; i++)
		cin >> vec[i];

	int min_val = num * num;
	for (int i = 0; i < (0x1 << num); i++)
	{
		int sum = 0;
		for (int j = 0; j < num; j++)
		{
			int cnt = 0;
			for (int k = 0; k < num; k++)
			{
				char ch = vec[k][j];
				if (i & (0x1 << k))
					ch = (ch == 'H') ? 'T' : 'H';

				if (ch == 'T')
					cnt++;
			}
			sum += min(cnt, num - cnt); 
		}

		if (min_val > sum)
			min_val = sum;
	}

	printf("%d\n", min_val);

	return 0;
}
