//###########################################################################
//
// FILE		: Variable.h
//
// TITLE		: _varhae33_ Tracer Variable header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.07.11 $
//###########################################################################



#ifndef  __VARIABLE_H__
#define  __VARIABLE_H__

#ifdef  __VARIABLE__

	#undef __VARIABLE__
	#define __VARIABLE_EXT__
	
#else

	#define __VARIABLE_EXT__ 	extern
	
#endif

#define	UP_SW		GpioDataRegs.GPADAT.bit.GPIO4
#define	DOWN_SW		GpioDataRegs.GPADAT.bit.GPIO2
#define	RIGHT_SW	GpioDataRegs.GPADAT.bit.GPIO5
#define	LEFT_SW		GpioDataRegs.GPADAT.bit.GPIO3

#define BUFF_MAX_SIZE				256


__VARIABLE_EXT__ volatile int32		g_int32menu_count,
									g_int32turn_vel , 
									g_int32turn_acc,
									g_int32sen_cnt , 
									g_int32adc_cnt ,
									g_int32pid_ISR_cnt , 
									g_int32time_cnt , 
									g_int32error_cnt , 
									g_int32mark_cnt ,
									g_int32total_mark , 
									g_int32speed_up_cnt , 
									g_int32max_speed ,
									g_int32max_acc , 
									g_int32end_acc , 
									g_int32mid_acc , 
									g_int32short_acc , 
									g_int32start_dist , 
									g_int32large_vel , 
									g_int32large_acc , 
									g_int32lineout_cnt , 
									g_int32shift_level , 
									g_int32decel_dist_scope , 
									g_int3245A_vel , 
									g_int32s44s_vel , 
									g_int3245A_acc , 
									g_int32pos_cnt , 
									g_int32escape45_vel , 
									g_int32force_mark , 
									g_int32limit_vel , 
									g_int32s4s_vel , 
									g_int32inverse_run , 
									g_int32large_turn_flag , 
									g_int32mark_gyro_toggle , 
									g_int32end_dist;

__VARIABLE_EXT__ volatile float32	g_fp32right_handle ,
									g_fp32left_handle ,
									g_fp32han_accstep ,
									g_fp32han_decstep ,
									g_fp32han_accmax ,
									g_fp32han_decmax ,
									g_fp32cross_dist , 
									g_fp32time , 
									g_fp32max_val , 
									g_fp32shift_pos_val , 
									g_fp32shift_dist , 
									g_fp32xrun_dist;


typedef enum
{
	L0 ,	L1 ,	L2 ,	L3 ,
	L4 ,	L5 ,	L6 ,	L7 ,
	R7 ,	R6 ,	R5 ,	R4 , 
	R3 ,	R2 ,	R1 ,	R0 		
}
pos_e;

typedef enum
{
	MAX_DIST_LIMIT = 2000 , 
	MID_DIST_LIMIT = 600 , 
	SHT_DIST_LIMIT = 400 , 
	END_DIST_LIMIT = 50
	
}fast_mode_e;

typedef enum
{
	NON_SHIFT ,

	LEFT_ONE_SHIFT , 
	LEFT_TWO_SHIFT , 	
	LEFT_THREE_SHIFT , 
	LEFT_FOUR_SHIFT ,
	LEFT_FIVE_SHIFT ,	
	LEFT_SIX_SHIFT , 
	LEFT_SEVEN_SHIFT ,
	LEFT_EIGHT_SHIFT ,	
	
	RIGHT_ONE_SHIFT = 1 , 
	RIGHT_TWO_SHIFT , 	
	RIGHT_THREE_SHIFT , 
	RIGHT_FOUR_SHIFT , 
	RIGHT_FIVE_SHIFT , 
	RIGHT_SIX_SHIFT , 
	RIGHT_SEVEN_SHIFT ,
	RIGHT_EIGHT_SHIFT	
	
}shift_rate_e;

