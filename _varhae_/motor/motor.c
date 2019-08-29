//###########################################################################
//
// FILE		: motor.c
//
// TITLE		: _varhae_ Tracer motor source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.10.02 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#pragma CODE_SECTION(motor_pid_ISR, "ramfuncs");

///////////////////////////////////////////////    motor information   ///////////////////////////////////////////////////

//#define WHEEL_RADIUS			36
//#define Gear_Ratio 				3.35
#define M_PI					3.141592653589

//#define SAMPLE_FRQ				0.00025			//250us
#define SAMPLE_FRQ_MS			0.25			//가속도를 낮은 값으로 쓰기 위해 250ms 로 계산

//PULSE_TO_D = (WHEEL_RADIUS * M_PI) / (encoder_pulse * 4) / geer_ratio 
//(36 * M_PI) / 2048 / 3.35
#define PULSE_TO_D				0.016484569660

//PULSE_TO_V = (WHEEL_RADIUS * M_PI) / (encoder_pulse * 4) / geer_ratio / SAMPLE_FRQ
//(36 * M_PI) / 2048 / 3.35 / 0.00025
#define PULSE_TO_V  			65.93827864344

////////////////////////////////////////////       PID information       ///////////////////////////////////////////////////

// 9000으로 임의로 잡고 계산했을 경우 공회전으로 7800mm/s 정도까지 올라가는것 확인-> 정속 주행일때를 위해 좀 더 올려야 할 듯...
#define MAX_PID_OUT				8950.0
#define MIN_PID_OUT				-8950.0
#define PWM_CONVERT				0.3333333333333//PWM주파수 최대값(EPWM.c) / MAX_PID_OUT => 3000 / 9000(수정 요망)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//떨어 뜨릴 값이 0.2 까지 이므로 1.5에서 0.2의 차이는 1.3 이다.
//따라서 간 거리가 200이 될때까지 1.3을 떨어뜨려야 하므로 X * 200 = 1.3 이된다.
//#define DOWN_KP				( float32 )( 0.00725 )
#define	DOWN_KP				( float32 )( 0.007 )  // 0.1
//#define	DOWN_KP				( float32 )( 0.0065 )  // 0.2

#define DOWN_KD				( float32 )( 0.005 )	//3.4
//#define DOWN_KD				( float32 )( 0.01 )		//2.4

///////////////////////////////////////////        jerk control            /////////////////////////////////////////////////////

 //jerk time.
 //T = ( ( 60 * S / x ) ^ 1/3 ) s

 //x에 관한 식으로 고치면...
 //x = ( ( 60 * S ) / T^3 ) m/s^3

 //로봇에 사용하려면 mm/s^3으로 고쳐야 된다.( 거리가 mm단위를 사용하므로... )
 //x = ( ( 6 * S ) / ( 2.5 * ( 0.00025 )^2 ) ) mm/s^3
 //S는 한 인터럽트 당 거리 * qep value -> fp32tick_distance = int16qep_value * PULSE_TO_D;

 //모든 계산을 거치면 9600 * S 가 나오는데 가속도를 작은 값으로 쓰기 위해 시간이 us가 아니라 ms 이므로 9.6 * S 가 된다.

 //시작 할 때는 S가 0 이므로 최대 가속도 17일때의 거리 S = 1/2at^2 에 의해 0.5 * 17000 * ( 0.00025 )^2 = 0.00053125 로 강제 처리.

#define JERK_CONTROL

#ifdef JERK_CONTROL
#define JERK_VALUE			( float32 )0.96
#define START_JERK_LIMIT	( float32 )0.00053125
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


float32	am_Rmotor_step = 0.0;
float32	am_Lmotor_step = 0.0;

void debug_force_PWM( str_point_t *pstr ) //강제로 모터 굴리기(PWM)
{
	pstr->ppos->fp32current_pos = 0.0;

	StopCpuTimer2();

	GpioDataRegs.GPBSET.bit.GPIO48 = 1; // left
	GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1; // right

	LeftPwmRegs.CMPA.half.CMPA = 400; //일정 PWM값 흘려보냄		
	LeftPwmRegs.CMPB = 400;

	VFDPrintf(" -TEST- ");

	while( 1 )
	{
		LED_ON;
		DELAY_US( 250000 );
		LED_OFF;
		DELAY_US( 250000 );

		if( !DOWN_SW )
		{
			LeftPwmRegs.CMPA.half.CMPA = 0;
			LeftPwmRegs.CMPB = 0;

			StartCpuTimer2();
			break; //motor 정지 후 탈출...
		}
	}
	
}

