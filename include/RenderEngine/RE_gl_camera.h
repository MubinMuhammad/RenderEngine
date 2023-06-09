#ifndef RE_CAMERA_H
#define RE_CAMERA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "glad/glad.h"

#include <GLFW/glfw3.h>
#include <stdlib.h>

#include "RE_types.h"
#include "RE_linmath.h"
#include "RE_gl_shader.h"

typedef struct RE_camera {
  RE_mat4x4 view;
  RE_mat4x4 proj;
  
  RE_vec3 position;

  f32 fov;
  f32 aspect_ratio;
  f32 near;
  f32 far;

} RE_camera;

RE_camera RE_camera_create();
void      RE_camera_3d_start(RE_camera *camera, RE_shader *shader);
void      RE_camera_2d_start(RE_camera *camera, RE_shader *shader, float left, float right, float bottom, float top, float near, float far); 

#ifdef __cplusplus
}
#endif

#endif
