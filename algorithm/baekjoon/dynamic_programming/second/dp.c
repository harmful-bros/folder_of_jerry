#include <stdio.h>

int dp[17][17];
int arr[17][17];

int main(void)
{
	int i;
	int j;
	int num;
	
	scanf("%d", &num);
	for (i = 1; i <= num; i++)
		for (j = 1; j <= num; j++)
			scanf("%d", &arr[i][j]);


	return 0;
}
