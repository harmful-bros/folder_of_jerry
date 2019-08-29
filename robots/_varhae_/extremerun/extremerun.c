//###########################################################################
//
// FILE		: extremerun.c
//
// TITLE		: _varhae_ Tracer extreme run source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.12.24 $
//###########################################################################

#include "DSP2833x_Device.h"		// DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"		// DSP2833x Examples Include File

typedef enum extrem_variable_vel
{
	LIMIT_45_VEL = 300 , 
	LIMIT_90_VEL = 200 , 

	LIMIT_SHIFT_VEL = 2800 ,

	LIMIT_ACC = 10

}x_vari_vel_e;

#define SHIFT_RATIO			( float32 )6.0
#define RETURN_RATIO		( float32 )7.0
#define ST_RET_RATIO		( float32 )2.4
#define PM_RATIO			( float32 )2.4

volatile float32 right_table[] = 
{
	0.0 , 1000.0 , 2000.0 , 3000.0 , 4275.0 , 6500.0 , 7200.0 , 8000.0 , 10000.0 , 12000.0 , 14000.0
};

volatile float32 left_table[] = 
{
	0.0 , -1000.0 , -2000.0 , -3000.0 , -4275.0 , -6500.0 , -7200.0 , -8000.0 , -10000.0 , -12000.0 , -14000.0
};

static void xcontinus_angle_vel_compute_func( sec_info_t *p_info , volatile float32 dist , volatile float32 kp );
static void xmemmove_sec_info_struct_func( sec_info_t *p_cur , sec_info_t *p_next , volatile float32 limit_vel , volatile float32 m_dist );
static void xsecession_for_angle_func( sec_info_t *pinfo , err_dps_t *perr , int32 mark_cnt );
static void xpos_shift_func( volatile float32 cur_dist , volatile float32 shift_dist , sec_info_t *p_info  );


