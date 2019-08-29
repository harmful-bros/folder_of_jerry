#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

enum
{
	FALSE = -1,
	TRUE,

	X_MODE = 0,
	Y_MODE,

	OFF = 0,
	ON
};

typedef enum 
{
	T_MAX = 10,
	N_MAX = 10,

	COORDI_MAX = 200,
	BUF_MAX

}overflow_e;

typedef struct coordinates_information
{
	int start_x;
	int start_y;

	int end_x;
	int end_y;
}cd_t;

typedef struct relative_direction
{
	int up;
	int down;
	int left;
	int right;

	int flag;

}re_dir_t;

/* for coordinates */
static int _check_overflow_all_data(cd_t *pcd);
static int _input_all_box_coordinates(cd_t *pcd);
static cd_t *_input_sub_box_number(int *pcnt);

/* for maze array */
static int _set_dir_in_array(cd_t *pall, cd_t *psub, 
		re_dir_t (*pdir)[BUF_MAX], int cnt);
static inline int _compare_relative_direction(re_dir_t *pdir, 
		int coordi, int start, int end, int mode);
static int _depth_first_search(cd_t *pall, re_dir_t (*pdir)[BUF_MAX], 
		int x, int y, int cnt, int *pmin, int *pmin_cnt);

/* for inline func */
static inline int _input_total_checking_number(int *ptotal);

/* for memory */
static inline int _create_memory_for_min_path(int **ppmin, int **ppmin_cnt,
		const int total_cnt);
static inline int _destory_memory_for_min_path(int **ppmin, int **ppmin_cnt);
static inline void *_create_memory(size_t size);
static inline int _destory_memory(void **ppdel);

static inline int _input_information_for_box_coordi(cd_t *pcd);
static inline int _check_overflow(int data, int min, int max);

///////////////////////////////////////////////////////////////////////////////

