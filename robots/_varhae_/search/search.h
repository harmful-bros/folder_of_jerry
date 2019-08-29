//###########################################################################
//
// FILE		: search.h
//
// TITLE		: _varhae_ Tracer search header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.11.15 $
//###########################################################################

#ifndef __SEARCH_H__
#define __SEARCH_H__

typedef enum
{
	ANGLE_DELAY = 175 , 
	STEP_CNT = 50 , 
	MARK_CNT_LIMIT = 255 , 
	LINE_OUT_DELAY = 500
	
}line_detec_e;

typedef enum
{
	DL_STR ,
	DL_45A = 50 , 
	DL_90A = 185 ,
	DL_180A = 135 , 
	DL_270A = 160

}speed_delay_e;


extern void line_info_debug( void );
extern int race_stop_check( void );
extern int line_out_func( void );
extern void turn_sort_division( sec_info_t *p_info , int32 i);
extern void line_information( turnmark_t *pmark );
extern void race_start_init( void );
extern void search_run( void );

#endif