static void xstraight_compute( sec_info_t *p_info , err_dps_t *p_err , int32 mark_cnt ) //직진 일때
{
	int32 shift = g_int32shift_level;

	sec_info_t *pinfo = p_info;
	err_dps_t *perr = p_err;

	volatile float32 big_vel = 0.0;	
	volatile float32 small_vel = 0.0;

	pinfo->fp32kp_down = POS_KP_UP;

	if(  mark_cnt > 0 )
	{
		pinfo->fp32in_vel  = ( pinfo - 1 )->fp32out_vel ? ( pinfo - 1 )->fp32out_vel : ( float32 )( g_int32turn_vel );
	}
	else
		pinfo->fp32in_vel = ( float32 )( 0.0 );

	if( !( pinfo->int32dir & DIR_END ) )
	{
		xsecession_for_angle_func( ( pinfo + 1 ) , perr , ( mark_cnt + 1 ) );  //다음 턴 미리 계산 한 후에 out_vel 를 결정
		pinfo->fp32out_vel = ( pinfo + 1 )->fp32in_vel;

		if( pinfo->fp32out_vel == 0.0 ) pinfo->fp32out_vel = ( float32 )( g_int32turn_vel );		
	}
	else
		pinfo->fp32out_vel = 0.0;	
	
	do
	{
		pinfo->int32down_flag = OFF;
		pinfo->int32s44s_flag = OFF;
	
		if( pinfo->int32dist > MAX_DIST_LIMIT )  //긴 직진
		{
			pinfo->fp32shift_before = 0.0; //무조건 돌아감.
						
			pinfo->int32acc = g_int32max_acc;
			pinfo->fp32dist_limit = ( float32 )( pinfo->int32dist ) * 0.65;  //총 거리의 65% 지나면 쉬프트 시작
		}
		else if( pinfo->int32dist > MID_DIST_LIMIT )
		{
			pinfo->fp32shift_before = 0.0; //무조건 돌아감.
						
			pinfo->int32acc = g_int32mid_acc;
			pinfo->fp32dist_limit = ( float32 )( pinfo->int32dist ) * 0.4;	//총 거리의 40% 지나면 쉬프트 시작
		}
		else
		{
			if( mark_cnt > 0 )
				pinfo->fp32shift_before = ( ( pinfo - 1 )->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];
			else
				pinfo->fp32shift_before = 0.0;  //start!!
					
			pinfo->int32acc = g_int32short_acc;
			pinfo->fp32dist_limit = ( float32 )( pinfo->int32dist ) * 0.15;  //총 거리의 15% 지나면 쉬프트 시작
		}
				
		if( pinfo->int32dir & DIR_END ) //END 이면 조건문 필요 없음...
			break;		

		pinfo->fp32shift_after = ( ( pinfo + 1 )->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];		
		
		if( ( ( pinfo + 1 )->int32dir & TURN_45 ) && ( ( pinfo + 2 )->int32dir & ( TURN_45 | TURN_90 ) ) ) // 연속턴 | 직진 - 45도 - 45도 - 직진 | 직진 - 45도 - 90도 - 45도
		{
			pinfo->fp32kp_down = POS_KP_DOWN;				
			
			if( pinfo->int32dist < ARBITRATE )	pinfo->int32down_flag = ON;
			else 								pinfo->int32s44s_flag = ON;

			if( ( pinfo + 2 )->int32dir & TURN_45 )
				pinfo->fp32shift_after = ( ( pinfo + 1 )->int32dir & RIGHT_TURN ) ? right_table[ shift + 1 ] : left_table[ shift + 1 ];
		}
		
	}
	while( 0 );

	if( pinfo->int32dir & DIR_END )   //END일때 포지션 당기지 않음...
	{
		pinfo->fp32shift_after = 0.0;
		pinfo->fp32dist_limit = ( float32 )( pinfo->int32dist >> 1 );
	}

	if( !mark_cnt && pinfo->int32acc > 10 )	pinfo->int32acc = 10;  //시작 직진 가속도 제한...

	big_vel = MAX( pinfo->fp32in_vel , pinfo->fp32out_vel );
	small_vel = MIN( pinfo->fp32in_vel , pinfo->fp32out_vel );
	diffvel_to_remaindist_cpt( pinfo->fp32in_vel , pinfo->fp32out_vel , pinfo->int32acc , &pinfo->fp32m_dist );  //속도 다른 구간 거리값 계산

	if( pinfo->fp32m_dist >= ( float32 )( pinfo->int32dist ) )  //빼야할 구간이 실제 거리보다 클 경우 -> 재계산 필요!!!
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
		dist_to_maxvel_cpt( ( float32 )( pinfo->int32dist ) , pinfo->fp32m_dist , big_vel ,  pinfo->int32acc , &( pinfo->fp32vel ) ); //현재 거리와 등가속도에서 최고 속도를 계산	
		diffvel_to_remaindist_cpt( pinfo->fp32vel , pinfo->fp32out_vel , pinfo->int32acc , &( pinfo->fp32decel_dist ) );   //감속 거리 계산	
	}


	perr->fp32err_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist << 2 );  //거리 에러 체크 값

	if( perr->fp32err_dist[ mark_cnt ] > ( float32 )( MID_DIST_LIMIT + SHT_DIST_LIMIT ) )  //직진 거리가 길 경우 -> 에러거리  재 조정.
		perr->fp32err_dist[ mark_cnt ] = ( float32 )( MID_DIST_LIMIT + SHT_DIST_LIMIT ); 

	perr->fp32err_dist[ mark_cnt ] += ( float32 )( pinfo->int32dist );  //곡률마다 에러값을 정해준다.

	perr->fp32under_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist ) * 0.65;  //마크 체크 시점 거리 제한.
	
}

