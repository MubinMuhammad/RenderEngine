/*
  Using OpenGL as the API for graphics.
  Other APIs are not available right now. As there is no Implementation
  for Vulkan, DirectX etc. The Implementations will be written soon.
  OpenGL is also not finished.
  But it is usable!

  You can use the OpenGL API using '#define RE_API_GL'.
  That might change soon.
*/

#define RE_API_GL
// Including the RE header file (the main header file).
#include "RE.h"
// Including the shaders for the texture.
#include "shaders.h"

int main() {
  // Creating a window.
  RE_window *window = RE_window_create(600, 400, "RenderEngine", RE_WINDOW_RESIZABLE);
  
  // loading a texture of a field.
  RE_texture texture = RE_texture_create("example.jpg", RE_TEXTURE_JPG);

  // Normalizing the texture's width and height to window's width and height;
  int texture_width_normalized = texture.width;
  int texture_height_normalized = texture.height;
  while (texture_width_normalized > window->width && texture_height_normalized > window->height) {
    texture_width_normalized /= 2;
    texture_height_normalized /= 2;
  }
  
  // Having vertices for a quad to applay the texture on.
  float quad_vertices[5 * 4] = {
    -texture_width_normalized, texture_height_normalized, 0.0f,    0.0f, 1.0f, 
    -texture_width_normalized,-texture_height_normalized, 0.0f,    0.0f, 0.0f, 
     texture_width_normalized,-texture_height_normalized, 0.0f,    1.0f, 0.0f, 
     texture_width_normalized, texture_height_normalized, 0.0f,    1.0f, 1.0f 
  };

  // Having indices for the quad.
  uint8_t quad_indices[2 * 3] = {
    0, 1, 2, 
    0, 3, 2
  };

  // Creating a camera.
  RE_camera camera = RE_camera_create();
  // Loading the GLSL (may create a new shading language) shader for the quad. 
  // You have to run the program where the shaders
  // folder is located.
  RE_shader quad_shader;
  quad_shader.vertex_shader = RE_shader_load_from_code(texture_vertex_shader, RE_VERTEX_SHADER);
  quad_shader.fragment_shader = RE_shader_load_from_code(texture_fragment_shader, RE_FRAGMENT_SHADER);
  RE_shader_program_create(&quad_shader);

  // Creating a quad object.
  RE_object quad = RE_object_create(quad_vertices, sizeof(quad_vertices), quad_indices, 
                                    sizeof(quad_indices), false, true, 0);


  RE_RENDER_LOOP(window) {
    // Setting a backround color.
    RE_window_background_color(0.8f, 0.8f, 0.6f);

    // Starting a 2d camera with orthographic projection.
    // (It makes it so that window's left, right, top, bottom are normalized with window's
    // width and height. By default OpenGL will set it to -1.0f, 1.0f range.)
    RE_camera_2d_start(&camera, &quad_shader, -window->width, window->width, 
                       -window->height, window->height, -1.0f, 1.0f);

    // Setting a position for that quad.
    RE_object_move(quad_shader, 0.0f, 0.0f, 0.0f);
    // Rendering that quad.
    RE_object_render_with_t(quad, quad_shader, texture, 0, "image");

    // Swapping the front frame with the back.
    RE_window_swap_frames(window);
  }

  // Closing the shader.
  RE_shader_terminate(&quad_shader);
  // Closing the object.
  RE_object_terminate(&quad);
  // Deleting the texture.
  RE_texture_terminate(&texture);
  // Closing the window.
  RE_window_terminate(window);

  // Closing the Application.
  return 0;
}
