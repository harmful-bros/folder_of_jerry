#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define JSLEE_DEBUG

#ifdef JSLEE_DEBUG
#define	MSG_MEM_SHORTAGE						\
	printf("[ERR] Memory shortage. %s %s %d\n",			\
			__FILE__, __func__, __LINE__)

#define MSG_MEM_EMPTY							\
	printf("[ERR] Memory points NULL status already. %s %s %d\n",	\
			__FILE__, __func__, __LINE__)

#define MSG_OVERFLOW(pstr)						\
	printf("[ERR] %s is overflow!! %s %s %d\n", 			\
			pstr, __FILE__, __func__, __LINE__)

#define MSG_CHECK_MEM(pstr, ptr)					\
	printf("%s : %p\n", pstr, ptr)
#else
#define	MSG_MEM_SHORTAGE				
#define MSG_MEM_EMPTY					
#define MSG_OVERFLOW(pstr)						
#define MSG_CHECK_MEM(pstr, ptr)					
#endif

enum
{
	FALSE = -1,
	TRUE
};

typedef enum
{
	T_MAX = 60,
	N_MAX = 100000, 

}overflow_e;

static int _sort_array_data(int *pnum, int n_case);
static int _find_maximum_bar(FILE *pwrite, const int *pnum, int n_case);

static inline int _input_case(int *pcase, overflow_e mode);
static inline int _check_overflow(int data, int min, int max);
static inline int _compare_func(const void *pnum_1, const void *pnum_2);

///////////////////////////////////////////////////////////////////////////////

static int _sort_array_data(int *pnum, int n_case)
{
	int i;
	if (pnum == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	for (i = 0; i < n_case; i++)
		scanf("%d", &pnum[i]);

	qsort(pnum, n_case, sizeof(int), _compare_func);

	return 0;
error :
	return -1;
}

static int _find_maximum_bar(FILE *pwrite, const int *pnum, int n_case)
{
	int i;
	int max = 0;
	int add = (n_case & 0x1) ? 1 : 0;

	for (i = 2; i < n_case; i += 2)
	{
		if (pnum[i] - pnum[i - 2] > max)
			max = pnum[i] - pnum[i - 2];
	}

	for (i = n_case - add - 1; i >= 2; i -= 2)
	{
		if (pnum[i] - pnum[i - 2] > max)
			max = pnum[i] - pnum[i - 2];
	}

	if (n_case >= 2 && pnum[1] - pnum[0] > max)
		max = pnum[1] - pnum[0];

	add = (max & 0x1) ? 1 : 0;
	fprintf(pwrite, "%d\n", (max >> 1) + add);

	return 0;
}

int main(int argc, char *argv[])
{
	int i;

	int t_case = 0;
	int n_case = 0;

	FILE *pread = NULL;
	FILE *pwrite = NULL;

	char *pstart = NULL;
	char write_str[64] = {0, };

	int num[N_MAX] = {0, };

	if (argc != 2)
	{
		printf("Argument number error.\n");
		goto error;
	}
	
	pread = freopen(argv[1], "r", stdin);
	if (pread == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	pstart = strstr(argv[1], ".");
	argv[1][pstart - argv[1]] = '\0';
	snprintf(write_str, sizeof(write_str), "%s.out", argv[1]);

	pwrite = fopen(write_str, "w");
	if (pwrite == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}
	
	/* input T case */
	if (_input_case(&t_case, T_MAX) < 0)
		goto error;

	i = 0;
	for (i = 0; i < t_case; i++)
	{
		memset((void *)&num, 0x00, sizeof(num));

		/* input N case */
		if (_input_case(&n_case, N_MAX) < 0)
			goto error;

		if (_sort_array_data(num, n_case) < 0)
			goto error;

		if (_find_maximum_bar(pwrite, num, n_case) < 0)
			goto error;
	}

error :
	if (pwrite)
	{
		fclose(pwrite);
		pwrite = NULL;
	}

	if (pread)
	{
		fclose(pread);
		pread = NULL;
	}

	return 0;
}

static inline int _input_case(int *pcase, overflow_e mode)
{
	if (pcase == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	scanf("%d", pcase);
	if (_check_overflow(*pcase, 1, (mode == T_MAX) ? T_MAX : N_MAX) < 0)
	{
		MSG_OVERFLOW("T Case");
		goto error;
	}

	return 0;
error :
	return -1;
}

static inline int _check_overflow(int data, int min, int max)
{
	return (data < min || data > max) ? FALSE : TRUE;
}

static inline int _compare_func(const void *pnum_1, const void *pnum_2)
{
	return (*(int *)pnum_1 - *(int *)pnum_2);
}
