//###########################################################################
//
// FILE		: search.c
//
// TITLE		: _varhae_ Tracer search source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.11.15 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define	S_ANGLE_MAX_LIMIT ( int32 )( g_gyro.fp32center ) + 550
#define	S_ANGLE_MIN_LIMIT ( int32 )( g_gyro.fp32center ) - 550

#define	A90_ANGLE_MAX_LIMIT ( int32 )( g_gyro.fp32center ) + 1900
#define	A90_ANGLE_MIN_LIMIT ( int32 )( g_gyro.fp32center ) - 1900

#define	A180_ANGLE_MAX_LIMIT ( int32 )( g_gyro.fp32center ) + 2700
#define	A180_ANGLE_MIN_LIMIT ( int32 )( g_gyro.fp32center ) - 2700

#define	A270_ANGLE_MAX_LIMIT ( int32 )( g_gyro.fp32center ) + 3200
#define	A270_ANGLE_MIN_LIMIT ( int32 )( g_gyro.fp32center ) - 3200


typedef enum
{
	S_DIST_MIN_LIMIT = 235	, 
	A90_DIST_MAX_LIMIT = 400 , 
	A180_DIST_MAX_LIMIT = 720 , 
	A270_DIST_MAX_LIMIT = 1100 ,

	LARGE_ABS_MAX_LIMIT = 700 , 
	LARGE_270_BOUNDRY_LIMIT = 600 , 
	LARGE_270_DIST_COMPARISON = 1100

}cur_limit_e;

typedef enum
{
	EDIT_END , 
	EDIT_STRA ,
	EDIT_L45 ,
	EDIT_R45 , 
	EDIT_L90 , 
	EDIT_R90 ,
	EDIT_L180 , 
	EDIT_R180 , 
	EDIT_L270 , 
	EDIT_R270 , 
	EDIT_LLAR , 
	EDIT_RLAR , 

	LARGE_DIST = 901 ,
	EDIT_SUM = 11
	
}edit_e;

static int32 angle_edit( sec_info_t *pinfo , int32 mark_cnt )
{
	int32 cnt = 0;
	int32 vfd_mode = 0;
	int32 sw_up = OFF , sw_down = OFF , sw_right = OFF , sw_left = OFF;

	const char *str[] = { "END " , 
						  "STRA" , 
						  "L 45" , 
						  "R 45" , 
						  "L 90" , 
						  "R 90" , 
						  "L180" , 
						  "R180" , 
						  "L270" , 
						  "R270" , 
						  "LLAR" , 
						  "RLAR" };

	const int angle[] = { 4100 , 
						  4100 , 
						  3950 , 
						  4250 , 
						  2800 , 
						  5400 , 
						  1700 , 
						  6500 , 
						  1100 , 
						  7100 , 
						  1100 ,
						  7100 };	 //하드 코딩

	while( 1 )
	{
		if( ( !UP_SW ) && ( !sw_up ) ) // up_sw
		{
			sw_up= ON;
			g_int32menu_count = ZERO;
		}
		else if( ( !DOWN_SW ) && ( !sw_down ) )
		{
			sw_down = ON;
			g_int32menu_count = ZERO;
		}
		else if( ( !RIGHT_SW ) && ( !sw_right ) )
		{
			sw_right = ON;
			g_int32menu_count = ZERO;
		}
		else if( ( !LEFT_SW ) && ( !sw_left ) )
		{
			sw_left = ON;
			g_int32menu_count = ZERO;
		}
		else if( UP_SW && DOWN_SW && RIGHT_SW && LEFT_SW )
		{
			if( ( sw_up ) && ( g_int32menu_count > KEY_CHATTERING ) ) // up_sw chattering debug
			{
				sw_up = OFF;
				
				cnt++;
				if( cnt > EDIT_SUM )	cnt = 0;
			}
			else if( ( sw_down ) && ( g_int32menu_count > KEY_CHATTERING ) )
			{
				sw_down = OFF;
			
				cnt--;
				if( cnt < 0 )	cnt = EDIT_SUM;
			}
			else if( ( sw_right ) && ( g_int32menu_count > KEY_CHATTERING ) )
			{
				switch( cnt )  
				{
					case EDIT_END :
						pinfo->int32dir = DIR_END | STRAIGHT;
						g_int32total_mark = mark_cnt + 1;
						break;

					case EDIT_STRA :
						pinfo->int32dir = TURN_HARD_STAR;
						break;
				
					case EDIT_L45 :			
					case EDIT_R45 : // 45도

						pinfo->int32dir = ( ( pinfo - 1 )->int32dir & LEFT_TURN ) ? RIGHT_TURN : LEFT_TURN;
						break;

					case EDIT_L270 :
					case EDIT_R270 :

						pinfo->int32dir = TURN_HARD_T270;
						break;

					case EDIT_LLAR :
					case EDIT_RLAR :  //큰턴

						pinfo->int32dist = LARGE_DIST;
						break;

					default :
						break;
				}

				pinfo->pchdir = ( char * )str[ cnt ];
				pinfo->int32angle = angle[ cnt ];		

				VFDPrintf("= SAVE =");
				break;
				
			}
			else if( ( sw_left ) && ( g_int32menu_count > KEY_CHATTERING ) )		break;			
			else;		
			
		}

		if( cnt != vfd_mode )
		{
			VFDPrintf("E@  %s" , str[ cnt ]);
			vfd_mode = cnt;
		}
	
	}

	return 0;
	
}


