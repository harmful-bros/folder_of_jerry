#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////

char time[101][10000002];
char sum[10000002];

int main(void)
{
	int i;
	int j;
	int k;

	int t_case;

	int wokers;
	int departs;

	int start;
	int end;
	int idx;

	int cnt = 0;
	int max = 0;
	int end_idx = 0;

	scanf("%d", &t_case);
	for (i = 0; i < t_case; i++)
	{
		/* init array */
		memset(time, '0', sizeof(time));

		scanf("%d %d", &wokers, &departs);
		for (j = 0; j < wokers; j++)
		{
			scanf("%d %d %d", &start, &end, &idx);

			/* possible conference time check */
			memset(&time[idx][start], '1', 
					&time[idx][end] - 
					&time[idx][start] + 1);

			/* save ending point in array */
			if (end_idx < end)
				end_idx = end;
		}

#if 0
		time[1][end_idx + 1] = '\0';
		time[2][end_idx + 1] = '\0';
		time[3][end_idx + 1] = '\0';

		printf("%s\n", time[1]);
		printf("%s\n", time[2]);
		printf("%s\n", time[3]);
#endif

		/* data sum */
		memset(sum, 0x00, sizeof(sum));
		for (j = 0; j <= end_idx; j++)
			for (k = 1; k <= departs; k++)
				sum[j] += (time[k][j] - '0');

		/* find max time blocks */
		for (j = 0; j < end_idx; j++)
		{
//			printf("%d : %d\n", j, sum[j]);
			if (sum[j] == departs)
				cnt++;
			else
			{
				if (max < cnt)
				{
					idx = j;
					max = cnt;
				}
				cnt = 0;
			}
		}

		if (max < cnt)
		{
			idx = j;
			max = cnt;
		}

		max ? printf("%d %d\n", idx - max, idx - 1) : printf("-1\n");
		max = cnt = end_idx = 0;
	}

	return 0;
}
