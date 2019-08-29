//###########################################################################
//
// FILE		: motor.h
//
// TITLE		: micromouse H2 motor header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2011.10.02 $
//###########################################################################

#ifndef __MOTOR_H__
#define __MOTOR_H__

#define MOTOR_ON	GpioDataRegs.GPASET.bit.GPIO16 = ON
#define MOTOR_OFF	GpioDataRegs.GPACLEAR.bit.GPIO16 = ON

extern void pwm_test_func( void );

extern void motor_vari_init( void );
extern void diffvel_to_remaindist_cpt( volatile float32 cur_vel , volatile float32 tar_vel , volatile int32 acc , volatile float32 *decel_dist );
extern void dist_to_maxvel_cpt( volatile float32 dist , volatile float32 minus_dist , volatile float32 cur_vel , volatile int32 acc , volatile float32 *max_vel , volatile float32 limit_vel  );


extern void move_end( volatile float32 r_dist , volatile float32 r_vel , volatile float32 l_dist , volatile float32 l_vel , volatile int32 acc );
extern void move_to_move( volatile float dist , volatile float tar_vel , volatile float32 dec_vel , volatile int32 acc );

extern void handle_ad_make( volatile float32 acc_rate , volatile float32 dec_rate );
extern interrupt void motor_pid_ISR( void );

#endif

