//###########################################################################
//
// FILE			: menu.c
//
// TITLE			: _varhae_(v.28335) menu source
//
// Author		: leejaeseong
//
// Company		: Hertz
//
//###########################################################################
// $Release Date: 2009.07.03 $
//###########################################################################
//
//			/* main menu */
//
// 오른쪽 버튼 		-> 	행 이동( 증가 )
// 위쪽 버튼 			-> 	열 이동( 증가 )
// 위쪽 long 버튼 		-> 	해당 함수 실행
//
//###########################################################################
//
//	/* sub menu( vel , acc , rally ) */
//
// 오른쪽 버튼 		-> 	행 이동( 증가 )
// 왼쪽 버튼 			-> 	행 이동( 감소 )
// 아래쪽 버튼 		-> 	변수 값 감소
// 위쪽 버튼 			-> 	변수 값 증가
// 오른쪽 long 버튼 	-> 	변수 저장 후 탈출.
//
//###########################################################################
//
//			/* debug menu */
//
// 오른쪽 버튼 		->	행 이동( 증가 )
// 왼쪽 버튼 			-> 	행 이동( 감소 )
// 아래쪽 버튼 		-> 	비어있음 or 실행 함수 탈출
// 위쪽 버튼 			-> 	해당 함수 실행
// 오른쪽 long 버튼 	-> 	디버그 메뉴 탈출
//
//###########################################################################


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File


void ( *select_func[ ROW ][ COL ] )( void );
static int on_off( e_ctrl_define num , volatile int32 *value );
 
const char menu_table[ ROW ][ COL ][ VFD_LIST ] = 
{
	"sch    ?","n_r    ?","f_r    ?" ,
	"vel    ?","acc    ?","info   ?" ,
	"sst    ?","deb    ?","init   ?" ,
};

const char *velocity_table[] = 
{
	"turn  v?","max   v?", "45t   v?" , "s44s  v?" , "lar   v?" , "level  ?" , "scope  ?" , "esc   v?" , "lmt   v?" , "mark   ?" , "s4s   v?" ,
};

const char *acceleration_table[] = 
{
	"turn  a?","max   a?", "mid   a?" , "sot   a?" , "lar   a?" , "45t   a?" , "end   a?" , "back   ?" , "lar   m?" , "gyro  m?" , "end   d?" ,
};

const char *rally_point_table[] = 
{
	"turn  v?", "max   a?" , "mid   a?" , "sot   a?" , "45t   a?" , "s44s  v?" , "s4s   v?" , "esc   v?" , "lar   a?" , "lmt   v?" , "end   a?" , "end   d?" , "level  ?" , 
};

const char *debug_table[] = 
{
	"s_val  ?" , "s_div  ?" , "s_dat  ?" , "s_pos  ?" , "s_sta  ?" , "g_val  ?" , "g_agl  ?" , "c_val  ?" , "PWM    ?" , 
};


static func_ctrl vel_plus[ VEL_LIST_END ] = 
{
		{	FIVE		,	plus		,	&g_int32turn_vel			} ,
		{	HUND 		,	plus		,	&g_int32max_speed			} ,
		{	FHUND		,	plus		,	&g_int3245A_vel				} ,		
		{	HUND		,	plus		,	&g_int32s44s_vel			} ,				
		{	FIFTY 		,	plus		,	&g_int32large_vel 			} ,
		{	ONE 		,	plus		,	&g_int32shift_level			} ,		
		{	TEN 		,	plus		,	&g_int32decel_dist_scope	} ,		
		{	FIFTY		,	plus		,	&g_int32escape45_vel		} ,		
		{	TEN 		,	plus		,	&g_int32limit_vel			} ,	
		{	ONE 		,	plus		,	&g_int32force_mark			} ,	
		{	FIFTY		,	plus		,	&g_int32s4s_vel				} ,			
};

