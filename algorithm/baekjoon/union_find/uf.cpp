#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	printf("leejaeseong\n");
	
	return 0;
}

#if 0
int data[1000001];

static int _find(int num)
{
	if (data[num] == num)
		return num;
	else
		return data[num] = _find(data[num]);
}

static void _union(int x, int y)
{
	x = _find(x);
	y = _find(y);

	if (x != y)
		data[y] = x;
}

int main(void)
{
	int total;
	int cnt;

	scanf("%d %d", &total, &cnt);
	for (int i = 1; i <= total; i++)
		data[i] = i;

	int mode;
	int x;
	int y;

	for (int i = 0; i < cnt; i++)
	{
		scanf("%d %d %d", &mode, &x, &y);
		if (mode)
		{
			x = _find(x);
			y = _find(y);
			(x == y) ? printf("YES\n") : printf("NO\n");
		}
		else
			_union(x, y);
	}

	return 0;
}
#endif
