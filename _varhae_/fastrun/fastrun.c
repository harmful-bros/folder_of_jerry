//###########################################################################
//
// FILE		: fastrun.c
//
// TITLE		: _varhae_ Tracer fastrun source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.11.21 $
//###########################################################################

#include "DSP2833x_Device.h"		// DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"		// DSP2833x Examples Include File


static void nsecession_for_angle_func( sec_info_t *pinfo , err_dps_t *perr , int32 mark_cnt );

void second_error_disposal( err_dps_t *p_err , sec_info_t *p_info , int32 mark_cnt )  //마크 에러 처리 함수
{
	sec_info_t *pcur;
	sec_info_t *pnext;

	err_dps_t *perr = p_err;

	volatile int32 dist = 0;	

	perr->fp32over_dist = ( R_motor.fp32gone_distance + L_motor.fp32gone_distance ) * 0.5;  //현재 간 거리 계속 확인

	if( g_Flag.err == ON )
	{
		g_Flag.goal_dest = OFF;
		return;
	}

	if( perr->fp32over_dist > perr->fp32err_dist[ mark_cnt ] )  //마크에 주어진 에러값보다 더 갔을경우( 마크를 놓쳤을 경우 )
	{
		perr->int32mark_val[ g_int32error_cnt++ ] = mark_cnt;	

		if( g_int32error_cnt > MARK_LIMIT || ( mark_cnt > g_int32total_mark - 1 ) )  //mark error cnt가 20개 이상이면 1차 주행으로 전환.
		{
			LED_ON;
			VFDPrintf(" -ERRO- ");

			g_Flag.err = ON;
			g_Flag.goal_dest = OFF;			
			
			return;
		}
		
		pcur = p_info + mark_cnt;
		pnext = ( p_info + mark_cnt + 1 );

		dist = ( int32 )( perr->fp32err_dist[ mark_cnt ] ) - pcur->int32dist - g_int32decel_dist_scope;
		if( dist < 0 )
			dist = ( int32 )( perr->fp32err_dist[ mark_cnt ] ) - pcur->int32dist;

		pnext->int32dist -= dist;  //실제 에러 수치를 다시 빼서 남은 거리를 구한다.
		if( pnext->int32dist < 0 )
			pnext->int32dist = 10;

		dist_to_maxvel_cpt( ( float32 )( pnext->int32dist ) , pnext->fp32m_dist , MAX( pnext->fp32in_vel , pnext->fp32out_vel ) , pnext->int32acc , &( pnext->fp32vel ) ); 	//현재 거리와 등가속도에서 최고 속도를 계산	
		diffvel_to_remaindist_cpt( pnext->fp32vel , pnext->fp32out_vel , pnext->int32acc , &( pnext->fp32decel_dist ) );   				//감속 거리 계산 

		perr->fp32under_dist[ mark_cnt + 1 ] = ( float32 )( pnext->int32dist >> 1 );

		runmode_lineinfo( p_info , perr ); //마크 강제 처리

	}
	
}