static func_ctrl vel_minus[ VEL_LIST_END ] = 
{
		{	FIVE		,	minus		,	&g_int32turn_vel			} ,
		{	HUND 		,	minus		,	&g_int32max_speed			} ,
		{	FHUND 		,	minus		,	&g_int3245A_vel				} ,		
		{	HUND 		,	minus		,	&g_int32s44s_vel			} ,				
		{	FIFTY 		,	minus		,	&g_int32large_vel 			} ,
		{	ONE 		,	minus		,	&g_int32shift_level			} ,	
		{	TEN 		,	minus		,	&g_int32decel_dist_scope	} ,			
		{	FIFTY		,	minus		,	&g_int32escape45_vel		} ,	
		{	TEN 		,	minus		,	&g_int32limit_vel			} ,	
		{	ONE 		,	minus		,	&g_int32force_mark			} ,		
		{	FIFTY		,	minus		,	&g_int32s4s_vel				} ,		
};

static func_ctrl acc_plus[ ACC_LIST_END ] = 
{
		{	ONE 		,	plus		,	&g_int32turn_acc			} ,
		{	ONE			,	plus		,	&g_int32max_acc				} ,
		{	ONE			,	plus		,	&g_int32mid_acc				} ,		
		{	ONE			,	plus		,	&g_int32short_acc			} ,		
		{	ONE			,	plus		,	&g_int32large_acc 			} ,	
		{	ONE			,	plus		,	&g_int3245A_acc				} ,			
		{	ONE			,	plus		,	&g_int32end_acc				} ,		
		{	ONE 		,	on_off		,	&g_int32inverse_run			} ,
		{	ONE 		,	on_off		,	&g_int32large_turn_flag		} ,		
		{	ONE 		,	on_off		,	&g_int32mark_gyro_toggle	} ,	
		{	TEN 		,	plus		,	&g_int32end_dist			} ,			
};

static func_ctrl acc_minus[ ACC_LIST_END ] = 
{
		{	ONE 		,	minus		,	&g_int32turn_acc			} ,
		{	ONE 		,	minus		,	&g_int32max_acc				} ,
		{	ONE 		,	minus		,	&g_int32mid_acc				} ,
		{	ONE 		,	minus		,	&g_int32short_acc			} ,		
		{	ONE 		,	minus		,	&g_int32large_acc			} ,	
		{	ONE 		,	minus		,	&g_int3245A_acc				} ,			
		{	ONE 		,	minus		,	&g_int32end_acc				} ,		
		{	ONE 		,	on_off		,	&g_int32inverse_run			} , 
		{	ONE 		,	on_off		,	&g_int32large_turn_flag		} , 				
		{	ONE 		,	on_off		,	&g_int32mark_gyro_toggle	} , 		
		{	TEN 		,	minus		,	&g_int32end_dist			} ,
};

static func_ctrl rally_point_plus[ RALLY_POINT_END ] = 
{
		{	TEN 		, 	plus 		, 	&g_int32turn_vel 		} ,
		{	ONE 		, 	plus 		, 	&g_int32max_acc			} , 
		{	ONE 		, 	plus 		, 	&g_int32mid_acc			} , 
		{	ONE 		, 	plus 		, 	&g_int32short_acc		},
		{	ONE 		, 	plus 		, 	&g_int3245A_acc			} ,		
		{	HUND 		, 	plus 		, 	&g_int32s44s_vel		} ,
		{	FIFTY		,	plus		,	&g_int32s4s_vel			} ,		
		{	FIFTY 		, 	plus 		, 	&g_int32escape45_vel	} , 			
		{	ONE			, 	plus 		, 	&g_int32large_acc		} ,		
		{	TEN 		,	plus		,	&g_int32limit_vel		} ,
		{	ONE 		, 	plus 		, 	&g_int32end_acc			} , 			
		{	TEN 		, 	plus 		, 	&g_int32end_dist		} , 					
		{	ONE 		,	plus		,	&g_int32shift_level		} ,		
};

static func_ctrl rally_point_minus[ RALLY_POINT_END ] = 
{
		{	TEN 		, 	minus 		, 	&g_int32turn_vel		} ,
		{	ONE 		, 	minus 		, 	&g_int32max_acc			} , 
		{	ONE 		, 	minus 		, 	&g_int32mid_acc			} , 
		{	ONE 		, 	minus 		, 	&g_int32short_acc		} , 
		{	ONE 		, 	minus 		, 	&g_int3245A_acc			} ,				
		{	HUND 		, 	minus 		, 	&g_int32s44s_vel		} ,	
		{	FIFTY		,	minus		,	&g_int32s4s_vel			} ,		
		{	FIFTY 		, 	minus 		, 	&g_int32escape45_vel	} , 			
		{	ONE 		, 	minus 		, 	&g_int32large_acc		} , 		
		{	TEN 		,	minus		,	&g_int32limit_vel		} ,			
		{	ONE 		, 	minus 		, 	&g_int32end_acc			} , 
		{	TEN 		, 	minus 		, 	&g_int32end_dist		} , 
		{	ONE 		,	minus		,	&g_int32shift_level		} ,			
};

