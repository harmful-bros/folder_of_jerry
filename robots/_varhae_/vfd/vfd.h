//###########################################################################
//
// FILE		: vfd.h
//
// TITLE		: _varhae_ Tracer VFD header file.
//
// Author	: leejaeseong
//
// Company	: Hertz
//
//###########################################################################
// $Release Date: 2011.04.14 $
//###########################################################################

#ifndef __VFD_H__
#define __VFD_H__

#define	VfdBright100	0
#define	VfdBright80		1
#define	VfdBright53		2
#define	VfdBright40		3
#define	VfdBright27		4
#define	VfdBright20		5
#define	VfdBright13		6
#define	VfdBright0		7


extern void InitVFDBright(Uint16 i);
extern void VFDPutChar(char Data);
extern void VFDString(char *Str);
extern void VFDPrintf(char *form, ...);
extern void VFDMenu(char *str);

extern void VFD_scroll( char *str , float32 sec );
extern void VFD_loiter( char *str , int gap , float32 sec );




#endif