void error_disposal_debug_func( err_dps_t *p_err )  //에러 정보들 보는 메뉴.
{
	int32 row = 0;
	int32 sw_left = OFF , sw_right = OFF;
	int32 menu_mode_select = OFF , vfd_mode = 0;

	err_dps_t *perr = p_err;

	LED_OFF;

	VFDPrintf( "e%2ld:%4ld" , row + 1 , perr->int32mark_val[ row ] );	

	while( 1 )
	{
		if( !RIGHT_SW && !sw_right )
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
		else if( RIGHT_SW && LEFT_SW )
		{
			if( ( !menu_mode_select ) && ( sw_right ) && ( g_int32menu_count > KEY_CHATTERING ) ) 
			{	
				SWSU_BELL;			
				sw_right = OFF;

				row++;
				if( row > g_int32error_cnt - 1 )	row = 0;
			}
			else if( ( !menu_mode_select ) && ( sw_left ) && ( g_int32menu_count > KEY_CHATTERING ) ) 
			{	
				SWSU_BELL;			
				sw_left = OFF;

				row--;
				if( row < 0 )						row = g_int32error_cnt - 1;
			}			
			else if( menu_mode_select )  //escape
			{
				LED_OFF;
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
			VFDPrintf( "e%2ld:%4ld" , row + 1 , perr->int32mark_val[ row ] );
			vfd_mode = row;
		}		
	
	}
	
}

static void nstraight_compute( sec_info_t *pinfo , err_dps_t *perr , int32 mark_cnt ) //직진 일때
{
	volatile float32 big_vel = 0.0;
	volatile float32 small_vel = 0.0;

	volatile float32 error_dist = 0.0;

	pinfo->fp32in_vel = mark_cnt > 0 ? ( pinfo - 1 )->fp32out_vel : ( float32 )( 0.0 );

	if( !( pinfo->int32dir & DIR_END ) )
	{
		nsecession_for_angle_func( ( pinfo + 1 ) , perr , ( mark_cnt + 1 ) );  //다음 턴 미리 계산 한 후에 out_vel 를 결정
		pinfo->fp32out_vel = ( pinfo + 1 )->fp32in_vel;

		pinfo->fp32out_vel = ( float32 )( g_int32turn_vel );
	}
	else
		( pinfo + 1 )->fp32in_vel = pinfo->fp32out_vel = 0.0;	

	if( pinfo->int32dist > MAX_DIST_LIMIT )
	{
		pinfo->int32acc = g_int32max_acc;

		if( pinfo->int32dir & DIR_END )
			pinfo->int32acc = pinfo->int32acc > 10 ? 10 : g_int32max_acc;
	}
	else if( pinfo->int32dist > MID_DIST_LIMIT )	pinfo->int32acc = g_int32mid_acc;
	else											pinfo->int32acc = g_int32short_acc;

	if( !mark_cnt && pinfo->int32acc > 10 )	pinfo->int32acc = 10;  //시작 직진 가속도 제한...

	big_vel = MAX( pinfo->fp32in_vel , pinfo->fp32out_vel );
	small_vel = MIN( pinfo->fp32in_vel , pinfo->fp32out_vel );

	diffvel_to_remaindist_cpt( pinfo->fp32in_vel , pinfo->fp32out_vel , pinfo->int32acc , &pinfo->fp32m_dist );

	if( pinfo->fp32m_dist >= ( float32 )pinfo->int32dist )
	{
		pinfo->fp32decel_dist = ( float32 )( pinfo->int32dist );
		dist_to_maxvel_cpt( ( float32 )( pinfo->int32dist ) , ( float32 )0.0 , small_vel ,  pinfo->int32acc , &( pinfo->fp32vel ) ); //현재 거리와 등가속도에서 최고 속도를 계산			

		if( pinfo->fp32in_vel > pinfo->fp32out_vel )	pinfo->fp32in_vel = pinfo->fp32vel;
		else											pinfo->fp32out_vel = pinfo->fp32vel;	

		if( !mark_cnt )  //start
			pinfo->fp32in_vel = 0.0;	
	}
	else
	{
		dist_to_maxvel_cpt( ( float32 )( pinfo->int32dist ) , pinfo->fp32m_dist , big_vel,  pinfo->int32acc , &( pinfo->fp32vel ) ); 	//현재 거리와 등가속도에서 최고 속도를 계산	
		diffvel_to_remaindist_cpt( pinfo->fp32vel , pinfo->fp32out_vel , pinfo->int32acc , &( pinfo->fp32decel_dist ) );   				//감속 거리 계산	
	}

	perr->fp32err_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist << 2 );  //거리 에러 체크 값

	if( perr->fp32err_dist[ mark_cnt ] > ( float32 )( MID_DIST_LIMIT + SHT_DIST_LIMIT ) )  //직진 거리가 길 경우 -> 에러거리  재 조정.
		perr->fp32err_dist[ mark_cnt ] = ( float32 )( MID_DIST_LIMIT + SHT_DIST_LIMIT ); 

	perr->fp32err_dist[ mark_cnt ] += ( float32 )( pinfo->int32dist );  //곡률마다 에러값을 정해준다.

	perr->fp32under_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist ) * 0.7;
	
}

