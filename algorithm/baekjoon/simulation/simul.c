#include <stdio.h>

typedef struct passenger
{
	int in;
	int out;

}pass_t;

int main(void)
{
	int i;
	int in;
	int out;
	int max = 0;
	pass_t pass;

	pass.in = pass.out = 0;
	for (i = 0; i < 4; i++)
	{
		scanf("%d %d", &out, &in);

		pass.in += in;
		pass.out -= out;

		if (max < pass.in + pass.out)
			max = pass.in + pass.out;
	}

	printf("%d\n", max);

	return 0;
}
