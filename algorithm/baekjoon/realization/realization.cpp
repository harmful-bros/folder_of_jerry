#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef struct cordi_information
{
	int row;
	int col;

}cordi_t;

static inline int _max_abs_val(const int p1, const int p2)
{
	return (abs(p1) > abs(p2)) ? p1 : p2;
}

static inline int _return_start_cordi(int std)
{
	int ret = 1;

	if (std < 0)		// 1 + 4*(n^2)
		ret = ((std * std) << 2) + 1;
	else if (std > 0)	// (2*n + 1)^2
		ret = ((std << 1) + 1) * ((std << 1) + 1);

	return ret;
}

int main(void)
{
	cordi_t start;
	cordi_t end;

	scanf("%d %d %d %d", &start.row, &start.col, &end.row, &end.col);

	int s_std = _max_abs_val(start.row, start.col);
	int e_std = _max_abs_val(end.row, end.col);

	printf("%d %d\n", s_std, e_std);
	
	printf("%d\n", _return_start_cordi(s_std));
	printf("%d\n", _return_start_cordi(e_std));

//	for (int i = start.row; i < end.row; i++)
	{
		for (int j = start.col; j < end.col; j++)
		{
			
		}
	}

	return 0;
}
