/*****************************************************************************/
/* stdlibf.h   v5.1.0                                                        */
/*     far versions of stdlib.h functions                                    */
/* Copyright (c) 1996-2008 Texas Instruments Incorporated                    */
/*****************************************************************************/
#ifndef _STDLIBF
#define _STDLIBF

#ifndef __cplusplus
_CODE_ACCESS long          far_strtol (const far char *st, far char **endptr, 
				   int base);
_CODE_ACCESS unsigned long far_strtoul(const far char *st, far char **endptr, 
				   int base);
_CODE_ACCESS double        far_strtod (const far char *st, far char **endptr);
_CODE_ACCESS long double   far_strtold (const far char *st, far char **endptr);
_CODE_ACCESS long long     far_strtoll(const far char *st, far char **endptr, 
		 						    int base);
_CODE_ACCESS unsigned long long far_strtoull(const far char *st, 
                                                   far char **endptr, int base);
_CODE_ACCESS int           far_atoi(const far char *st);
_CODE_ACCESS long          far_atol(const far char *st);
_IDECL       double        far_atof(const far char *st);
_CODE_ACCESS long long     far_atoll(const far char *st);

_CODE_ACCESS far void     *far_calloc  (unsigned long num, unsigned long size);
_CODE_ACCESS far void     *far_malloc  (unsigned long size);
_CODE_ACCESS far void     *far_realloc (far void *ptr, unsigned long size);
_CODE_ACCESS void          far_free    (far void *ptr);

_CODE_ACCESS far void     *far_bsearch(const far void *key, 
                                       const far void *base, 
			               size_t nmemb, size_t size, 
			               int (*compar)(const far void *,
                                                     const far void *));
_CODE_ACCESS void          far_qsort  (far void *base, 
                                       size_t nmemb, size_t size,
			               int (*compar)(const far void *, 
                                                     const far void *));

_CODE_ACCESS int	   free_memory(void);
_CODE_ACCESS int           max_free(void);
_CODE_ACCESS void         *chkheap();

#ifdef _INLINE
static __inline double far_atof(const far char *st) 
{ 
   return far_strtod(st, NULL);
}
#endif /* _INLINE */

#else /* __cplusplus */

namespace std {

extern "C" int	       free_memory(void);
extern "C" int         max_free(void);
extern "C" void        *chkheap();

_CODE_ACCESS long      far_calloc  (unsigned long num, unsigned long size);
_CODE_ACCESS long      far_malloc  (unsigned long size);
_CODE_ACCESS long      far_realloc (long ptr, unsigned long size);
_CODE_ACCESS void      far_free    (long ptr);
_CODE_ACCESS long      far_free_memory(void);
_CODE_ACCESS long      far_max_free(void);
_CODE_ACCESS long      far_chkheap(void);

}
#endif /* __cplusplus */
#endif /* _STDLIBF */

#if defined(__cplusplus) && !defined(_CPP_STYLE_HEADER)
using std::free_memory; 
using std::max_free;
using std::chkheap;
using std::far_calloc;
using std::far_malloc;
using std::far_realloc;
using std::far_free;
using std::far_free_memory; 
using std::far_max_free;
using std::far_chkheap;
#endif /* _CPP_STYLE_HEADER */
