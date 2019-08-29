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

///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
	int i;
	int t_case = 0;

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
	scanf("%d", &t_case);

	for (i = 0; i < t_case; i++)
	{
		/* TODO */

	}

error :
	return 0;
}