int plus( e_ctrl_define num , volatile int32 *value ) //변수 증가
{
	if( value == NULL )
	{
		VFDPrintf(" =NULL= ");
		DELAY_US( 100000 );

		return -1;
	}

	( *value ) += num;
	if( ( *value ) > 30000 )	( *value ) = 30000;

	VFDPrintf("E@  %4ld" , ( *value ) );
	DELAY_US( 30000 );

	return 0;
}

int minus( e_ctrl_define num, volatile int32 *value ) //변수 감소
{
	if( value == NULL )
	{
		VFDPrintf(" =NULL= ");
		DELAY_US( 100000 );

		return -1;
	}

	( *value ) -= num;
	if( ( *value ) < 0 )	( *value ) = 0;

	VFDPrintf("E@  %4ld" , ( *value ) );
	DELAY_US( 30000 );

	return 0;
}

static int on_off( e_ctrl_define num , volatile int32 *value )
{
	const char *table[] = { "OFF" , " ON" };

	if( value == NULL )
	{
		VFDPrintf(" =NULL= ");
		DELAY_US( 100000 );

		return -1;
	}

	( *value ) ^= num;

	VFDPrintf("E@   %s" , table[ *value ] );
	DELAY_US( 60000 );	

	return 0;
}

static void setting_value_save( void )
{
	 velocity_save_rom();
	 accel_save_rom();
}

static void menu_shift_control( int list_end , const char *table[] , 
								func_ctrl *pfunc_plus , func_ctrl *pfunc_minus , 
								e_menu_mode mode , void ( *pfunc_debug[] )( str_point_t * ) ) //메뉴 이동 및 실행 함수
{
	int32 cnt = 0;
	int32 sw_right = 0;
	int32 sw_left = 0;

	LED_OFF;
	VFDPrintf( ( char * )table[ 0 ] );

	while( 1 )
	{
		if( !UP_SW )
		{
			if( !mode ) //증감 모드일 경우
				( pfunc_plus + cnt )->vel_ctr( ( pfunc_plus + cnt )->num ,  ( pfunc_plus + cnt )->variable ); //해당하는 증감 함수에 변수를 집어넣고 조절
			else //디버깅 모드일 경우
			{
				if( *pfunc_debug[ cnt ] == NULL ) //메뉴가 비어있을 경우( 에러처리 )
				{
					VFDPrintf(" =NULL= ");
					vh_delay();
				}
				else
					pfunc_debug[ cnt ]( g_ptr ); //디버깅 메뉴의 해당 함수 실행
			}
		}
		else if( !DOWN_SW )
		{
			if( !mode )
				( pfunc_minus + cnt )->vel_ctr( ( pfunc_minus + cnt )->num ,  ( pfunc_minus + cnt )->variable );
			else
			{
				VFDPrintf(" -NONE- ");
				vh_delay();
			}
		}
		else if( !LEFT_SW && !( sw_left ) ) //왼쪽 스위치 ON
		{
			LMARK_LED_ON;
			sw_left = ON;
			g_int32menu_count = ZERO;
		}
		else if( LEFT_SW && sw_left && ( g_int32menu_count > KEY_CHATTERING ) ) //왼쪽 스위치 채터링 필터링 후 ON
		{
			LMARK_LED_OFF;
			SWSU_BELL;
			sw_left = OFF;

			cnt--;							//해당 메뉴 리스트 감소.
			if( cnt < 0 )	cnt = ( list_end - 1 );	 //한바퀴 다 돌면 제일 뒤로 돌림
			VFDPrintf( ( char * )table[ cnt ] );		//해당 메뉴 vfd table 갱신
		}
		else if( !RIGHT_SW && !( sw_right ) ) //오른쪽 스위치 ON
		{
			RMARK_LED_ON;
			sw_right = ON;
			g_int32menu_count = ZERO;
		}
		else if( RIGHT_SW && sw_right && ( g_int32menu_count > KEY_CHATTERING ) ) //오른쪽 스위치 채터링 필터링 후 ON
		{
			RMARK_LED_OFF;
			SWSU_BELL;
			sw_right = OFF;

			cnt++;								 //해당 메뉴 리스트 증가.
			if( cnt > ( list_end - 1 ) )	cnt = ZERO;		 //한바퀴 다 돌면 제일 앞으로 돌림
			VFDPrintf( ( char * )table[ cnt ] );			 //해당 메뉴 vfd table 갱신
		}
		else if( !RIGHT_SW && sw_right && ( g_int32menu_count > LONG_KEY_CAHTTERING ) ) //오른쪽 스위치 long key
		{
			LED_OFF;
			vh_delay();
			sw_right = OFF;

			//save
			setting_value_save(); //변수들 변경값 저장			

			return; //탈출
		}
		else;

	}

}

