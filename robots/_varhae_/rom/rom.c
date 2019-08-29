//###########################################################################
//
// FILE		: rom.c
//
// TITLE		: _varhae_ Tracer rom source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.10.31 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

typedef enum //롬 페이지
{
	_SEN_BLOCK_STEP = 67 , 
	_BLOCK_SETP = 256,

	_SENSOR_CONTROL = 1 ,
	
	_GONE_DIST_CONTROL_1 ,
	_GONE_DIST_CONTROL_2 ,
	
	_ANGLE_LIST_CONTROL_1 ,
	_ANGLE_LIST_CONTROL_2 ,

	_DIRECTION_CONTROL_1,
	_DIRECTION_CONTROL_2,

	_ETC_CONTROL ,
	
	_VELOCITY_CONTROL ,
	_ACCEL_CONTROL ,

	_MARK_DIR_CONTROL_1 , 
	_MARK_DIR_CONTROL_2 , 

	_RIGHT_DIST_CONTROL_1 , 
	_RIGHT_DIST_CONTROL_2 , 

	_LEFT_DIST_CONTROL_1 , 
	_LEFT_DIST_CONTROL_2

}rom_e;

volatile int32 diff_mark_cnt;
volatile int32 diff_mark_buf[ _BLOCK_SETP ];

void mark_direction_diff_func( sec_info_t *p_info , volatile int32 mark_buf[] , volatile int32 cnt )  //gyro와 mark 방향이 다른 경우 -> 확인 메뉴...
{
	int32 row = 0;
	int32 sw_left = OFF , sw_right = OFF;
	int32 menu_mode_select = OFF , vfd_mode = 0;

	volatile int32 *buf = mark_buf;
	sec_info_t *pinfo = p_info;

	LED_OFF;

	VFDPrintf("diff %3ld" , cnt);
	DELAY_US( 500000 );	
	VFDPrintf("%2ld%2ldm%sg%c" , row + 1 , buf[ 0 ] , ( pinfo + buf[ 0 ] )->pchmk_dir , ( pinfo + buf[ 0 ] )->pchdir[ 0 ] );

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
			VFDPrintf("Run_Time");
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
				if( row > cnt - 1 )	row = 0;
			}
			else if( ( !menu_mode_select ) && ( sw_left ) && ( g_int32menu_count > KEY_CHATTERING ) ) 
			{	
				SWSU_BELL;			
				sw_left = OFF;

				row--;
				if( row < 0 )		row = cnt - 1;
			}			
			else if( menu_mode_select )  //escape
			{
				LED_OFF;
				VFDPrintf("        ");
				
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
			VFDPrintf("%2ld%2ldm%sg%c" , row + 1 , buf[ row ] , ( pinfo + buf[ row ] )->pchmk_dir , ( pinfo + buf[ row ] )->pchdir[ 0 ] );
			vfd_mode = row;
		}		
	
	}	


}

