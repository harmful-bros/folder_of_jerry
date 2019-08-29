#include "international.h"

static int _check_front_number_for_international(const char *pstr);

///////////////////////////////////////////////////////////////////////////////

static int _check_front_number_for_international(const char *pstr)
{
	if (pstr == NULL || strlen(pstr) < 3)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* International nubmer have to start 00Y. */
	if (pstr[0] != '0' || pstr[1] != '0')
	{
		MSG_NUM_OVERFLOW;
		goto error;
	}

	if (pstr[2] - '0' < Y_STYLE || pstr[2] - '0' > NUM_END)
	{
		MSG_NUM_OVERFLOW;
		goto error;
	}

	return 0;

error :
	return -1;
}

int check_number_to_international(char *pstr)
{
	/* Start number check. pstr[0], [1], [2] -> 0N0 */
	if (_check_front_number_for_international(pstr) < 0)
		goto error;

	/* add first '-' */
	memmove(pstr + 4, pstr + 3, strlen(pstr + 3));
	pstr[3] = '-';

	return 0;

error :
	return -1;
}
