//###########################################################################
//
// FILE		: sensor.h
//
// TITLE		: _varhae_ Tracer sensor header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.09.19 $
//###########################################################################



#ifndef __SENSOR_H__
#define __SENSOR_H__


extern void init_sen_vari( void );
extern interrupt void sensor_timer_ISR( void );
extern interrupt void adc_timer_ISR( void );
extern void sensor_setting_classic( void );
extern int32 gyro_center_value_search( gyro_t *pgyro );
extern void debug_sen_val( str_point_t *pstr );
extern void debug_sen_div( str_point_t *pstr );
extern void debug_sen_data( str_point_t *pstr );
extern void debug_gyro_val( str_point_t *pstr );
extern void debug_gyro_angle( str_point_t *pstr );
extern void debug_sen_pos( str_point_t *pstr );
extern void debug_sen_state( str_point_t *pstr );
extern void debug_cps_val( str_point_t *pstr );
extern void sensor_printf_func( sen_t *psen );

extern void shift_test_func( int32 mode );
#if 0
extern void compass_setting_func( void );
extern void compass_printf_func( compass_t *pxcps , compass_t *pycps );
#endif

extern void position_compute( void );
extern void position_PID_handle( void );

extern void mark_checking_func( turnmark_t *pmark , turnmark_t *premark );

#endif 


