#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

bitset<100000> init;
bitset<100000> ret;

int main(void)
{
	int num;
	scanf("%d", &num);

	int i;
	int temp;
	for (i = 0; i < num; i++)
	{
		scanf("%1d", &temp);

		if (temp)
			init.set(i, true);
	}

	for (i = 0; i < num; i++)
	{
		scanf("%1d", &temp);

		if (temp)
			ret.set(i, true);
	}

	int cnt = 0;
	for (i = 1; i < num - 1; i++)
	{
		cnt++;
		init.flip(i - 1);
		init.flip(i);
		init.flip(i + 1);

		for (int j = 0; j < num; j++)
			cout << init[j];
		printf("\n");
	}

	printf("%d\n", cnt);

	return 0;
}

