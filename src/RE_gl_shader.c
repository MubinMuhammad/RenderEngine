#include "RE_gl_shader.h"

u64 RE_file_get_size(const i8 *file_path) {
  FILE *fp = fopen(file_path, "r");

  if (!fp) {
    return (u64)NULL;
  }
  fseek(fp, 0, SEEK_END);
  u64 file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  return file_size + 1;
}

void RE_file_get_contents(const i8 *file_path, i8 *file_contents, u64 file_size) {
  memset((void*)file_contents, '\0', file_size);

  FILE *fp = fopen(file_path, "r");
  if (!fp) {
    file_contents = NULL;
  }
  else {
    fread((void*)file_contents, file_size - 1, sizeof(i8), fp);
  }
}

u32 RE_shader_load_from_file(const i8 *file_path, RE_shader_type shader_type) {
  u64 file_size = RE_file_get_size(file_path);
  i8 file_contents[file_size];
  RE_file_get_contents(file_path, file_contents, file_size);

  if (file_size == (u64)NULL) {
    printf("__RENDER_ENGINE_ERROR: Invalid shader path or error in shader!");
    exit(-1);
  }

  u32 shader;

  if (shader_type == RE_VERTEX_SHADER)
    shader = glCreateShader(GL_VERTEX_SHADER);
  if (shader_type == RE_FRAGMENT_SHADER)
    shader = glCreateShader(GL_FRAGMENT_SHADER);

  const char *file_contents_usable = file_contents;

  glShaderSource(shader, 1, &file_contents_usable, NULL);
  glCompileShader(shader);

  int shader_status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_status);

  if (shader_status == GL_FALSE) {
    int err_length;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &err_length);

    char err[err_length];
    glGetShaderInfoLog(shader, err_length, &err_length, err);

    printf("Failed to compile %s shader %s", 
           shader_type == RE_VERTEX_SHADER ? "vertex" : 
           shader_type == RE_FRAGMENT_SHADER ? "fragment" : 0,
           err);

    exit(-1);
  }

  return shader;
}

u32 RE_shader_load_from_code(const i8 *shader_code, RE_shader_type shader_type) {
  u32 shader;

  if (shader_type == RE_VERTEX_SHADER)
    shader = glCreateShader(GL_VERTEX_SHADER);
  if (shader_type == RE_FRAGMENT_SHADER)
    shader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(shader, 1, &shader_code, NULL);
  glCompileShader(shader);

  int shader_status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_status);

  if (shader_status == GL_FALSE) {
    int err_length;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &err_length);

    char err[err_length];
    glGetShaderInfoLog(shader, err_length, &err_length, err);

    printf("__RENDER_ENGINE_%s_SHADER_ERROR: %s", 
           shader_type == RE_VERTEX_SHADER ? "VERTEX" : 
           shader_type == RE_FRAGMENT_SHADER ? "FRAGMENT" : 0,
           err);

    exit(-1);
  }

  return shader;
}

void RE_shader_program_create(RE_shader *shader) {
  shader->shader_program = glCreateProgram();

  glAttachShader(shader->shader_program, shader->vertex_shader);
  glAttachShader(shader->shader_program, shader->fragment_shader);

  glLinkProgram(shader->shader_program);
  glDeleteShader(shader->vertex_shader);
  glDeleteShader(shader->fragment_shader);
}

void RE_shader_terminate(RE_shader *shader) {
  glDeleteShader(shader->shader_program);
}