/* motor variable struct initialize func */
void init_motor_variable( motor_vari *pm )
{
	memset( ( void * )pm , 0x00 , sizeof( motor_vari ) );

	pm->fp32kp = 0.6; // 0.8
	pm->fp32ki = 0.00002;
	pm->fp32kd = 0.65; // 0.85 //정지 토크만 만족하면 된다 -> 더 떨어뜨려도 될듯. 

	pm->int32accel = 5;	
#ifdef JERK_CONTROL	
	pm->fp32next_acc = START_JERK_LIMIT;
#endif
}

void diffvel_to_remaindist_cpt( volatile float32 cur_vel , volatile float32 tar_vel , volatile int32 acc , volatile float32 *decel_dist )
{
	cur_vel /= ( float32 )( 1000.0 );
	tar_vel /= ( float32 )( 1000.0 );

	*decel_dist = ( fabs( ( cur_vel * cur_vel ) - ( tar_vel * tar_vel ) ) / ( ( float32 )( 2.0 ) * ( float32 )( acc ) ) ) * ( float32 )( 1000.0 );
}

void dist_to_maxvel_cpt( volatile float32 dist , volatile float32 minus_dist , volatile float32 cur_vel , volatile int32 acc , volatile float32 *max_vel )
{
	dist -= minus_dist;

	dist /= ( float32 )( 2000.0 );
	cur_vel /= ( float32 )( 1000.0 );

	*max_vel = sqrt( ( cur_vel * cur_vel ) + ( float32 )( 2.0 ) * ( float32 )( acc ) * dist ) * ( float32 )( 1000.0 );

	if( *max_vel > ( float32 )( g_int32max_speed ) )			*max_vel = ( float32 )( g_int32max_speed ); //최고 속도가 셋팅 속도보다 높으면 -> 셋팅 속도로 주행
	else if( *max_vel < ( float32 )( g_int32turn_vel ) )		*max_vel = ( float32 )( g_int32turn_vel );  //최저 속도가 현재 턴 속도보다 낮으면 -> 턴속도로 주행
	else;
}

void move_end( volatile float32 dist , volatile float32 vel , volatile int32 acc ) //dist거리만큼 vel속도로 이동한 후 acc가속도로 정지
{
	StopCpuTimer2(); // 값이 변경될 때 타이머가 걸리면 안되므로...

	R_motor.int32accel = L_motor.int32accel = acc; //정지 구간 가속도 변경

	diffvel_to_remaindist_cpt( vel , ( float32 )0.0 , acc , &R_motor.fp32decel_distance );  //감속 거리 계산
	L_motor.fp32decel_distance = R_motor.fp32decel_distance;

	R_motor.fp32user_distacne = dist; //명령 거리
	L_motor.fp32user_distacne = dist;

	R_motor.fp32user_vel = vel; //명령 속도
	L_motor.fp32user_vel = vel;

	R_motor.fp32err_distance = R_motor.fp32user_distacne - R_motor.fp32distance_sum; //남은 거리
	L_motor.fp32err_distance = L_motor.fp32user_distacne - L_motor.fp32distance_sum;

	R_motor.fp32decel_vel = 0.0; //타겟 속도
	L_motor.fp32decel_vel = 0.0;

	R_motor.u16decel_flag = ON;
	L_motor.u16decel_flag = ON;

	g_Flag.move_state = OFF;

	g_fp32time =  ( float32 )g_int32time_cnt * ( float32 )0.00025; // time count compute	

	StartCpuTimer2(); //motor interrupt start
	
}

