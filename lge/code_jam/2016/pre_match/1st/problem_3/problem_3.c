#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define JSLEE_DEBUG
//#define ERROR_DISPOSAL

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

	ALPHABET_NUM = 26
};

typedef enum
{
	T_MAX = 100,
	N_MAX = 100000, 

}overflow_e;

static int _divide_string_to_classify(FILE *pwrite, char *pstr);

#ifdef ERROR_DISPOSAL
static inline int _input_case(int *pcase, overflow_e mode);
static inline int _check_overflow(int data, int min, int max);
#endif
static inline int _check_array_value(int *parr);

///////////////////////////////////////////////////////////////////////////////

static int _divide_string_to_classify(FILE *pwrite, char *pstr)
{
	int i;
	int j;
	int k;

	int len;
	int str_len;
	int cnt = 0;
	int div = 2;

	int idx;
	char sub;
	int arr[ALPHABET_NUM] = {0, };

#ifdef ERROR_DISPOSAL
	if (pwrite == NULL || pstr == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}
#endif

	scanf("%s", pstr);
	len = str_len = strlen(pstr) - 1;
	while (len > 0)
	{
//		printf("@@ %d\t", len);
		for (i = 0; i < len; i++)
		{
			if (len == str_len)
			{
				if (pstr[i] == pstr[i + 1])
					cnt++;
			}
			else
			{
				for (j = i, k = 0; k < div; j++, k++)
				{
					sub = (pstr[j] >= 'a') ? 'a' : 'A';
					idx = pstr[j] - sub;
#ifdef ERROR_DISPOSAL
					if (_check_overflow(idx, 
							0, ALPHABET_NUM) < 0)
					{
						MSG_OVERFLOW("Alphabet Index");
						goto error;
					}
#endif
					arr[idx]++;
				}

				cnt += _check_array_value(arr);
				memset((void *)arr, 0x00, sizeof(arr));
			}
		}
		div += 2;
		len -= 2;
	}
//	printf("\n");

//	printf("%d\n", cnt);
	fprintf(pwrite, "%d\n", cnt);
	return 0;

#ifdef ERROR_DISPOSAL
error :
	return -1;
#endif
}

int main(int argc, char *argv[])
{
	int i;
	int t_case = 0;

	FILE *pread = NULL;
	FILE *pwrite = NULL;

	char *pstart = NULL;
	char write_str[64] = {0, };

	char str[N_MAX] = {0, };

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
#ifdef ERROR_DISPOSAL
	if (_input_case(&t_case, T_MAX) < 0)
		goto error;
#else
	scanf("%d", &t_case);
#endif

	for (i = 0; i < t_case; i++)
	{
		/* TODO */
		if (_divide_string_to_classify(pwrite, str) < 0)
			goto error;

	}

error :
	return 0;
}

#ifdef ERROR_DISPOSAL
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
#endif

static inline int _check_array_value(int *parr)
{
	int i = 0;
#ifdef ERROR_DISPOSAL
	if (parr == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}
#endif

	for (i = 0; i < ALPHABET_NUM; i++)
	{
		if (parr[i] & 0x1)
			break;
	}

#ifdef ERROR_DISPOSAL
error :
#endif
	return (i == ALPHABET_NUM) ? 1 : 0;
}