static void x45angle_turn_compute( sec_info_t *p_info , err_dps_t *perr , int32 mark_cnt )  // 45도 곡률
{
	int32 shift = g_int32shift_level;
	sec_info_t *pinfo = p_info;
	volatile float32 m_dist = 0.0;
	
	xsecession_for_angle_func( ( pinfo + 1 ) , perr , ( mark_cnt + 1 ) );		

	pinfo->fp32kp_down = POS_KP_UP;	
	pinfo->int32acc = g_int32turn_acc;

	if( ( ( pinfo - 1 )->int32dir & STRAIGHT ) && ( ( pinfo + 1 )->int32dir & STRAIGHT ) )  //직진 - 45도 - 직진
	{
		pinfo->int32acc = LIMIT_ACC;	
		xmemmove_sec_info_struct_func( pinfo , pinfo + 1 , ( float32 )( g_int32s4s_vel ) , m_dist );  //2800이 MAX 속도임 -> 테스트 했을 시... 위험 정도	
		pinfo->fp32shift_before = ( pinfo->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];
	}
	else
	{
		pinfo->fp32in_vel = ( float32 )( g_int32turn_vel );
		pinfo->fp32kp_down = POS_KP_DOWN;		

		do
		{
			if( ( mark_cnt < 2 ) || ( ( pinfo + 1 )->int32dir & DIR_END ) ) //array index < -1 || array index > g_int32total_mark -> 에러 처리,,,
			{
				pinfo->fp32kp_down = POS_KP_UP;
			
				pinfo->fp32vel = pinfo->fp32out_vel = pinfo->fp32in_vel = ( float32 )( g_int32turn_vel );

				//방향 바로 틀자!!
				if( ( pinfo + 1 )->int32dir & STRAIGHT )
					pinfo->fp32shift_before = ( pinfo->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];
				else		
					pinfo->fp32shift_before = ( ( pinfo + 1 )->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];
			
				break;
			}

			m_dist = ( pinfo + 1 )->int32dist > MID_DIST_LIMIT ? ( float32 )( ( pinfo + 1 )->int32dist >> 2 ) : ( float32 )( ( pinfo + 1 )->int32dist >> 1 );
		
			if( ( ( pinfo - 1 )->int32dir & STRAIGHT ) && ( ( pinfo + 1 )->int32dir & TURN_45 ) && ( ( pinfo + 2 )->int32dir & STRAIGHT ) ) //직진 - 45도 - 45도 - 직진 에서의 45도,,,
			{
				pinfo->int32down_flag = ON;

				xmemmove_sec_info_struct_func( pinfo , pinfo + 2 , ( float32 )( g_int32s44s_vel ) , m_dist );  //탈출 직진을 봐야함 -> pinfo + 2
			
				//상태 유지.
				pinfo->fp32shift_before = ( ( pinfo + 1 )->int32dir & RIGHT_TURN ) ? right_table[ shift + 1 ] : left_table[ shift + 1 ];  //다음 턴 방향을 기준으로 쉬프트...
			}
			else if( ( ( pinfo - 2 )->int32dir & STRAIGHT ) && ( ( pinfo - 1 )->int32dir & TURN_45 ) && ( ( pinfo + 1 )->int32dir & STRAIGHT ) )
			{
				pinfo->int32down_flag = ON;
				pinfo->int32escape_flag = ON;	//escape 이면 90도 가변 하면 안되므로...				

				xmemmove_sec_info_struct_func( pinfo , pinfo + 1 , ( float32 )( g_int32s44s_vel ) , m_dist );  //탈출 직진을 봐야함 -> pinfo + 1
			
				//상태 유지.
				pinfo->fp32shift_before = ( pinfo->int32dir & RIGHT_TURN ) ? right_table[ shift + 1 ] : left_table[ shift + 1 ];  //현재 턴 방향을 기준으로 쉬프트...
			}	
			else if( ( ( pinfo - 1  )->int32dir > TURN_180 ) && ( ( pinfo + 1 )->int32dir > TURN_180 ) )  //큰턴 - 45도 - 큰턴 일때 45도에서 크게 틀지 않도록...
			{
				pinfo->int32down_flag = ON;
				pinfo->fp32vel = pinfo->fp32out_vel = pinfo->fp32in_vel;					
			}
			else if( ( pinfo + 1 )->int32dir & ( TURN_45 | TURN_90 ) )  //연속 턴
			{
				xcontinus_angle_vel_compute_func( pinfo , ( float32 )( pinfo->int32dist >> 1 ) , POS_KP_DOWN );

				if( ( pinfo + 1 )->int32dir & TURN_90 )
					pinfo->fp32shift_before = ( ( pinfo + 1 )->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ]; 
			}
			else if( ( ( pinfo - 1 )->int32dir & TURN_45 ) && ( ( pinfo + 1 )->int32dir & STRAIGHT ) ) //45도 연속턴 탈출 - 직진 
			{
				pinfo->int32down_flag = ON;		//보정 풀면서 들어가야 뻣뻣하지 않음 -> 어차피 직진에서 복구 되므로...
				pinfo->int32escape_flag = ON;	//escape 이면 90도 가변 하면 안되므로...

				xmemmove_sec_info_struct_func( pinfo , pinfo + 1 , ( float32 )( g_int32escape45_vel ) , m_dist );				

				if( ( pinfo + 1 )->int32dist > MID_DIST_LIMIT )
					pinfo->fp32shift_before = 0.0;  //거리가 길때 꺾으면 흔들림 심함,,,
				else
					pinfo->fp32shift_before = ( pinfo->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];
			}
			else if( ( ( pinfo - 2 )->int32dir & ( TURN_45 | TURN_90 ) ) && ( ( pinfo  - 1 )->int32dir & TURN_90 ) && ( ( pinfo + 1 )->int32dir & STRAIGHT ) ) // ( 45도 | 90도 ) - 90도 - 45도 - 직진 에서의 탈출 45도...
			{
				pinfo->int32down_flag = ON;  	//보정 풀면서 들어가야 뻣뻣하지 않음 -> 어차피 직진에서 복구 되므로...
				pinfo->int32escape_flag = ON;	//escape 이면 90도 가변 하면 안되므로...				

				xmemmove_sec_info_struct_func( pinfo , pinfo + 1 , ( float32 )( g_int32escape45_vel ) , m_dist );

				pinfo->fp32shift_before = ( pinfo->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];  //다음이 직진이므로 현재 방향으로 쉬프트.		
			}
			else
			{
				pinfo->fp32kp_down = POS_KP_UP;
			
				//가변 턴 -> 현재 턴 속도 보다 300 더 높인다!!
				if( ( pinfo + 1 )->int32dir & STRAIGHT )
					xmemmove_sec_info_struct_func( pinfo , pinfo + 1 , ( float32 )( g_int32turn_vel + LIMIT_45_VEL ) , m_dist );
				else
				{
					dist_to_maxvel_cpt( ( float32 )( pinfo->int32dist ) , ( float32 )( pinfo->int32dist >> 1 ) , ( float32 )( g_int32turn_vel ) ,  pinfo->int32acc , &pinfo->fp32vel );

					if( pinfo->fp32vel > ( float32 )( g_int32turn_vel + LIMIT_45_VEL ) )
						pinfo->fp32vel = ( float32 )( g_int32turn_vel + LIMIT_45_VEL );
					
					diffvel_to_remaindist_cpt( pinfo->fp32vel , ( float32 )( g_int32turn_vel ) , pinfo->int32acc , &pinfo->fp32decel_dist );

					pinfo->fp32in_vel = pinfo->fp32out_vel = ( float32 )g_int32turn_vel;
				}

				//방향 바로 틀자!!
				if( ( pinfo + 1 )->int32dir & STRAIGHT )
					pinfo->fp32shift_before = ( pinfo->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];
				else		
					pinfo->fp32shift_before = ( ( pinfo + 1 )->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];
			}
		
		}
		while( 0 );
		
	}	

	pinfo->fp32shift_after = pinfo->fp32shift_before;	
	pinfo->fp32dist_limit = ( float32 )( pinfo->int32dist >> 1 );					

	perr->fp32err_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist << 1 ); 		//곡률마다 에러값을 정해준다.
	perr->fp32under_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist >> 2 );	//마크 체크 시점 거리 제한.
	
}