void line_info_debug( void ) //디버깅은 완료 했으니 곡률 값 자체도 수정할 수 있도록!!!!
{
	int32 row = 0 , half = 0;
	int32 sw_left = OFF , sw_right = OFF;
	int32 menu_mode_select = OFF , vfd_mode = 0;

	sec_info_t *pinfo = g_ptr->psecinfo;

	LED_OFF;

	VFDPrintf(" -wait- ");

	g_Flag.line_info = ON;
	line_load_rom();  //저장된 변수 로드

	VFDPrintf("   0D%4ld" , pinfo->int32dist);
	
	while( 1 )
	{
		if( !UP_SW )  //up switch
		{
			if( row & 0x01 ) // angle
				angle_edit( ( pinfo + half ) , half );			
			else
				plus( TEN , &( pinfo + half )->int32dist );	 //해당 거리나 각도를 증가
		}
		else if( !DOWN_SW )  //down switch
		{
			if( row & 0x01 ) // angle
				angle_edit( ( pinfo + half ) , half );			
			else
				minus( TEN , &( pinfo + half )->int32dist );  //해당 거리나 각도를 감소
		}		
		else if( !RIGHT_SW && !sw_right )
		{
			RMARK_LED_ON;

			sw_right = ON;
			g_int32menu_count = ZERO;
		}
		else if( !LEFT_SW && !sw_left )
		{
			LMARK_LED_ON;
			
			sw_left = ON;
			g_int32menu_count = ZERO;		
		}
		else if( ( !menu_mode_select ) && ( sw_right ) && ( g_int32menu_count > LONG_KEY_CAHTTERING ) )  //long key check
		{
			vh_delay();			
			menu_mode_select = ON;		
		}
		else if( ( sw_left ) && ( g_int32menu_count > DELAY_KEY ) )  //빠르게 넘기기 위한 메뉴 -> 대회때 시간이 없으므로...
		{
			sw_left = OFF;

			row++;
			if( row > ( g_int32total_mark << 1 ) - 1 )		row = 0;
		}
		else if( RIGHT_SW && LEFT_SW && UP_SW && DOWN_SW )
		{
			if( ( !menu_mode_select ) && ( sw_right ) && ( g_int32menu_count > KEY_CHATTERING ) ) 
			{	
				sw_right = OFF;
				SWSU_BELL;

				row++;
				if( row > ( g_int32total_mark << 1 ) - 1 )		row = 0;
			}
			else if( ( !menu_mode_select ) && ( sw_left ) && ( g_int32menu_count > KEY_CHATTERING ) ) 
			{	
				sw_left = OFF;
				SWSU_BELL;

				row--;
				if( row < 0 )		row = ( g_int32total_mark << 1 ) - 1;
			}			
			else if( menu_mode_select )  //escape
			{
				LED_OFF;
			
				VFDPrintf(" -wait- ");
				
				g_int32mark_cnt = g_int32total_mark;
				
				line_save_rom();
				
				break;
			}
			else
			{
				LED_OFF;
				sw_right = sw_left = OFF;
			}
		
		}
		else;

		if( vfd_mode != row )
		{
			half = row >> 1;
		
			if( row & 0x1 )	VFDPrintf("%3ld %s" , half , ( pinfo + half )->pchdir );
			else			VFDPrintf("%3ldD%4ld" , half , ( pinfo + half )->int32dist );

			vfd_mode = row;
		}

	}

}

