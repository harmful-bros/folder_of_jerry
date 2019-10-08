/*****************************************************************************/
/* setjmp.h   v5.1.0                                                         */
/* Copyright (c) 1993-2008 Texas Instruments Incorporated                    */
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
    #if defined(__EDG_JMP_BUF_NUM_ELEMENTS) 
       #if __EDG_JMP_BUF_NUM_ELEMENTS !=6
          #error "Front end and runtime disagree on size of jmp_buf"
       #endif
    #endif
#elif defined(__TMS320C28X__) 
  #if defined(__TMS320C28XX_FPU32__)
    typedef long jmp_buf[9];
    #if defined(__EDG_JMP_BUF_NUM_ELEMENTS) 
       #if __EDG_JMP_BUF_NUM_ELEMENTS !=9
          #error "Front end and runtime disagree on size of jmp_buf"
       #endif
    #endif
  #else
    typedef long jmp_buf[5];
    #if defined(__EDG_JMP_BUF_NUM_ELEMENTS) 
       #if __EDG_JMP_BUF_NUM_ELEMENTS !=5
          #error "Front end and runtime disagree on size of jmp_buf"
       #endif
    #endif
  #endif
#else
#warn "This header only intended for use with C6x, C54x, C55x, and Arm."
    typedef int jmp_buf[13];
    #if defined(__EDG_JMP_BUF_NUM_ELEMENTS) 
       #if __EDG_JMP_BUF_NUM_ELEMENTS !=13
          #error "Front end and runtime disagree on size of jmp_buf"
       #endif
    #endif
#endif

_CODE_ACCESS int  _setjmp(jmp_buf env); 

_CODE_ACCESS void longjmp(jmp_buf env, int val);

/*****************************************************************************/
/*	DEFINE THE FAR VERSION OF THE SETJMP for ANKOOR.		     */
/*****************************************************************************/
#define far_setjmp(x) _far_setjmp(x)

#if defined(__TMS320C27X__)
typedef far int far_jmp_buf[6];
#elif defined(__TMS320C28X__) 
  #if defined(__TMS320C28XX_FPU32__)
   typedef far long far_jmp_buf[9];
  #else 
   typedef far long far_jmp_buf[5];
  #endif
#endif

_CODE_ACCESS int  _far_setjmp(far_jmp_buf env); 
_CODE_ACCESS void far_longjmp(far_jmp_buf env, int val);


#ifdef __cplusplus
} /* extern "C" namespace std */
#endif /* __cplusplus */

#endif /* _SETJMP */

#if defined(__cplusplus) && !defined(_CPP_STYLE_HEADER)
using std::jmp_buf;
using std::_setjmp;
using std::longjmp;
#endif /* _CPP_STYLE_HEADER */


