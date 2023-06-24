#ifndef RE_OBJECT_H
#define RE_OBJECT_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "RE_types.h"
#include "RE_gl_shader.h"
#include "RE_gl_texture.h"

typedef struct RE_object {
  u32 vao;
  u32 indices_size;
  u32 vertices_size;
  const char *shader_code;
} RE_object;

RE_object RE_object_create(f32 *vertices, u64 vertices_size, u8 *indices, 
                           u64 indices_size, bool is_colors, bool is_textures,  
                           u16 shader_layout_location);

void RE_object_render(RE_object object, RE_shader shader);

void RE_object_render_with_t(RE_object object, RE_shader shader, 
                             RE_texture texture, int texture_slot, 
                             const char *texture_name);

void RE_object_move(RE_shader shader, float x, float y, float z);
void RE_object_rotate();
void RE_object_terminate(RE_object *object);

#endif
