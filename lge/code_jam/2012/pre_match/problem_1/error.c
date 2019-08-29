#include "error.h"

static inline int _check_right_string(const char *pstr)
{
	int idx;
	char *ptemp;

	if (pstr == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	idx = 0;
	ptemp = (char *)pstr;
	while (ptemp[idx])
	{
		if (ptemp[idx] < '0' || ptemp[idx] > '9')
		{
			if (!(ptemp[idx] == '-' || ptemp[idx] == ' '))
			{
				MSG_NUM_OVERFLOW;
				goto error;
			}
		}
		idx++;
	}

	return 0;

error :
	return -1;
}

static inline int _remove_special_charater(const char *pstr, const char *pch)
{
	char *ptr;
	if (pstr == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* Remove special charater in string. */
	while ((ptr = strstr(pstr, pch)))
	{
		memmove(ptr, ptr + 1, strlen(ptr + 1));
		ptr[strlen(ptr + 1)] = '\0';
	}

	return 0;

error :
	return -1;
}

int check_length_overflow(const char *pstr)
{
	int len;
	if (pstr == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* Is string length overflow? */
	len = strlen(pstr);
	if (len < NUM_MIN || len > NUM_MAX)
	{
		MSG_NUM_OVERFLOW;
		goto error;
	}

	return len;

error :
	return -1;
}

int disposal_char_error(const char *pstr)
{
	/* Is this right charater string? */
	if (_check_right_string(pstr) < 0)
		goto error;

	/* Remove blank in string. */
	if (_remove_special_charater(pstr, " ") < 0)
		goto error;

	/* Remove bar in string. */
	if (_remove_special_charater(pstr, "-") < 0)
		goto error;

	return 0;

error :
	return -1;
}
