//###########################################################################
//
// FILE		: fastrun.h
//
// TITLE		: _varhae_ Tracer fastrun header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.11.21 $
//###########################################################################

#ifndef __FASTRUN_H__
#define __FASTRUN_H__

extern void second_error_disposal( err_dps_t *p_err , sec_info_t *p_info, int32 mark_cnt );
extern void error_disposal_debug_func( err_dps_t *p_err );
extern void runmode_lineinfo( sec_info_t *pinfo , err_dps_t *perr );

extern void inverse_run_info_compute( void );
extern void speed_up_compute( sec_info_t *pinfo );
extern void nomal_run( sec_info_t *p_info );


#endif