static void x90angle_turn_compute( sec_info_t *p_info , err_dps_t *perr , int32 mark_cnt )  // 90도 곡률
{
	sec_info_t *pinfo = p_info;
	volatile float32 m_dist = 0.0;
	int32 shift = g_int32shift_level;	

	int32 ret = 0;

	pinfo->int32acc = g_int32turn_acc;

	pinfo->fp32kp_down = POS_KP_UP;	

	pinfo->fp32in_vel = ( float32 )( g_int32turn_vel );	
	pinfo->fp32vel = pinfo->fp32out_vel = pinfo->fp32in_vel;

	pinfo->fp32shift_before = ( pinfo->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];
	
	if( ( pinfo + 1 )->int32dir & STRAIGHT )
	{	
		do
		{
			if( ( mark_cnt > 2 && ( pinfo - 2 )->int32escape_flag == ON ) ||
				( ( pinfo - 1 )->int32dir & STRAIGHT ) && ( ( pinfo - 1 )->int32dist > MID_DIST_LIMIT ) ) //이전 이전 턴이 탈출 속도 적용 턴 | 긴 직진 이면 가변 하진 않는다!!!!
				break;
		
			xsecession_for_angle_func( ( pinfo + 1 ) , perr , ( mark_cnt + 1 ) );
		
			if( ( ( pinfo - 1 )->int32down_flag == OFF ) && ( ( pinfo - 1 )->int32s44s_flag == OFF ) ) //이전이 ( 직진 | 연속턴 ) 이면 가변속 하지 않는다.
			{
				m_dist = ( pinfo + 1 )->int32dist > MID_DIST_LIMIT ? ( float32 )( ( pinfo + 1 )->int32dist >> 2 ) : ( float32 )( ( pinfo + 1 )->int32dist >> 1 );
				xmemmove_sec_info_struct_func( pinfo , pinfo + 1 , ( float32 )( g_int32turn_vel + LIMIT_90_VEL ) , m_dist );	
			}
		}
		while( 0 );

		pinfo->fp32shift_after = pinfo->fp32shift_before;		

	}
	else
	{
		do
		{
			if( ( pinfo + 1 )->int32dir & ( TURN_45 | TURN_90 ) )  //연속 턴
			{
				xsecession_for_angle_func( ( pinfo + 1 ) , perr , ( mark_cnt + 1 ) );				
				xcontinus_angle_vel_compute_func( pinfo , ( float32 )( pinfo->int32dist >> 1 ) , POS_KP_DOWN );		

				if( ( ( pinfo - 1 )->int32dir & STRAIGHT ) && ( ( pinfo - 1 )->int32dist > MID_DIST_LIMIT ) )  //이전 턴이 중간 이상급 직진 or 다다음턴이 큰 턴일 경우 -> 취소한다
				{
					pinfo->int32s44s_flag = ON;
					pinfo->int32down_flag = OFF;

					pinfo->fp32in_vel = ( float32 )( g_int32turn_vel );
					pinfo->fp32out_vel = pinfo->fp32vel = pinfo->fp32in_vel;
				}
				else if( !( ( pinfo + 1 )->int32dir & DIR_END ) && ( ( pinfo + 2 )->int32dir > TURN_180 ) )
				{
					pinfo->fp32kp_down = POS_KP_UP;
				
					pinfo->int32s44s_flag = OFF;
					pinfo->int32down_flag = OFF;

					pinfo->fp32in_vel = ( float32 )( g_int32turn_vel );
					pinfo->fp32out_vel = pinfo->fp32vel = pinfo->fp32in_vel;					

					ret = 1;
				}
				else;
				
			}
			else
			{
				if( mark_cnt > 2 && ( pinfo - 2 )->int32escape_flag == ON ) //이전 이전 턴이 탈출 속도 적용 턴 이면 가변 하진 않는다!!!!
					break;
				
				if( ( ( pinfo - 1 )->int32down_flag == OFF ) && ( ( pinfo - 1 )->int32s44s_flag == OFF ) && 
					( ( pinfo - 1 )->int32dir & STRAIGHT ) && ( ( pinfo - 1 )->int32dist < MID_DIST_LIMIT ) &&
					( ( pinfo + 1 )->int32dir & STRAIGHT ) && ( ( pinfo + 1 )->int32dist < MID_DIST_LIMIT ) )  //짧은 직진 - 90도 - 짧은 직진 에서만 가변한다!!
				{
					//가변 턴 -> 현재 턴 속도보다 200 더 높인다.
					dist_to_maxvel_cpt( ( float32 )( pinfo->int32dist ) , ( float32 )( pinfo->int32dist >> 1 ) , ( float32 )( g_int32turn_vel ) ,  pinfo->int32acc , &pinfo->fp32vel );

					if( pinfo->fp32vel > ( float32 )( g_int32turn_vel + LIMIT_90_VEL ) )
						pinfo->fp32vel = ( float32 )( g_int32turn_vel + LIMIT_90_VEL );
					
					diffvel_to_remaindist_cpt( pinfo->fp32vel , ( float32 )( g_int32turn_vel ) , pinfo->int32acc , &pinfo->fp32decel_dist );			

					pinfo->fp32in_vel = pinfo->fp32out_vel = ( float32 )g_int32turn_vel;
				}
			}	
			
		}
		while( 0 );

		if( ret )
			pinfo->fp32shift_after = pinfo->fp32shift_before;
		else
			pinfo->fp32shift_after = ( ( pinfo + 1 )->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];			
		
	}

	pinfo->fp32dist_limit = pinfo->int32dist >> 1;	

	perr->fp32err_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist >> 1 );
	perr->fp32err_dist[ mark_cnt ] += ( float32 )( pinfo->int32dist );  //곡률마다 에러값을 정해준다.

	perr->fp32under_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist >> 1 );	 //마크 체크 시점 거리 제한.
	
}

