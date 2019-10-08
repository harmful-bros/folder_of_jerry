/*****************************************************************************/
/* stdarg.h   v5.1.0                                                         */
/* Copyright (c) 1996-2008 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _STDARG
#define _STDARG

#include <linkage.h>

#ifdef __cplusplus
#define va_start(ap, parmN) (ap = ((std::va_list)__va_parmadr(parmN)))
namespace std {
#else
#define va_start(ap, parmN) (ap = ((va_list)__va_parmadr(parmN)))
#endif /* __cplusplus */

typedef char *va_list;

#ifdef __cplusplus
} /* namespace std */
#endif

#define va_end(ap)

/****************************************************************************/
/* RETURN THE NEXT VALUE ON THE STACK ...                                   */
/*                                                                          */
/* (<advance ap>, <access the value>) BECOMES ...                           */
/*                                                                          */
/* ap -= 1 (stack grows toward high addresses)                              */
/* ap -= 1 more if type is long or float                                    */
/* ap -= 1 more if type is long or float and to account for alignment       */
/*       if necessary                                                       */
/*                                                                          */
/* if      (<type is passed by address [struct or union]>) return **ap;     */
/* else if (<type is integer size>)                        return *ap;      */
/*                                                                          */
/* LONG/FLOATS ARE ALWAYS ALIGNED ON AN EVEN WORD BOUNDARY, EVEN WHEN       */
/* PASSED AS PARAMETERS, THUS ap MUST BE ALIGNED FOR THOSE ACCESSES.        */
/****************************************************************************/
#if __LARGE_MODEL__
#define va_arg(ap, type)                                                 \
( (ap -= 1 + (__va_argref(type) ? (((long)ap & 1) ? 2 : 1) :		 \
				  (sizeof(type) == sizeof(int)) ? 0 :    \
                                   ((long)ap & 1) ? sizeof(type) :       \
                                                    sizeof(type) - 1 )), \
   (__va_argref(type)             ? (** (type **) (ap)) : (* (type *) (ap)) ))
#else
#define va_arg(ap, type)                                                 \
( (ap -= 1 + (__va_argref(type) ? (((int)ap & 1) ? 2 : 1) : 		 \
				  (sizeof(type) == sizeof(int)) ? 0 :    \
                                   ((int)ap & 1) ? sizeof(type)      :   \
                                                   sizeof(type) - 1 )),  \
   (__va_argref(type)             ? (** (type **) (ap)) : (* (type *) (ap)) ))
#endif

#endif /* _STDARG */

#if defined(__cplusplus) && !defined(_CPP_STYLE_HEADER)
using std::va_list;
#endif /* _CPP_STYLE_HEADER */

