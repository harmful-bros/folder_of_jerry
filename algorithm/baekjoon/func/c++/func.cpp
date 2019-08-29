#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_DATA 3072 // 3 * 2 ^ 10

char data[MAX_DATA][MAX_DATA << 1];

static int _print_star(int num, int y_pos, int x_pos);

static int _print_star(int num, int y_pos, int x_pos)
{
	if (num == 3)
	{
		/* Top */
		data[y_pos][x_pos] = '*';

		/* Middle */
		data[y_pos + 1][x_pos - 1] = '*';
		data[y_pos + 1][x_pos + 1] = '*';

		/* Bottom */
		data[y_pos + 2][x_pos - 2] = '*';
		data[y_pos + 2][x_pos - 1] = '*';
		data[y_pos + 2][x_pos + 0] = '*';
		data[y_pos + 2][x_pos + 1] = '*';
		data[y_pos + 2][x_pos + 2] = '*';
	}
	else
	{
		/* Center */
		_print_star(num >> 1, y_pos, x_pos);

		/* Left */
		_print_star(num >> 1, y_pos + (num >> 1), x_pos - (num >> 1));

		/* Right */
		_print_star(num >> 1, y_pos + (num >> 1), x_pos + (num >> 1));
	}

	return 0;
}

int main(void)
{
	int num;
	scanf("%d", &num);

	/* Data init */
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num << 1; j++)
			if (j != (num << 1) - 1)
				data[i][j] = ' ';

	/* draw func,, */
	_print_star(num, 0, num - 1);

	/* Data print */
	for (int i = 0; i < num; i++)
		printf("%s\n", data[i]);

	return 0;
}
