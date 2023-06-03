#ifndef RE_SHADER_H
#define RE_SHADER_H

#include "glad/glad.h"
#include "RE_types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum RE_shader_type {
  RE_VERTEX_SHADER,
  RE_FRAGMENT_SHADER
  
} RE_shader_type;

typedef struct RE_shader {
  u32 vertex_shader;
  u32 fragment_shader;
  u32 shader_program;
  
} RE_shader;

u32 RE_shader_load_from_file(const char *file_path, RE_shader_type shader_type);
u32 RE_shader_load_from_code(const char *shader_code, RE_shader_type shader_type);
void RE_shader_program_create(RE_shader *shader);


#endif
