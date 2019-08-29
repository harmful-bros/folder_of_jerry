#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	int cnt;
	scanf("%d", &cnt);

	int num_1;
	int num_2;

	for (int i = 0; i < cnt; i++)
	{
		scanf("%d %d", &num_1, &num_2);
		printf("%d\n", num_1 + num_2);
	}

	return 0;
}
