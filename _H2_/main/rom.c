//###########################################################################
//
// FILE		: rom.c
//
// TITLE		: micromouse H2 rom source file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2012.01.16 $
//###########################################################################


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define ROM_DEBUG
#define SENSOR_DECIMAL		( float32 )100000.0

void front_sensor_value_write_rom( void )
{
	int32 i , j;
	Uint16 wbuf[ MAZE_MAX_BLOCK ] = { 0 , };

	for( i = 0 , j = 0 ; j < SENSOR_SECTION ; j++ )
	{
		g_fp32rfs_section[ j ] *= ( SENSOR_DECIMAL );
		g_fp32lfs_section[ j ] *= ( SENSOR_DECIMAL );
	
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32rfs_section[ j ] ) >> 0 ) & 0xff;
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32rfs_section[ j ] ) >> 8 ) & 0xff;
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32rfs_section[ j ] ) >> 16 ) & 0xff;
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32rfs_section[ j ] ) >> 24 ) & 0xff;		

		wbuf[ i++ ] = ( ( Uint32 )( g_fp32lfs_section[ j ] ) >> 0 ) & 0xff;
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32lfs_section[ j ] ) >> 8 ) & 0xff;
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32lfs_section[ j ] ) >> 16 ) & 0xff;
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32lfs_section[ j ] ) >> 24 ) & 0xff;	
	}	

	SpiSaveRom( ( Uint16 )( FRONT_SENSOR_VALUE_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , wbuf );	

	for( i = 0 , j = 0 ; j < SENSOR_SECTION - 1 ; j++ )
	{
		g_fp32rfs_sec_diff[ j ] *= ( SENSOR_DECIMAL );
		g_fp32lfs_sec_diff[ j ] *= ( SENSOR_DECIMAL );
	
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32rfs_sec_diff[ j ] ) >> 0 ) & 0xff;
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32rfs_sec_diff[ j ] ) >> 8 ) & 0xff;
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32rfs_sec_diff[ j ] ) >> 16 ) & 0xff;
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32rfs_sec_diff[ j ] ) >> 24 ) & 0xff;		

		wbuf[ i++ ] = ( ( Uint32 )( g_fp32lfs_sec_diff[ j ] ) >> 0 ) & 0xff;
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32lfs_sec_diff[ j ] ) >> 8 ) & 0xff;
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32lfs_sec_diff[ j ] ) >> 16 ) & 0xff;
		wbuf[ i++ ] = ( ( Uint32 )( g_fp32lfs_sec_diff[ j ] ) >> 24 ) & 0xff;	
	}

	SpiSaveRom( ( Uint16 )( FRONT_SENSOR_DIFF_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , wbuf );		
	
}