static int _check_overflow_all_data(cd_t *pcd)
{
	if (pcd == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* error check!! */
	if (_check_overflow(pcd->start_x, 0, COORDI_MAX) < 0)
		goto overflow;

	if (_check_overflow(pcd->start_y, 0, COORDI_MAX) < 0)
		goto overflow;

	if (_check_overflow(pcd->end_x, pcd->start_x, COORDI_MAX) < 0)
		goto overflow;

	if (_check_overflow(pcd->end_y, pcd->start_y, COORDI_MAX) < 0)
		goto overflow;

	return 0;

overflow :
	MSG_NUM_OVERFLOW;
error :
	return -1;
}

static int _input_all_box_coordinates(cd_t *pcd)
{
	if (pcd == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* intput all box data */
	if (_input_information_for_box_coordi(pcd) < 0)
		goto error;

	/* check overflow */
	if (_check_overflow_all_data(pcd) < 0)
		goto error;

	return 0;
error :
	return -1;
}

static cd_t *_input_sub_box_number(int *pcnt)
{
	int i;
	cd_t *pnew = NULL;

	if (pcnt == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	scanf("%d", pcnt);
	if (_check_overflow(*pcnt, 0, N_MAX) < 0)
		goto error;

	pnew = (cd_t *)_create_memory(sizeof(cd_t) * (*pcnt));
	if (pnew == NULL)
	{
		MSG_MEM_SHORTAGE;
		goto error;
	}

	for (i = 0; i < *pcnt; i++)
	{
		/* input sub box data */
		if (_input_information_for_box_coordi(&pnew[i]) < 0)
			goto error;

		/* check overflow */
		if (_check_overflow_all_data(&pnew[i]) < 0)
			goto error;
	}
	
	return pnew;
error :
	_destory_memory((void *)&pnew);
	return NULL;
}

static int _set_dir_in_array(cd_t *pall, cd_t *psub, 
		re_dir_t (*pdir)[BUF_MAX], int cnt)
{
	int i;
	int j;
	int k;

	if (pall == NULL || psub == NULL || pdir == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	for (i = 0; i < cnt; i++)
	{
		for (j = psub[i].start_y; j <= psub[i].end_y; j++)
		{
			for (k = psub[i].start_x; k <= psub[i].end_x; k++)
			{
				/* left, right */
				if (_compare_relative_direction(
							&pdir[j][k],
							k, 
							psub[i].start_x,
							psub[i].end_x,
							X_MODE) < 0)
					goto error;

				/* up, down */
				if (_compare_relative_direction(
							&pdir[j][k],
							j, 
							psub[i].start_y,
							psub[i].end_y,
							Y_MODE) < 0)
					goto error;

				/* set flag value */
				pdir[j][k].flag = 1;
			}
		}	
	}

	return 0;
error :
	return -1;
}

static int _depth_first_search(cd_t *pall, re_dir_t (*pdir)[BUF_MAX], 
		int x, int y, int cnt, int *pmin, int *pmin_cnt)
{
	if (pall == NULL || pdir == NULL || pmin == NULL || pmin_cnt == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	if (x == pall->end_x && y == pall->end_y)
	{
		if (*pmin >= cnt)
		{
			*pmin_cnt = (*pmin == cnt) ? *pmin_cnt + 1 : 1;
			*pmin = cnt;
		}

		goto escape;
	}


//	printf("%d %d \n", y, x);

	pdir[y][x].flag = 0;

	/* Is it possible to move UP? */
	if (y > pall->start_y && pdir[y - 1][x].flag && pdir[y][x].up)
		_depth_first_search(pall, pdir, x, y - 1, cnt + 1, 
				pmin, pmin_cnt);

	/* Is it possible to move DOWN? */
	if (y < pall->end_y && pdir[y + 1][x].flag && pdir[y][x].down)
		_depth_first_search(pall, pdir, x, y + 1, cnt + 1, 
				pmin, pmin_cnt);

	/* Is it possible to move LEFT? */
	if (x > pall->start_x && pdir[y][x - 1].flag && pdir[y][x].left)
		_depth_first_search(pall, pdir, x - 1, y, cnt + 1, 
				pmin, pmin_cnt);

	/* Is it possible to move RIGHT? */
	if (x < pall->end_x  && pdir[y][x + 1].flag && pdir[y][x].right)
		_depth_first_search(pall, pdir, x + 1, y, cnt + 1, 
				pmin, pmin_cnt);

	pdir[y][x].flag = 1;

escape :
	return 0;

error :
	return -1;
}

static int _depth_first_search__(cd_t *pall, re_dir_t (*pdir)[BUF_MAX], 
		int x, int y, int cnt, int *pmin, int *pmin_cnt)
{
	if (pall == NULL || pdir == NULL || pmin == NULL || pmin_cnt == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	while (1)
	{
		if (x == pall->end_x && y == pall->end_y)
		{
			if (*pmin >= cnt)
			{
				*pmin_cnt = (*pmin == cnt) ? *pmin_cnt + 1 : 1;
				*pmin = cnt;
			}
		}

		pdir[y][x].flag = 0;

		/* Is it possible to move UP? */
		if (y > pall->start_y && pdir[y - 1][x].flag && pdir[y][x].up)
		{
			y--;
		}

		/* Is it possible to move DOWN? */
		if (y < pall->end_y && pdir[y + 1][x].flag && pdir[y][x].down)
		{
			y++;
		}

		/* Is it possible to move LEFT? */
		if (x > pall->start_x && pdir[y][x - 1].flag && pdir[y][x].left)
		{
			x--;
		}

		/* Is it possible to move RIGHT? */
		if (x < pall->end_x && pdir[y][x + 1].flag && pdir[y][x].right)
		{
			x++;
		}

		pdir[y][x].flag = 1;
	}
	

escape :
	return 0;

error :
	return -1;
}

int main(void)
{
	int i;
	int cnt = 0;
	int total_cnt = 0;

	int *pmin = NULL;
	int *pmin_cnt = NULL;

	cd_t all_cd;
	cd_t *psub_cd = NULL;

	re_dir_t dir[BUF_MAX][BUF_MAX];

	/* input total number */
	if (_input_total_checking_number(&total_cnt) < 0)
		goto error;

	/* for min path save */
	if (_create_memory_for_min_path(&pmin, &pmin_cnt, total_cnt) < 0)
		goto error;

	for (i = 0; i < total_cnt; i++)
	{
		/* input cooridinates for all box */
		memset((void *)&all_cd, 0x00, sizeof(cd_t));
		if (_input_all_box_coordinates(&all_cd) < 0)
			goto error;

		/* input coordinates for sub box */
		psub_cd = _input_sub_box_number(&cnt);
		if (psub_cd == NULL)
			goto error;

		/* set direction value in array */
		memset((void *)dir, 0x00, sizeof(dir));
		if (_set_dir_in_array(&all_cd, psub_cd, dir, cnt) < 0)
			goto error;

#ifdef JSLEE_DEBUG
		printf("\n");

		int j;
		int k;
		for (j = all_cd.start_y; j <= all_cd.end_y; j++)
		{
			for (k = all_cd.start_x; k <= all_cd.end_x; k++)
			{
				printf("[%d][%d] U:%d D:%d L:%d R:%d F:%d\n",
						j, k, 
						dir[j][k].up,
						dir[j][k].down,
						dir[j][k].left,
						dir[j][k].right,
						dir[j][k].flag);
			}
			printf("\n");
		}
#endif

		pmin[i] = BUF_MAX * BUF_MAX;
		if (_depth_first_search(&all_cd, dir, 
					all_cd.start_x, all_cd.start_y, 
					0, &pmin[i], &pmin_cnt[i]) < 0)
			goto error;

		_destory_memory((void **)&psub_cd);
	}

	for (i = 0; i < total_cnt; i++)
	{
//		printf("Min Path : %d\n", pmin[i]);
		printf("Path Cnt : %d\n", pmin_cnt[i]);
	}

	return 0;

error :
	_destory_memory((void **)&psub_cd);
	_destory_memory_for_min_path(&pmin, &pmin_cnt);
	return -1;
}

static inline int _input_total_checking_number(int *ptotal)
{
	if (ptotal == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	scanf("%d", ptotal);
	if (_check_overflow(*ptotal, 0, T_MAX) < 0)
		goto overflow;

	return 0;

overflow :
	MSG_NUM_OVERFLOW;
error :
	return -1;
}

static inline int _create_memory_for_min_path(int **ppmin, int **ppmin_cnt,
		const int total_cnt)
{
	if (ppmin == NULL || ppmin_cnt == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	*ppmin = (int *)_create_memory(sizeof(int) * total_cnt);
	if (*ppmin == NULL)
	{
		MSG_MEM_SHORTAGE;
		goto error;
	}

	*ppmin_cnt = (int *)_create_memory(sizeof(int) * total_cnt);
	if (*ppmin_cnt == NULL)
	{
		MSG_MEM_SHORTAGE;
		goto error;
	}

	return 0;

error :
	_destory_memory_for_min_path(ppmin, ppmin_cnt);
	return -1;
}

static inline int _destory_memory_for_min_path(int **ppmin, int **ppmin_cnt)
{
	if (ppmin == NULL || ppmin_cnt == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	if (*ppmin)
	{
		free((void *)*ppmin);
		*ppmin = NULL;
	}

	if (*ppmin_cnt)
	{
		free((void *)*ppmin_cnt);
		*ppmin_cnt = NULL;
	}

	return 0;
error :
	return -1;
}

static inline void *_create_memory(size_t size)
{
	/* allocate new memory */
	void *pnew = malloc(size);
	if (pnew == NULL)
		goto error;

	memset(pnew, 0x00, size);
error:
	return pnew;
}

static inline int _destory_memory(void **ppdel)
{
	if (ppdel == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	/* delete memory */
	if (*ppdel)
	{
		free((void *)*ppdel);
		*ppdel = NULL;
	}

	return 0;
error :
	return -1;
}

static inline int _input_information_for_box_coordi(cd_t *pcd)
{
	if (pcd == NULL)
	{
		MSG_MEM_EMPTY;
		goto error;
	}

	scanf("%d %d %d %d", &pcd->start_x, &pcd->start_y, 
			&pcd->end_x, &pcd->end_y);
	return 0;
error :
	return -1;
}

static inline int _check_overflow(int data, int min, int max)
{
	return (data < min || data > max) ? FALSE : TRUE;
}

static inline int _compare_relative_direction(re_dir_t *pdir, 
		int coordi, int start, int end, int mode)
{
	int *ptemp;

	if (coordi == start)
	{
		ptemp = (mode == X_MODE) ? &pdir->right : &pdir->down;
		*ptemp = ON;
	}
	else if (coordi == end)
	{
		ptemp = (mode == X_MODE) ? &pdir->left : &pdir->up;
		*ptemp = ON;
	}
	else
	{
		if (mode == X_MODE)
		{
			pdir->left = ON;
			pdir->right = ON;
		}
		else
		{
			pdir->up = ON;
			pdir->down = ON;
		}
	}

	return 0;
}
