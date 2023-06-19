/*
  Using OpenGL as the API for graphics.
  Other APIs are not available right now. As there is no Implementation
  for Vulkan, DirectX etc. The Implementations will be written soon.
  OpenGL is also not finished.
  But it is usable!

  You can use the OpenGL API using '#define RE_API_GL'
  That might change soon.
*/

#define RE_API_GL
// Including the RE header file (the main header file).
#include "RE.h"

int main() {
  // Creating a window
  RE_window *window = RE_window_create((RE_ivec2){600, 400},"OpenGL", RE_WINDOW_RESIZABLE);
  
  // Having vertices for a square.
  float square_vertices[7 * 4] = {
    -200.0f, 200.0f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f, 
    -200.0f,-200.0f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f, 
     200.0f,-200.0f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f, 
     200.0f, 200.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f
  };

  // Having indices for the square.
  uint8_t square_indices[2 * 3] = {
    0, 1, 2, 
    0, 3, 2
  };

  // Creating a camera.
  RE_camera camera = RE_camera_create();

  // Loading the GLSL (may create a new shading language) shader for the square.
  // You have to run the program where the shaders
  // folder is located.
  RE_shader square_shader;
  square_shader.vertex_shader = RE_shader_load_from_file("./shaders/square.vert", RE_VERTEX_SHADER);
  square_shader.fragment_shader = RE_shader_load_from_file("./shaders/square.frag", RE_FRAGMENT_SHADER);
  RE_shader_program_create(&square_shader);

  // Creating a square object.
  RE_object square = RE_object_create(square_vertices, sizeof(square_vertices), square_indices, sizeof(square_indices), true, false, 0);


  RE_RENDER_LOOP(window) {
    // Setting a backround color.
    RE_window_background_color(0.8f, 0.8f, 0.6f);

    // Starting a 2d camera with orthographic projection.
    // (It makes it so that window's left, right, top, bottom are normalized with window's
    // width and height. By default OpenGL will set it to -1.0f, 1.0f range.)
    RE_camera_2d_start(&camera, &square_shader, -window->size[0], window->size[0], -window->size[1], window->size[1], -1.0f, 1.0f);

    // Setting a position for that square.
    RE_object_move(square_shader, 0.0f, 0.0f, 0.0f);
    // Rendering that square.
    RE_object_render(square, square_shader);

    // Swapping the front frame with the back.
    RE_window_swap_frames(window);
  }

  // Closing the window.
  RE_window_terminate(window);

  // Closing the Application.
  return 0;
}