void curvature_redetection( sec_info_t *p_info , int32 mark )  //곡률 재 검출
{
	int32 i;
	int32 mark_cnt = mark;
	sec_info_t *pinfo = p_info;

	diff_mark_cnt = 0;
	memset( ( void * )diff_mark_buf , 0x00 , sizeof( diff_mark_buf ) );

#ifdef DEBUG_MODE
	SCIa_Printf("\n\n\n");
#endif

	for( i = 0 ; i < mark_cnt ; i++ )  //총 마크 갯수만큼
	{		
		turn_sort_division( pinfo + i , i );
	
		switch( ( pinfo + i )->int32dir )
		{
			case STRAIGHT :					( pinfo + i )->pchdir = "STRA";		break;			
			case LEFT_TURN :				( pinfo + i )->pchdir = "LTUR";		break;
			case RIGHT_TURN :				( pinfo + i )->pchdir = "RTUR";		break;
				
			case LEFT_TURN | TURN_45 :		( pinfo + i )->pchdir = "L 45";		break;
			case LEFT_TURN | TURN_90 :		( pinfo + i )->pchdir = "L 90";		break;
			case LEFT_TURN | TURN_180 :		( pinfo + i )->pchdir = "L180";		break;
			case LEFT_TURN | TURN_270 :		( pinfo + i )->pchdir = "L270";		break;
			case LEFT_TURN | LARGE_TURN :	( pinfo + i )->pchdir = "LLAR";		break;

			case RIGHT_TURN | TURN_45 :		( pinfo + i )->pchdir = "R 45";		break;
			case RIGHT_TURN | TURN_90 :		( pinfo + i )->pchdir = "R 90";		break;
			case RIGHT_TURN | TURN_180 :	( pinfo + i )->pchdir = "R180";		break;
			case RIGHT_TURN | TURN_270 :	( pinfo + i )->pchdir = "R270";		break;
			case RIGHT_TURN | LARGE_TURN :	( pinfo + i )->pchdir = "RLAR";		break;

			case DIR_END | STRAIGHT :		( pinfo + i )->pchdir = "END ";		break;					

			default :															break;
		}

		switch( ( pinfo + i )->int32mk_dir )
		{
			case STRAIGHT :					( pinfo + i )->pchmk_dir = "S";		break;
			case LEFT_TURN :				( pinfo + i )->pchmk_dir = "L";		break;
			case RIGHT_TURN :				( pinfo + i )->pchmk_dir = "R";		break;
			case DIR_END :					( pinfo + i )->pchmk_dir = "E";		break;			

			default :															break;
		}

		if( g_int32mark_gyro_toggle == ON && ( ( pinfo + i )->pchmk_dir[ 0 ] != ( pinfo + i )->pchdir[ 0 ] ) )  //gyro와 마크 방향이 다른 경우...
		{
			diff_mark_buf[ diff_mark_cnt ] = i;
			diff_mark_cnt++;
		}
		
	}

	if( diff_mark_cnt )
		mark_direction_diff_func( g_secinfo , diff_mark_buf , diff_mark_cnt );
	
}

void sensor_write_rom( void ) //sensor setting value save
{
	int32 j;
	Uint16 write_buf[ _SEN_BLOCK_STEP ] = { 0 , };

	j = 0;

/////////////////////////// max  sensor value saved ///////////////////////////

	write_buf[ j++ ] = ( g_sen[ 0 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 0 ].u16max_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 1 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 1 ].u16max_value >> 8 ) & 0xff;

	write_buf[ j++ ] = ( g_sen[ 2 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 2 ].u16max_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 3 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 3 ].u16max_value >> 8 ) & 0xff;

	write_buf[ j++ ] = ( g_sen[ 4 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 4 ].u16max_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 5 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 5 ].u16max_value >> 8 ) & 0xff;

	write_buf[ j++ ] = ( g_sen[ 6 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 6 ].u16max_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 7 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 7 ].u16max_value >> 8 ) & 0xff;		

	write_buf[ j++ ] = ( g_sen[ 8 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 8 ].u16max_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 9 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 9 ].u16max_value >> 8 ) & 0xff;

	write_buf[ j++ ] = ( g_sen[ 10 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 10 ].u16max_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 11 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 11 ].u16max_value >> 8 ) & 0xff;

	write_buf[ j++ ] = ( g_sen[ 12 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 12 ].u16max_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 13 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 13 ].u16max_value >> 8 ) & 0xff;

	write_buf[ j++ ] = ( g_sen[ 14 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 14 ].u16max_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 15 ].u16max_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 15 ].u16max_value >> 8 ) & 0xff;				

/////////////////////////// min  sensor value saved ///////////////////////////		
		
	write_buf[ j++ ] = ( g_sen[ 0 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 0 ].u16min_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 1 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 1 ].u16min_value >> 8 ) & 0xff;

	write_buf[ j++ ] = ( g_sen[ 2 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 2 ].u16min_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 3 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 3 ].u16min_value >> 8 ) & 0xff;

	write_buf[ j++ ] = ( g_sen[ 4 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 4 ].u16min_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 5 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 5 ].u16min_value >> 8 ) & 0xff;

	write_buf[ j++ ] = ( g_sen[ 6 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 6 ].u16min_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 7 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 7 ].u16min_value >> 8 ) & 0xff;		

	write_buf[ j++ ] = ( g_sen[ 8 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 8 ].u16min_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 9 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 9 ].u16min_value >> 8 ) & 0xff;

	write_buf[ j++ ] = ( g_sen[ 10 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 10 ].u16min_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 11 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 11 ].u16min_value >> 8 ) & 0xff;

	write_buf[ j++ ] = ( g_sen[ 12 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 12 ].u16min_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 13 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 13 ].u16min_value >> 8 ) & 0xff;

	write_buf[ j++ ] = ( g_sen[ 14 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 14 ].u16min_value >> 8 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 15 ].u16min_value >> 0 ) & 0xff;
	write_buf[ j++ ] = ( g_sen[ 15 ].u16min_value >> 8 ) & 0xff;				

	// gyro center value.
	write_buf[ j++ ] = ( ( Uint16 )( g_gyro.fp32center ) >> 0 ) & 0xff;
	write_buf[ j++ ] = ( ( Uint16 )( g_gyro.fp32center ) >> 8 ) & 0xff;
		
	SpiSaveRom( ( Uint16 )( _SENSOR_CONTROL ) , 0 , ( Uint16 )( _SEN_BLOCK_STEP ) , write_buf );

}

