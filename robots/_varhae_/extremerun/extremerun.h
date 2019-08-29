//###########################################################################
//
// FILE		: extremerun.h
//
// TITLE		: _varhae_ Tracer extreme run header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2009.12.24 $
//###########################################################################

#ifndef __EXTREMERUN_H__
#define __EXTREMERUN_H__

extern void xkval_ctrl_func( Uint32 mode , position_t *p_pos , float32 ratio , volatile float32 limit );
extern void extreme_run( sec_info_t *p_info );

#endif