int race_stop_check( void ) //정지 했는가??
{
	if( !g_Flag.stop_check )	return 0; //주행중이면 return

	LED_OFF;
	if( R_motor.fp32cur_vel_avr < 10.0 && L_motor.fp32cur_vel_avr < 10.0 ) //양쪽 모터 평균 속도가 10 이하로 떨어지면
	{
		while( R_motor.fp32next_vel != 0.0 && L_motor.fp32next_vel != 0.0 ); // 속도가 완전히 0이 될때까지 기다리기

		g_Flag.start_flag = OFF;
		VFDPrintf("%3ld HOW?" , g_int32mark_cnt);

		while( !g_Flag.goal_dest && !g_Flag.err )
		{
			if( !UP_SW )
			{
				if( g_int32mark_cnt < MARK_CNT_LIMIT ) // 1차 주행
				{
					VFDPrintf(" -SAVE- ");
					line_information( NULL );	//END 찍고 제동한 거리까지 저장
					line_save_rom();				//검출한 라인 정보 저장
					break;
				}				
			}
			else if( !DOWN_SW )
			{
				g_int32mark_cnt++;
				
				VFDPrintf(" -NONE- ");
				DELAY_US( 100000 );
				break;
			}
			else;
			
		}		

		g_int32total_mark = g_int32mark_cnt;

		while( 1 )
		{
			TOGLE_BLUE;
			VFDPrintf("E%2ldT%2lf" , g_int32error_cnt , g_fp32time ); //주행 시간 & 에러 카운터 갯수
			DELAY_US( 200000 );			
			TOGLE_RED;
			if( !g_Flag.goal_dest && !g_Flag.err )	VFDPrintf("M%3ld END" , g_int32mark_cnt - 1);  //현재 턴마크 갯수
			else									VFDPrintf("M%3ld END" , g_int32mark_cnt);  //현재 턴마크 갯수
			DELAY_US( 200000 );

			if( !DOWN_SW )
			{
				vh_delay();
				return 1;
			}
			else if( !UP_SW )
			{
				vh_delay();
			
				if( g_int32error_cnt )
					error_disposal_debug_func( &g_err );

				return 1;
			}
			else;
			
		}
	
	}

	return 0;
	
}

int line_out_func( void ) //라인 아웃 체킹 함수
{
	if( g_Flag.line_out )   //라인 아웃(검은판 or 대리석)
	{
		g_int32lineout_cnt++;
		if( g_int32lineout_cnt < LINE_OUT_DELAY ) 		return 0;// 딜레이

		g_int32lineout_cnt = 0;
		g_Flag.move_state = OFF;

		R_motor.int32accel = 15;
		L_motor.int32accel = 15; //급 제동

		R_motor.fp32user_vel = 0.0;
		L_motor.fp32user_vel = 0.0;

		while( R_motor.fp32next_vel != 0.0 && L_motor.fp32next_vel != 0.0 ); // 속도가 완전히 0이 될때까지 기다리기

		LED_ON;
		VFDPrintf("M%3ld OUT" , g_int32mark_cnt );		

		DELAY_US( 150000 );			
		g_Flag.start_flag = OFF;

		while( 1 )
		{
			if( !DOWN_SW )
			{
				vh_delay();
				return 1;
			}
		}
		
	}
	else
	{
		g_Flag.line_out = OFF;
		g_int32lineout_cnt = 0;
	}
	
	return 0;
	
}


