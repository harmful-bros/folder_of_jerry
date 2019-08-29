#include "mobile_communications.h"

static int _check_front_number_for_mobile_commnucations(const char *pstr);

///////////////////////////////////////////////////////////////////////////////

static int _check_front_number_for_mobile_commnucations(const char *pstr)
{
	if (pstr == NULL || strlen(pstr) < 3)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* Mobile communications nubmer have to start 01X. */
	if (pstr[0] != '0' || pstr[1] != '1')
	{
		MSG_NUM_OVERFLOW;
		goto error;
	}

	if (pstr[2] - '0' < X_STYLE || pstr[2] - '0' > NUM_END)
	{
		MSG_NUM_OVERFLOW;
		goto error;
	}

	return 0;

error :
	return -1;
}

int check_number_to_mobile_communications(char *pstr)
{
	int len;

	/* Start number check. pstr[0], [1], [2] -> 01X */
	if (_check_front_number_for_mobile_commnucations(pstr) < 0)
		goto error;

	/* To remain number length check. */
	len = strlen(pstr + 3);
	if (len < REMAIN_NUM_7 || len > REMAIN_NUM_8)
		goto error;

	/* String is changed to phone number style. */
	if (change_string_to_phone_number(pstr + 3, (check_num_e)len) < 0)
		goto error;

	return 0;

error :
	return -1;
}
