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
	BUF_MAX = 5, 
	T_MAX = 300,
	MEM_MAX = 256

}overflow_e;

typedef struct data_information
{
	int data;
	int len;
	char str[8];

}data_t;

static int _set_and_compute_array_value(data_t *pnum, FILE *pwrite);

static inline int _input_case(int *pcase);
static inline int _check_overflow(int data, int min, int max);

///////////////////////////////////////////////////////////////////////////////

static int _set_and_compute_array_value(data_t *pnum, FILE *pwrite)
{
	int i;
	int len;
	int sum_len;
	char *psum = NULL;

	int idx = 1;
	int cnt = 0;

	int add = 0;
	int carry = 0;

	int esc_flag = 0;
	int mem_cnt = 1;
	unsigned long long num_cnt = 1;

	scanf("%d %d %d %d %d", 
			&pnum[0].data, 
			&pnum[1].data, 
			&pnum[2].data, 
			&pnum[3].data, 
			&pnum[4].data);

	snprintf(pnum[0].str, sizeof(pnum[0].str), "%d", pnum[0].data);
	snprintf(pnum[1].str, sizeof(pnum[1].str), "%d", pnum[1].data);
	snprintf(pnum[2].str, sizeof(pnum[2].str), "%d", pnum[2].data);
	snprintf(pnum[3].str, sizeof(pnum[3].str), "%d", pnum[3].data);
	snprintf(pnum[4].str, sizeof(pnum[4].str), "%d", pnum[4].data);
	
	pnum[0].len = strlen(pnum[0].str);
	pnum[1].len = strlen(pnum[1].str);
	pnum[2].len = strlen(pnum[2].str);
	pnum[3].len = strlen(pnum[3].str);
	pnum[4].len = strlen(pnum[4].str);

	psum = (char *)malloc(sizeof(char) * MEM_MAX);
	if (psum == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}
	memset((void *)psum, 0x00, sizeof(char) * MEM_MAX);
	snprintf(psum, sizeof(char) * MEM_MAX, "%s", pnum[0].str);


	while (1)
	{
		len = sum_len = strlen(psum);
		if (sum_len < pnum[idx].len)
		{
			len = pnum[idx].len;
			if (len >= MEM_MAX)
			{
				mem_cnt++;
				psum = (char *)realloc(psum,
						sizeof(char) * 
						MEM_MAX * mem_cnt);
				if (psum == NULL)
				{
					MSG_MEM_SHORTAGE;
					goto error;
				}
			}
			memmove(&psum[len - sum_len], 
					&psum[0], sizeof(char) * sum_len);

			for (i = 0; i < len - sum_len; i++)
				psum[i] = '0';
		}

		for (i = len - 1; i >= 0; i--)
		{
			if (cnt < pnum[idx].len)
			{
				add = pnum[idx].str[pnum[idx].len - cnt - 1] - '0';
				cnt++;
			}
			else
				add = 0;

			psum[i] = ((psum[i] - '0') + add + carry) + '0';
			if (psum[i] > '9')
			{
				psum[i] = (psum[i] - '0') - 10 + '0';
				carry = 1;
			}
			else
				carry = 0;
		}

		if (carry)
		{
			if (len >= MEM_MAX - 1)
			{
				mem_cnt++;
				psum = (char *)realloc(psum,
						sizeof(char) * 
						MEM_MAX * mem_cnt);
				if (psum == NULL)
				{
					MSG_MEM_SHORTAGE;
					goto error;
				}
			}

			memmove(&psum[1], &psum[0], sizeof(char) * len);
			psum[0] = '1';
			carry = 0;
		}

//		printf("####%s####%llu$$%d\n", psum, num_cnt, len);

		esc_flag = 0;
		len = strlen(psum);
		if (len > 1)
		{
			for (i = 1; i < len; i++)
			{
				if (psum[0] != psum[i])
				{
					esc_flag = 1;
					break;
				}
			}

			if (esc_flag == 0)
				break;
		}

		cnt = 0;

		idx++;
		if (idx >= BUF_MAX)
			idx = 0;

		num_cnt++;
	}

//	printf("\n");

	fprintf(pwrite, "%llu %c(%d)\n", num_cnt % 1000000007ULL, psum[0], len);
//	printf("%llu %c(%d)\n", num_cnt, psum[0], len);

	if (psum)
	{
		free((void *)psum);
		psum = NULL;
	}

	return 0;

error :
	return -1;
}

int main(int argc, char *argv[])
{
	int i;
	int t_case = 0;

	FILE *pread = NULL;
	FILE *pwrite = NULL;

	char *pstart = NULL;
	char write_str[64] = {0, };

	data_t num[BUF_MAX];

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
	if (_input_case(&t_case) < 0)
		goto error;

	i = 0;
	for (i = 0; i < t_case; i++)
	{
		memset((void *)num, 0x00, sizeof(num));

		if (_set_and_compute_array_value(num, pwrite) < 0)
			goto error;

//		fprintf(pwrite, "\n");
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

static inline int _input_case(int *pcase)
{
	if (pcase == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	scanf("%d", pcase);
	if (_check_overflow(*pcase, 1, T_MAX) < 0)
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
