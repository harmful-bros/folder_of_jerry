//###########################################################################
//
// FILE		: menu.c
//
// TITLE		: micromouse H2 menu source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2011.10.01 $
//###########################################################################

#ifndef __MENU_H__
#define __MENU_H__

typedef struct switch_table_variable
{
	int32 int32row;
	int32 int32col;

	int32 int32vfd_chatt_row;
	int32 int32vfd_chatt_col;

	Uint16 u16up:1;
	Uint16 u16down:1;
	Uint16 u16left:1;
	Uint16 u16right:1;

	Uint16 u16long_rkey:1;
	
}sw_t;

typedef enum menu_table_value
{
	HIGH , // 스위치가 풀업이므로 high가 zero...
	LOW ,

	ROW = 3 , 
	COL = 5 , 
	VFD_LIST = 5 , 

	ZERO = 0,

	KEY_CHATTERING = 22,
	LONG_KEY_CAHTTERING = 700 , 

	DELAY_KEY = 300	
	
}menu_table_value_e;


#define SWU_BELL	buzz( 800 , 24 );	buzz( 600 , 26 )
#define SWR_BELL	buzz( 900 , 24 );	buzz( 700 , 26 )
#define SWLU_BELL	buzz( 700 , 36 );	buzz( 500 , 36 )
#define SWSU_BELL	buzz( 750 , 24 );	buzz( 650 , 26 )


extern void run_acc_select_func( void );

extern void menu_func_init( void );
extern void menu_select_func( void );
extern void buzz( Uint16 hz , Uint16 time );
extern void h2_delay( void );

#endif