static void x180angle_turn_compute( sec_info_t *pinfo , err_dps_t *perr , int32 mark_cnt )
{
	int32 shift = g_int32shift_level;

	pinfo->int32acc = g_int32turn_acc;

	pinfo->fp32kp_down = POS_KP_UP;	

	pinfo->fp32in_vel = ( float32 )( g_int32turn_vel );
	pinfo->fp32out_vel = pinfo->fp32vel = pinfo->fp32in_vel;

	pinfo->fp32shift_before = ( pinfo->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];
	
	if( ( pinfo + 1 )->int32dir & STRAIGHT )
		pinfo->fp32shift_after = ( pinfo->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];		
	else
		pinfo->fp32shift_after = ( ( pinfo + 1 )->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];

	pinfo->fp32dist_limit = ( float32 )( pinfo->int32dist ) * 0.65;

	perr->fp32err_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist >> 1 );
	perr->fp32err_dist[ mark_cnt ] += ( float32 )( pinfo->int32dist );  //곡률마다 에러값을 정해준다.

	perr->fp32under_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist ) * 0.65;	 //마크 체크 시점 거리 제한.

}


static void xdefault_turn_compute( sec_info_t *pinfo , err_dps_t *perr , int32 mark_cnt ) //default turn -> 270도 곡률이 될 꺼임
{
	int32 shift = g_int32shift_level;

	pinfo->int32acc = g_int32turn_acc;

	pinfo->fp32kp_down = POS_KP_UP;	

	pinfo->fp32in_vel = ( float32 )( g_int32turn_vel );
	if( g_int32turn_vel > LIMIT_SHIFT_VEL )
		pinfo->fp32in_vel = ( float32 )( LIMIT_SHIFT_VEL );
	
	pinfo->fp32out_vel = pinfo->fp32vel = pinfo->fp32in_vel;

	pinfo->fp32shift_before = ( pinfo->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];
	
	if( ( pinfo + 1 )->int32dir & STRAIGHT )	
		pinfo->fp32shift_after = ( pinfo->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];
	else
		pinfo->fp32shift_after = ( ( pinfo + 1 )->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];

	pinfo->fp32dist_limit = ( float32 )( pinfo->int32dist ) * 0.8;

	perr->fp32err_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist >> 1 );
	perr->fp32err_dist[ mark_cnt ] += ( float32 )( pinfo->int32dist );  //곡률마다 에러값을 정해준다.

	perr->fp32under_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist ) * 0.65;	 //마크 체크 시점 거리 제한.
	
}

