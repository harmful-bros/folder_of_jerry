//###########################################################################
//
// FILE		: rom.h
//
// TITLE		: _varhae_ Tracer rom header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.10.31 $
//###########################################################################

#ifndef	__ROM_H__
#define	__ROM_H__

extern void curvature_redetection( sec_info_t *p_info , int32 mark );

extern void sensor_write_rom( void );
extern void sensor_load_rom( void );
extern void velocity_save_rom( void );
extern void velocity_load_rom(void);
extern void accel_save_rom( void );
extern void accel_load_rom( void );
extern void line_save_rom( void );
extern void line_load_rom( void );

#endif
