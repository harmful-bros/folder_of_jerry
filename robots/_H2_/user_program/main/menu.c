//###########################################################################
//
// FILE		: menu.c
//
// TITLE		: micromouse H2 menu source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2011.10.01 $
//###########################################################################


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

typedef enum menu_control
{
	ONE = 1 , 

	RALLY_POINT_END = 2
		
}menu_ctrl_e;

typedef volatile struct function_control
{
	menu_ctrl_e num;
	int ( *pvel_ctr )( menu_ctrl_e , volatile int32 * );
	volatile int32 *p_val;
	
}func_ctrl_t;


void ( *pselect_menu[ ROW ][ COL ] )( void );

const char menu_table[ ROW ][ COL ][ VFD_LIST ] = 
{
	"sch?" , " 800" , "1000" , "1200" , " 1-5" , 
	"fst?" , "sst?" , "t_t?" , "s_t?" , " 2-5" , 
	"init" , "val?" , "r_p?" , "pos?" , "gyro" 
};

static void _rom_init( void );

static int plus( menu_ctrl_e num , volatile int32 *p_val );
static int minus( menu_ctrl_e num, volatile int32 *p_val );


static func_ctrl_t rally_point_plus[ RALLY_POINT_END ] = 
{
		{	ONE 		, 	plus 		, 	&g_int32straight_acc	} ,
		{	ONE 		, 	plus 		, 	&g_int32diag_acc		}			
};


static func_ctrl_t rally_point_minus[ RALLY_POINT_END ] = 
{
		{	ONE 		, 	minus 		, 	&g_int32straight_acc	} ,
		{	ONE 		, 	minus 		, 	&g_int32diag_acc		}			
};

static int plus( menu_ctrl_e num , volatile int32 *p_val ) //변수 증가
{
	if( p_val == NULL )
	{
		vfdprintf("NULL");
		DELAY_US( 100000 );

		return -1;
	}

	( *p_val ) += num;
	if( ( *p_val ) > 10 )	( *p_val ) = 10;

	vfdprintf("E@%2u" , ( Uint16 )( *p_val ) );
	DELAY_US( 30000 );

	return 0;
}

static int minus( menu_ctrl_e num, volatile int32 *p_val ) //변수 감소
{
	if( p_val == NULL )
	{
		vfdprintf("NULL");
		DELAY_US( 100000 );

		return -1;
	}

	( *p_val ) -= num;
	if( ( *p_val ) < 0 )	( *p_val ) = 0;

	vfdprintf("E@%2u" , ( Uint16 )( *p_val ) );
	DELAY_US( 30000 );

	return 0;
}

void menu_func_init( void )
{
	pselect_menu[ 0 ][ 0 ] = search_run_mode;
	pselect_menu[ 0 ][ 1 ] = fastrun_800velocity_mode;
	pselect_menu[ 0 ][ 2 ] = fastrun_1000velocity_mode;
	pselect_menu[ 0 ][ 3 ] = fastrun_1200velocity_mode;	
	pselect_menu[ 0 ][ 4 ] = NULL;

	pselect_menu[ 1 ][ 0 ] = front_sensor_setting;
	pselect_menu[ 1 ][ 1 ] = side_and_45diag_sensor_setting;
	pselect_menu[ 1 ][ 2 ] = smoothturn_test_func;
	pselect_menu[ 1 ][ 3 ] = straight_run_test_func;	
	pselect_menu[ 1 ][ 4 ] = NULL;

	pselect_menu[ 2 ][ 0 ] = _rom_init;
	pselect_menu[ 2 ][ 1 ] = sensor_value_view;
	pselect_menu[ 2 ][ 2 ] = real_position_value_view;
	pselect_menu[ 2 ][ 3 ] = sensor_position_view;	
	pselect_menu[ 2 ][ 4 ] = gyro_value_view;
	
}

static void _rom_init( void )
{
	g_int32turn_vel = SEARCH_S;
	g_int32turn_acc = 5;

	g_int32straight_acc = 4;
	g_int32diag_acc = 4;
	
	turn_vari_write_rom();
	fastrun_vari_write_rom();

	vfdprintf("-ok-");
	DELAY_US( 200000 );
}