static void xlarge_turn_compute( sec_info_t *p_info , err_dps_t *p_err , int32 mark_cnt )
{
	int32 shift = g_int32shift_level;

	sec_info_t *pinfo = p_info;
	err_dps_t *perr = p_err;

	volatile float32 big_vel = 0.0;
	volatile float32 small_vel = 0.0;

	pinfo->fp32kp_down = POS_KP_UP;
	pinfo->fp32in_vel = pinfo->fp32vel = pinfo->fp32out_vel = ( float32 )g_int32turn_vel;

	if( ( pinfo + 1 )->int32dir & STRAIGHT )  //다음이 직진이면 직진 최고 속도로 탈출 한다.
	{
		xsecession_for_angle_func( ( pinfo + 1 ) , perr , ( mark_cnt + 1 ) );
		xmemmove_sec_info_struct_func( pinfo , pinfo + 1 , ( float32 )( g_int32large_vel ) , ( float32 )0.0 );
		pinfo->fp32in_vel = ( float32 )( g_int32turn_vel );
	}

	pinfo->int32down_flag = OFF;
	pinfo->int32s44s_flag = OFF;

	pinfo->fp32shift_before = ( pinfo->int32dir & RIGHT_TURN ) ? right_table[ shift + 2 ] : left_table[ shift + 2 ];
	pinfo->int32acc = g_int32large_acc;
	pinfo->fp32dist_limit = ( float32 )( pinfo->int32dist ) * 0.8;  //총 거리의 65% 지나면 쉬프트 시작

	if( ( pinfo + 1 )->int32dir & STRAIGHT )
		pinfo->fp32shift_after = pinfo->fp32shift_before;
	else
		pinfo->fp32shift_after = ( ( pinfo + 1 )->int32dir & RIGHT_TURN ) ? right_table[ shift ] : left_table[ shift ];
	
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

	if( pinfo->fp32vel > ( float32 )( g_int32large_vel ) )
		pinfo->fp32vel = ( float32 )( g_int32large_vel );
	
	if( ( pinfo - 1 )->int32dir & STRAIGHT )  //이전이 직진이면 직진 최고 속도로 진입한다.
		pinfo->fp32in_vel = pinfo->fp32vel;

	perr->fp32err_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist << 2 );  //거리 에러 체크 값

	if( perr->fp32err_dist[ mark_cnt ] > ( float32 )( MID_DIST_LIMIT + SHT_DIST_LIMIT ) )  //직진 거리가 길 경우 -> 에러거리  재 조정.	
		perr->fp32err_dist[ mark_cnt ] = ( float32 )( MID_DIST_LIMIT + SHT_DIST_LIMIT ); 

	perr->fp32err_dist[ mark_cnt ] += ( float32 )( pinfo->int32dist );	//곡률마다 에러값을 정해준다.

	perr->fp32under_dist[ mark_cnt ] = ( float32 )( pinfo->int32dist ) * 0.65;	//마크 체크 시점 거리 제한.

}

