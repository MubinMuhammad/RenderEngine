#include "RE_gl_camera.h"
#define RE_API_GL
#include "RE.h"

int main() {
  RE_window *window = RE_window_create((RE_ivec2){600, 400},"OpenGL", RE_WINDOW_RESIZABLE);
  
  float vertices[7 * 4] = {
    -0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f, 
    -0.5f,-0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f, 
     0.5f,-0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f, 
     0.5f, 0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f
  };

  uint8_t indices[2 * 3] = {
    0, 1, 2, 
    0, 3, 2
  };

  RE_camera camera = RE_camera_create();

  RE_shader shader;
  shader.vertex_shader = RE_shader_load_from_file("./shaders/square.vert", RE_VERTEX_SHADER);
  shader.fragment_shader = RE_shader_load_from_file("./shaders/square.frag", RE_FRAGMENT_SHADER);
  RE_shader_program_create(&shader);

  RE_object object = RE_object_create(vertices, sizeof(vertices), indices, sizeof(indices), true, false, 0);

  RE_RENDER_LOOP(window) {
    RE_window_background_color(0.8f, 0.8f, 0.6f);
    RE_camera_start(&camera, &shader, 90.0f, (float)window->size[0] / (float)window->size[1], 0.0f, 100.0f, (RE_vec3){0.0f, 0.0f, -3.0f});
    RE_object_render(object, shader);    
    RE_window_swap_frames(window);
  }

  RE_window_terminate(window);
  return 0;
}