void sensor_load_rom( void ) //sensor setting value load
{
	int32 j;
	Uint16 read_buf[ _SEN_BLOCK_STEP ] = { 0 , };
	Uint16 gyro_center = 0;

	j = 0;
	SpiLoadRom( ( Uint16 )( _SENSOR_CONTROL ) , 0 , ( Uint16 )( _SEN_BLOCK_STEP ) , read_buf );

/////////////////////////// max  sensor value load ///////////////////////////

	g_sen[ 0 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 0 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 1 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 1 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 2 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 2 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 3 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 3 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 4 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 4 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 5 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 5 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 6 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 6 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 7 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 7 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 8 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 8 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 9 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 9 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 10 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 10 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 11 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 11 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 12 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 12 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 13 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 13 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 14 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 14 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 15 ].u16max_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 15 ].u16max_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

/////////////////////////// min  sensor value load ///////////////////////////		
		
	g_sen[ 0 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 0 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 1 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 1 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 2 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 2 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 3 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 3 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 4 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 4 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 5 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 5 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 6 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 6 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 7 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 7 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 8 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 8 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 9 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 9 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 10 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 10 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 11 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 11 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 12 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 12 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 13 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 13 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	g_sen[ 14 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 14 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );
	g_sen[ 15 ].u16min_value = ( ( read_buf[ j++ ] & 0xff ) << 0 );
	g_sen[ 15 ].u16min_value |= ( ( read_buf[ j++ ] & 0xff ) << 8 );

	gyro_center = ( read_buf[ j++ ] & 0xff ) << 0;
	gyro_center |= ( read_buf[ j++ ] & 0xff ) << 8;

	g_gyro.fp32center = ( float32 )gyro_center;

	SCIa_Printf("\n-------------------------- gyro center value -------------------------------\n\n");
	SCIa_Printf("gyro center value : %10lf\n\n" , g_gyro.fp32center);
		
#ifdef DEBUG_MODE
	sensor_printf_func( g_sen ); //printf
#endif

}

void velocity_save_rom( void ) //velocity variable save
{
	int32 i = 0;
	Uint16 vel_wbuf[ _BLOCK_SETP ] = { 0 , };

	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32turn_vel ) ) >> 0 ) & 0xff;
	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32turn_vel ) ) >> 8 ) & 0xff;

	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32max_speed ) ) >> 0 ) & 0xff;
	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32max_speed ) ) >> 8 ) & 0xff;

	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32large_vel ) ) >> 0 ) & 0xff;
	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32large_vel ) ) >> 8 ) & 0xff;

	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32shift_level ) ) >> 0 ) & 0xff;
	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32shift_level ) ) >> 8 ) & 0xff;

	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32decel_dist_scope ) ) >> 0 ) & 0xff;
	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32decel_dist_scope ) ) >> 8 ) & 0xff;

	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int3245A_vel ) ) >> 0 ) & 0xff;
	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int3245A_vel ) ) >> 8 ) & 0xff;

	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32s44s_vel ) ) >> 0 ) & 0xff;
	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32s44s_vel ) ) >> 8 ) & 0xff;	

	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32escape45_vel ) ) >> 0 ) & 0xff;
	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32escape45_vel ) ) >> 8 ) & 0xff;
	
	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32limit_vel ) ) >> 0 ) & 0xff;
	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32limit_vel ) ) >> 8 ) & 0xff;

	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32s4s_vel ) ) >> 0 ) & 0xff;
	vel_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32s4s_vel ) ) >> 8 ) & 0xff;	

	SpiSaveRom( ( Uint16 )( _VELOCITY_CONTROL ) , 0x00 ,  ( Uint16 )( _BLOCK_SETP ) , vel_wbuf );
	
}

