#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <string.h>

//#define JSLEE_DEBUG

#define TXT_FILE_NAME	"string.txt"

#ifdef JSLEE_DEBUG
#define MSG_FAIL_FILE							\
	printf("[ERR] Fail to open file. %s %s %d\n",			\
			__FILE__, __func__, __LINE__)

#define	MSG_MEM_SHORTAGE						\
	printf("[ERR] Memory shortage. %s %s %d\n",			\
			__FILE__, __func__, __LINE__)

#define MSG_MEM_EMPTY							\
	printf("[ERR] Memory points NULL status already. %s %s %d\n",	\
			__FILE__, __func__, __LINE__)

#define MSG_NUM_OVERFLOW						\
	printf("[ERR] Number is overflow!! %s %s %d\n",			\
			__FILE__, __func__, __LINE__)
#else
#define MSG_FAIL_FILE							
#define	MSG_MEM_SHORTAGE						
#define MSG_MEM_EMPTY					
#define MSG_NUM_OVERFLOW						
#endif

typedef enum
{
	BUF_MAX = 32,

	NUM_MIN = 8,
	NUM_MAX = 11

}max_overflow_e;

typedef enum
{
	X_STYLE,
	Y_STYLE,
	N_STYLE,

	NUM_END = 9,

	REMAIN_NUM_7 = 7,
	REMAIN_NUM_8 = 8

}check_num_e;

///////////////////////////////////////////////////////////////////////////////

extern int change_string_to_phone_number(char *pstr, check_num_e len);

#endif