static void nlarge_turn_compute( sec_info_t *pinfo , err_dps_t *perr , int32 mark_cnt )
{
	volatile float32 big_vel = 0.0;
	volatile float32 small_vel = 0.0;

	pinfo->fp32in_vel  = ( pinfo - 1 )->fp32out_vel ? ( pinfo - 1 )->fp32out_vel : ( float32 )( g_int32turn_vel );

	nsecession_for_angle_func( ( pinfo + 1 ) , perr , ( mark_cnt + 1 ) );  //다음 턴 미리 계산 한 후에 out_vel 를 결정
	pinfo->fp32out_vel = ( pinfo + 1 )->fp32in_vel;

	if( pinfo->fp32out_vel == 0.0 )
		pinfo->fp32out_vel = ( float32 )( g_int32turn_vel );

	if( pinfo->fp32in_vel > ( float32 )( g_int32large_vel ) )
		pinfo->fp32in_vel = ( float32 )( g_int32large_vel );

	if( pinfo->fp32out_vel > ( float32 )( g_int32large_vel ) )
		pinfo->fp32out_vel = ( float32 )( g_int32large_vel );

	pinfo->int32acc = g_int32large_acc;

	big_vel = MAX( pinfo->fp32in_vel , pinfo->fp32out_vel );
	small_vel = MIN( pinfo->fp32in_vel , pinfo->fp32out_vel );
	diffvel_to_remaindist_cpt( pinfo->fp32in_vel , pinfo->fp32out_vel , pinfo->int32acc , &pinfo->fp32m_dist );  //속도 다른 구간 거리값 계산

	if( pinfo->fp32m_dist >= ( float32 )( pinfo->int32dist ) )  //빼야할 구간이 실제 거리보다 클 경우 -> 재계산 필요!!!
	{
		pinfo->fp32decel_dist = ( float32 )( pinfo->int32dist );
		dist_to_maxvel_cpt( ( float32 )( pinfo->int32dist ) , ( float32 )0.0 , small_vel ,  pinfo->int32acc , &( pinfo->fp32vel ) ); //현재 거리와 등가속도에서 최고 속도를 계산

		if( pinfo->fp32in_vel > pinfo->fp32out_vel )	pinfo->fp32in_vel = pinfo->fp32vel;
		else											pinfo->fp32out_vel = pinfo->fp32vel;
	}
	else
	{
		dist_to_maxvel_cpt( ( float32 )( pinfo->int32dist ) , pinfo->fp32m_dist , big_vel ,  pinfo->int32acc , &( pinfo->fp32vel ) ); //현재 거리와 등가속도에서 최고 속도를 계산
		diffvel_to_remaindist_cpt( pinfo->fp32vel , pinfo->fp32out_vel , pinfo->int32acc , &( pinfo->fp32decel_dist ) );   //감속 거리 계산
	}

	perr->fp32err_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist << 2 );  //거리 에러 체크 값

	if( perr->fp32err_dist[ mark_cnt ] > ( float32 )( MID_DIST_LIMIT + SHT_DIST_LIMIT ) )  //직진 거리가 길 경우 -> 에러거리  재 조정.	
		perr->fp32err_dist[ mark_cnt ] = ( float32 )( MID_DIST_LIMIT + SHT_DIST_LIMIT ); 

	perr->fp32err_dist[ mark_cnt ] += ( float32 )( pinfo->int32dist );	//곡률마다 에러값을 정해준다.

	perr->fp32under_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist ) * 0.65;	//마크 체크 시점 거리 제한.

	
}

static void ndefault_turn_compute( sec_info_t *pinfo , err_dps_t *perr , int32 mark_cnt ) //default turn -> 270도 곡률이 될 꺼임
{
	pinfo->int32acc = g_int32turn_acc;

	pinfo->fp32kp_down = POS_KP_UP;	

	pinfo->fp32in_vel = ( float32 )( g_int32turn_vel );	
	pinfo->fp32vel = pinfo->fp32out_vel = pinfo->fp32in_vel;	

	perr->fp32err_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist >> 1 );
	perr->fp32err_dist[ mark_cnt ] += ( float32 )( pinfo->int32dist );  //곡률마다 에러값을 정해준다.

	perr->fp32under_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist ) * 0.65;

	if( ( pinfo->int32dir & TURN_45 ) && ( pinfo + 1 )->int32dir & ( TURN_45 | TURN_90 ) )
	{
		pinfo->int32down_flag = ON;
		pinfo->fp32kp_down = POS_KP_DOWN;		

		/* error */
		perr->fp32err_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist << 2 );
		perr->fp32under_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist >> 1 );	 //마크 체크 시점 거리 제한.		
	}
	
}

