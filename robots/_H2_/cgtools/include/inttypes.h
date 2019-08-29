/*****************************************************************************/
/* INTTYPES.H v4.1.3                                                         */
/* Copyright (c) 2002-2006 Texas Instruments Incorporated                    */
/*****************************************************************************/
#ifndef _INTTYPES_H_
#define _INTTYPES_H_

#include <stdint.h>

/* 7.8 Format conversion of integer types */

typedef struct { intmax_t quot, rem; } imaxdiv_t;

/* 
   According to footnotes in the 1999 C standard, "C++ implementations
   should define these macros only when __STDC_FORMAT_MACROS is defined
   before <inttypes.h> is included." 
*/
#if !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS)

/* 7.8.1 Macros for format specifiers */


#define PRIdLEAST8     	"d"
#define PRIiLEAST8     	"i"
#define PRIoLEAST8     	"o"
#define PRIuLEAST8     	"u"
#define PRIxLEAST8     	"x"
#define PRIXLEAST8     	"X"
#define PRIdFAST8     	"d"
#define PRIiFAST8     	"i"
#define PRIoFAST8     	"o"
#define PRIuFAST8     	"u"
#define PRIxFAST8     	"x"
#define PRIXFAST8     	"X"
#define PRId16		"d"
#define PRIi16		"i"
#define PRIo16		"o"
#define PRIu16		"u"
#define PRIx16		"x"
#define PRIX16		"X"
#define PRIdLEAST16    	"d"
#define PRIiLEAST16    	"i"
#define PRIoLEAST16    	"o"
#define PRIuLEAST16    	"u"
#define PRIxLEAST16    	"x"
#define PRIXLEAST16    	"X"
#define PRIdFAST16    	"d"
#define PRIiFAST16    	"i"
#define PRIoFAST16    	"o"
#define PRIuFAST16    	"u"
#define PRIxFAST16    	"x"
#define PRIXFAST16    	"X"

#define SCNdLEAST8 	"d"
#define SCNiLEAST8 	"i"
#define SCNoLEAST8 	"o"
#define SCNuLEAST8 	"u"
#define SCNxLEAST8 	"x"
#define SCNdFAST8 	"d"
#define SCNiFAST8 	"i"
#define SCNoFAST8 	"o"
#define SCNuFAST8 	"u"
#define SCNxFAST8 	"x"
#define SCNd16		"d"
#define SCNi16		"i"
#define SCNo16		"o"

#define SCNu16		"u"
#define SCNx16		"x"
#define SCNdLEAST16 	"d"
#define SCNiLEAST16 	"i"
#define SCNoLEAST16 	"o"
#define SCNuLEAST16 	"u"
#define SCNxLEAST16 	"x"
#define SCNdFAST16 	"d"
#define SCNiFAST16 	"i"
#define SCNoFAST16 	"o"
#define SCNuFAST16 	"u"
#define SCNxFAST16 	"x"

#define PRId32		"ld"
#define PRIi32		"li"
#define PRIo32		"lo"
#define PRIu32		"lu"
#define PRIx32		"lx"
#define PRIX32		"lX"
#define PRIdLEAST32    	"ld"
#define PRIiLEAST32    	"li"
#define PRIoLEAST32    	"lo"
#define PRIuLEAST32    	"lu"
#define PRIxLEAST32    	"lx"
#define PRIXLEAST32    	"lX"
#define PRIdFAST32    	"ld"
#define PRIiFAST32    	"li"
#define PRIoFAST32    	"lo"
#define PRIuFAST32    	"lu"
#define PRIxFAST32    	"lx"
#define PRIXFAST32    	"lX"
#define SCNd32		"ld"
#define SCNi32		"li"
#define SCNo32		"lo"
#define SCNu32		"lu"
#define SCNx32		"lx"
#define SCNdLEAST32    	"ld"
#define SCNiLEAST32    	"li"
#define SCNoLEAST32    	"lo"
#define SCNuLEAST32    	"lu"
#define SCNxLEAST32    	"lx"
#define SCNdFAST32    	"ld"
#define SCNiFAST32    	"li"
#define SCNoFAST32    	"lo"
#define SCNuFAST32    	"lu"
#define SCNxFAST32    	"lx"


#if 0 || 0 || defined(__TMS320C28X__)
#define PRId64		"lld"
#define PRIi64		"lli"
#define PRIo64		"llo"
#define PRIu64		"llu"
#define PRIx64		"llx"
#define PRIX64		"llX"
#define PRIdLEAST64    	"lld"
#define PRIiLEAST64    	"lli"
#define PRIoLEAST64    	"llo"
#define PRIuLEAST64    	"llu"
#define PRIxLEAST64    	"llx"
#define PRIXLEAST64    	"llX"
#define PRIdFAST64    	"lld"
#define PRIiFAST64    	"lli"
#define PRIoFAST64    	"llo"
#define PRIuFAST64    	"llu"
#define PRIxFAST64    	"llx"
#define PRIXFAST64    	"llX"
#define SCNd64		"lld"
#define SCNi64		"lli"
#define SCNo64		"llo"
#define SCNu64		"llu"
#define SCNx64		"llx"
#define SCNdLEAST64    	"lld"
#define SCNiLEAST64    	"lli"
#define SCNoLEAST64    	"llo"
#define SCNuLEAST64    	"llu"
#define SCNxLEAST64    	"llx"
#define SCNdFAST64    	"lld"
#define SCNiFAST64    	"lli"
#define SCNoFAST64    	"llo"
#define SCNuFAST64    	"llu"
#define SCNxFAST64    	"llx"
#endif

#define PRIdPTR		"ld"
#define PRIiPTR		"li"
#define PRIoPTR		"lo"
#define PRIuPTR		"lu"
#define PRIxPTR		"lx"
#define PRIXPTR		"lX"
#define SCNdPTR		"ld"
#define SCNiPTR		"li"
#define SCNoPTR		"lo"

#define SCNuPTR		"lu"
#define SCNxPTR		"lx"

#if defined(__TMS320C27X__) || 0 || 0
#define PRIdMAX		"ld"
#define PRIiMAX		"li"
#define PRIoMAX		"lo"
#define PRIuMAX		"lu"
#define PRIxMAX		"lx"
#define PRIXMAX		"lX"
#define SCNdMAX		"ld"
#define SCNiMAX		"li"
#define SCNoMAX		"lo"
#define SCNuMAX		"lu"
#define SCNxMAX		"lx"
#elif defined(__TMS320C28X__) || defined(__TMS320C55X__) || defined(__TMS470__) || defined(_TMS320C6X)
#define PRIdMAX		"lld"
#define PRIiMAX		"lli"
#define PRIoMAX		"llo"
#define PRIuMAX		"llu"
#define PRIxMAX		"llx"
#define PRIXMAX		"llX"
#define SCNdMAX		"lld"
#define SCNiMAX		"lli"
#define SCNoMAX		"llo"
#define SCNuMAX		"llu"
#define SCNxMAX		"llx"
#endif

#endif /* !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS) */

/* 7.8.2 Functions for greatest-width integer types */
#include <linkage.h>

_CODE_ACCESS intmax_t  imaxabs(intmax_t j);
_CODE_ACCESS imaxdiv_t imaxdiv(intmax_t numer, intmax_t denom);
_CODE_ACCESS intmax_t  strtoimax(const char * restrict nptr, 
		    char ** restrict endptr, int base);
_CODE_ACCESS uintmax_t strtoumax(const char * restrict nptr, 
		    char ** restrict endptr, int base);

#endif /* _INTTYPES_H_ */

