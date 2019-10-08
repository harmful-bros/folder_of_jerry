//###########################################################################
//
// FILE		: rom.h
//
// TITLE		: micromouse H2 rom header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2012.01.16 $
//###########################################################################

#ifndef __ROM_H__
#define __ROM_H__

typedef enum rom_sector_define
{
	FRONT_SENSOR_VALUE_PAGE , 
	FRONT_SENSOR_DIFF_PAGE , 
	SIDE_DIAG_SENSOR_PAGE , 

	MAZE_MAP_BACKUP0_PAGE , 
	MAZE_MAP_BACKUP1_PAGE , 
	MAZE_MAP_BACKUP2_PAGE , 
	MAZE_MAP_BACKUP3_PAGE ,

	TURN_VARI_PAGE , 
	FASTRUN_ACC_VARI_PAGE
	
}rom_sector_define_e;

typedef enum rom_information
{
	MAZE_MAX_BLOCK = 256
		
}rom_info_e;

extern void front_sensor_value_write_rom( void );
extern void front_sensor_value_read_rom( void );

extern void side_and_diag_sensor_value_write_rom( void );
extern void side_and_diag_sensor_value_read_rom( void );

extern void maze_map_write_rom( void );
extern void maze_map_read_rom( int32 idx );

extern void turn_vari_write_rom( void );
extern void turn_vari_read_rom( void );

extern void fastrun_vari_write_rom( void );
extern void fastrun_vari_read_rom( void );

#endif