static void xcontinus_angle_vel_compute_func( sec_info_t *p_info , volatile float32 dist , volatile float32 kp )
{
	sec_info_t *pinfo = p_info;

	pinfo->fp32kp_down = kp;
	pinfo->int32acc = g_int3245A_acc;

	pinfo->int32down_flag = ON;

	 //돌아오면서 계산 되어줘야 하는 구간.
	pinfo->fp32out_vel = ( pinfo + 1 )->fp32in_vel;
	dist_to_maxvel_cpt( ( float32 )( pinfo->int32dist ) , dist , pinfo->fp32out_vel ,  pinfo->int32acc , &( pinfo->fp32vel ) ); //현재 거리와 등가속도에서 최고 속도를 계산
	diffvel_to_remaindist_cpt( pinfo->fp32out_vel , pinfo->fp32vel , pinfo->int32acc , &pinfo->fp32decel_dist );

	if( pinfo->fp32vel > ( float32 )( g_int3245A_vel ) )	pinfo->fp32vel = ( float32 )( g_int3245A_vel );  //최고 속도 제한.

	pinfo->fp32in_vel = pinfo->fp32vel;	
	
}

static void xmemmove_sec_info_struct_func( sec_info_t *p_cur , sec_info_t *p_next , volatile float32 limit_vel , volatile float32 m_dist )
{
	sec_info_t cpy_info;
	sec_info_t *pinfo = p_cur;

	memset( ( void * )&cpy_info , 0x00 , sizeof( sec_info_t ) );

	memmove( ( void * )&cpy_info , ( const void * )p_next , sizeof( sec_info_t ) );	 //다음 턴 정보를 info 변수에 copy -> 직접 계산하면 call by reference 이므로 안됨...
	dist_to_maxvel_cpt( ( float32 )( cpy_info.int32dist ) , m_dist , MIN( cpy_info.fp32in_vel , cpy_info.fp32out_vel ) , cpy_info.int32acc , &cpy_info.fp32vel );  //다음 턴 정보를 가지고 다음 턴에서의 최고속도를 계산한다.
	
	if( cpy_info.fp32vel > limit_vel ) 								pinfo->fp32in_vel = limit_vel;
	else if( cpy_info.fp32vel < ( float32 )( g_int32turn_vel ) )	pinfo->fp32in_vel = ( float32 )( g_int32turn_vel );
	else															pinfo->fp32in_vel = cpy_info.fp32vel;
	
	pinfo->fp32vel = pinfo->fp32out_vel = pinfo->fp32in_vel;
}

static void xsecession_for_angle_func( sec_info_t *pinfo , err_dps_t *perr , int32 mark_cnt ) //직진?? / 45도?? / 90도?? / 180도?? / 270도?? / 큰턴??
{
		 if( pinfo->int32dir & STRAIGHT 	)	xstraight_compute( pinfo , perr , mark_cnt );
	else if( pinfo->int32dir & TURN_45 		)	x45angle_turn_compute( pinfo , perr , mark_cnt );
	else if( pinfo->int32dir & TURN_90 		)	x90angle_turn_compute( pinfo , perr , mark_cnt );
	else if( pinfo->int32dir & TURN_180 	)	x180angle_turn_compute( pinfo , perr , mark_cnt );
	else if( pinfo->int32dir & TURN_270 	)	xdefault_turn_compute( pinfo , perr , mark_cnt );
	else if( pinfo->int32dir & LARGE_TURN 	)	xlarge_turn_compute( pinfo , perr , mark_cnt );
	else										xdefault_turn_compute( pinfo , perr , mark_cnt );
}

static void xmaxvel_compute_inadvance( void )
{
	int32 i;
	sec_info_t *pinfo = NULL;

	SCIa_Printf("\n\n");

	for( i = 0 ; i < g_int32total_mark ; i++ )
	{
		xsecession_for_angle_func( &g_secinfo[ i ] , &g_err , i );
	}

	if( g_int32total_mark < BUFF_MAX_SIZE )
	{
		pinfo = &g_secinfo[ g_int32total_mark ];
		memset( ( void * )pinfo , 0x00 , sizeof( sec_info_t ) );  //넘어간 조건에 대해 초기화 -> 에러처리시 속도보다 500 떨어지고 1차주행한다.

		pinfo->int32acc = g_int32turn_acc;
		pinfo->fp32kp_down = POS_KP_UP;			
		pinfo->fp32in_vel = pinfo->fp32vel = pinfo->fp32out_vel = ( float32 )( g_int32turn_vel - 500 );
	}

#if 0
	SCIa_Printf("!! large mode %s !!\n\n" , g_int32large_turn_flag == ON ? "ON" : "OFF");

#if 1
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
#endif

	while( 1 )
	{
		DELAY_US( 1 );
	}
#endif

}