void front_sensor_value_read_rom( void )
{
	int32 i , j;
	
	Uint32 real_value = 0;
	Uint16 rbuf[ MAZE_MAX_BLOCK ] = { 0 , };

	SpiLoadRom( ( Uint16 )( FRONT_SENSOR_VALUE_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , rbuf );

	for( i = 0 , j = 0 ; j < SENSOR_SECTION ; j++ )
	{
		real_value  = ( Uint32 )( rbuf[ i++ ] & 0xff ) << 0;
		real_value |= ( Uint32 )( rbuf[ i++ ] & 0xff ) << 8;
		real_value |= ( Uint32 )( rbuf[ i++ ] & 0xff ) << 16;
		real_value |= ( Uint32 )( rbuf[ i++ ] & 0xff ) << 24;		

		g_fp32rfs_section[ j ] = ( float32 )real_value / SENSOR_DECIMAL;

		real_value  = ( Uint32 )( rbuf[ i++ ] & 0xff ) << 0;
		real_value |= ( Uint32 )( rbuf[ i++ ] & 0xff ) << 8;
		real_value |= ( Uint32 )( rbuf[ i++ ] & 0xff ) << 16;
		real_value |= ( Uint32 )( rbuf[ i++ ] & 0xff ) << 24;		

		g_fp32lfs_section[ j ] = ( float32 )real_value / SENSOR_DECIMAL;
	}

	SpiLoadRom( ( Uint16 )( FRONT_SENSOR_DIFF_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , rbuf );	

	for( i = 0 , j = 0 ; j < SENSOR_SECTION - 1 ; j++ )
	{
		real_value  = ( Uint32 )( rbuf[ i++ ] & 0xff ) << 0;
		real_value |= ( Uint32 )( rbuf[ i++ ] & 0xff ) << 8;
		real_value |= ( Uint32 )( rbuf[ i++ ] & 0xff ) << 16;
		real_value |= ( Uint32 )( rbuf[ i++ ] & 0xff ) << 24;		

		g_fp32rfs_sec_diff[ j ] = ( float32 )real_value / SENSOR_DECIMAL;

		real_value  = ( Uint32 )( rbuf[ i++ ] & 0xff ) << 0;
		real_value |= ( Uint32 )( rbuf[ i++ ] & 0xff ) << 8;
		real_value |= ( Uint32 )( rbuf[ i++ ] & 0xff ) << 16;
		real_value |= ( Uint32 )( rbuf[ i++ ] & 0xff ) << 24;		

		g_fp32lfs_sec_diff[ j ] = ( float32 )real_value / SENSOR_DECIMAL;
	}	

#ifdef ROM_DEBUG
	SCIa_Printf("\n\n------- FRONT SENSOR VALUE READ --------\n\n\n");

	for( j = 0 ; j < SENSOR_SECTION ; j++ )
	{
		SCIa_Printf("[ %3.0lf ] rfs : %10lf lfs : %10lf " , ( float32 )j , g_fp32rfs_section[ j ] , g_fp32lfs_section[ j ] );

		if( j != SENSOR_SECTION - 1 )
			SCIa_Printf("r_diff : %10lf l_diff : %10lf\n" , g_fp32rfs_sec_diff[ j ] , g_fp32lfs_sec_diff[ j ] );
		else
			SCIa_Printf("\n");
	}

	SCIa_Printf("\n\n");
#endif	
	
}

void side_and_diag_sensor_value_write_rom( void )
{
	int32 i;
	Uint16 wbuf[ MAZE_MAX_BLOCK ] = { 0 , };

	sen_t *psen[ SIDE_SENSOR_NUM ];

	psen[ 0 ] = g_plss;
	psen[ 1 ] = g_pl45s;
	psen[ 2 ] = g_pr45s;
	psen[ 3 ] = g_prss;	

	for( i = 0 ; i < SIDE_SENSOR_NUM ; i++ )
	{
		psen[ i ]->fp32max_val *= ( SENSOR_DECIMAL );			 //최대값 저장.		

		wbuf[ i * 20 + 0 ] = ( ( Uint32 )( psen[ i ]->fp32max_val ) >> 0 ) & 0xff;
		wbuf[ i * 20 + 1 ] = ( ( Uint32 )( psen[ i ]->fp32max_val ) >> 8 ) & 0xff;
		wbuf[ i * 20 + 2 ] = ( ( Uint32 )( psen[ i ]->fp32max_val ) >> 16 ) & 0xff;
		wbuf[ i * 20 + 3 ] = ( ( Uint32 )( psen[ i ]->fp32max_val ) >> 24 ) & 0xff;

		psen[ i ]->fp32min_val *= ( SENSOR_DECIMAL );			 //최소값 저장.
		
		wbuf[ i * 20 + 4 ] = ( ( Uint32 )( psen[ i ]->fp32min_val ) >> 0 ) & 0xff;
		wbuf[ i * 20 + 5 ] = ( ( Uint32 )( psen[ i ]->fp32min_val ) >> 8 ) & 0xff;
		wbuf[ i * 20 + 6 ] = ( ( Uint32 )( psen[ i ]->fp32min_val ) >> 16 ) & 0xff;
		wbuf[ i * 20 + 7 ] = ( ( Uint32 )( psen[ i ]->fp32min_val ) >> 24 ) & 0xff;				

		psen[ i ]->fp32mid_val *= ( SENSOR_DECIMAL );			 //센터값 저장.
		
		wbuf[ i * 20 + 8 ] = ( ( Uint32 )( psen[ i ]->fp32mid_val ) >> 0 ) & 0xff;
		wbuf[ i * 20 + 9 ] = ( ( Uint32 )( psen[ i ]->fp32mid_val ) >> 8 ) & 0xff;
		wbuf[ i * 20 + 10 ] = ( ( Uint32 )( psen[ i ]->fp32mid_val ) >> 16 ) & 0xff;
		wbuf[ i * 20 + 11 ] = ( ( Uint32 )( psen[ i ]->fp32mid_val ) >> 24 ) & 0xff;				

		psen[ i ]->fp32high_coefficient *= -( SENSOR_DECIMAL );	 //높은 미분 값 저장.
		
		wbuf[ i * 20 + 12 ] = ( ( Uint32 )( psen[ i ]->fp32high_coefficient ) >> 0 ) & 0xff;
		wbuf[ i * 20 + 13 ] = ( ( Uint32 )( psen[ i ]->fp32high_coefficient ) >> 8 ) & 0xff;
		wbuf[ i * 20 + 14 ] = ( ( Uint32 )( psen[ i ]->fp32high_coefficient ) >> 16 ) & 0xff;
		wbuf[ i * 20 + 15 ] = ( ( Uint32 )( psen[ i ]->fp32high_coefficient ) >> 24 ) & 0xff;				

		psen[ i ]->fp32low_coefficient *= -( SENSOR_DECIMAL );	 //낮은 미분 값 저장.
		
		wbuf[ i * 20 + 16 ] = ( ( Uint32 )( psen[ i ]->fp32low_coefficient ) >> 0 ) & 0xff;
		wbuf[ i * 20 + 17 ] = ( ( Uint32 )( psen[ i ]->fp32low_coefficient ) >> 8 ) & 0xff;
		wbuf[ i * 20 + 18 ] = ( ( Uint32 )( psen[ i ]->fp32low_coefficient ) >> 16 ) & 0xff;
		wbuf[ i * 20 + 19 ] = ( ( Uint32 )( psen[ i ]->fp32low_coefficient ) >> 24 ) & 0xff;
		
	}

	SpiSaveRom( ( Uint16 )( SIDE_DIAG_SENSOR_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , wbuf );
	
}

void side_and_diag_sensor_value_read_rom( void )
{
	int32 i;
	
	Uint32 real_value = 0;
	Uint16 rbuf[ MAZE_MAX_BLOCK ] = { 0 , };

	sen_t *psen[ SIDE_SENSOR_NUM ];

	psen[ 0 ] = g_plss;
	psen[ 1 ] = g_pl45s;
	psen[ 2 ] = g_pr45s;
	psen[ 3 ] = g_prss;		

	SpiLoadRom( ( Uint16 )( SIDE_DIAG_SENSOR_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , rbuf );

	for( i = 0 ; i < SIDE_SENSOR_NUM ; i++ )
	{
		real_value  = ( Uint32 )( rbuf[ i * 20 + 0 ] & 0xff ) << 0;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 1 ] & 0xff ) << 8;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 2 ] & 0xff ) << 16;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 3 ] & 0xff ) << 24;

		psen[ i	]->fp32max_val = ( float32 )real_value / SENSOR_DECIMAL;

		real_value  = ( Uint32 )( rbuf[ i * 20 + 4 ] & 0xff ) << 0;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 5 ] & 0xff ) << 8;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 6 ] & 0xff ) << 16;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 7 ] & 0xff ) << 24;

		psen[ i	]->fp32min_val = ( float32 )real_value / SENSOR_DECIMAL;

		real_value  = ( Uint32 )( rbuf[ i * 20 + 8 ] & 0xff ) << 0;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 9 ] & 0xff ) << 8;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 10 ] & 0xff ) << 16;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 11 ] & 0xff ) << 24;

		psen[ i	]->fp32mid_val = ( float32 )real_value / SENSOR_DECIMAL;

		real_value  = ( Uint32 )( rbuf[ i * 20 + 12 ] & 0xff ) << 0;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 13 ] & 0xff ) << 8;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 14 ] & 0xff ) << 16;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 15 ] & 0xff ) << 24;

		psen[ i	]->fp32high_coefficient = ( float32 )real_value / -SENSOR_DECIMAL;

		real_value  = ( Uint32 )( rbuf[ i * 20 + 16 ] & 0xff ) << 0;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 17 ] & 0xff ) << 8;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 18 ] & 0xff ) << 16;
		real_value |= ( Uint32 )( rbuf[ i * 20 + 19 ] & 0xff ) << 24;

		psen[ i	]->fp32low_coefficient = ( float32 )real_value / -SENSOR_DECIMAL;		

	}

