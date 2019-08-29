//###########################################################################
//
// FILE		: vfd.h
//
// TITLE		: micromouse H2 vfd header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2011.10.01 $
//###########################################################################


#ifndef __VFD_H__
#define __VFD_H__


extern void vfd_init( void );
extern void vfdprintf( char *pchar , ... );
extern void vfd_scroll( char *str );


#endif

