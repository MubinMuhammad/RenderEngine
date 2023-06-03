#ifndef RE_UTILS_H
#define RE_UTILS_H

#include "RE_types.h"

#define RE_max(a, b) a > b ? a : b
#define RE_min(a, b) a > b ? b : a

i32 RE_array_sum_i32(i32 *array, i32 size);

#endif
