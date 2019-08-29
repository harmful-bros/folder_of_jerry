/*****************************************************************************/
/*  ERRNO.H  v5.2.8                                                          */
/*  Copyright (c) 1995-2010 Texas Instruments Incorporated                   */
/*****************************************************************************/

#ifndef _ERRNO
#define _ERRNO


#ifdef __cplusplus
//----------------------------------------------------------------------------
// <cerrno> IS RECOMMENDED OVER <errno.h>.  <errno.h> IS PROVIDED FOR
// COMPATIBILITY WITH C AND THIS USAGE IS DEPRECATED IN C++
//----------------------------------------------------------------------------
extern "C" namespace std
{
#endif /* __cplusplus */

#include <linkage.h>


extern _DATA_ACCESS int errno;
#ifdef __cplusplus
  #define errno ::std::errno
#else
  #define errno errno
#endif

/*---------------------------------------------------------------------------*/
/* Change #defines for CLIB ABI conformance.                                 */
/*---------------------------------------------------------------------------*/
#ifdef __TI_ELFABI__

    #define EDOM   33
    #define ERANGE 34
    #define ENOENT 2
    #define EFPOS  152
    #define EILSEQ 88

#else

    #define EDOM   1
    #define ERANGE 2
    #define ENOENT 3
    #define EFPOS  5
    #define EILSEQ 6

#endif /* __TI_ELFABI__ */


#ifdef __cplusplus
} /* extern "C" namespace std */
#endif /* __cplusplus */

#endif  /* _ERRNO */

#if defined(__cplusplus) && !defined(_CPP_STYLE_HEADER)


#endif /* _CPP_STYLE_HEADER */

