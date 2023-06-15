#include "RE_gl_window.h"

RE_window window;

static void RE_callback_frame_buffer_size(GLFWwindow *window_id, i32 width, i32 height) {
  window.size[0] = width;
  window.size[1] = height;
  glViewport(0, 0, width, height);
}

RE_window *RE_window_create(RE_ivec2 size, const i8 *title, RE_window_mode window_mode) {
  window.size[0] = size[0];
  window.size[1] = size[1];
  window.title = title;

  if (!glfwInit()) {
    printf("__RENDER_MASTER_ERROR: Failed To Init Glfw! \n");
    exit(-1);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  if (RE_WINDOW_NOT_RESIZABLE)
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
  #endif

  if (window_mode == RE_WINDOW_FULLSCREEN)
    window.id = glfwCreateWindow(size[0], size[1], title, glfwGetPrimaryMonitor(), NULL);
  else 
    window.id = glfwCreateWindow(size[0], size[1], title, NULL, NULL);

  glfwMakeContextCurrent(window.id);

  if (!window.id) {
    printf("__RENDER_MASTER_ERROR: Failed to create window!");
    glfwTerminate();
    exit(-1);
  }

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    printf("__RENDER_MASTER_ERROR: Failed to init OpenGL!");
    glfwTerminate();
    exit(-1);
  }

  
  glfwSetFramebufferSizeCallback(window.id, RE_callback_frame_buffer_size);
  
  return &window;
}

void RE_window_background_color(f32 r, f32 g, f32 b) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(r, g, b, 1.0f);
}

void RE_window_swap_frames(RE_window *window) {
  glfwSwapBuffers(window->id);
  glfwPollEvents();
}

void RE_window_terminate(RE_window *window) {
  glfwDestroyWindow(window->id);
  glfwTerminate();
}
