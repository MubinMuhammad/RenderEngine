#include "RE_timer.h"

void RE_timer_start(RE_timer *timer) {
  timer->current = glfwGetTime();
  timer->delta   = timer->current - timer->last;
  timer->last    = timer->current;
}