void xkval_ctrl_func( Uint32 mode , position_t *p_pos , float32 ratio , volatile float32 limit )
{
	position_t *ppos = p_pos;
	
	volatile float32 kval = 0.0;
	volatile float32 *pval = NULL;

	volatile float32 up_limit = 0.0;

	if( mode & KVAL_KP )
	{
		kval = ppos->fp32kp;
		pval = &ppos->fp32kp;

		up_limit = POS_KP_UP;
	}
	else		
	{
		kval = ppos->fp32kd;
		pval = &ppos->fp32kd;

		up_limit = POS_KD_UP;
	}

	if( mode & KVAL_UP )
	{
		kval += ( ratio * g_fp32shift_dist );
		if( kval > up_limit )
			kval = up_limit;
	}
	else
	{
		kval -= ( ratio * g_fp32shift_dist );
		if( kval < limit )
			kval = limit;	
	}

	*pval = kval;
	
}


static void xpos_shift_func( volatile float32 cur_dist , volatile float32 shift_dist , sec_info_t *p_info )
{
	sec_info_t *pinfo = p_info;

	volatile float32 c_dist = cur_dist;
	volatile float32 s_dist = shift_dist;

	volatile float32 pre_ratio = ( pinfo->int32dir & STRAIGHT ) && ( pinfo->int32dist > MID_DIST_LIMIT ) ? ST_RET_RATIO : SHIFT_RATIO;
	volatile float32 aft_ratio = ( pinfo->int32dir & STRAIGHT ) && ( pinfo->int32dist > MID_DIST_LIMIT ) ? ST_RET_RATIO : RETURN_RATIO;		
	
	volatile float32 pos_val = g_fp32shift_pos_val;


	if( g_Flag.cross_shift )
		return;

	if( g_Flag.err )
	{
		if( pos_val > ( float32 )( 0.0 ) )			pos_val -= ( g_fp32shift_dist * SHIFT_RATIO );
		else if( pos_val < ( float32 )( 0.0 ) )		pos_val += ( g_fp32shift_dist * SHIFT_RATIO );
		else										pos_val = ( float32 )( 0.0 );		

		g_fp32shift_pos_val = pos_val;
		
		return;
	}

	if( c_dist < pinfo->fp32dist_limit )
	{
		if( pos_val > pinfo->fp32shift_before + PM_RATIO )			pos_val -= ( s_dist * pre_ratio );
		else if( pos_val < pinfo->fp32shift_before - PM_RATIO )		pos_val += ( s_dist * pre_ratio );
		else														pos_val = pinfo->fp32shift_before;
	}
	else
	{
		if( pos_val > pinfo->fp32shift_after + PM_RATIO )			pos_val -= ( s_dist * aft_ratio );
		else if( pos_val < pinfo->fp32shift_after - PM_RATIO )		pos_val += ( s_dist * aft_ratio );
		else
		{
			if( pinfo->int32dir > TURN_180 )
				YELLOW_ON;
			
			pos_val = pinfo->fp32shift_after;	
		}
	}		

	g_fp32shift_pos_val = pos_val;	
	
}


void extreme_run( sec_info_t *p_info )
{
	sec_info_t *pinfo = p_info;
	volatile float32 turn_vel = ( float32 )( g_int32turn_vel + LIMIT_90_VEL );  //실제 턴속도 보다 약간 높게!!
	
	volatile float32 shift_dist;

	if( turn_vel > ( float32 )( LIMIT_SHIFT_VEL ) ) //2800을 넘기지 않는다
		turn_vel = ( float32 )( LIMIT_SHIFT_VEL );

	shift_dist = turn_vel * SAMPLE_FRQ;  //인터럽트 주기당 거리

	g_Flag.xrun = ON;  // 3차 주행.
	g_Flag.goal_dest = ON; // 2차 주행

	if( gyro_center_value_search( &g_gyro ) < 0 )
		return;
	
	VFDPrintf("Run_Time");
	DELAY_US( 240000 );	
	VFDPrintf("        ");

	race_start_init(); //주행 하기 전 반드시 초기화 다시 되어야 하는 변수들 집합

	line_load_rom();  //저장된 변수 로드

	if( g_int32inverse_run == ON )
		inverse_run_info_compute();	

	xmaxvel_compute_inadvance(); //주행 전 미리 곡률들 속도 및 가속도 계산

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
		g_fp32xrun_dist = ( L_motor.fp32gone_distance + R_motor.fp32gone_distance ) * 0.5;
		xpos_shift_func( g_fp32xrun_dist , shift_dist , &g_secinfo[ g_int32mark_cnt ] );
	
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
			second_error_disposal( &g_err ,  pinfo , g_int32mark_cnt );  //마크 에러처리

			g_int32pid_ISR_cnt = 0; //조건 리셋
		}		
		
	}
	
}


