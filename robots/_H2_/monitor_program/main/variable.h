
#ifndef __VARIABLE_H__
#define __VARIABLE_H__

#ifdef __VARIABLE__
#undef __VARIABLE__
#define __VARIABLE_EXT__
#else
#define __VARIABLE_EXT__	extern 
#endif


__VARIABLE_EXT__ volatile int32 g_int32vfd_flag;


#endif
