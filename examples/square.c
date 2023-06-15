#define RE_API_GL
#include "RE.h"

int main() {
  RE_window *window = RE_window_create((RE_ivec2){600, 400},"OpenGL", RE_WINDOW_RESIZABLE);
  
  float square_vertices[7 * 4] = {
    -0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f, 
    -0.5f,-0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f, 
     0.5f,-0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f, 
     0.5f, 0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f
  };

  uint8_t square_indices[2 * 3] = {
    0, 1, 2, 
    0, 3, 2
  };

  float tri_vertices[3 * 3] = {
     0.5f, 0.5f, 0.0f,
    -0.5f,-0.5f, 0.0f,
     0.5f,-0.5f, 0.0f,
  };

  uint8_t tri_indices[3] = {
    0, 1, 2 
  };

  RE_camera camera = RE_camera_create();

  RE_shader square_shader;
  square_shader.vertex_shader = RE_shader_load_from_file("./shaders/square.vert", RE_VERTEX_SHADER);
  square_shader.fragment_shader = RE_shader_load_from_file("./shaders/square.frag", RE_FRAGMENT_SHADER);
  RE_shader_program_create(&square_shader);
  RE_shader triangle_shader;
  triangle_shader.vertex_shader = RE_shader_load_from_file("./shaders/triangle.vert", RE_VERTEX_SHADER);
  triangle_shader.fragment_shader = RE_shader_load_from_file("./shaders/triangle.frag", RE_FRAGMENT_SHADER);
  RE_shader_program_create(&triangle_shader);

  RE_object square = RE_object_create(square_vertices, sizeof(square_vertices), square_indices, sizeof(square_indices), true, false, 0);
  RE_object triangle = RE_object_create(tri_vertices, sizeof(tri_vertices), tri_indices, sizeof(tri_indices), false, false, 0);

  RE_RENDER_LOOP(window) {
    RE_window_background_color(0.8f, 0.8f, 0.6f);

    camera.fov  = 90.0f;
    camera.aspect_ratio = (float)window->size[0] / (float)window->size[1];
    camera.near = 0.0f;
    camera.far  = 100.0f;
    RE_camera_start(&camera, &shader);

    RE_object_render(square, square_shader);
    RE_object_render(triangle, triangle_shader);
    RE_window_swap_frames(window);

    if (glfwGetKey(window->id, GLFW_KEY_W) == GLFW_PRESS) camera.position[1] -= 0.025f;
    if (glfwGetKey(window->id, GLFW_KEY_S) == GLFW_PRESS) camera.position[1] += 0.025f;
    if (glfwGetKey(window->id, GLFW_KEY_D) == GLFW_PRESS) camera.position[0] -= 0.025f;
    if (glfwGetKey(window->id, GLFW_KEY_A) == GLFW_PRESS) camera.position[0] += 0.025f;
  }

  RE_window_terminate(window);
  return 0;
}
