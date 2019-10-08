/*****************************************************************************/
/* stdarg.h   v4.1.3                                                         */
/* Copyright (c) 1996-2006 Texas Instruments Incorporated                    */
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
#if LARGE_MODEL
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

#ifdef __cplusplus

#ifndef _CPP_STYLE_HEADER
using std::va_list;
#endif

#endif /* __cplusplus */

#else

#ifdef __cplusplus

#ifndef _CPP_STYLE_HEADER
using std::va_list;
#endif

#endif /* __cplusplus */

#endif /* _STDARG */

