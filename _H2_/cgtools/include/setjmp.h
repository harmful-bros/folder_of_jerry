/*****************************************************************************/
/* setjmp.h   v4.1.3                                                         */
/* Copyright (c) 1996-2006 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _SETJMP
#define _SETJMP

#include <linkage.h>

#ifdef __cplusplus
extern "C" namespace std {
#endif

#define setjmp(x) _setjmp(x)

#if defined(__TMS320C27X__)
typedef int jmp_buf[6];
#if defined(__EDG_JMP_BUF_NUM_ELEMENTS) && __EDG_JMP_BUF_NUM_ELEMENTS !=6
   #error "Front end and runtime disagree on size of jmp_buf"
#endif
#elif defined(__TMS320C28X__)
typedef int jmp_buf[9];
#if defined(__EDG_JMP_BUF_NUM_ELEMENTS) && __EDG_JMP_BUF_NUM_ELEMENTS !=9
   #error "Front end and runtime disagree on size of jmp_buf"
#endif
#endif

_CODE_ACCESS int  _setjmp(jmp_buf env); 
_CODE_ACCESS void longjmp(jmp_buf env, int val);

/*****************************************************************************/
/*	DEFINE THE FAR VERSION OF THE SETJMP.				     */
/*****************************************************************************/
#define far_setjmp(x) _far_setjmp(x)

#if defined(__TMS320C27X__)
typedef far int far_jmp_buf[6];
#elif defined(__TMS320C28X__)
typedef far int far_jmp_buf[9];
#endif

_CODE_ACCESS int  _far_setjmp(far_jmp_buf env); 
_CODE_ACCESS void far_longjmp(far_jmp_buf env, int val);

#ifdef __cplusplus
} /* extern "C" namespace std */

#ifndef _CPP_STYLE_HEADER
using std::jmp_buf;
using std::_setjmp;
using std::longjmp;
#endif /* _CPP_STYLE_HEADER */

#endif /* __cplusplus */

#else

#ifdef __cplusplus

#ifndef _CPP_STYLE_HEADER
using std::jmp_buf;
using std::_setjmp;
using std::longjmp;
#endif /* _CPP_STYLE_HEADER */

#endif /* __cplusplus */

#endif /* _SETJMP */

