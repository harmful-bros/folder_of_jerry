#include <stdio.h>

static inline void _print_block(int num)
{
	int i;

	for (i = 0; i < num; i++)
		printf(" ");
}

static inline void _print_first_line(int num)
{
	printf("*");

	if (num)
		printf("\n");
}

static inline void _print_second_line(int num)
{
	printf("* *");

	if (num)
		printf("\n");
}

static inline void _print_third_line(int num)
{
	printf("*****");

	if (num)
		printf("\n");
}

int main(void)
{
	int n_case;
	int temp;
	int temp_2;

	scanf("%d", &n_case);
	temp = 6;
	temp_2 = 12;
//	while (n_case)
	{
#if 0
		_print_block(n_case - 1);
		_print_first_line(1);
		n_case--;

		_print_block(n_case - 1);
		_print_second_line(1);
		n_case--;

		_print_block(n_case - 1);
		_print_third_line(1);
		n_case--;
#endif

#if 0
		_print_block(n_case - 1);
		_print_first_line(1);
		n_case--;

		_print_block(n_case - 1);
		_print_second_line(1);
		n_case--;

		_print_block(n_case - 1);
		_print_third_line(1);
		n_case--;

		_print_block(n_case - 1);
		_print_first_line(0);
		_print_block(temp - 1);
		_print_first_line(1);
		n_case--;
		temp -= 2;

		_print_block(n_case - 1);
		_print_second_line(0);
		_print_block(temp - 1);
		_print_second_line(1);
		n_case--;
		temp -= 2;

		_print_block(n_case - 1);
		_print_third_line(0);
		_print_block(temp - 1);
		_print_third_line(1);
		n_case--;
		temp -= 2;
#endif

		/* 3 */
		_print_block(n_case - 1);
		_print_first_line(1);
		n_case--;

		_print_block(n_case - 1);
		_print_second_line(1);
		n_case--;

		_print_block(n_case - 1);
		_print_third_line(1);
		n_case--;

		/* 6 */
		_print_block(n_case - 1);
		_print_first_line(0);
		_print_block(temp - 1);
		_print_first_line(1);
		n_case--;
		temp -= 2;

		_print_block(n_case - 1);
		_print_second_line(0);
		_print_block(temp - 1);
		_print_second_line(1);
		n_case--;
		temp -= 2;

		_print_block(n_case - 1);
		_print_third_line(0);
		_print_block(temp - 1);
		_print_third_line(1);
		n_case--;
		temp -= 2;

		/* 9 */
		temp = 6;

		_print_block(n_case - 1);
		_print_first_line(0);
		_print_block(temp_2 - 1);
		_print_first_line(1);
		n_case--;
		temp_2 -= 2;

		_print_block(n_case - 1);
		_print_second_line(0);
		_print_block(temp_2 - 1);
		_print_second_line(1);
		n_case--;
		temp_2 -= 2;

		_print_block(n_case - 1);
		_print_third_line(0);
		_print_block(temp_2 - 1);
		_print_third_line(1);
		n_case--;
		temp_2 -= 2;

		/* 12 */
		_print_block(n_case - 1);
		_print_first_line(0);
		_print_block(temp - 1);
		_print_first_line(0);
		_print_block(temp_2 - 1);
		_print_first_line(0);
		_print_block(temp - 1);
		_print_first_line(1);
		n_case--;
		temp -= 2;
		temp_2 -= 2;

		_print_block(n_case - 1);
		_print_second_line(0);
		_print_block(temp - 1);
		_print_second_line(0);
		_print_block(temp_2 - 1);
		_print_second_line(0);
		_print_block(temp - 1);
		_print_second_line(1);
		n_case--;
		temp -= 2;
		temp_2 -= 2;

		_print_block(n_case - 1);
		_print_third_line(0);
		_print_block(temp - 1);
		_print_third_line(0);
		_print_block(temp_2 - 1);
		_print_third_line(0);
		_print_block(temp - 1);
		_print_third_line(1);
		n_case--;
		temp -= 2;
		temp_2 -= 2;
	}

	return 0;
}