void turn_sort_division( sec_info_t *p_info , int32 i )  //턴구분 하는 함수
{
	int32  temp_dist = 0;
	sec_info_t *pinfo = p_info;	

	if( !i )  //출발은 무조건 직진.
		pinfo->int32dir = STRAIGHT;

	if( g_int32mark_gyro_toggle == OFF && pinfo->int32mk_dir & STRAIGHT )
		pinfo->int32dir = STRAIGHT;

	if( pinfo->int32dir & STRAIGHT && !( pinfo->int32dir & DIR_END ) )  //이미 직진임이 판단 났을 경우
	{
		pinfo->int32dir = STRAIGHT;
		pinfo->int32cnt = DL_STR;  //직진 가속시 -> 자세  보정 후 가속할 수 있도록 딜레이 카운터를 적용. ( fastrun.c -> speed_up_compute함수 참조 )

		if( i )		//거리값 빼는 것 또한 딜레이에 따라서 정확하게 계산!!!!
		{			
			if( pinfo->int32dist > SHT_DIST_LIMIT )
			{			
				temp_dist = pinfo->int32dist - ( int32 )( ( float32 )( g_int32turn_vel ) * SAMPLE_FRQ * ( float32 )( ( pinfo - 1 )->int32cnt ) ) - g_int32decel_dist_scope;
				if( temp_dist <= 0 )			
				{
					temp_dist = pinfo->int32dist;
					( pinfo - 1 )->int32cnt = DL_STR;
				}	
			}
			else
			{
				temp_dist = pinfo->int32dist - g_int32decel_dist_scope;
				( pinfo - 1 )->int32cnt = DL_STR;
			}

			pinfo->int32dist = temp_dist;
		}
		
	}
	else if( !( pinfo->int32dir & DIR_END ) )  //END는 턴 구분 필요없음
	{
		if( !( pinfo->int32dir & TURN_HARD_STAR ) && ( pinfo->int32dist <= S_DIST_MIN_LIMIT ) ) // 45도
		{
			pinfo->int32dir = pinfo->int32angle > ( int32 )( g_gyro.fp32center ) ? RIGHT_TURN | TURN_45 : LEFT_TURN | TURN_45;  //전턴이 180도 이상이면 그 자이로값의 영향을 받으므로 다시 계산
			pinfo->int32cnt = DL_45A;
		}
		else if( ( pinfo->int32angle < S_ANGLE_MAX_LIMIT && 
		    pinfo->int32angle > S_ANGLE_MIN_LIMIT && 
		    pinfo->int32dist > S_DIST_MIN_LIMIT ) || ( pinfo->int32dir & TURN_HARD_STAR ) ) //직진
		{		
			pinfo->int32dir = STRAIGHT;
			pinfo->int32cnt = DL_STR;

			if( pinfo->int32dist > SHT_DIST_LIMIT )
			{
				//거리값 빼는 것 또한 딜레이에 따라서 정확하게 계산!!!!
				temp_dist = pinfo->int32dist - ( int32 )( ( float32 )( g_int32turn_vel ) * SAMPLE_FRQ * ( float32 )( ( pinfo - 1 )->int32cnt ) ) - g_int32decel_dist_scope;
				
				if( temp_dist <= 0 )
					temp_dist = pinfo->int32dist;
			}
			else
			{
				temp_dist = pinfo->int32dist - g_int32decel_dist_scope;
				( pinfo - 1 )->int32cnt = DL_STR;
			}

			pinfo->int32dist = temp_dist;				
		}
		else if( pinfo->int32angle < A90_ANGLE_MAX_LIMIT && 
			     pinfo->int32angle > A90_ANGLE_MIN_LIMIT && 
			     pinfo->int32dist < A90_DIST_MAX_LIMIT ) // 90도
		{
			pinfo->int32dir = pinfo->int32angle > ( int32 )( g_gyro.fp32center ) ? RIGHT_TURN | TURN_90 : LEFT_TURN | TURN_90; //전턴이 180도 이상이면 그 자이로값의 영향을 받으므로 다시 계산
			pinfo->int32cnt = DL_90A;
		}
		else if( pinfo->int32angle < A180_ANGLE_MAX_LIMIT && 
			     pinfo->int32angle > A180_ANGLE_MIN_LIMIT && 
			     pinfo->int32dist < A180_DIST_MAX_LIMIT &&
			     pinfo->int32abs > LARGE_ABS_MAX_LIMIT )  // 180도
		{
			pinfo->int32dir |= TURN_180;
			pinfo->int32cnt = DL_180A;

			if( ( pinfo + 1 )->int32dist < MID_DIST_LIMIT && ( pinfo + 1 )->int32angle ) //다음턴이 90도 보다 작은 곡률일 때 -> 방향을 봐서 앵글 값을 보정한다.
				( pinfo + 1 )->int32angle += pinfo->int32dir & RIGHT_TURN ? ( -400 ) : 400;
		}
		else if( ( pinfo->int32angle < A270_ANGLE_MAX_LIMIT && 
			     pinfo->int32angle > A270_ANGLE_MIN_LIMIT && 
			     pinfo->int32dist < A270_DIST_MAX_LIMIT &&
			     pinfo->int32abs > LARGE_ABS_MAX_LIMIT ) || ( pinfo->int32dir & TURN_HARD_T270 ) ) // 270도
		{
			pinfo->int32dir |= TURN_270;
			pinfo->int32cnt = DL_270A;		

			if( ( pinfo + 1 )->int32dist < MID_DIST_LIMIT )//다음턴이 90도 보다 작은 곡률일 때 -> 방향을 봐서 앵글 값을 보정한다.
				( pinfo + 1 )->int32angle += pinfo->int32dir & RIGHT_TURN ? ( -600 ) : 600;
		}	
		else if( g_int32large_turn_flag == ON && ( pinfo->int32dist >= A270_DIST_MAX_LIMIT || ( ( pinfo->int32abs <= LARGE_ABS_MAX_LIMIT ) && ( pinfo->int32dist > A90_DIST_MAX_LIMIT ) ) ) )
		{
			pinfo->int32dir |= LARGE_TURN;
			pinfo->int32cnt = DL_STR;			 //다음이 직진인 경우 감속없이 나간다.

			//large 조건에 부합하지 않는 경우를 따로 두어 270도로 처리한다!!
			if( ( pinfo->int32abs > LARGE_270_BOUNDRY_LIMIT ) && ( pinfo->int32r_dist <= LARGE_270_DIST_COMPARISON ) && ( pinfo->int32l_dist <= LARGE_270_DIST_COMPARISON ) )
			{
				pinfo->int32dir |= TURN_270;
				pinfo->int32dir &= ~( LARGE_TURN );
				
				pinfo->int32cnt = DL_270A;
				
				if( ( pinfo + 1 )->int32dist < MID_DIST_LIMIT )//다음턴이 90도 보다 작은 곡률일 때 -> 방향을 봐서 앵글 값을 보정한다.
					( pinfo + 1 )->int32angle += pinfo->int32dir & RIGHT_TURN ? ( -600 ) : 600;			
			}
			else //거리값 빼는 것 또한 딜레이에 따라서 정확하게 계산!!!!
			{			
				temp_dist = pinfo->int32dist - ( int32 )( ( float32 )( g_int32turn_vel ) * SAMPLE_FRQ * ( float32 )( ( pinfo - 1 )->int32cnt ) ) - g_int32decel_dist_scope;
				if( temp_dist <= 0 )			
				{
					temp_dist = pinfo->int32dist;
					( pinfo - 1 )->int32cnt = DL_STR;
				}	

				pinfo->int32dist = temp_dist;
			}
			
		}
		else  //사실상 에러...
		{
			pinfo->int32dir |= TURN_270;
			pinfo->int32cnt = DL_270A;		

			if( ( pinfo + 1 )->int32dist < MID_DIST_LIMIT )//다음턴이 90도 보다 작은 곡률일 때 -> 방향을 봐서 앵글 값을 보정한다.
				( pinfo + 1 )->int32angle += pinfo->int32dir & RIGHT_TURN ? ( -600 ) : 600;		
		}

		if( ( pinfo->int32dir & ( pinfo + 1 )->int32dir ) )  //현재 마크 방향과 다음 마크 방향이 같을 경우 -> 다음턴은 무조건 직진
			( pinfo + 1 )->int32dir = STRAIGHT;
		
	}
	else  //END일 때
	{
		temp_dist = g_int32start_dist >> 1; //END 실제 거리 보정.
		pinfo->int32dist += temp_dist;  //START - END가 짧을경우 -> END거리를 뺀다 but 길경우 END거리를 더해준다.
	}
	
}