static void nsecession_for_angle_func( sec_info_t *pinfo , err_dps_t *perr , int32 mark_cnt ) //직진?? / 45도?? / 90도?? / 180도?? / 270도?? / 큰턴??
{
	if( pinfo->int32dir & STRAIGHT )			nstraight_compute( pinfo , perr , mark_cnt );
	else if( pinfo->int32dir & LARGE_TURN )		nlarge_turn_compute( pinfo , perr , mark_cnt );
	else										ndefault_turn_compute( pinfo , perr , mark_cnt );
}

static void nmaxvel_compute_inadvance( void )
{
	int32 i;

	SCIa_Printf("\n\n");

	for( i = 0 ; i < g_int32total_mark ; i++ )
	{
		nsecession_for_angle_func( &g_secinfo[ i ] , &g_err , i );
	}

#if 0
	SCIa_Printf("\n\n");
	for( i = 0 ; i < g_int32total_mark ; i++ )	
	{
		SCIa_Printf("MARK[%3ld] : mkdir : %s dir : %s in_vel : %12lf vel : %12lf out_vel : %12lf acc : %2ld dist : %4ld dec_dist : %12lf err_dist : %12lf angle : %6ld l_dist : %4ld r_dist : %4ld abs : %4ld\n" , 
																												i , 
																												g_secinfo[ i ].pchmk_dir ,
																												g_secinfo[ i ].pchdir , 
																												g_secinfo[ i ].fp32in_vel  , 
																				   								g_secinfo[ i ].fp32vel , 
																				   								g_secinfo[ i ].fp32out_vel ,  
																				   								g_secinfo[ i ].int32acc , 
																				   								g_secinfo[ i ].int32dist , 
																				   								g_secinfo[ i ].fp32decel_dist , 
																				   								g_err.fp32err_dist[ i ] , 
																				   								g_secinfo[ i ].int32angle , 
																				   								g_secinfo[ i ].int32l_dist , 
																				   								g_secinfo[ i ].int32r_dist , 
																				   								g_secinfo[ i ].int32abs);

	}	

	while(1)
	{
		DELAY_US( 1 );
	}

#endif

}

void runmode_lineinfo( sec_info_t *pinfo , err_dps_t *perr ) // 2차 주행 라인 정보 꺼내오기
{
	 //턴마크 나올 거리가 안됬을 경우( 마크를 더 찍은 경우 )
	if( g_Flag.err == OFF && perr->fp32over_dist < perr->fp32under_dist[ g_int32mark_cnt ] )		return;

	g_int32mark_cnt++;  //저장된 곡률보다 한칸 뒷 정보를 불러와야 한다.

	if( g_Flag.err == OFF )
	{
		LED_OFF;

		if( g_int32total_mark < g_int32mark_cnt )
		{
			g_Flag.err = ON;

			R_motor.fp32gone_distance = 0.0;
			L_motor.fp32gone_distance = 0.0; //검출용 변수들 다시 초기화

			R_motor.fp32distance_sum = 0.0;
			L_motor.fp32distance_sum = 0.0;			
			
			return;
		}
	
		if( ( pinfo + g_int32mark_cnt )->int32dir & STRAIGHT || ( pinfo + g_int32mark_cnt )->int32dir & LARGE_TURN )	g_Flag.speed_up_start = ON; 	//가속 시작 플래그 ON
		else																											g_Flag.straight = OFF;

	
		move_to_move( ( float32 )( ( pinfo + g_int32mark_cnt )->int32dist ) , ( pinfo + g_int32mark_cnt )->fp32decel_dist , 
						( pinfo + g_int32mark_cnt )->fp32vel , ( pinfo + g_int32mark_cnt )->fp32out_vel , 
						( pinfo + g_int32mark_cnt )->int32acc ); //가속
						
	}
	else
	{
		 //에러 체크.
	}

	perr->fp32over_dist = 0.0;

	R_motor.fp32gone_distance = 0.0;
	L_motor.fp32gone_distance = 0.0; //검출용 변수들 다시 초기화

	R_motor.fp32distance_sum = 0.0;
	L_motor.fp32distance_sum = 0.0;
	
}

