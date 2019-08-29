#include "common_services.h"

static int _check_front_number_for_common_services(const char *pstr);

///////////////////////////////////////////////////////////////////////////////

static int _check_front_number_for_common_services(const char *pstr)
{
	if (pstr == NULL || strlen(pstr) < 3)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* Common services nubmer have to start 0N0. */
	if (pstr[0] != '0' || pstr[2] != '0')
	{
		MSG_NUM_OVERFLOW;
		goto error;
	}

	if (pstr[1] - '0' < N_STYLE || pstr[1] - '0' > NUM_END)
	{
		MSG_NUM_OVERFLOW;
		goto error;
	}

	return 0;

error :
	return -1;
}

int check_number_to_common_services(char *pstr)
{
	int len;

	/* Start number check. pstr[0], [1], [2] -> 0N0 */
	if (_check_front_number_for_common_services(pstr) < 0)
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