typedef enum
{
	NONE = 0 , 
	S_ONE , 
	S_TWO , 
	S_THREE , 
	S_FOUR , 
	S_FIVE , 
	S_SIX , 
	S_SEVEN , 
	S_EIGHT , 
	S_NINE , 
	S_TEN , 
	S_ELEVEN , 
	S_TWELVE
	
}pos_idx_e;

typedef enum k_value_control
{
	ARBITRATE = 200
	
}kval_ctrl_e;

typedef enum error_information
{
	MARK_LIMIT = 20
		
}err_info_e;


//#define DEBUG_MODE

//#define	MOTOR_TEST


#define SAMPLE_FRQ					( float32 )0.00025			//250us

#define	MAX_SPEED_HANDLE			1.15

#define	LEFT_MARK_CHEK				0xf000
#define	RIGHT_MARK_CHEK				0x000f

#define	LEFT_ENABLE					0x0100
#define	RIGHT_ENABLE				0x0010

#define	HANDLE_CENTER				( float32 )( 8000.0 )
#define	CENTER_POSITION				( float32 )( 16000.0 )

#define	OUT_CONER_LIMIT				0.25
#define	IN_CONER_LIMIT				2.3
#define FASTRUN_IN_CONER_LIMIT		3.0


#define	SEARCH_ACC_VALUE			5
#define	SEARCH_DIST					1000

#define	STRAIGHT					0x0001
#define	LEFT_TURN					0x0002
#define	RIGHT_TURN					0x0004
#define	DIR_END						0x0008

#define	TURN_45						0x0010
#define	TURN_90						0x0020
#define	TURN_135					0x0040
#define	TURN_180					0x0080
#define	TURN_225					0x0100
#define	TURN_270					0x0200
#define	LARGE_TURN					0x0400

#define TURN_HARD_STAR				0x1000
#define TURN_HARD_T270				0x2000

#define KVAL_UP						0x0001
#define KVAL_DOWN					0x0002
#define KVAL_KP						0x0004
#define KVAL_KD						0x0008

#define MAX( a , b )				( ( a ) > ( b ) ? a : b )
#define MIN( a , b )				( ( a ) > ( b ) ? b : a )

#define POS_KP_UP					( float32 )1.5
//#define POS_KP_DOWN				( float32 )0.05
#define POS_KP_DOWN					( float32 )0.1 
//#define POS_KP_DOWN				( float32 )0.2 

#define POS_KD_UP					( float32 )4.4
#define POS_KD_DOWN					( float32 )3.4
//#define POS_KD_DOWN					( float32 )2.4


#define CROSS_DIST_LIMIT			( float32 )( 200.0 )

#define ON_L						1L

#define	LED_ON						GpioDataRegs.GPADAT.all |= 0x0cc1c000
#define	LED_OFF						GpioDataRegs.GPADAT.all &= ~(0x0cc1c000)

#define LED_SEL_ON( num )			GpioDataRegs.GPASET.all |= ( ON_L << num )
#define LED_SEL_OFF( num )			GpioDataRegs.GPACLEAR.all |= ( ON_L << num )

#define	RED_ON						LED_SEL_ON( 23 )
#define	RED_OFF						LED_SEL_OFF( 23 )

#define	GREEN_ON					LED_SEL_ON( 22 )
#define	GREEN_OFF					LED_SEL_OFF( 22 )

#define	BLUE_ON						LED_SEL_ON( 26 )
#define	BLUE_OFF					LED_SEL_OFF( 26 )

#define	YELLOW_ON					LED_SEL_ON( 27 )
#define	YELLOW_OFF					LED_SEL_OFF( 27 )

#define	LMARK_LED_ON				LED_SEL_ON( 15 )
#define	LMARK_LED_OFF				LED_SEL_OFF( 15 )

#define	RMARK_LED_ON				LED_SEL_ON( 14 )
#define	RMARK_LED_OFF				LED_SEL_OFF( 14 )

#define	TOGLE_RED					RED_ON;	BLUE_OFF
#define	TOGLE_BLUE					RED_OFF; BLUE_ON

#endif