void speed_up_compute( sec_info_t *pinfo ) //가속 시작 플래그 ON
{
	if( !g_Flag.speed_up_start || g_Flag.err == ON )	return; //가속 시작 플래그가 들어오지 않으면 실행 안됨

	g_int32speed_up_cnt++;
	if( g_int32mark_cnt == 0 || g_int32speed_up_cnt > ( pinfo + g_int32mark_cnt - 1 )->int32cnt ) //일정 카운터 딜레이 -> 자세가 틀어진 상태로 직진으로 진입했을 시 자세보정 시간 딜레이
	{
		g_Flag.speed_up = ON;		 	//가속 플래그 ON -> motor.c -> position_to_vel() 함수에서 user_vel 결정
		g_Flag.speed_up_start = OFF;	//다시 함수 안으로 들어오지 않음
		g_int32speed_up_cnt = 0;
	}
}

static int compare_markcnt_func( const void *ptr1 , const void *ptr2 )
{
	return -( ( ( sec_info_t * )ptr1 )->int32mark - ( ( sec_info_t * )ptr2 )->int32mark );
}

void inverse_run_info_compute( void )
{
	int32 i;
	sec_info_t *pinfo = g_secinfo;

	//모든 정보를 뒤집어야 함!!
	qsort( ( void * )pinfo , g_int32total_mark , sizeof( sec_info_t ) , compare_markcnt_func );

	for( i = 0 ; i < g_int32total_mark ; i++ )
	{
		//방향은 모두 반대로 줘야 한다.
		if( ( pinfo + i )->int32dir & RIGHT_TURN )
		{
			( pinfo + i )->int32dir |= LEFT_TURN;
			( pinfo + i )->int32dir &= ~( RIGHT_TURN );

			( pinfo + i )->pchdir[ 0 ] = 'L';
		}
		else if( ( pinfo + i )->int32dir & LEFT_TURN )
		{
			( pinfo + i )->int32dir |= RIGHT_TURN;
			( pinfo + i )->int32dir &= ~( LEFT_TURN );		

			( pinfo + i )->pchdir[ 0 ] = 'R';			
		}
		else;
	}

	//start
	pinfo->pchdir = "STRA";
	pinfo->int32dir = STRAIGHT;	

	//END
	( pinfo + i - 1 )->pchdir = "END ";
	( pinfo + i - 1 )->int32dir = ( DIR_END | STRAIGHT ); 
	( pinfo + i - 1 )->int32dist += ( g_int32decel_dist_scope << 1 );	
	
}

void nomal_run( sec_info_t *p_info )
{
	sec_info_t *pinfo = p_info;

	g_Flag.goal_dest = ON; // 2차 주행

	if( gyro_center_value_search( &g_gyro ) < 0 )
		return;

	VFDPrintf("Run_Time");
	DELAY_US( 240000 );
	VFDPrintf("        ");

	race_start_init(); //주행 하기 전 반드시 초기화 다시 되어야 하는 변수들 집합

	line_load_rom();   //저장 변수 로드
	
	if( g_int32inverse_run == ON )
		inverse_run_info_compute();

	nmaxvel_compute_inadvance(); //주행 전 미리 곡률들 속도 및 가속도 계산
	
	if( pinfo->int32dir & STRAIGHT ) //첫 곡률이 직진일 경우.	
	{
		BLUE_ON;
		g_Flag.speed_up_start = ON; //가속 시작 플래그 ON
	}
	else
		g_Flag.straight = OFF;

	handle_ad_make( OUT_CONER_LIMIT , FASTRUN_IN_CONER_LIMIT ); //핸들비 계산	
	move_to_move( ( float32 )( pinfo->int32dist ) , pinfo->fp32decel_dist , pinfo->fp32vel , pinfo->fp32out_vel , pinfo->int32acc );

	g_Flag.start_flag = ON;	

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

			speed_up_compute( pinfo ); //가속 시작 플래그 기다리는 함수
			second_error_disposal( &g_err ,  pinfo , g_int32mark_cnt );
					
			g_int32pid_ISR_cnt = 0; //조건 리셋
		}		
		
	}
	
}


