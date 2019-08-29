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
	TRUE,
	FLAG
};

typedef enum
{
	T_MAX = 65,
	N_MAX = 100000, 

}overflow_e;

typedef struct data_information
{
	int *parr;

	int cnt;
	int max;
	int min;
	unsigned long long sum;

}data_t;

static void *_allocate_memory(size_t size);
static int _free_memory(void **ppdel);

static int _set_data_in_array(data_t *pdata, int n_case);
static int _find_to_matching_figure(FILE *pwrite, int n_case);

static inline int _input_case(int *pcase, overflow_e mode);
static inline int _check_overflow(int data, int min, int max);
static inline int _check_sign(int data);

///////////////////////////////////////////////////////////////////////////////

static void *_allocate_memory(size_t size)
{
	void *pnew = malloc(size);
	if (pnew == NULL)
		goto error;

	MSG_CHECK_MEM("Malloc", pnew);
	memset(pnew, 0x00, size);

error :
	return pnew;
}

static int _free_memory(void **ppdel)
{
	if (ppdel == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	if (*ppdel)
	{
		MSG_CHECK_MEM("Free", *ppdel);
		free((void *)*ppdel);
		*ppdel = NULL;
	}

	return 0;

error :
	return -1;
}

static int _set_data_in_array(data_t *pdata, int n_case)
{
	int i;
	int abs_data;

	int sign_first;
	int sign_pre;
	int sign_after;

	if (pdata == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	for (i = 0; i < n_case; i++)
	{
		scanf("%d", &pdata->parr[i]);
		abs_data = abs(pdata->parr[i]);
		pdata->sum += (unsigned long long)abs_data;

		if (i)
		{
			/* find max/min value */
			if (pdata->max > abs_data)
				pdata->max = abs_data;
			else if (pdata->min < abs_data)
				pdata->min = abs_data;

			/* sign check */
			sign_after = _check_sign(pdata->parr[i]);
			if (sign_pre != sign_after)
			{
				pdata->cnt++;
				sign_pre = sign_after;
			}
		}
		else
		{
			pdata->max = pdata->min = abs_data;
			sign_first = sign_pre = _check_sign(pdata->parr[0]);
		}
	}

	/* first idx vs end idx */
	if (sign_first != sign_after)
		pdata->cnt++;

	return 0;

error :
	return -1;
}

static int _find_to_matching_figure(FILE *pwrite, int n_case)
{
	data_t info[2];

	if (pwrite == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	memset((void *)info, 0x00, sizeof(info));

	info[0].parr = (int *)_allocate_memory(sizeof(int) * n_case);
	info[1].parr = (int *)_allocate_memory(sizeof(int) * n_case);
	if (info[0].parr == NULL || info[1].parr == NULL)
	{
		MSG_MEM_SHORTAGE;
		goto error;
	}

	if (_set_data_in_array(&info[0], n_case) < 0)
		goto error;

	if (_set_data_in_array(&info[1], n_case) < 0)
		goto error;

#ifdef JSLEE_DEBUG
	printf("SUM : %10llu %10llu\n", info[0].sum, info[1].sum);
	printf("CNT : %10d %10d\n", info[0].cnt, info[1].cnt);
	printf("MAX : %10d %10d\n", info[0].max, info[1].max);
	printf("MIN : %10d %10d\n\n", info[0].min, info[1].min);
#endif

	fprintf(pwrite, "%d\n", 
			(info[0].sum != info[1].sum || 
			 info[0].cnt != info[1].cnt || 
			 info[0].max != info[1].max || 
			 info[0].min != info[1].min) ? 0 : 1);

	_free_memory((void *)&info[1].parr);
	_free_memory((void *)&info[0].parr);

	return 0;

error :
	_free_memory((void *)info[1].parr);
	_free_memory((void *)info[0].parr);

	return -1;
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

	if (argc != 2)
	{
		printf("Argument number error.\n");
		goto error;
	}
	
	/* File that test case open */
	pread = freopen(argv[1], "r", stdin);
	if (pread == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* File to write create */
	pstart = strstr(argv[1], ".");
	argv[1][pstart - argv[1]] = '\0';
	snprintf(write_str, sizeof(write_str), "%s.out", argv[1]);

	/* file open */
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
		/* input N case */
		if (_input_case(&n_case, N_MAX) < 0)
			goto error;

		/* find */
		if (_find_to_matching_figure(pwrite, n_case) < 0)
			goto error;
	}

error :
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

static inline int _check_sign(int data)
{
	return data >> ((sizeof(int) << 3) - 1);
}