static void velocity_control( void ) //속도 값 변경
{
	menu_shift_control( VEL_LIST_END , velocity_table , vel_plus , vel_minus ,  CONTROL , NULL ); //속도 증감 컨트롤
}

static void acceleration_control( void ) //가속도 값 변경
{
	menu_shift_control( ACC_LIST_END , acceleration_table , acc_plus , acc_minus , CONTROL , NULL ); //가속도 증감 컨트롤	
}

static void rally_point_vari_control( void ) //주행시 빠르게 필요한 메뉴들만 값 바꿀 수 있는 함수포인터
{
	menu_shift_control( RALLY_POINT_END , rally_point_table , rally_point_plus , rally_point_minus , CONTROL , NULL ); //rally point variable
}
static void debug_menu_select( void ) //디버깅 메뉴 집합
{
	void ( *debug_func[ DEBUG_LIST_END ] )( str_point_t * ); //디버그 메뉴 등록 함수 포인터

	debug_func[ SEN_VAL ] 		= 	debug_sen_val;
	debug_func[ SEN_DIV ] 		=	debug_sen_div;
	debug_func[ SEN_DATA ] 		= 	debug_sen_data;
	debug_func[ SEN_POS ] 		= 	debug_sen_pos;	
	debug_func[ SEN_STATE ] 	= 	debug_sen_state;		
	debug_func[ GYRO_VAL ] 		= 	debug_gyro_val;
	debug_func[ GYRO_ANGLE ] 	= 	debug_gyro_angle;	
	debug_func[ CPS_VAL ] 		= 	debug_cps_val;	
	debug_func[ PWM_TEST ] 		= 	debug_force_PWM;

	menu_shift_control( DEBUG_LIST_END , debug_table , NULL , NULL , DEBUG , debug_func );		
}

static void rom_init( void ) //강제로 변수들 초기화
{
	 //velocity vari
	g_int32turn_vel = 2100; //기본 턴
	g_int32max_speed = 7000;
	g_int32large_vel = 3200;
	g_int32shift_level = 4;
	g_int32decel_dist_scope = 60;
	g_int3245A_vel = 7000;
	g_int32s44s_vel = 2700;
	g_int32escape45_vel = 3000;
	g_int32force_mark = 0;
	g_int32limit_vel = 3600;
	g_int32s4s_vel = 2800;	
	g_int32end_dist = END_DIST_LIMIT;

	 //accelation vari
	g_int32turn_acc = 17; 	//기본 가속도
	g_int32max_acc = 3; 	//긴 직진 가속도( 거리 2000 이상)
	g_int32mid_acc = 5;		//중간 직진 가속도( 거리 600이상 )
	g_int32short_acc = 8;	//짧은 직진 가속도	
	g_int32large_acc = 1;
	g_int3245A_acc = 6;
	g_int32end_acc = 9;		//엔드 후 가속도

	g_int32inverse_run = OFF;	
	g_int32large_turn_flag = OFF;
	g_int32mark_gyro_toggle = OFF;

	velocity_save_rom();
	accel_save_rom();

	VFDPrintf(" --OK-- ");
	DELAY_US( 100000 );
	
}