#ifdef ROM_DEBUG
	SCIa_Printf("------- SIDE & DIAG SENSOR VALUE READ --------\n\n");

	SCIa_Printf("LSS  => max : %10lf min : %10lf mid : %10lf high : %10lf low : %10lf\n" , psen[ 0 ]->fp32max_val , 
																						   psen[ 0 ]->fp32min_val , 
																						   psen[ 0 ]->fp32mid_val , 
																						   psen[ 0 ]->fp32high_coefficient , 
																						   psen[ 0 ]->fp32low_coefficient );

	SCIa_Printf("LDS => max : %10lf min : %10lf mid : %10lf high : %10lf low : %10lf\n" ,  psen[ 1 ]->fp32max_val , 
					 																	   psen[ 1 ]->fp32min_val , 
																						   psen[ 1 ]->fp32mid_val , 
																						   psen[ 1 ]->fp32high_coefficient , 
																						   psen[ 1 ]->fp32low_coefficient );

	SCIa_Printf("RDS => max : %10lf min : %10lf mid : %10lf high : %10lf low : %10lf\n" ,  psen[ 2 ]->fp32max_val , 
																						   psen[ 2 ]->fp32min_val , 
																						   psen[ 2 ]->fp32mid_val , 
																						   psen[ 2 ]->fp32high_coefficient , 
																						   psen[ 2 ]->fp32low_coefficient );

	SCIa_Printf("RSS  => max : %10lf min : %10lf mid : %10lf high : %10lf low : %10lf\n" , psen[ 3 ]->fp32max_val , 
																						   psen[ 3 ]->fp32min_val , 
																						   psen[ 3 ]->fp32mid_val , 
																						   psen[ 3 ]->fp32high_coefficient , 
																						   psen[ 3 ]->fp32low_coefficient );
