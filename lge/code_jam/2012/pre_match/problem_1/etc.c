#include "etc.h"

static int _check_front_number_for_etc(const char *pstr);

///////////////////////////////////////////////////////////////////////////////

static int _check_front_number_for_etc(const char *pstr)
{
	if (pstr == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* ETC nubmer have to start 1XXX - XXXX. */
	if (pstr[0] != '1' || strlen(pstr) != REMAIN_NUM_8)
	{
		MSG_NUM_OVERFLOW;
		goto error;
	}

	return 0;

error :
	return -1;
}

int check_number_to_etc(char *pstr)
{
	/* Start number check. pstr[0] -> 1XXX-XXXX */
	if (_check_front_number_for_etc(pstr) < 0)
		goto error;

	/* add first '-' */
	memmove(pstr + 5, pstr + 4, strlen(pstr + 4));
	pstr[4] = '-';
	pstr[strlen(pstr)] = '\0';

	return 0;

error :
	return -1;
}

