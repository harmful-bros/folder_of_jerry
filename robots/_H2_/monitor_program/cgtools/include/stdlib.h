/*****************************************************************************/
/* stdlib.h   v4.1.3                                                         */
/* Copyright (c) 1996-2006 Texas Instruments Incorporated                    */
/*****************************************************************************/

#ifndef _STDLIB
#define _STDLIB

#ifdef __cplusplus
//----------------------------------------------------------------------------
// <cstdlib> IS RECOMMENDED OVER <stdlib.h>.  <stdlib.h> IS PROVIDED FOR 
// COMPATIBILITY WITH C AND THIS USAGE IS DEPRECATED IN C++
//----------------------------------------------------------------------------
#include <cstdlib>
using std::div_t;
using std::ldiv_t;

using std::size_t;
using std::abs;
using std::labs;
using std::atoi;
using std::atol;
using std::atof;
using std::strtol;
using std::strtoul;
using std::strtod;
using std::strtold;
using std::rand;
using std::srand;
using std::calloc;
using std::far_calloc;
using std::malloc;
using std::far_malloc;
using std::realloc;
using std::far_realloc;
using std::free;
using std::far_free;
using std::free_memory;
using std::far_free_memory;
using std::max_free;
using std::far_max_free;
using std::far_chkheap;
using std::chkheap;
using std::abort;
using std::atexit;
using std::bsearch;
using std::qsort;
using std::exit;
using std::div;
using std::ldiv;
using std::getenv;
using std::system;

using std::atoll;
using std::lldiv_t;
using std::lldiv;
using std::strtoll;
using std::strtoull;

#else /* !__cplusplus */

#include <linkage.h>

typedef struct { int  quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

#define MB_CUR_MAX    1

#ifndef NULL
#define NULL          0
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef __SIZE_T_TYPE__ size_t;

#endif

#ifndef _WCHAR_T
#define _WCHAR_T
typedef unsigned int wchar_t;
#endif

#define EXIT_FAILURE  1
#define EXIT_SUCCESS  0

#define RAND_MAX      32767

         int           abs (int _val);
         long          labs(long _val);
	 long long 	llabs(long long _val);

         long          strtol (const char *st, char **endptr, int base);
         long          far_strtol (const far char *st, far char **endptr, 
				   int base);
         unsigned long strtoul(const char *st, char **endptr, int base);
         unsigned long far_strtoul(const far char *st, far char **endptr, 
				   int base);
         double        strtod (const char *st, char **endptr);
         long double   strtold (const char *st, char **endptr);
         double        far_strtod (const far char *st, far char **endptr);
         long double   far_strtold (const far char *st, far char **endptr);

	 long long     strtoll(const char *st, char **endptr, int base);
	 unsigned long long strtoull(const char *st, char **endptr, int base);
	 long long     far_strtoll(const far char *st, far char **endptr, 
		 						    int base);
	 unsigned long long far_strtoull(const far char *st, far char **endptr,
		 						    int base);
         int           atoi(const char *st);
         int           far_atoi(const far char *st);
         long          atol(const char *st);
	 int           ltoa(long val, char *buffer);
         long          far_atol(const far char *st);
__inline double        atof(const char *st) { return strtod(st, NULL); }
__inline double        far_atof(const far char *st) { return far_strtod(st, NULL); }

	 long long     atoll(const char *st);
	 long long     far_atoll(const far char *st);
         int           rand (void);
         void          srand(unsigned seed);

         void         *calloc  (size_t num, size_t size);
         far void     *far_calloc  (unsigned long num, unsigned long size);
	 void         *malloc  (size_t size);
         far void     *far_malloc  (unsigned long size);
	 void         *realloc (void *ptr, size_t size);
         far void     *far_realloc (far void *ptr, unsigned long size);
         void          free    (void *ptr);
         void          far_free    (far void *ptr);
	 int	       free_memory(void);
	 long          far_free_memory(void);
	 int           max_free(void);
	 long          far_max_free(void);
	 void         *chkheap();
	 long  	       far_chkheap();


         void          abort  (void); 
         int           atexit (void (*func)(void));
         void         *bsearch(const void *key, const void *base, 
			       size_t nmemb, size_t size, 
			       int (*compar)(const void *,const void *));
         far void     *far_bsearch(const far void *key, const far void *base, 
			           size_t nmemb, size_t size, 
			           int (*compar)(const far void *,const far void *));
         void          qsort  (void *base, size_t nmemb, size_t size,
			       int (*compar)(const void *, const void *));
         void          far_qsort  (far void *base, size_t nmemb, size_t size,
			           int (*compar)(const far void *, const far void *));
         void          exit   (int status);

         div_t         div (int numer, int denom);
         ldiv_t        ldiv(long numer, long denom);
         lldiv_t       lldiv(long long numer, long long denom);

         char         *getenv(const char *string);
         int           system(const char *name);

#endif /* __cplusplus */
#endif /* _STDLIB */


