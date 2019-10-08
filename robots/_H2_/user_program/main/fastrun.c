//###########################################################################
//
// FILE		: fastrun.c
//
// TITLE		: micromouse H2 fastrun source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2012.05.12 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File


void recursive_fastrun_code_func( void )
{
	Uint16 state;	
	Uint16 path_cnt;

	algorithm_vari_init();		//알고리즘 초기화
	fastrun_path_make_func();	//2차  패쓰 생성.

	POS_CPN_ON;
	ANGLE_CPN_ON;		 //보정 ON!!
	motor_vari_init();	 //모터 변수 초기화.
	edge_vari_init();	 //엣지 변수 초기화.	

	known_path_printf();

	//속도 및 가속도 셋팅.
	g_run.fp32str_limit_vel = ( float32 )STRAIGHT_MAX;
	g_run.fp32diag_limit_vel = ( float32 )DIAGONAL_MAX;

	g_run.fp32str_limit_acc = ( float32 )g_int32straight_acc;
	g_run.fp32diag_limit_acc = ( float32 )g_int32diag_acc;	

	if( g_knownpath[ 0 ].u8cnt == 1 && g_knownpath[ 0 ].u8state == STRAIGHT && ( g_int32turn_vel == S1000 || g_int32turn_vel == S1200 ) )  //첫블럭 대각.
	{
		GREEN_ON;
	
		g_rmotor.int32accel = g_lmotor.int32accel = 15;
	
		g_int32backup_turnvel = g_int32turn_vel;
		g_int32backup_turnsel = g_int32vel_select;

		g_int32turn_vel = FIRST_DIAG_S;
		g_int32vel_select = V_FIR_DIG;

		g_flag.first_block_diag = ON;
	}

	move_to_move( ONE_BLOCK , ( float32 )g_int32turn_vel , ( float32 )g_int32turn_vel , g_int32turn_acc );  //출발!!

	g_rmotor.fp32distance_sum = g_lmotor.fp32distance_sum = ( float32 )60.0; //첫블럭 거리 보상.

	path_cnt = g_u16path_cnt;
	g_u16path_cnt = 0;

	vfdprintf("    ");

	g_flag.algo = OFF;

	g_u32time_cnt = 0;
	while( 1 )
	{
		state = g_knownpath[ g_u16path_cnt ].u8state;

		if( g_u16path_cnt == path_cnt - 1 ) //goal 도착 하면 알고리즘 돌리기.
		{
			LED_ON;

			g_flag.algo = ON;
			g_flag.second_rungoal = ON;
			
			break;
		}

		pselect_func[ state ](); //각 조건에 맞는 턴 실행.				
		g_u16path_cnt++;	
		
	}

	pselect_func[ state ](); //마지막 턴.

	LED_OFF;
	
	//돌아올 속도 셋팅.
	g_int32turn_vel = ( int32 )S800;
	g_int32vel_select = ( int32 )V_800;

	g_run.fp32str_limit_vel = BASE_VEL_LIMIT;
	g_run.fp32diag_limit_vel = BASE_VEL_LIMIT;

	g_run.fp32str_limit_acc = BASE_ACC_LIMIT;
	g_run.fp32diag_limit_acc = BASE_ACC_LIMIT;

	while( ( state != BACKTURN ) || ( g_flag.search_end != ON ) || ( g_u16yet_mpos != 0x00 ) ) //시작점으로 돌아올 때 까지.
	{
		path_cnt = g_u16path_cnt;
		g_u16path_cnt = 0;

		g_flag.algo = ( path_cnt > 0 ) ? OFF : ON;

		while( 1 )
		{	
			state = g_knownpath[ g_u16path_cnt ].u8state; //아는길 블럭 상태 받아 옴.

			if( g_u16path_cnt == ( path_cnt - 1 ) && g_flag.algo == OFF ) //아는길 -> 모르는 길 진입.
				g_flag.algo = ON;


			pselect_func[ state ](); //각 조건에 맞는 턴 실행.

			if( g_flag.algo == ON )
				break;
			
			g_u16path_cnt++; //인덱스 증가.
		}
		
	}
	
}

static void _fastrun_mode( volatile int32 real_vel , turn_vel_e turn_vel )
{
	g_flag.goal = GO_GOAL;
	g_flag.fastrun = ON;

	if( race_start_init( NULL , NULL ) < 0 )
		return;

	while( 1 )
	{
		g_int32turn_vel = real_vel;
		g_int32vel_select = ( int32 )turn_vel;
	
		recursive_fastrun_code_func();
	}
}

void fastrun_800velocity_mode( void )
{
	_fastrun_mode( S800 , V_800 );
}

void fastrun_1000velocity_mode( void )
{
	_fastrun_mode( S1000 , V_1000 );
}

void fastrun_1200velocity_mode( void )
{
	_fastrun_mode( S1200 , V_1200 );
}