void move_to_move( volatile float dist , volatile float dec_dist , volatile float tar_vel , volatile float32 dec_vel , volatile int32 acc ) //dist거리를 cur_vel속도에서 tar_vel속도로 변속한 후 dec_vel속도로 acc가속도로 감속
{
	StopCpuTimer2();// 값이 변경될 때 타이머가 걸리면 안되므로...

	R_motor.int32accel = L_motor.int32accel = acc;	 //이동할 턴 속도에 도달 가속도 설정

	R_motor.fp32decel_distance = dec_dist;
	L_motor.fp32decel_distance = dec_dist;

	R_motor.fp32user_distacne = dist;
	L_motor.fp32user_distacne = dist;

	if( ( g_Flag.goal_dest == OFF ) || ( g_Flag.goal_dest && !( g_secinfo[ g_int32mark_cnt ].int32dir & STRAIGHT ) ) )
	{
		R_motor.fp32user_vel = tar_vel;
		L_motor.fp32user_vel = tar_vel;
	}

	R_motor.fp32err_distance = R_motor.fp32user_distacne - R_motor.fp32distance_sum;
	L_motor.fp32err_distance = L_motor.fp32user_distacne - L_motor.fp32distance_sum;

	R_motor.fp32decel_vel = dec_vel;
	L_motor.fp32decel_vel = dec_vel;

	R_motor.u16decel_flag = ON;
	L_motor.u16decel_flag = ON;

	g_Flag.move_state = ON;	

	StartCpuTimer2();  //motor interrupt start

}

void handle_ad_make( volatile float32 acc_rate , volatile float32 dec_rate ) //handle 비율 갱신 함수 -> 포지션에 따른 턴속도 조절시 사용
{
	g_fp32han_accstep = ( 1.0 -  acc_rate ) / HANDLE_CENTER;
	g_fp32han_decstep = ( dec_rate - 1.0 ) / HANDLE_CENTER;

	g_fp32han_accmax = acc_rate;
	g_fp32han_decmax = ( 2.0 - dec_rate );
}

static void position_to_vel( void )
{
	volatile float32 limit_vel = ( float32 )( g_int32limit_vel );

	if( g_Flag.line_out || !g_Flag.start_flag || g_Flag.stop_check )
		return; //현재 주행중이 아니면 탈출

	if( g_Flag.err )
	{
		LED_ON;
	
		L_motor.int32accel = 10;
		R_motor.int32accel = 10;
	
		L_motor.fp32user_vel = ( float32 )( g_int32turn_vel - 500 );
		R_motor.fp32user_vel = ( float32 )( g_int32turn_vel - 500 );

		return;
	}


	//positon kp 값 ctrl -> 연속턴 보정 풀고 조으기
	if( g_secinfo[ g_int32mark_cnt ].int32down_flag )  //짧은 연속 턴 
	{
		if( R_motor.fp32decel_distance >= ( float32 )fabs( ( double )( R_motor.fp32err_distance ) ) && 
			L_motor.fp32decel_distance >= ( float32 )fabs( ( double )( L_motor.fp32err_distance ) ) )  //감속 구간.
		{
			GREEN_OFF;
			YELLOW_ON;
		}
		else  //가속 구간.
		{
			GREEN_ON;
			YELLOW_OFF;
		}	
		
		xkval_ctrl_func( ( KVAL_DOWN | KVAL_KP ) , &g_pos , DOWN_KP , g_secinfo[ g_int32mark_cnt ].fp32kp_down );
	}
	else if( g_secinfo[ g_int32mark_cnt ].int32s44s_flag )  //직진 - 45도 - 45도 - 직진 에서 진입직진이 짧은 직진이 아닐 경우
	{
		if( g_fp32xrun_dist > ( float32 )( g_secinfo[ g_int32mark_cnt ].int32dist - ARBITRATE ) )  //진입하자마자 kp를 풀면 직진 보정을 못하므로...
		{		
			LMARK_LED_ON;
			RMARK_LED_ON;
			
			xkval_ctrl_func( ( KVAL_DOWN | KVAL_KP ) , &g_pos , DOWN_KP , g_secinfo[ g_int32mark_cnt ].fp32kp_down );
		}
		else
			xkval_ctrl_func( ( KVAL_UP | KVAL_KP ) , &g_pos , DOWN_KP , g_secinfo[ g_int32mark_cnt ].fp32kp_down );
	}
	else  //kp값 원래대로 돌리기
		xkval_ctrl_func( ( KVAL_UP | KVAL_KP ) , &g_pos , DOWN_KP , g_secinfo[ g_int32mark_cnt ].fp32kp_down );


	
	//가속 플래그가 떳을 경우 user_vel만 최고 속도로 변경한 후 탈출
	if( g_Flag.speed_up ) 
	{
		BLUE_ON; 					//가속구간 파란색 LED	
		g_Flag.straight = ON;
	
		L_motor.fp32user_vel = g_secinfo[ g_int32mark_cnt ].fp32vel;
		R_motor.fp32user_vel = L_motor.fp32user_vel;

		//position kd 값 ctrl -> 직진 보정 흔들림 감소.
		if( ( g_Flag.xrun == ON ) && ( g_secinfo[ g_int32mark_cnt ].int32dir & STRAIGHT ) && ( g_secinfo[ g_int32mark_cnt ].int32dist > MID_DIST_LIMIT ) )  //middle 직진 이상일 때만!!
		{	
			if( g_fp32xrun_dist <= ( float32 )( ARBITRATE ) )  //거리 200 동안 KD를 낮춘다.
			{
				GREEN_ON;
				xkval_ctrl_func( ( KVAL_DOWN | KVAL_KD ) , &g_pos , DOWN_KD , POS_KD_DOWN );					
			}
			else
			{
				GREEN_OFF;
				xkval_ctrl_func( ( KVAL_UP | KVAL_KD ) , &g_pos , DOWN_KD , POS_KD_DOWN );
			}
		}
		else
			xkval_ctrl_func( ( KVAL_UP | KVAL_KD ) , &g_pos , DOWN_KD , POS_KD_DOWN );

		return;
	}
	
	
	//핸들값 증가 막기
	if( g_secinfo[ g_int32mark_cnt ].int32dir >= TURN_180 )
	{
		if( ( R_motor.fp32next_vel * g_fp32right_handle ) > limit_vel )		R_motor.fp32next_vel = ( limit_vel / g_fp32right_handle );
		else if( ( L_motor.fp32next_vel * g_fp32left_handle ) > limit_vel )	L_motor.fp32next_vel = ( limit_vel / g_fp32left_handle );
		else;
	}
		
}