void velocity_load_rom( void ) //velocity variable load
{
	int32 i = 0;
	Uint16 vel_lbuf[ _BLOCK_SETP ] = { 0 , };

	SpiLoadRom( ( Uint16 )( _VELOCITY_CONTROL ) , 0x00 ,  ( Uint16 )( _BLOCK_SETP ) , vel_lbuf );

	g_int32turn_vel = ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32turn_vel |= ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 8 );

	g_int32max_speed = ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32max_speed |= ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 8 );	

	g_int32large_vel = ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32large_vel |= ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 8 );		

	g_int32shift_level = ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32shift_level |= ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 8 );			

	g_int32decel_dist_scope = ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32decel_dist_scope |= ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 8 );

	g_int3245A_vel = ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 0 );
	g_int3245A_vel |= ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 8 );

	g_int32s44s_vel = ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32s44s_vel |= ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 8 );	

	g_int32escape45_vel = ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32escape45_vel |= ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 8 );

	g_int32limit_vel = ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32limit_vel |= ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 8 );	

	g_int32s4s_vel = ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32s4s_vel |= ( int32 )( ( vel_lbuf[ i++ ] & 0xff ) << 8 );		

}

void accel_save_rom( void ) //accelation variable save
{
	int32 i = 0;
	Uint16 acc_wbuf[ _BLOCK_SETP ] = { 0 , };

	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32turn_acc ) ) >> 0 ) & 0xff;
	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32turn_acc ) ) >> 8 ) & 0xff;

	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32max_acc ) ) >> 0 ) & 0xff;
	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32max_acc ) ) >> 8 ) & 0xff;

	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32end_acc ) ) >> 0 ) & 0xff;
	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32end_acc ) ) >> 8 ) & 0xff;
	
	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32mid_acc ) ) >> 0 ) & 0xff;
	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32mid_acc ) ) >> 8 ) & 0xff;

	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32short_acc ) ) >> 0 ) & 0xff;
	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32short_acc ) ) >> 8 ) & 0xff;

	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32large_acc ) ) >> 0 ) & 0xff;
	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32large_acc ) ) >> 8 ) & 0xff;

	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int3245A_acc ) ) >> 0 ) & 0xff;
	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int3245A_acc ) ) >> 8 ) & 0xff;	

	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32large_turn_flag ) ) >> 0 ) & 0xff;
	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32large_turn_flag ) ) >> 8 ) & 0xff;		

	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32end_dist ) ) >> 0 ) & 0xff;
	acc_wbuf[ i++ ] = ( ( ( Uint16 )( g_int32end_dist ) ) >> 8 ) & 0xff;			

	SpiSaveRom( ( Uint16 )( _ACCEL_CONTROL ) , 0x00 ,  ( Uint16 )( _BLOCK_SETP ) , acc_wbuf );	
	
}

void accel_load_rom( void ) //accelation variable load
{
	int32 i = 0;
	Uint16 acc_lbuf[ _BLOCK_SETP ] = { 0 , };

	SpiLoadRom( ( Uint16 )( _ACCEL_CONTROL ) , 0x00 ,  ( Uint16 )( _BLOCK_SETP ) , acc_lbuf );
	
	g_int32turn_acc = ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32turn_acc |= ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 8 );

	g_int32max_acc = ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32max_acc |= ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 8 );	

	g_int32end_acc = ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32end_acc |= ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 8 );		

	g_int32mid_acc = ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32mid_acc |= ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 8 );		

	g_int32short_acc = ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32short_acc |= ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 8 );			

	g_int32large_acc = ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32large_acc |= ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 8 );

	g_int3245A_acc = ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 0 );
	g_int3245A_acc |= ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 8 );	

	g_int32large_turn_flag = ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32large_turn_flag |= ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 8 );		

	g_int32end_dist = ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 0 );
	g_int32end_dist |= ( int32 )( ( acc_lbuf[ i++ ] & 0xff ) << 8 );			
	
}