void line_information( turnmark_t *pmark ) //라인 정보 계산 및 턴마크 증가
{
	int32 angle = 0;

	if( g_int32mark_cnt > MARK_CNT_LIMIT )	return;  // 턴마크 체킹값이 250 이상이면 탈출

	g_secinfo[ g_int32mark_cnt ].int32r_dist = ( int32 )( R_motor.fp32gone_distance );
	g_secinfo[ g_int32mark_cnt ].int32l_dist = ( int32 )( L_motor.fp32gone_distance );	

	g_secinfo[ g_int32mark_cnt ].int32dist = ( g_secinfo[ g_int32mark_cnt ].int32r_dist + g_secinfo[ g_int32mark_cnt ].int32l_dist ) >> 1;  //마크와 마크 사이 거리

	g_secinfo[ g_int32mark_cnt ].int32angle = ( int32 )( ( float32 )( g_lineinfo.int32gyro_angle ) / ( float32 )( g_lineinfo.int32step_divider ) ); //앵글 계산
	angle = g_secinfo[ g_int32mark_cnt ].int32angle;	

	g_secinfo[ g_int32mark_cnt ].int32dir = ( angle > ( int32 )( g_gyro.fp32center ) ? ( int32 )( g_rmark.u16mark_dir ) : ( int32 )( g_lmark.u16mark_dir ) ); //턴 방향 결정

	if( pmark == NULL ) //마지막 주행.
	{
		g_secinfo[ g_int32mark_cnt ].int32mk_dir = DIR_END;
		g_secinfo[ g_int32mark_cnt ].int32dir = DIR_END | STRAIGHT;
	}

	g_int32mark_cnt++; //턴마크 증가

	//단순 마크 방향도 따로 저장 -> gyro만 신뢰할 수 없으므로...
	g_secinfo[ g_int32mark_cnt ].int32mk_dir = pmark == g_ptr->plmark ? LEFT_TURN : RIGHT_TURN;
	if( g_int32mark_cnt && g_secinfo[ g_int32mark_cnt ].int32mk_dir == g_secinfo[ g_int32mark_cnt - 1 ].int32mk_dir )  //출발이 직진이므로 이전턴과 방향이 같으면 직진이다.
		g_secinfo[ g_int32mark_cnt ].int32mk_dir = STRAIGHT;

	g_gyro.fp32ag_intergral = 0.0;  //자이로 각도 초기화

	g_lineinfo.int32gone_cnt = 0;
	g_lineinfo.int32gyro_angle = 0;

	g_lineinfo.int32step_divider = 0;
	g_lineinfo.int32history_step = ANGLE_DELAY; //이놈의 초기값을 좀 주면 이전 곡률의 영향을 덜 받을 수 있을 듯...

	R_motor.fp32gone_distance = 0.0;
	L_motor.fp32gone_distance = 0.0; //검출용 변수들 다시 초기화

}