static void extreme_mode0_func( void )
{
}

static void extreme_mode1_func( void )
{
}

static void extreme_mode2_func( void )
{
}

static void extreme_mode3_func( void )
{
}

static void extreme_mode4_func( void )
{
}

static int32 short_menu_ctrl( void )
{
	int32 ret = 1;
	int32 sw_right = 0;
	LED_OFF;

	VFDPrintf("Let'sGo?");

	while( 1 )
	{
		if( !DOWN_SW && !sw_right )  //DOWN switch -> 탈출
		{
			vh_delay();			
			break;
		}
		else if( !UP_SW && !sw_right )  //up switch -> menu로 comeback
		{
			ret = 0;
			vh_delay();			
			break;
		}		
		else if( !RIGHT_SW && !sw_right )  //RIGHT switch -> 변수 값 조절
		{
			sw_right = ON;
			g_int32menu_count = ZERO;					
		}
		else if( RIGHT_SW && sw_right  && ( g_int32menu_count > KEY_CHATTERING ) )
		{
			sw_right = OFF;						
			rally_point_vari_control();		

			break;
		}		
		else;
		
	}

	return ret;

}

static int32 extreme_mode_select_func( void )
{
	int32 ret = 1;
	int32 sw_right = 0;
	int32 sw_left = 0;
	static int32 cnt = 0;

	const char *vfd_table[ 6 ] = { "esc  >>" , "lev0  >>" , "lev1  >>" , "lev2  >>" , "lev3  >>" , "lev4  >>" };
	void ( *pfunc[ 6 ] )( void );

	VFDPrintf( ( char * )( vfd_table[ cnt ] ) );

	while( 1 )
	{
		if( !UP_SW && !sw_right ) //up switch -> menu로 comeback	
		{
			ret = 0;
			vh_delay();

			break;
		}
		else if( !DOWN_SW && !sw_right )  //DOWN switch -> 탈출
		{
			pfunc[ 0 ] = NULL;
			pfunc[ 1 ] = extreme_mode0_func;
			pfunc[ 2 ] = extreme_mode1_func;
			pfunc[ 3 ] = extreme_mode2_func;
			pfunc[ 4 ] = extreme_mode3_func;
			pfunc[ 5 ] = extreme_mode4_func;

			vh_delay();			

			if( cnt )
			{
				pfunc[ cnt ]();

				velocity_save_rom();
				accel_save_rom();
			}

			break;
			
		}
		else if( !RIGHT_SW && !sw_right )  //RIGHT switch -> 변수 값 조절
		{
			RMARK_LED_ON;		
			sw_right = ON;
			g_int32menu_count = ZERO;
		}
		else if( RIGHT_SW && sw_right  && ( g_int32menu_count > KEY_CHATTERING ) )
		{
			RMARK_LED_OFF;
			SWSU_BELL;
			sw_right = OFF;
			
			cnt++;
			if( cnt > 5 )	cnt = 0;

			VFDPrintf( ( char * )( vfd_table[ cnt ] ) );			
		}
		else if( !LEFT_SW && !sw_left )  //RIGHT switch -> 변수 값 조절
		{
			LMARK_LED_ON;		
			sw_left = ON;
			g_int32menu_count = ZERO;
		}
		else if( LEFT_SW && sw_left  && ( g_int32menu_count > KEY_CHATTERING ) )
		{
			LMARK_LED_OFF;
			SWSU_BELL;
			sw_left = OFF;
			
			cnt--;
			if( cnt < 0  )	cnt = 5;

			VFDPrintf( ( char * )( vfd_table[ cnt ] ) );			
		}		
		else;
		
	}	

	return ret;
	
}

static void search_run_mode( void ) //탐색 주행 시작...
{
	if( short_menu_ctrl() )	
		search_run(); //탐색 주행 시작

	VFDPrintf( (char *)menu_table[ 0 ][ 0 ] ); //다시 메인 메뉴로 돌아감
}

static void nomal_run_mode( void )
{
	if( short_menu_ctrl() )	
		nomal_run( g_secinfo ); // 2차 주행

	g_int32mark_gyro_toggle = OFF;

	VFDPrintf( (char *)menu_table[ 0 ][ 1 ] ); //다시 메인 메뉴로 돌아감
}

