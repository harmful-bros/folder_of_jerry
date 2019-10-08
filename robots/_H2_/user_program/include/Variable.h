//###########################################################################
//
// FILE		: variable.h
//
// TITLE		: micromouse H2 grobal variable header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2011.10.02 $
//###########################################################################

#ifndef  __VARIABLE_H__
#define  __VARIABLE_H__

#ifdef  __VARIABLE__

	#undef __VARIABLE__
	#define __VARIABLE_EXT__
	
#else

	#define __VARIABLE_EXT__ 	extern
	
#endif

#define	UP_SW		GpioDataRegs.GPADAT.bit.GPIO10
#define	RIGHT_SW	GpioDataRegs.GPADAT.bit.GPIO11
#define	DOWN_SW		GpioDataRegs.GPADAT.bit.GPIO12
#define	LEFT_SW		GpioDataRegs.GPADAT.bit.GPIO13

typedef enum motor_state
{
	STOP , 
	RUN
	
}motor_state_e;

typedef enum sensor_setting
{
	SENSOR_SECTION = 26 , 
	SIDE_SENSOR_NUM = 4	

}sen_set_e;

typedef volatile enum maze_draw
{
	MAZE_ROW = 16 , 
	MAZE_COL = 16 , 

	MAX_MAZE = 256

}maze_draw_e;

typedef enum mouse_speed
{
	SEARCH_S = 650 ,
	S800 = 800 , 
	S1000 = 1000 , 
	S1200 = 1200 ,
	FIRST_DIAG_S = 1000 , 

	STRAIGHT_MAX = 3500 , 
	DIAGONAL_MAX = 2800
	
}mouse_speed_e;


__VARIABLE_EXT__ volatile Uint32	g_u32time_cnt;

__VARIABLE_EXT__ volatile Uint16	g_u16batt_volt , 
									g_u16map[ MAX_MAZE ] , 
									g_u16map_backup0[ MAX_MAZE ] , 
									g_u16map_backup1[ MAX_MAZE ] , 
									g_u16map_backup2[ MAX_MAZE ] , 
									g_u16map_backup3[ MAX_MAZE ] ,									
									g_u16mouse_pos , 
									g_u16mouse_dir , 
									g_u16yet_mpos , 
									g_u16yet_mdir , 
									g_u16path_cnt;


__VARIABLE_EXT__ volatile int32		g_int32menu_cnt , 
									g_int32sen_cnt , 
									g_int32pid_ISR_cnt , 
									g_int32edge_diff_cnt , 
									g_int32turn_vel , 
									g_int32vel_select , 
									g_int32block_to_block , 
									g_int32tick , 
									g_int32turn_acc , 
									g_int32straight_acc , 
									g_int32diag_acc , 
									g_int32backup_turnvel , 
									g_int32backup_turnsel;

__VARIABLE_EXT__ volatile float32	g_fp32right_handle , 
									g_fp32left_handle ,
									g_fp32han_accdiff , 
									g_fp32han_decdiff , 
									g_fp32han_accref , 
									g_fp32han_decref ,
									g_fp32rfs_section[ SENSOR_SECTION ] , 
									g_fp32lfs_section[ SENSOR_SECTION ] , 
									g_fp32rfs_sec_diff[ SENSOR_SECTION ] , 
									g_fp32lfs_sec_diff[ SENSOR_SECTION ] , 
									g_fp32err_dist , 
									g_fp32time , 
									g_fp32left_pos , 
									g_fp32right_pos;


__VARIABLE_EXT__ void ( *pselect_func[ 24 ] )( void );

extern const Uint16 g_u16wall_t[ 4 ]; 
extern const int32 g_int32move_t[ 4 ];

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define SAMPLE_FRQ					( float32 )0.0005		//500us

#define CENTER_POSITION				( float32 )256.0
#define ADJ_DIFF_MAX				( float32 )100.0

#define ONE_BLOCK					( float32 )180.0
#define DIAG_ONE_BLOCK				( float32 )127.27922061

#define BLOCK_COMPEN_DIST			( float32 )80.0
#define BACKTURN_COMPEN_DIST		( float32 )10.0

#define ACC_RATIO					( float32 )0.6
#define DEC_RATIO					( float32 )0.6

#define BACKTURN_DIST				( float32 )110.0 // 107.599548385450418417345
#define HALF_BTTN_DIST				( float32 )53.7997741927252092086727

//#define SMOOTH_STRA_DIST_TEST			

#define POS_CPN_ON					{ g_flag.pos_compen = ON; }
#define POS_CPN_OFF					{ g_flag.pos_compen = OFF; }

#define ANGLE_CPN_ON				{ g_flag.angle_compen = ON; }
#define ANGLE_CPN_OFF				{ g_flag.angle_compen = OFF; }

#define	ON_L						1L

#define	LED_ON						GpioDataRegs.GPADAT.all |= 0x0cc0c000
#define	LED_OFF						GpioDataRegs.GPADAT.all &= ~( 0x0cc0c000 )

#define LED_SEL_ON( num )			GpioDataRegs.GPASET.all |= ( ON_L << num )
#define LED_SEL_OFF( num )			GpioDataRegs.GPACLEAR.all |= ( ON_L << num )

#define	YELLOW_ON					LED_SEL_ON( 27 )
#define	YELLOW_OFF					LED_SEL_OFF( 27 )

#define	GREEN_ON					LED_SEL_ON( 26 )
#define	GREEN_OFF					LED_SEL_OFF( 26 )

#define	R_RED_ON					LED_SEL_ON( 23 )
#define	R_RED_OFF					LED_SEL_OFF( 23 )

#define	L_RED_ON					LED_SEL_ON( 22 )
#define	L_RED_OFF					LED_SEL_OFF( 22 )

#define	LEDGE_LED_ON				LED_SEL_ON( 15 )
#define	LEDGE_LED_OFF				LED_SEL_OFF( 15 )

#define	REDGE_LED_ON				LED_SEL_ON( 14 )
#define	REDGE_LED_OFF				LED_SEL_OFF( 14 )


#define MAX( x , y )				( x ) > ( y ) ? ( x ) : ( y )
#define MIN( x , y )				( x ) < ( y ) ? ( x ) : ( y )

#endif

