#ifndef RE_WINDOW_H
#define RE_WINDOW_H

#include "glad/glad.h"
#include "RE_types.h"

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#define RE_RENDER_LOOP(window) while (!glfwWindowShouldClose(window->id))

typedef enum RE_window_mode {
  RE_WINDOW_RESIZABLE,
  RE_WINDOW_NOT_RESIZABLE,
  RE_WINDOW_FULLSCREEN

}  RE_window_mode;

typedef struct RE_window {
  GLFWwindow *id;
  RE_ivec2 size;
  const char *title;

} RE_window;

RE_window *RE_window_create(RE_ivec2 size, const i8 *title, RE_window_mode window_mode); 
void RE_window_background_color(f32 r, f32 g, f32 b); 
void RE_window_terminate(RE_window *window);
void RE_window_swap_frames(RE_window *window);

#endif