static void extreme_run_mode( void )
{
	if( short_menu_ctrl() && extreme_mode_select_func() )	
		extreme_run( g_secinfo ); // 2차 주행

	g_int32mark_gyro_toggle = OFF;
		
	VFDPrintf( (char *)menu_table[ 0 ][ 2 ] ); //다시 메인 메뉴로 돌아감
}


void menu_func_init( void )
{
	select_func[ 0 ][ 0 ] = search_run_mode;
	select_func[ 0 ][ 1 ] = nomal_run_mode;
	select_func[ 0 ][ 2 ] = extreme_run_mode;

	select_func[ 1 ][ 0 ] = velocity_control;
	select_func[ 1 ][ 1 ] = acceleration_control;
	select_func[ 1 ][ 2 ] = line_info_debug;

	select_func[ 2 ][ 0 ] = sensor_setting_classic;
	select_func[ 2 ][ 1 ] = debug_menu_select;
	select_func[ 2 ][ 2 ] = rom_init;
}


void menu_select( void )
{
	int32 row = 0 , col = 0;
	int32 sw_up = 0 , sw_right = 0;
	int32 fact_mode0 = 0 , fact_mode1 = 0;
	int32 menu_mode_select = 0;

	LED_OFF;
	VFDPrintf( ( char * )menu_table[ 0 ][ 0 ] );

	while( TRUE )
	{
		if( ( !UP_SW ) && ( !sw_up ) ) // up_sw
		{
			RED_ON;
			BLUE_ON;
			
			sw_up= ON;
			g_int32menu_count = ZERO;
		}
		else if( ( !RIGHT_SW ) && ( !sw_right ) ) // right_sw
		{
			GREEN_ON;
			YELLOW_ON;
			sw_right = ON;
			g_int32menu_count = ZERO;
		}		
		else if( ( !menu_mode_select ) && ( sw_up ) && ( g_int32menu_count > LONG_KEY_CAHTTERING ) ) // long_up_sw chattering debug
		{
			vh_delay();			
			menu_mode_select = ON;		
		}
		else if( ( UP_SW ) && ( RIGHT_SW ) )
		{		
			if( ( !menu_mode_select ) && ( sw_up ) && ( g_int32menu_count > KEY_CHATTERING ) ) // up_sw chattering debug
			{
				sw_up = OFF;
				SWU_BELL;	
				
				row++;
				if( row >= ROW ) row = 0;
				else;				
			}
			else if( ( !menu_mode_select ) && ( sw_right ) && ( g_int32menu_count > KEY_CHATTERING ) ) // right_sw chattering debug
			{	
				sw_right = OFF;

				SWR_BELL;
				col++;

				if( col >= COL )	col = 0;
				else;
			}	
			else if( menu_mode_select ) // long_up_sw
			{
				menu_mode_select = OFF;
				sw_up = sw_right = OFF;

				if( *select_func[ row ][ col ] == NULL )	VFDPrintf(" --NC-- "); // func pointer is NULL
				else // func pointer excute
				{
					select_func[ row ][ col ]();	
					if( row != 0 )
					{
						row = col = 0;
						VFDPrintf( ( char * )menu_table[ 0 ][ 0 ] );
					}
				}
			}
			else
			{
				LED_OFF;
				sw_up = sw_right = OFF;
			}
			
		}
		else;

		if( fact_mode0 != row ) // vfd chattering debug
		{
			VFDPrintf( ( char * )menu_table[ row ][ col ] );
			fact_mode0 = row;
		}

		if( fact_mode1 != col ) // vfd chattering debug
		{
			VFDPrintf( ( char * )menu_table[ row ][ col ] );
			fact_mode1 = col;		
		}		
		
	}
	
}

void buzz( Uint16 hz , Uint16 time )
{
	int i;

	for( i = 0 ; i < time ; i++ )
	{
		DELAY_US( hz );
		GpioDataRegs.GPASET.bit.GPIO17 = ON;
		DELAY_US( hz );
		GpioDataRegs.GPACLEAR.bit.GPIO17 = ON;		
	}

}

void vh_delay( void )
{
	SWR_BELL;
	SWU_BELL;
	SWLU_BELL;
	DELAY_US( 100000 );			
}


