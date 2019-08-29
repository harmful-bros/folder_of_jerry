//###########################################################################
//
// FILE			: menu.h
//
// TITLE			: _varhae_(v.28335) menu header file
//
// Author		: leejaeseong
//
// Company		: Hertz
//
//###########################################################################
// $Release Date: 2009.07.03 $
//###########################################################################

#ifndef __MENU_H__
#define __MENU_H__


#define SWU_BELL	buzz( 1100 , 12 );	buzz( 800 , 13 )
#define SWR_BELL	buzz( 1200 , 12 );	buzz( 900 , 13 )
#define SWLU_BELL	buzz( 900 , 18 );	buzz( 600 , 18 )
#define SWSU_BELL	buzz( 1000 , 12 );	buzz( 700 , 13 )

typedef enum
{
	HIGH, // 스위치가 풀업이므로 high가 zero...
	LOW,

	ZERO = 0,

	ROW = 3,
	COL = 3,
	VFD_LIST = 9,
	
	KEY_CHATTERING = 25,
	LONG_KEY_CAHTTERING = 1400 , 

	DELAY_KEY = 300
	
}e_menu_define;

typedef enum
{
	NILL,

	ONE = 1,
	FIVE = 5 , 
	TEN = 10,
	FIFTY = 50,
	HUND = 100,
	FHUND = 500 , 
	THOU = 1000
		
}e_ctrl_define;

typedef enum
{
	TURN_VEL,
	MAX_VEL,
	T45_VEL , 
	S44S_VEL , 
	LARGE_VEL , 
	SHIFT_LEVEL , 
	DECEL_DIST_SCOPE , 
	ESCAPE45A_VEL , 
	LIMIT_VEL , 	
	FORCE_MARK_CNT , 
	S4S_VEL , 
	VEL_LIST_END

}e_vel_menu;

typedef enum
{
	TURN_ACC,
	MAX_ACC,
	MID_ACC , 
	SHORT_ACC ,
	LARGE_ACC , 
	A45_ACC , 
	END_ACC ,
	INVERSE_MODE ,
	LARGE_TURN_MODE ,
	MARK_GYRO_CONFIRM , 
	END_DIST_VALUE ,
	ACC_LIST_END
	
}e_acc_menu;

typedef enum
{
	SEN_VAL , 
	SEN_DIV ,
	SEN_DATA,
	SEN_POS,
	SEN_STATE,	
	GYRO_VAL,
	GYRO_ANGLE , 
	CPS_VAL , 
	PWM_TEST , 
	DEBUG_LIST_END
	
}e_debug_menu;

typedef enum
{
	RALLY_TURN_VEL , 
	RALLY_MAX_ACC,
	RALLY_MID_ACC , 
	RALLY_SHORT_ACC , 
	RALLY_45T_ACC ,
	RALLY_S44S_VEL , 
	RALLY_S4S_VEL , 
	RALLY_ESC45_VEL , 	
	RALLY_LARGE_ACC , 
	RALLY_LIMIT_VEL ,
	RALLY_END_ACC, 
	RALLY_END_DIST ,
	RALLY_SHIFT_LEVEL , 
	RALLY_POINT_END

}e_rally_point_menu;

typedef volatile struct
{
	e_ctrl_define num;
	int (*vel_ctr)( e_ctrl_define num , volatile int32 *value);
	volatile int32 *variable;
	
}func_ctrl;

typedef enum
{
	CONTROL , 
	DEBUG , 
	RUNNING , 
	REVISION

}e_menu_mode;

extern int plus( e_ctrl_define num , volatile int32 *value );
extern int minus( e_ctrl_define num, volatile int32 *value );

extern void menu_func_init( void );
extern void menu_select( void );
extern void buzz( Uint16 hz , Uint16 time );
extern void vh_delay(void);

#endif