#endif

}

void maze_map_write_rom( void )
{
	memcpy( ( void * )g_u16map_backup3 , ( const void * )g_u16map_backup2 , sizeof( g_u16map ) );
	memcpy( ( void * )g_u16map_backup2 , ( const void * )g_u16map_backup1 , sizeof( g_u16map ) );
	memcpy( ( void * )g_u16map_backup1 , ( const void * )g_u16map_backup0 , sizeof( g_u16map ) );
	memcpy( ( void * )g_u16map_backup0 , ( const void * )g_u16map , sizeof( g_u16map ) );

	SpiSaveRom( ( Uint16 )( MAZE_MAP_BACKUP0_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , ( Uint16 * )g_u16map_backup0 );
	SpiSaveRom( ( Uint16 )( MAZE_MAP_BACKUP1_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , ( Uint16 * )g_u16map_backup1 );
	SpiSaveRom( ( Uint16 )( MAZE_MAP_BACKUP2_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , ( Uint16 * )g_u16map_backup2 );
	SpiSaveRom( ( Uint16 )( MAZE_MAP_BACKUP3_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , ( Uint16 * )g_u16map_backup3 );
}

void maze_map_read_rom( int32 idx )
{
	SpiLoadRom( ( Uint16 )( MAZE_MAP_BACKUP0_PAGE + idx ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , ( Uint16 * )g_u16map );
}

void turn_vari_write_rom( void )
{
	int i;
	Uint16 wbuf[ MAZE_MAX_BLOCK ] = { 0 , };

	i = 0;
	wbuf[ i++ ] = ( ( ( Uint16 )g_int32turn_vel ) >> 0 ) & 0xff;
	wbuf[ i++ ] = ( ( ( Uint16 )g_int32turn_vel ) >> 8 ) & 0xff;	

	wbuf[ i++ ] = ( ( ( Uint16 )g_int32turn_acc ) >> 0 ) & 0xff;
	wbuf[ i++ ] = ( ( ( Uint16 )g_int32turn_acc ) >> 8 ) & 0xff;		

	SpiSaveRom( ( Uint16 )( TURN_VARI_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , wbuf );	
}

void turn_vari_read_rom( void )
{
	int i;
	Uint16 rbuf[ MAZE_MAX_BLOCK ] = { 0 , };

	i = 0;
	SpiLoadRom( ( Uint16 )( TURN_VARI_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , rbuf );

	g_int32turn_vel = ( int32 )( ( rbuf[ i++ ] & 0xff ) << 0 );
	g_int32turn_vel |= ( int32 )( ( rbuf[ i++ ] & 0xff ) << 8 );

	g_int32turn_acc = ( int32 )( ( rbuf[ i++ ] & 0xff ) << 0 );
	g_int32turn_acc |= ( int32 )( ( rbuf[ i++ ] & 0xff ) << 8 );	
	
#ifdef ROM_DEBUG
	SCIa_Printf("\n\n----------- TURN VARIABLE VALUE READ ------------\n\n");

	SCIa_Printf("turn vel : %4lu\n" , ( Uint32 )g_int32turn_vel );
	SCIa_Printf("turn acc : %4lu\n" , ( Uint32 )g_int32turn_acc );	
#endif
	
}

void fastrun_vari_write_rom( void )
{
	int i;
	Uint16 wbuf[ MAZE_MAX_BLOCK ] = { 0 , };

	i = 0;
	wbuf[ i++ ] = ( ( ( Uint16 )g_int32straight_acc ) >> 0 ) & 0xff;
	wbuf[ i++ ] = ( ( ( Uint16 )g_int32straight_acc ) >> 8 ) & 0xff;	

	wbuf[ i++ ] = ( ( ( Uint16 )g_int32diag_acc ) >> 0 ) & 0xff;
	wbuf[ i++ ] = ( ( ( Uint16 )g_int32diag_acc ) >> 8 ) & 0xff;		

	SpiSaveRom( ( Uint16 )( FASTRUN_ACC_VARI_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , wbuf );	
}

void fastrun_vari_read_rom( void )
{
	int i;
	Uint16 rbuf[ MAZE_MAX_BLOCK ] = { 0 , };

	i = 0;
	SpiLoadRom( ( Uint16 )( FASTRUN_ACC_VARI_PAGE ) , 0x00 ,  ( Uint16 )( MAZE_MAX_BLOCK ) , rbuf );

	g_int32straight_acc = ( int32 )( ( rbuf[ i++ ] & 0xff ) << 0 );
	g_int32straight_acc |= ( int32 )( ( rbuf[ i++ ] & 0xff ) << 8 );

	g_int32diag_acc = ( int32 )( ( rbuf[ i++ ] & 0xff ) << 0 );
	g_int32diag_acc |= ( int32 )( ( rbuf[ i++ ] & 0xff ) << 8 );	
	
#ifdef ROM_DEBUG
	SCIa_Printf("\n\n----------- FASTRUN VARIABLE VALUE READ ------------\n\n");

	SCIa_Printf("straight acc : %4lu\n" , ( Uint32 )g_int32straight_acc );
	SCIa_Printf("diagnal acc : %4lu\n" , ( Uint32 )g_int32diag_acc );	
#endif
	
}


