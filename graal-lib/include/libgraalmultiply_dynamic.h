#ifndef __LIBGRAALMULTIPLY_H
#define __LIBGRAALMULTIPLY_H

#include <graal_isolate_dynamic.h>


#if defined(__cplusplus)
extern "C" {
#endif

typedef int (*graal_multiply_fn_t)(graal_isolatethread_t*, int, int);

#if defined(__cplusplus)
}
#endif
#endif
