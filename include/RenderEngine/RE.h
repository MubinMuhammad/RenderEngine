#ifndef RE_H
#define RE_H

#ifdef RE_API_GL
  #include "RE_gl_window.h"
  #include "RE_gl_shader.h"
  #include "RE_gl_object.h"
  #include "RE_gl_camera.h"
  #include "RE_gl_texture.h"
  #include "RE_types.h"
  #include "RE_timer.h"
#elif RE_API_VULKAN
#elif RE_API_DIRECTX
#endif

#endif
