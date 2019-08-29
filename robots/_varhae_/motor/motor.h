//###########################################################################
//
// FILE		: motor.h
//
// TITLE		: _varhae_ Tracer motor header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.07.12 $
//###########################################################################

#ifndef __MOTOR_H__
#define	__MOTOR_H__


extern void debug_force_PWM( str_point_t *pstr );
extern void init_motor_variable( motor_vari *pm );

extern void diffvel_to_remaindist_cpt( volatile float32 cur_vel , volatile float32 tar_vel , volatile int32 acc , volatile float32 *decel_dist );
extern void dist_to_maxvel_cpt( volatile float32 dist , volatile float32 minus_dist , volatile float32 cur_vel , volatile int32 acc , volatile float32 *max_vel );

extern void move_end( volatile float32 dist , volatile float32 vel , volatile int32 acc );
extern void move_to_move( volatile float dist , volatile float dec_dist , volatile float tar_vel , volatile float32 dec_vel , volatile int32 acc );

extern void handle_ad_make( volatile float32 acc_rate , volatile float32 dec_rate );
extern interrupt void motor_pid_ISR(void);


#endif