static void etc_vari_save_rom( void )
{
	int j;
	Uint16 etc_buf[ _BLOCK_SETP ] = { 0 , };		

	j = 0;
	etc_buf[ j++ ] = ( ( Uint16 )( g_int32mark_cnt ) >> 0 ) & 0xff;
	etc_buf[ j++ ] = ( ( Uint16 )( g_int32mark_cnt ) >> 8 ) & 0xff;

	etc_buf[ j++ ] = ( ( Uint16 )( g_int32start_dist ) >> 0 ) & 0xff;
	etc_buf[ j++ ] = ( ( Uint16 )( g_int32start_dist ) >> 8 ) & 0xff;

	etc_buf[ j++ ] = ( ( Uint16 )( g_int32force_mark ) >> 0 ) & 0xff;
	etc_buf[ j++ ] = ( ( Uint16 )( g_int32force_mark ) >> 8 ) & 0xff;

	SpiSaveRom( ( Uint16 )( _ETC_CONTROL ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , etc_buf );	
	
}

static void etc_vari_load_rom( void )
{
	int j;
	Uint16 etc_buf[ _BLOCK_SETP ] = { 0 , };

	j = 0;
	SpiLoadRom( ( Uint16 )( _ETC_CONTROL ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , etc_buf );
	
	g_int32total_mark = ( int32 )( ( etc_buf[ j++ ] & 0xff ) << 0 );
	g_int32total_mark |= ( int32 )( ( etc_buf[ j++ ] & 0xff ) << 8 );

	g_int32start_dist = ( int32 )( ( etc_buf[ j++ ] & 0xff ) << 0 );
	g_int32start_dist |= ( int32 )( ( etc_buf[ j++ ] & 0xff ) << 8 );	

	g_int32force_mark = ( int32 )( ( etc_buf[ j++ ] & 0xff ) << 0 );
	g_int32force_mark |= ( int32 )( ( etc_buf[ j++ ] & 0xff ) << 8 );		
	
}

void line_save_rom( void ) //line information save
{
	int32 i , j , k , l , m , n , o;
	
	Uint16 dist_buf[ _BLOCK_SETP ] = { 0 , };
	Uint16 angle_buf[ _BLOCK_SETP ] = { 0 , };
	Uint16 dir_buf[ _BLOCK_SETP ] = { 0 , };
	Uint16 mark_buf[ _BLOCK_SETP ] = { 0 , };
	Uint16 left_buf[ _BLOCK_SETP ] = { 0 , };
	Uint16 right_buf[ _BLOCK_SETP ] = { 0 , };

	j = k = l = m = n = o = 0;
	for( i = 0 ; i < 128 ; i++ )
	{
		dist_buf[ j++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32dist ) ) >> 0 ) & 0xff;
		dist_buf[ j++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32dist ) ) >> 8 ) & 0xff;

		angle_buf[ k++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32angle ) ) >> 0 ) & 0xff;
		angle_buf[ k++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32angle ) ) >> 8 ) & 0xff;		

		dir_buf[ l++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32dir ) ) >> 0 ) & 0xff;
		dir_buf[ l++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32dir ) ) >> 8 ) & 0xff;	

		mark_buf[ m++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32mk_dir ) ) >> 0 ) & 0xff;
		mark_buf[ m++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32mk_dir ) ) >> 8 ) & 0xff;			

		left_buf[ n++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32l_dist ) ) >> 0 ) & 0xff;
		left_buf[ n++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32l_dist ) ) >> 8 ) & 0xff;			

		right_buf[ o++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32r_dist ) ) >> 0 ) & 0xff;
		right_buf[ o++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32r_dist ) ) >> 8 ) & 0xff;					
	}
	SpiSaveRom( ( Uint16 )( _GONE_DIST_CONTROL_1 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , dist_buf );
	SpiSaveRom( ( Uint16 )( _ANGLE_LIST_CONTROL_1 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , angle_buf );
	SpiSaveRom( ( Uint16 )( _DIRECTION_CONTROL_1 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , dir_buf );
	SpiSaveRom( ( Uint16 )( _MARK_DIR_CONTROL_1 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , mark_buf );
	SpiSaveRom( ( Uint16 )( _LEFT_DIST_CONTROL_1 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , left_buf );
	SpiSaveRom( ( Uint16 )( _RIGHT_DIST_CONTROL_1 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , right_buf );	
	
	j = k = l = m = n = o = 0;
	for( i = 128 ; i < 256 ; i++ )
	{
		dist_buf[ j++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32dist ) ) >> 0 ) & 0xff;
		dist_buf[ j++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32dist ) ) >> 8 ) & 0xff;

		angle_buf[ k++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32angle ) ) >> 0 ) & 0xff;
		angle_buf[ k++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32angle ) ) >> 8 ) & 0xff;		
		
		dir_buf[ l++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32dir ) ) >> 0 ) & 0xff;
		dir_buf[ l++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32dir ) ) >> 8 ) & 0xff;				

		mark_buf[ m++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32mk_dir ) ) >> 0 ) & 0xff;
		mark_buf[ m++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32mk_dir ) ) >> 8 ) & 0xff;			

		left_buf[ n++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32l_dist ) ) >> 0 ) & 0xff;
		left_buf[ n++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32l_dist ) ) >> 8 ) & 0xff;			

		right_buf[ o++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32r_dist ) ) >> 0 ) & 0xff;
		right_buf[ o++ ] = ( ( ( Uint16 )( g_secinfo[ i ].int32r_dist ) ) >> 8 ) & 0xff;		
	}	
	SpiSaveRom( ( Uint16 )( _GONE_DIST_CONTROL_2 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , dist_buf );
	SpiSaveRom( ( Uint16 )( _ANGLE_LIST_CONTROL_2 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , angle_buf );	
	SpiSaveRom( ( Uint16 )( _DIRECTION_CONTROL_2 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , dir_buf );	
	SpiSaveRom( ( Uint16 )( _MARK_DIR_CONTROL_2 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , mark_buf );
	SpiSaveRom( ( Uint16 )( _LEFT_DIST_CONTROL_2 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , left_buf );
	SpiSaveRom( ( Uint16 )( _RIGHT_DIST_CONTROL_2 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , right_buf );	

	etc_vari_save_rom();

}

void line_load_rom( void ) //line information load
{
	int32 i , j , k , l , m , n , o;

	Uint16 dist_buf[ _BLOCK_SETP ] = { 0 , };
	Uint16 angle_buf[ _BLOCK_SETP ] = { 0 , };
	Uint16 dir_buf[ _BLOCK_SETP ] = { 0 , };
	Uint16 mark_buf[ _BLOCK_SETP ] = { 0 , };
	Uint16 left_buf[ _BLOCK_SETP ] = { 0 , };
	Uint16 right_buf[ _BLOCK_SETP ] = { 0 , };

	j = k = l = m = n = o = 0;
	SpiLoadRom( ( Uint16 )( _GONE_DIST_CONTROL_1 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , dist_buf );
	SpiLoadRom( ( Uint16 )( _ANGLE_LIST_CONTROL_1 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , angle_buf );	
	SpiLoadRom( ( Uint16 )( _DIRECTION_CONTROL_1 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , dir_buf );
	SpiLoadRom( ( Uint16 )( _MARK_DIR_CONTROL_1 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , mark_buf );	
	SpiLoadRom( ( Uint16 )( _LEFT_DIST_CONTROL_1 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , left_buf );	
	SpiLoadRom( ( Uint16 )( _RIGHT_DIST_CONTROL_1 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , right_buf );		
	for( i = 0 ; i < 128 ; i++ )
	{
		g_secinfo[ i ].int32dist = ( int32 )( ( dist_buf[ j++ ] & 0xff ) << 0 );
		g_secinfo[ i ].int32dist |= ( int32 )( ( dist_buf[ j++ ] & 0xff ) << 8 );		

		g_secinfo[ i ].int32angle = ( int32 )( ( angle_buf[ k++ ] & 0xff ) << 0 );
		g_secinfo[ i ].int32angle |= ( int32 )( ( angle_buf[ k++ ] & 0xff ) << 8 );				
		
		g_secinfo[ i ].int32dir = ( int32 )( ( dir_buf[ l++ ] & 0xff ) << 0 );
		g_secinfo[ i ].int32dir |= ( int32 )( ( dir_buf[ l++ ] & 0xff ) << 8 );

		g_secinfo[ i ].int32mk_dir = ( int32 )( ( mark_buf[ m++ ] & 0xff ) << 0 );
		g_secinfo[ i ].int32mk_dir |= ( int32 )( ( mark_buf[ m++ ] & 0xff ) << 8 );	

		g_secinfo[ i ].int32l_dist = ( int32 )( ( left_buf[ n++ ] & 0xff ) << 0 );
		g_secinfo[ i ].int32l_dist |= ( int32 )( ( left_buf[ n++ ] & 0xff ) << 8 );	

		g_secinfo[ i ].int32r_dist = ( int32 )( ( right_buf[ o++ ] & 0xff ) << 0 );
		g_secinfo[ i ].int32r_dist |= ( int32 )( ( right_buf[ o++ ] & 0xff ) << 8 );			

		g_secinfo[ i ].int32mark = i;
		g_secinfo[ i ].int32abs = abs( g_secinfo[ i ].int32l_dist - g_secinfo[ i ].int32r_dist );
		
	}

	j = k = l = m = n = o = 0;
	SpiLoadRom( ( Uint16 )( _GONE_DIST_CONTROL_2 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , dist_buf );
	SpiLoadRom( ( Uint16 )( _ANGLE_LIST_CONTROL_2 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , angle_buf );	
	SpiLoadRom( ( Uint16 )( _DIRECTION_CONTROL_2 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , dir_buf );	
	SpiLoadRom( ( Uint16 )( _MARK_DIR_CONTROL_2 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , mark_buf );	
	SpiLoadRom( ( Uint16 )( _LEFT_DIST_CONTROL_2 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , left_buf );	
	SpiLoadRom( ( Uint16 )( _RIGHT_DIST_CONTROL_2 ) , 0x00 , ( Uint16 )( _BLOCK_SETP ) , right_buf );			
	for( i = 128 ; i < 256 ; i++ )
	{
		g_secinfo[ i ].int32dist = ( int32 )( ( dist_buf[ j++ ] & 0xff ) << 0 );
		g_secinfo[ i ].int32dist |= ( int32 )( ( dist_buf[ j++ ] & 0xff ) << 8 );		

		g_secinfo[ i ].int32angle = ( int32 )( ( angle_buf[ k++ ] & 0xff ) << 0 );
		g_secinfo[ i ].int32angle |= ( int32 )( ( angle_buf[ k++ ] & 0xff ) << 8 );				

		g_secinfo[ i ].int32dir = ( int32 )( ( dir_buf[ l++ ] & 0xff ) << 0 );
		g_secinfo[ i ].int32dir |= ( int32 )( ( dir_buf[ l++ ] & 0xff ) << 8 );		

		g_secinfo[ i ].int32mk_dir = ( int32 )( ( mark_buf[ m++ ] & 0xff ) << 0 );
		g_secinfo[ i ].int32mk_dir |= ( int32 )( ( mark_buf[ m++ ] & 0xff ) << 8 );	

		g_secinfo[ i ].int32l_dist = ( int32 )( ( left_buf[ n++ ] & 0xff ) << 0 );
		g_secinfo[ i ].int32l_dist |= ( int32 )( ( left_buf[ n++ ] & 0xff ) << 8 );	

		g_secinfo[ i ].int32r_dist = ( int32 )( ( right_buf[ o++ ] & 0xff ) << 0 );
		g_secinfo[ i ].int32r_dist |= ( int32 )( ( right_buf[ o++ ] & 0xff ) << 8 );			

		g_secinfo[ i ].int32mark = i;
		g_secinfo[ i ].int32abs = abs( g_secinfo[ i ].int32l_dist - g_secinfo[ i ].int32r_dist );
		
	}	

	etc_vari_load_rom();

#ifdef DEBUG_MODE
	SCIa_Printf("\n\n\n-------------------------- variable saved value table -----------------------------------------\n\n");	

	SCIa_Printf("turn velocity : %5ld\n" , g_int32turn_vel);
	SCIa_Printf("max velocity : %5ld\n" , g_int32max_speed);	
	SCIa_Printf("large velocity : %5ld\n" , g_int32large_vel);
	SCIa_Printf("45a velocity : %5ld\n" , g_int3245A_vel);
	SCIa_Printf("s44s velocity : %5ld\n" , g_int32s44s_vel);	

	SCIa_Printf("\n\n");

	SCIa_Printf("turn accelation : %5ld\n" , g_int32turn_acc);	
	SCIa_Printf("max accelation : %5ld\n" , g_int32max_acc);	
	SCIa_Printf("mid accelation : %5ld\n" , g_int32mid_acc);	
	SCIa_Printf("short accelation : %5ld\n" , g_int32short_acc);		
	SCIa_Printf("end accelation : %5ld\n" , g_int32end_acc);		
	SCIa_Printf("large accelation : %5ld\n" , g_int32large_acc);			

	SCIa_Printf("\n\n");

	SCIa_Printf("total mark cnt : %5ld\n" , g_int32total_mark);
	SCIa_Printf("start dist : %5ld\n" , g_int32start_dist);		

#endif


	if( g_Flag.line_info )	g_Flag.line_info = OFF;
	else					curvature_redetection( g_secinfo , g_int32total_mark );

}


