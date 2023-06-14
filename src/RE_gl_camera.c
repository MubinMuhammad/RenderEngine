#include "RE_gl_camera.h"
#include "RE_linmath.h"

RE_camera RE_camera_create() {
  RE_camera camera;

  RE_mat4x4_identity(camera.view);
  RE_mat4x4_identity(camera.proj);

  camera.position[0] =  0.0f;
  camera.position[1] =  0.0f;
  camera.position[2] = -3.0f;

  return camera;
}

void RE_camera_start(RE_camera *camera, RE_shader *shader, f32 fov, f32 aspect_ratio, f32 near, f32 far, RE_vec3 position) {
  RE_mat4x4_translate(camera->view, position[0], position[1], position[2]);
  RE_mat4x4_perspective(camera->proj, fov, aspect_ratio, near, far);
  
  glUniformMatrix4fv(glGetUniformLocation(shader->shader_program, "RE_view"), 1, GL_FALSE, (f32 *)&camera->view[0][0]);
  glUniformMatrix4fv(glGetUniformLocation(shader->shader_program, "RE_proj"), 1, GL_FALSE, (f32 *)&camera->proj[0][0]);
}
