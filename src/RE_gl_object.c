#include "RE_gl_object.h"

RE_object RE_object_create(
  f32 *vertices,
  u64 vertices_size,
  u8 *indices,
  u64 indices_size,
  bool is_colors, 
  bool is_textures, 
  u16 shader_layout_location
) {
	RE_object object;
	object.indices_size = indices_size;
	object.vertices_size = vertices_size;

	u32 vbo;
	u32 ebo;

  int stride = 0;

  if (is_colors == false && is_textures == false)
    stride = 3;
  else if (is_colors == false && is_textures == true )
    stride = 5;
  else if (is_colors == true  && is_textures == false)
    stride = 7;
  else if (is_colors == true  && is_textures == true )
    stride = 9;

	glGenVertexArrays(1, &object.vao);
	glBindVertexArray(object.vao);

	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_size, indices, GL_STATIC_DRAW);


	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glEnableVertexAttribArray(shader_layout_location);
	glVertexAttribPointer(shader_layout_location, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)0);
  if (is_colors) {
	  glEnableVertexAttribArray(shader_layout_location + 1);
	  glVertexAttribPointer(shader_layout_location + 1, 4, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(3 * sizeof(f32)));
  }
  if (is_textures) {
	  glEnableVertexAttribArray(shader_layout_location + 2);

    if (!is_colors)
	    glVertexAttribPointer(shader_layout_location + 2, 2, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(3 * sizeof(f32)));
    else if (is_colors)
	    glVertexAttribPointer(shader_layout_location + 2, 2, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(7 * sizeof(f32)));
  }

	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	

	return object;
}

void RE_object_render(RE_object object, RE_shader shader) {
	glBindVertexArray(object.vao);
	glUseProgram(shader.shader_program);
	glDrawElements(GL_TRIANGLES, object.indices_size, GL_UNSIGNED_BYTE, 0);
}

