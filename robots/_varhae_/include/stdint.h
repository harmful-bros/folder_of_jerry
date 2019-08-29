/*****************************************************************************/
/* STDINT.H v5.1.0                                                           */
/* Copyright (c) 2002-2008 Texas Instruments Incorporated                    */
/*****************************************************************************/
#ifndef _STDINT_H_
#define _STDINT_H_

/* 7.18.1.1 Exact-width integer types */

    typedef          int    int16_t;
    typedef unsigned int   uint16_t;
    typedef          long   int32_t;
    typedef unsigned long  uint32_t;


#if defined(__TMS470__) || defined(_TMS320C6X) || defined(__TMS320C28X__)
    typedef          long long  int64_t;
    typedef unsigned long long uint64_t;
#endif

/* 7.18.1.2 Minimum-width integer types */

    typedef  int16_t  int_least8_t;
    typedef uint16_t uint_least8_t;

    typedef  int16_t  int_least16_t;
    typedef uint16_t uint_least16_t;
    typedef  int32_t  int_least32_t;
    typedef uint32_t uint_least32_t;


#if defined(__TMS470__) || defined(_TMS320C6X) || defined(__TMS320C28X__)
    typedef  int64_t  int_least64_t;
    typedef uint64_t uint_least64_t;
#else
/* sorry, int_least64_t not implemented for C54x, C55x, MSP430 */
#endif

/* 7.18.1.3 Fastest minimum-width integer types */

    typedef  int16_t  int_fast8_t;
    typedef uint16_t uint_fast8_t;
    typedef  int16_t  int_fast16_t;
    typedef uint16_t uint_fast16_t;

    typedef  int32_t  int_fast32_t;
    typedef uint32_t uint_fast32_t;


#if defined(__TMS470__) || defined(_TMS320C6X) || defined(__TMS320C28X__)
    typedef  int64_t  int_fast64_t;
    typedef uint64_t uint_fast64_t;
#endif

/* 7.18.1.4 Integer types capable of holding object pointers */
    typedef          long intptr_t;
    typedef unsigned long uintptr_t;

/* 7.18.1.5 Greatest-width integer types */
#if defined(__TMS320C55X__) || defined(__TMS470__) || defined(_TMS320C6X) || defined(__TMS320C28X__)
    typedef          long long intmax_t;
    typedef unsigned long long uintmax_t;
#elif defined(_TMS320C5XX) || defined(__TMS320C27X__) || defined(__MSP430__)
    typedef          long intmax_t;
    typedef unsigned long uintmax_t;
#endif

/* 
   According to footnotes in the 1999 C standard, "C++ implementations
   should define these macros only when __STDC_LIMIT_MACROS is defined
   before <stdint.h> is included." 
*/
#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS)

/* 7.18.2 Limits of specified width integer types */


    #define  INT16_MAX  0x7fff
    #define  INT16_MIN  (-INT16_MAX-1)
    #define UINT16_MAX  0xffff

    #define  INT32_MAX  0x7fffffff
    #define  INT32_MIN  (-INT32_MAX-1)
    #define UINT32_MAX  0xffffffff


#if defined(__TMS470__) || defined(_TMS320C6X) || defined(__TMS320C28X__)
    #define  INT64_MAX  0x7fffffffffffffff
    #define  INT64_MIN  (-INT64_MAX-1)
    #define UINT64_MAX  0xffffffffffffffff
#endif

    #define  INT_LEAST8_MAX   INT16_MAX
    #define  INT_LEAST8_MIN   INT16_MIN
    #define UINT_LEAST8_MAX   UINT16_MAX

    #define  INT_LEAST16_MAX  INT16_MAX
    #define  INT_LEAST16_MIN  INT16_MIN
    #define UINT_LEAST16_MAX  UINT16_MAX
    #define  INT_LEAST32_MAX  INT32_MAX
    #define  INT_LEAST32_MIN  INT32_MIN
    #define UINT_LEAST32_MAX  UINT32_MAX


#if defined(__TMS470__) || defined(_TMS320C6X) || defined(__TMS320C28X__)
    #define  INT_LEAST64_MAX  INT64_MAX
    #define  INT_LEAST64_MIN  INT64_MIN
    #define UINT_LEAST64_MAX  UINT64_MAX
#endif

    #define  INT_FAST8_MAX   INT16_MAX
    #define  INT_FAST8_MIN   INT16_MIN
    #define UINT_FAST8_MAX   UINT16_MAX
    #define  INT_FAST16_MAX  INT16_MAX
    #define  INT_FAST16_MIN  INT16_MIN
    #define UINT_FAST16_MAX  UINT16_MAX

    #define  INT_FAST32_MAX  INT32_MAX
    #define  INT_FAST32_MIN  INT32_MIN
    #define UINT_FAST32_MAX  UINT32_MAX


#if defined(__TMS470__) || defined(_TMS320C6X) || defined(__TMS320C28X__)
    #define  INT_FAST64_MAX  INT64_MAX
    #define  INT_FAST64_MIN  INT64_MIN
    #define UINT_FAST64_MAX  UINT64_MAX
#endif

    #define INTPTR_MAX   INT32_MAX
    #define INTPTR_MIN   INT32_MIN
    #define UINTPTR_MAX  UINT32_MAX

#if defined(__TMS470__) || defined(_TMS320C6X) || defined(__TMS320C28X__)
    #define INTMAX_MIN   INT64_MIN
    #define INTMAX_MAX   INT64_MAX
    #define UINTMAX_MAX  UINT64_MAX
#elif defined(_TMS320C5XX) || defined(__TMS320C27X__) || defined(__MSP430__)
    #define INTMAX_MIN   INT32_MIN
    #define INTMAX_MAX   INT32_MAX
    #define UINTMAX_MAX  UINT32_MAX
#endif

/* 7.18.3 Limits of other integer types */

    #define PTRDIFF_MAX INT32_MAX
    #define PTRDIFF_MIN INT32_MIN

    #define SIG_ATOMIC_MIN INT32_MIN
    #define SIG_ATOMIC_MAX INT32_MAX

    #define SIZE_MAX INT32_MAX

#ifndef WCHAR_MAX
#define WCHAR_MAX 0xffffu
#endif

#ifndef WCHAR_MIN
#define WCHAR_MIN 0
#endif

    #define WINT_MIN INT32_MIN
    #define WINT_MAX INT32_MAX

/* 7.18.4.1 Macros for minimum-width integer constants */

/*
   There is a defect report filed against the C99 standard concerning how 
   the (U)INTN_C macros should be implemented.  Please refer to --
   http://wwwold.dkuug.dk/JTC1/SC22/WG14/www/docs/dr_209.htm 
   for more information.  These macros are implemented according to the
   suggestion given at this web site.
*/

    #define  INT8_C(value)  ((int_least8_t)(value))
    #define UINT8_C(value)  ((uint_least8_t)(value))
    #define  INT16_C(value) ((int_least16_t)(value))
    #define UINT16_C(value) ((uint_least16_t)(value))
    #define  INT32_C(value) ((int_least32_t)(value))
    #define UINT32_C(value) ((uint_least32_t)(value))


#if defined(__TMS470__) || defined(_TMS320C6X) || defined(__TMS320C28X__)
    #define  INT64_C(value) ((int_least64_t)(value))
    #define UINT64_C(value) ((uint_least64_t)(value))
#endif

/* 7.18.4.2 Macros for greatest-width integer constants */

    #define  INTMAX_C(value) ((intmax_t)(value))
    #define UINTMAX_C(value) ((uintmax_t)(value))

#endif /* !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) */

#endif /* _STDINT_H_ */
