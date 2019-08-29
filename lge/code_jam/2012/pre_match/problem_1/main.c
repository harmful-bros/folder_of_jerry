#include "main.h"
#include "error.h"
#include "international.h"
#include "mobile_communications.h"
#include "common_services.h"
#include "area_code.h"
#include "etc.h"

typedef enum case_information
{
	INTERNATIONAL,
	MOBILE_COMMUNI,
	COMMOMN_SERVICES,
	AREA_CODE,
	ETC_NUM,

	TOTAL_CASE_NUM
}case_e;

static FILE *_open_file(void);
static int _close_file(FILE **ppfile);

static int _disposal_string_and_print(FILE *pfile);

///////////////////////////////////////////////////////////////////////////////

static FILE *_open_file(void)
{
	/* Create memory. */
	FILE *pnew = fopen(TXT_FILE_NAME, "r");
	if (pnew == NULL)
	{
		MSG_FAIL_FILE;
		goto error;
	}

error :
	return pnew;
}

static int _close_file(FILE **ppfile)
{
	/* Pointer error. */
	if (ppfile == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* Destory memory. */
	if (*ppfile)
	{
		fclose((FILE *)*ppfile);
		*ppfile = NULL;
	}
	
	return 0;

error :
	return -1;
}

static int _disposal_string_and_print(FILE *pfile)
{
	int i;
	int len;
	char str[BUF_MAX] = {0, };

	int (*pfunc[TOTAL_CASE_NUM])(char *pstr);

	/* Pointer error. */
	if (pfile == NULL)
	{
		MSG_FAIL_FILE;
		goto error;
	}

	/* init func pointer */
	pfunc[INTERNATIONAL] 	= check_number_to_international;
	pfunc[MOBILE_COMMUNI] 	= check_number_to_mobile_communications;
	pfunc[COMMOMN_SERVICES] = check_number_to_common_services;
	pfunc[AREA_CODE] 	= check_number_to_area_code;
	pfunc[ETC_NUM]		= check_number_to_etc;

	while (fgets(str, sizeof(str), pfile))
	{
		/*  for fgets*/
		str[strlen(str) - 1] = '\0';
		printf("%13s\t", str);

		/* error!! */
		if (disposal_char_error(str) < 0)
			goto error;

		/* String length overflow check. */
		if ((len = check_length_overflow(str)) < 0)
			goto print;

		/* check number to change phone number */
		for (i = 0; i < TOTAL_CASE_NUM; i++)
		{
			if (*pfunc[i] && pfunc[i](str) == 0)
				goto print;
		}
	print:
		printf("%13s\t%3d\n", str, len);
	}

	return 0;

error :
	return -1;
}

int change_string_to_phone_number(char *pstr, check_num_e len)
{
	int idx;

	if (pstr == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* add first '-' */
	memmove(pstr + 1, pstr, len);
	pstr[0] = '-';

	/* add second '-' */
	idx = (len == REMAIN_NUM_7) ? 4 : 5;
	memmove(pstr + idx + 1, pstr + idx, strlen(pstr + idx));
	pstr[idx] = '-';

	/* phone number end,, */
	pstr[idx + 5] = '\0';
	
	return 0;

error :
	return -1;
}

int main(void)
{
	/* File open. */
	FILE *pfile = _open_file();
	if (pfile == NULL)
		goto error;
	
	/* File contents disposal. */
	if (_disposal_string_and_print(pfile) < 0)
		goto error;

	/* File close. */
	_close_file((FILE **)&pfile);

error :
	printf("\n\n");
	return 0;
}