static void line_angle_detection( void ) //라인 곡률 검출
{
	g_lineinfo.int32gone_cnt++;  //이놈도 마크 체크시 초기화 고려해봐야 할 듯... -> 현재 title값이 이전 곡률에 영향을 받으므로 초기화를 해주면 좀 덜 받지 않을까???

	if( g_lineinfo.int32gone_cnt > g_lineinfo.int32history_step + STEP_CNT )  //50을 카운터 할 때마다 실행된다 250us * 50 = 0.0125초마다 곡률값 적분 
	{
		g_lineinfo.int32history_step = g_lineinfo.int32gone_cnt; //카운터 값 갱신

		g_lineinfo.int32gyro_angle += ( ( int32 )( g_gyro.fp32angle ) ); //자이로 적분 -> 테스트 용도.

		g_lineinfo.int32step_divider++; //최종 나눌 카운터
	}
}

void race_start_init( void ) //주행전 반드시 다시 초기화 되어야 하는 변수들 집합
{
	g_Flag.stop_check = OFF;
	g_Flag.race_start = OFF;
	g_Flag.cross_flag = OFF;
	g_Flag.line_out = OFF;
	
	g_Flag.speed_up = OFF;
	g_Flag.speed_up_start = OFF;
	g_int32speed_up_cnt = 0;
	g_Flag.straight = OFF;

	g_Flag.err = OFF;

	g_Flag.xrun = OFF;
	g_Flag.cross_shift = OFF;

	g_secflag.u16sen_enable = NON_SHIFT;
	g_secflag.u16sen_state = NON_SHIFT;

	memset( ( void * )&g_lmark ,  0x00 , sizeof( turnmark_t ) );
	memset( ( void * )&g_rmark ,  0x00 , sizeof( turnmark_t ) );	

	g_lmark.u16mark_enable = RIGHT_MARK_CHEK; // 1110 0000 0000 0000	
	g_rmark.u16mark_enable = LEFT_MARK_CHEK; // 0000 0000 0000 0111	

	g_lmark.u16mark_dir = LEFT_TURN;
	g_rmark.u16mark_dir = RIGHT_TURN;

	L_motor.fp32distance_sum = 0.0;
	R_motor.fp32distance_sum = 0.0;

	L_motor.fp32next_vel = 0.0;
	R_motor.fp32next_vel = 0.0;	

	L_motor.fp32gone_distance = 0.0;
	R_motor.fp32gone_distance = 0.0; 

	g_err.fp32over_dist = 0.0;
	g_pos.u16enable = 0xffff; // 1111 1111 1111 1111

	g_gyro.fp32ag_intergral = 0.0;

	//거리값 초기화 필수 -> 바퀴를 닦으면서 움직이는 것또한 QEP를 통해 거리로 환산되므로...

	if( g_int32shift_level > 8 )	g_int32shift_level = 8;

	g_fp32cross_dist = 0.0;
	g_int32mark_cnt = 0;
	g_int32error_cnt = 0;
	g_int32lineout_cnt = 0;
	g_fp32shift_pos_val = 0.0;

	g_pos.fp32kp = POS_KP_UP;
	g_fp32xrun_dist = 0.0;

}

