#ifndef __TYPES_H__
#define __TYPES_H__

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)   /* C99 */
#include <stdint.h>

typedef uint16_t color_t;

#else

typedef unsigned short        color_t;

#endif

#endif // __TYPES_H__