interrupt void motor_pid_ISR(void)
{
	g_int32menu_count++;	 //menu switch chattering prevention
	g_int32pid_ISR_cnt++;	 //motor interrupt synchronization 
	g_int32time_cnt++;		 //driving time count

#ifndef MOTOR_TEST
	position_PID_handle();	 //handle compute
	position_to_vel();		 //position to velocity change
#endif

	/* qep value sampling */
	R_motor.u16qep_sample = ( Uint16 )RQepRegs.QPOSCNT;
	L_motor.u16qep_sample = ( Uint16 )LQepRegs.QPOSCNT;

	/* qep reset */
	RQepRegs.QEPCTL.bit.SWI = 1;
	LQepRegs.QEPCTL.bit.SWI = 1;

	/* qep counter value signed */
	R_motor.int16qep_value = R_motor.u16qep_sample > 2048 ? ( int16 )( R_motor.u16qep_sample ) - 4097 : ( int16 )R_motor.u16qep_sample;
	L_motor.int16qep_value = L_motor.u16qep_sample > 2048 ? ( int16 )( L_motor.u16qep_sample ) - 4097 : ( int16 )L_motor.u16qep_sample;	

	/* distance compute */
	R_motor.fp32tick_distance = ( float32 )R_motor.int16qep_value * ( float32 )PULSE_TO_D;	
	R_motor.fp32distance_sum += R_motor.fp32tick_distance;
	R_motor.fp32err_distance = R_motor.fp32user_distacne - R_motor.fp32distance_sum;

	L_motor.fp32tick_distance = ( float32 )L_motor.int16qep_value * ( float32 )PULSE_TO_D;	
	L_motor.fp32distance_sum += L_motor.fp32tick_distance;
	L_motor.fp32err_distance = L_motor.fp32user_distacne - L_motor.fp32distance_sum;

	/* extern distance  make over */
	am_Rmotor_step = R_motor.fp32tick_distance;
	am_Lmotor_step = L_motor.fp32tick_distance;

	g_fp32shift_dist = ( am_Rmotor_step + am_Lmotor_step ) * 0.5;
	
	R_motor.fp32gone_distance += am_Rmotor_step;
	L_motor.fp32gone_distance += am_Lmotor_step;	

	g_rmark.fp32check_dis += am_Rmotor_step;
	g_lmark.fp32check_dis += am_Lmotor_step;

	g_fp32cross_dist += ( ( am_Rmotor_step + am_Lmotor_step ) * 0.5 );

	/* average velocity compute */
	R_motor.fp32current_vel[ 3 ] = R_motor.fp32current_vel[ 2 ];
	R_motor.fp32current_vel[ 2 ] = R_motor.fp32current_vel[ 1 ];
	R_motor.fp32current_vel[ 1 ] = R_motor.fp32current_vel[ 0 ];
	R_motor.fp32current_vel[ 0 ] = ( float32 )R_motor.int16qep_value * ( float32 )PULSE_TO_V;	
	R_motor.fp32cur_vel_avr = ( R_motor.fp32current_vel[ 0 ] + R_motor.fp32current_vel[ 1 ] + R_motor.fp32current_vel[ 2 ] + R_motor.fp32current_vel[ 3 ] ) * 0.25;

	L_motor.fp32current_vel[ 3 ] = L_motor.fp32current_vel[ 2 ];
	L_motor.fp32current_vel[ 2 ] = L_motor.fp32current_vel[ 1 ];
	L_motor.fp32current_vel[ 1 ] = L_motor.fp32current_vel[ 0 ];
	L_motor.fp32current_vel[ 0 ] = ( float32 )L_motor.int16qep_value * ( float32 )PULSE_TO_V;	
	L_motor.fp32cur_vel_avr = ( L_motor.fp32current_vel[ 0 ] + L_motor.fp32current_vel[ 1 ] + L_motor.fp32current_vel[ 2 ] + L_motor.fp32current_vel[ 3 ] ) * 0.25;

	/* decelation a point of time flag */
	if( R_motor.u16decel_flag ) //move_to_move나 move_end함수가 호출 되었을 경우
	{
		if( R_motor.fp32decel_distance >= ( float32 )fabs( ( double )( R_motor.fp32err_distance ) ) ) //가속 할 수 있는 계산된 구간이 지났을 경우.
		{
			if( g_secinfo[ g_int32mark_cnt ].int32dir & STRAIGHT )
			{
				RED_ON;
				BLUE_OFF;			
			}

#ifdef JERK_CONTROL  //감속 구간 이므로 가속도를 뒤집는다.
			R_motor.int32accel = -R_motor.int32accel;
			L_motor.int32accel = -L_motor.int32accel;
#endif
		
			R_motor.fp32user_vel = R_motor.fp32decel_vel;
			L_motor.fp32user_vel = L_motor.fp32decel_vel; //user_vel을 감속 속도로 변환
			
			R_motor.u16decel_flag = OFF;
			L_motor.u16decel_flag = OFF;

			/* accelation start flag OFF */		
			g_Flag.speed_up = OFF;
			g_Flag.speed_up_start = OFF;
			
			g_err.fp32over_dist = 0.0;
		}
		
	}
	else if( L_motor.u16decel_flag ) //move_to_move나 move_end함수가 호출 되었을 경우
	{
		if( L_motor.fp32decel_distance >= ( float32 )fabs( ( double )( L_motor.fp32err_distance ) ) ) //가속 할 수 있는 계산된 구간이 지났을 경우.
		{
			if( g_secinfo[ g_int32mark_cnt ].int32dir & STRAIGHT )
			{
				RED_ON;
				BLUE_OFF;			
			}

#ifdef JERK_CONTROL  //감속 구간 이므로 가속도를 뒤집는다.
			R_motor.int32accel = -R_motor.int32accel;
			L_motor.int32accel = -L_motor.int32accel;
#endif
			
			R_motor.fp32user_vel = R_motor.fp32decel_vel;
			L_motor.fp32user_vel = L_motor.fp32decel_vel; //user_vel을 감속 속도로 변환
			
			R_motor.u16decel_flag = OFF;
			L_motor.u16decel_flag = OFF;

			/* accelation start flag OFF */
			g_Flag.speed_up = OFF;
			g_Flag.speed_up_start = OFF;			

			g_err.fp32over_dist = 0.0;			
		}
		
	}
	else;

#ifdef JERK_CONTROL

	/* jerk accel & decel compute */
	if( ( float32 )( R_motor.int32accel ) > R_motor.fp32next_acc )
	{
		R_motor.fp32next_acc += ( JERK_VALUE * R_motor.fp32tick_distance );
		if( ( float32 )R_motor.int32accel < R_motor.fp32next_acc )
			R_motor.fp32next_acc = ( float32 )( R_motor.int32accel );	
	}
	else if( ( float32 )( R_motor.int32accel ) < R_motor.fp32next_acc )	
	{
		R_motor.fp32next_acc -= ( JERK_VALUE * R_motor.fp32tick_distance );
		if( ( float32 )R_motor.int32accel > R_motor.fp32next_acc )
			R_motor.fp32next_acc = ( float32 )( R_motor.int32accel );	
	}
	else;

	if( ( float32 )( L_motor.int32accel ) > L_motor.fp32next_acc )
	{
		L_motor.fp32next_acc += ( JERK_VALUE * L_motor.fp32tick_distance );
		if( ( float32 )L_motor.int32accel < L_motor.fp32next_acc )
			L_motor.fp32next_acc = ( float32 )( L_motor.int32accel );		
	}
	else if( ( float32 )( L_motor.int32accel ) < L_motor.fp32next_acc )	
	{
		L_motor.fp32next_acc -= ( JERK_VALUE * L_motor.fp32tick_distance );
		if( ( float32 )L_motor.int32accel > L_motor.fp32next_acc )
			L_motor.fp32next_acc = ( float32 )( L_motor.int32accel );		
	}
	else;
	
#else

	R_motor.fp32next_acc = ( float32 )R_motor.int32accel;
	L_motor.fp32next_acc = ( float32 )L_motor.int32accel;	
	
#endif

	/* accel & decel compute */
	if( R_motor.fp32user_vel > R_motor.fp32next_vel )
	{
		R_motor.fp32next_vel += ( ( float32 )fabs( ( double )( R_motor.fp32next_acc ) ) * ( float32 )SAMPLE_FRQ_MS );
		if( R_motor.fp32user_vel < R_motor.fp32next_vel )
			R_motor.fp32next_vel = R_motor.fp32user_vel;	
	}
	else if( R_motor.fp32user_vel < R_motor.fp32next_vel )
	{
		R_motor.fp32next_vel -= ( ( float32 )fabs( ( double )( R_motor.fp32next_acc ) ) * ( float32 )SAMPLE_FRQ_MS );
		if( R_motor.fp32user_vel > R_motor.fp32next_vel )
			R_motor.fp32next_vel = R_motor.fp32user_vel;	
	}
	else;
	
	if( L_motor.fp32user_vel > L_motor.fp32next_vel )
	{
		L_motor.fp32next_vel += ( ( float32 )fabs( ( double )( L_motor.fp32next_acc ) ) * ( float32 )SAMPLE_FRQ_MS );
		if( L_motor.fp32user_vel < L_motor.fp32next_vel )
			L_motor.fp32next_vel = L_motor.fp32user_vel;	
	}
	else if( L_motor.fp32user_vel < L_motor.fp32next_vel )
	{
		L_motor.fp32next_vel -= ( ( float32 )fabs( ( double )( L_motor.fp32next_acc ) ) * ( float32 )SAMPLE_FRQ_MS );
		if( L_motor.fp32user_vel > L_motor.fp32next_vel )
			L_motor.fp32next_vel = L_motor.fp32user_vel;	
	}
	else;

	/* motor PID compute */
	R_motor.fp32err_vel_sum -= R_motor.fp32err_vel[ 3 ];
	R_motor.fp32err_vel[ 3 ] = R_motor.fp32err_vel[ 2 ];
	R_motor.fp32err_vel[ 2 ] = R_motor.fp32err_vel[ 1 ];
	R_motor.fp32err_vel[ 1 ] = R_motor.fp32err_vel[ 0 ];
	R_motor.fp32err_vel[ 0 ] = ( R_motor.fp32next_vel * g_fp32right_handle ) - R_motor.fp32cur_vel_avr;
	R_motor.fp32err_vel_sum += R_motor.fp32err_vel[ 0 ];

	R_motor.fp32proportion_val = R_motor.fp32kp * R_motor.fp32err_vel[ 0 ];
	R_motor.fp32integral_val = R_motor.fp32ki * R_motor.fp32err_vel_sum;
	R_motor.fp32differential_val = R_motor.fp32kd * ( ( R_motor.fp32err_vel[ 0 ] - R_motor.fp32err_vel[ 3 ] ) + ( ( float32 )3.0 * ( R_motor.fp32err_vel[ 1 ] - R_motor.fp32err_vel[ 2 ] ) ) );
	R_motor.fp32PID_output += R_motor.fp32proportion_val + R_motor.fp32integral_val + R_motor.fp32differential_val;

	L_motor.fp32err_vel_sum -= L_motor.fp32err_vel[ 3 ];
	L_motor.fp32err_vel[ 3 ] = L_motor.fp32err_vel[ 2 ];
	L_motor.fp32err_vel[ 2 ] = L_motor.fp32err_vel[ 1 ];
	L_motor.fp32err_vel[ 1 ] = L_motor.fp32err_vel[ 0 ];
	L_motor.fp32err_vel[ 0 ] = ( L_motor.fp32next_vel * g_fp32left_handle ) - L_motor.fp32cur_vel_avr;
	L_motor.fp32err_vel_sum += L_motor.fp32err_vel[0];

	L_motor.fp32proportion_val = L_motor.fp32kp * L_motor.fp32err_vel[ 0 ];
	L_motor.fp32integral_val = L_motor.fp32ki * L_motor.fp32err_vel_sum;
	L_motor.fp32differential_val = L_motor.fp32kd * ( ( L_motor.fp32err_vel[ 0 ] - L_motor.fp32err_vel[ 3 ] ) + ( ( float32 )3.0 * ( L_motor.fp32err_vel[ 1 ] - L_motor.fp32err_vel[ 2 ] ) ) );
	L_motor.fp32PID_output += L_motor.fp32proportion_val + L_motor.fp32integral_val + L_motor.fp32differential_val;	

	if( g_Flag.start_flag ) //실제 주행일 경우
	{
		/* PID -> PWM */
		if( R_motor.fp32PID_output > 0.0 )
		{
			if( R_motor.fp32PID_output > MAX_PID_OUT )	R_motor.fp32PID_output = MAX_PID_OUT;

			GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1; // right

			LeftPwmRegs.CMPA.half.CMPA = ( Uint16 )( R_motor.fp32PID_output * PWM_CONVERT );
		}
		else
		{
			if( R_motor.fp32PID_output < MIN_PID_OUT )	R_motor.fp32PID_output = MIN_PID_OUT;

			GpioDataRegs.GPBSET.bit.GPIO49 = 1; // right

			LeftPwmRegs.CMPA.half.CMPA = ( Uint16 )( R_motor.fp32PID_output * PWM_CONVERT * ( -1.0 ) );
		}
		
		if( L_motor.fp32PID_output > 0.0  )
		{
			if( L_motor.fp32PID_output > MAX_PID_OUT )	L_motor.fp32PID_output = MAX_PID_OUT;

			GpioDataRegs.GPBSET.bit.GPIO48 = 1; // left

			LeftPwmRegs.CMPB = ( Uint16 )( L_motor.fp32PID_output * PWM_CONVERT );

		}
		else
		{
			if( L_motor.fp32PID_output < MIN_PID_OUT )	L_motor.fp32PID_output = MIN_PID_OUT;

			GpioDataRegs.GPBCLEAR.bit.GPIO48 = 1; // left

			LeftPwmRegs.CMPB = ( Uint16 )( L_motor.fp32PID_output * PWM_CONVERT * ( -1.0 ) );
		}

	}
	else //모터 상 풀기
	{
		GpioDataRegs.GPBSET.bit.GPIO48 = 1; // left
		GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1; // right	
		
		LeftPwmRegs.CMPA.half.CMPA = 0;  //모터 정지
		LeftPwmRegs.CMPB = 0;
	}

	StartCpuTimer0();  //sensor interrupt start
	
}

