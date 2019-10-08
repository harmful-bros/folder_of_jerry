//###########################################################################
//
// FILE		: smooth_turn.h
//
// TITLE		: micromouse H2 smooth header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2012.03.10 $
//###########################################################################

#ifndef __SMOOTH_TURN__
#define __SMOOTH_TURN__

typedef volatile enum block_to_block
{
	TURN_TO_STRAIGHT , 
	TURN_TO_TURN , 
	TURN_TO_BACKTURN

}block_to_block_e;

typedef volatile enum turn_velocity_select
{
	V_650 , 
	V_800 , 
	V_1000 , 
	V_1200 , 
	V_FIR_DIG

}turn_vel_e;

extern void init_select_fuction_pointer( void );
extern void straight_run_test_func( void );
extern void smoothturn_test_func( void );


#endif

