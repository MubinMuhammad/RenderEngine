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

  RE_shader shader;
  shader.vertex_shader = RE_shader_load_from_file("./shaders/shader.vert", RE_VERTEX_SHADER);
  shader.fragment_shader = RE_shader_load_from_file("./shaders/shader.frag", RE_FRAGMENT_SHADER);
  RE_shader_program_create(&shader);

  RE_object object = RE_object_create(vertices, sizeof(vertices), indices, sizeof(indices), true, false, 0);

  RE_RENDER_LOOP(window) {
    RE_window_background_color(0.8f, 0.8f, 0.6f);
    RE_object_render(object, shader);    
    RE_window_swap_frames(window);
  }

  RE_window_terminate(window);
  return 0;
}
