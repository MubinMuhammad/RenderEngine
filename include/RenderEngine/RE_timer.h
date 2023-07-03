#ifndef RE_TIMER_H
#define RE_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <GLFW/glfw3.h>
#include "RE_types.h"

typedef struct RE_timer {
  f32 current;
  f32 last;
  f32 delta;

} RE_timer;

void RE_timer_start(RE_timer *timer);

#ifdef __cplusplus
}
#endif

#endif
