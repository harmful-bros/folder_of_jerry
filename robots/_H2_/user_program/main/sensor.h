//###########################################################################
//
// FILE		: sensor.h
//
// TITLE		: micromouse H2 sensor header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2011.10.01 $
//###########################################################################

#ifndef __SENSOR_H__
#define __SENSOR_H__

typedef volatile enum sensor_name
{
	LFS , 	// left front sensor
	RSS , 	// right side sensor
	LDS , 	// left diag sensor
	RFS , 	// right front sensor
	LSS , 	// left side sensor
	RDS		// right diag sensor

}sen_name_e;


extern interrupt void sensor_timer_ISR( void );
extern interrupt void adc_external_ISR( void );

extern void sensor_vari_init( void );
extern void edge_vari_init( void );
extern void batt_volt_comform_func( sw_t *psw );

extern void sensor_value_view( void );
extern void gyro_value_view( void );
extern void sensor_position_view( void );
extern void real_position_value_view( void );

extern void front_sensor_setting( void );
extern void side_and_45diag_sensor_setting( void );


extern int32 init_gyro_reference_value_search( gyro_t *p_gyro );

extern void position_pid_compute_func( void );

extern Uint16 wall_check_func( sen_t *p_rsen , sen_t *p_lsen );

#endif

