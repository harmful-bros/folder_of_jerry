/*****************************************************************************/
/* linkage.h   v4.1.3                                                         */
/* Copyright (c) 1998-2006 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _LINKAGE
#define _LINKAGE

/* No modifiers needed to access code */

#define _CODE_ACCESS

/*--------------------------------------------------------------------------*/
/* Define _DATA_ACCESS ==> how to access RTS global or static data          */
/*--------------------------------------------------------------------------*/
#ifndef _FAR_RTS
#define _DATA_ACCESS
#else
#define _DATA_ACCESS far
#endif

/*--------------------------------------------------------------------------*/
/* Define _OPTIMIZE_FOR_SPACE ==> Always optimize for space.                */
/*--------------------------------------------------------------------------*/
#ifndef _OPTIMIZE_FOR_SPACE
#define _OPTIMIZE_FOR_SPACE 1
#endif

/*--------------------------------------------------------------------------*/
/* Define LARGE_MODEL ==> used with large memory model switch               */
/*--------------------------------------------------------------------------*/
#ifndef LARGE_MODEL
#define LARGE_MODEL  0
#endif

/*--------------------------------------------------------------------------*/
/* Define _IDECL ==> how inline functions are declared                      */
/*--------------------------------------------------------------------------*/
#ifdef _INLINE
#define _IDECL static __inline
#define _IDEFN static __inline
#else
#define _IDECL extern _CODE_ACCESS
#define _IDEFN _CODE_ACCESS
#endif

#endif /* _LINKAGE */

