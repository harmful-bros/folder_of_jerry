/*****************************************************************************/
/* float.h    v5.1.0                                                         */
/* Copyright (c) 1996-2008 Texas Instruments Incorporated                    */
/*****************************************************************************/

/********************************************************************/
/*    KEY:  FLT_     - APPLIES TO TYPE FLOAT                        */
/*          DBL_     - APPLIES TO TYPE DOUBLE                       */
/*          LDBL_    - APPLIES TO TYPE LONG DOUBLE                  */
/********************************************************************/
#ifndef _FLOAT
#define _FLOAT

#define FLT_RADIX                         2   /* RADIX OF EXPONENT         */
#define FLT_ROUNDS                        1   /* ROUND TO NEAREST          */
 
#define FLT_DIG                           6   /* DECIMAL PRECISION         */
#define FLT_MANT_DIG                     24   /* BITS IN MANTISSA          */
#define FLT_MIN_EXP                    -125   /* SMALLEST EXPONENT         */
#define FLT_MAX_EXP                     128   /* LARGEST EXPONENT          */
#define FLT_EPSILON        1.192092896E-07F   /* SMALLEST X WHERE 1+X != 1 */
#define FLT_MIN            1.175494351E-38F   /* SMALLEST POSITIVE VALUE   */
#define FLT_MAX            3.402823466E+38F   /* LARGEST POSITIVE VALUE    */
#define FLT_MIN_10_EXP                  -37   /* MIN POWER OF 10           */
#define FLT_MAX_10_EXP                   38   /* MAX POWER OF 10           */
 
#define DBL_DIG                           6   /* DECIMAL PRECISION         */
#define DBL_MANT_DIG                     24   /* BITS IN MANTISSA          */
#define DBL_MIN_EXP                    -125   /* SMALLEST EXPONENT         */
#define DBL_MAX_EXP                     128   /* LARGEST EXPONENT          */
#define DBL_EPSILON        1.192092896E-07    /* SMALLEST X WHERE 1+X != 1 */
#define DBL_MIN            1.175494351E-38    /* SMALLEST POSITIVE VALUE   */
#define DBL_MAX            3.402823466E+38    /* LARGEST POSITIVE VALUE    */
#define DBL_MIN_10_EXP                  -37   /* MIN POWER OF 10           */
#define DBL_MAX_10_EXP                   38   /* MAX POWER OF 10           */
 
#if defined(__TMS320C27X__)

#define LDBL_DIG                          6   /* DECIMAL PRECISION         */
#define LDBL_MANT_DIG                    24   /* BITS IN MANTISSA          */
#define LDBL_MIN_EXP                   -125   /* SMALLEST EXPONENT         */
#define LDBL_MAX_EXP                    128   /* LARGEST EXPONENT          */
#define LDBL_EPSILON       1.192092896E-07    /* SMALLEST X WHERE 1+X != 1 */
#define LDBL_MIN           1.175494351E-38    /* SMALLEST POSITIVE VALUE   */
#define LDBL_MAX           3.402823466E+38    /* LARGEST POSITIVE VALUE    */
#define LDBL_MIN_10_EXP                 -37   /* MIN POWER OF 10           */
#define LDBL_MAX_10_EXP                  38   /* MAX POWER OF 10           */

#elif defined(__TMS320C28X__)

#define LDBL_DIG                         15   /* DECIMAL PRECISION         */
#define LDBL_MANT_DIG                    53   /* BITS IN MANTISSA          */
#define LDBL_MIN_EXP                  -1021   /* SMALLEST EXPONENT         */
#define LDBL_MAX_EXP                   1024   /* LARGEST EXPONENT          */
#define LDBL_EPSILON 2.2204460492503131E-16L  /* SMALLEST X WHERE 1+X != 1 */
#define LDBL_MIN    2.2250738585072014E-308L  /* SMALLEST POSITIVE VALUE   */
#define LDBL_MAX    1.7976931348623157E+308L  /* LARGEST POSITIVE VALUE    */
#define LDBL_MIN_10_EXP                -307   /* MIN POWER OF 10           */
#define LDBL_MAX_10_EXP                 308   /* MAX POWER OF 10           */

#endif /* __TMS320C28X__ */

#endif /* _FLOAT */