void search_run( void ) //탐색
{
	if( gyro_center_value_search( &g_gyro ) < 0 )
		return;

	VFDPrintf("Run_Time");
	DELAY_US( 100000 );
	VFDPrintf("        "); 	

	sensor_write_rom(); //sensor setting value save

	memset( ( void * )g_secinfo , 0x00 , sizeof( sec_info_t ) * BUFF_MAX_SIZE ); // 2차 주행 라인 정보 저장 초기화

	g_Flag.goal_dest = OFF; // 1차 주행

	handle_ad_make( OUT_CONER_LIMIT , IN_CONER_LIMIT ); //핸들비 계산
	move_to_move( ( float32 )( SEARCH_DIST ) , ( float32 )( 0.0 ) , 
					( float32 )( g_int32turn_vel ) , ( float32 )( g_int32turn_vel ) , 
					( int32 )( SEARCH_ACC_VALUE ) ); //주행 시작

	race_start_init(); //주행 하기 전 반드시 초기화 다시 되어야 하는 변수들 집합
	g_Flag.start_flag = ON;

	/* 1st search run soruce */	
	while( 1 )
	{
		position_compute(); //포지션 갱신

		if( g_Flag.move_state ) //주행 중일때만...
		{
			g_lmark.fp32turn_dis = ( g_lmark.fp32check_dis + g_rmark.fp32check_dis ) * 0.5; //턴마크 체크 거리값 갱신
			g_rmark.fp32turn_dis = g_lmark.fp32turn_dis;

			mark_checking_func( g_ptr->plmark , g_ptr->prmark ); //왼쪽 턴마크 체킹
			mark_checking_func( g_ptr->prmark , g_ptr->plmark ); //오른쪽 턴마크 체킹
		}

		if( g_int32pid_ISR_cnt ) //모터 interrupt 동기화
		{
			if ( line_out_func() ||
			     race_stop_check() )
			     return;

			line_angle_detection(); //라인 각도 검출 함수

			g_int32pid_ISR_cnt = 0; //조건 리셋
		}

	}	
	
}


