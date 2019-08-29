#include "area_code.h"

static int _check_front_number_for_area_code(const char *pstr);

///////////////////////////////////////////////////////////////////////////////

static int _check_front_number_for_area_code(const char *pstr)
{
	int ret = -1;

	if (pstr == NULL || strlen(pstr) < 4)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* Area code nubmer have to start 02 or 0NX. */
	if (pstr[0]  == '0' && pstr[1] == '2')
	{
		/* 02 - NXXX - XXXXX */
		if (pstr[2] - '0' < N_STYLE || pstr[2] - '0' > NUM_END)
		{
			MSG_NUM_OVERFLOW;
			goto error;
		}
		ret = 0;
	}
	else
	{
		/* 0NX - NXX - XXXX */
		if (pstr[0] != '0' || 
		    (pstr[1] - '0' < N_STYLE || pstr[1] - '0' > NUM_END) ||
		    (pstr[2] - '0' < X_STYLE || pstr[2] - '0' > NUM_END) ||
		    (pstr[3] - '0' < N_STYLE || pstr[3] - '0' > NUM_END))
		{
			MSG_NUM_OVERFLOW;
			goto error;
		}
		ret = 1;
	}

error :
	return ret;
}

int check_number_to_area_code(char *pstr)
{
	int len;
	int idx;
	int idx_arr[] = {2, 3};

	/* Start number check. pstr[0], [1], [2], [3] -> 02-N or 0NX-N */
	if ((idx = _check_front_number_for_area_code(pstr)) < 0)
		goto error;

	/* To remain number length check. */
	len = strlen(pstr + idx_arr[idx]);
	if (len < REMAIN_NUM_7 || len > REMAIN_NUM_8)
		goto error;

	/* String is changed to phone number style. */
	if (change_string_to_phone_number(pstr + idx_arr[idx], 
				(check_num_e)len) < 0)
		goto error;

	return 0;

error :
	return -1;
}