void run_acc_select_func( void )
{
	func_ctrl_t *pctrl;
	const char *type[] = { "s_a?" , "d_a?" };	

	sw_t sw;
	memset( ( void * )&sw , 0x00 , sizeof( sw_t ) );

	vfdprintf( ( char * )type[ 0 ] );

	while( TRUE )
	{		
		if( !UP_SW ) 
		{
			pctrl = &rally_point_plus[ sw.int32col ];
			pctrl->pvel_ctr( pctrl->num , pctrl->p_val );
		}
		else if( !DOWN_SW )
		{
			pctrl = &rally_point_minus[ sw.int32col ];
			pctrl->pvel_ctr( pctrl->num , pctrl->p_val );
		}
		else if( !LEFT_SW && sw.u16left == OFF )
		{
			YELLOW_ON;

			sw.u16left = ON;
			g_int32menu_cnt = ZERO;
		}		
		else if( !RIGHT_SW && sw.u16right == OFF )
		{
			YELLOW_ON;
					
			sw.u16right = ON;
			g_int32menu_cnt = ZERO;
		}
		else if( sw.u16long_rkey == OFF && sw.u16right == ON && g_int32menu_cnt > LONG_KEY_CAHTTERING )
		{
			fastrun_vari_write_rom(); //변수 save 후 탈출.			
			break;
		}
		else if( LEFT_SW && RIGHT_SW )
		{
			if( sw.u16left == ON && g_int32menu_cnt > KEY_CHATTERING )
			{
				SWR_BELL;
				sw.u16left = OFF;
		
				sw.int32col--;
				if( sw.int32col < 0 )	sw.int32col = RALLY_POINT_END - 1;
			}
			else if( sw.u16right == ON && g_int32menu_cnt > KEY_CHATTERING )
			{
				SWR_BELL;
				sw.u16right = OFF;
		
				sw.int32col++;
				if( sw.int32col >= RALLY_POINT_END )	sw.int32col = ZERO;
			}
			else
			{
				LED_OFF;
				sw.u16left = sw.u16right = OFF;
			}		
			
		}
		else;
		
		if( sw.int32vfd_chatt_col != sw.int32col )
		{
			vfdprintf( ( char * )type[ sw.int32col ] );
			sw.int32vfd_chatt_col = sw.int32col;			
		}
		
	}	

	LED_OFF;
	h2_delay();

}

void menu_select_func( void )
{
	sw_t sw;
	memset( ( void * )&sw , 0x00 , sizeof( sw_t ) );

	LED_OFF;	
	vfdprintf( ( char * )menu_table[ 0 ][ 0 ] );	
	
	while( TRUE )
	{
		batt_volt_comform_func( &sw );
	
		if( !UP_SW && sw.u16up == OFF )	
		{
			GREEN_ON;
		
			sw.u16up = ON;
			g_int32menu_cnt = ZERO;
		}
		else if( !RIGHT_SW && sw.u16right == OFF )
		{
			YELLOW_ON;
					
			sw.u16right = ON;
			g_int32menu_cnt = ZERO;
		}
		else if( sw.u16long_rkey == OFF && sw.u16up == ON && g_int32menu_cnt > LONG_KEY_CAHTTERING )
		{
			h2_delay();
			sw.u16long_rkey = ON;
		}
		else if( UP_SW && RIGHT_SW )
		{
			if( sw.u16long_rkey )
			{
				sw.u16up = sw.u16right = sw.u16long_rkey = OFF;

				if( *pselect_menu[ sw.int32row ][ sw.int32col ] == NULL )
					vfdprintf("-NC-");
				else
				{
					pselect_menu[ sw.int32row ][ sw.int32col ]();
					
					sw.int32row = sw.int32col = 0;
					vfdprintf( ( char * )menu_table[ 0 ][ 0 ] );
				}				
			}
			else if( sw.u16up == ON && g_int32menu_cnt > KEY_CHATTERING )
			{
				SWU_BELL;
				sw.u16up = OFF;

				sw.int32row++;
				if( sw.int32row >= ROW )	sw.int32row = ZERO;
			}
			else if( sw.u16right == ON && g_int32menu_cnt > KEY_CHATTERING )
			{
				SWR_BELL;
				sw.u16right = OFF;

				sw.int32col++;
				if( sw.int32col >= COL )	sw.int32col = ZERO;
			}
			else
			{
				LED_OFF;
				sw.u16up = sw.u16right = OFF;
			}		
			
		}
		else;

		if( sw.int32vfd_chatt_row != sw.int32row || sw.int32vfd_chatt_col != sw.int32col )
		{
			vfdprintf( ( char * )menu_table[ sw.int32row ][ sw.int32col ] );
			
			sw.int32vfd_chatt_row = sw.int32row;
			sw.int32vfd_chatt_col = sw.int32col;			
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

void h2_delay( void )
{
	SWR_BELL;
	SWU_BELL;
	SWLU_BELL;
	DELAY_US( 100000 );			
}


