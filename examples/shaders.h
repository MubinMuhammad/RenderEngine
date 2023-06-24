#ifndef SHADERS_H
#define SHADERS_H

const char *square_vertex_shader = 
"#version 330 core \n"

"layout(location = 0) in vec3 pos; \n"
"layout(location = 1) in vec4 color; \n"

"uniform mat4 RE_proj; \n"
"uniform mat4 RE_model; \n"

"out vec4 v_color; \n"

"void main() { \n"
"  gl_Position = RE_proj * RE_model * vec4(pos, 1.0f); \n"
"  v_color = color; \n"
"} \0"
;

const char *square_fragment_shader = 
"#version 330 core \n"

"out vec4 out_color; \n"
"in vec4 v_color; \n"

"void main() { \n"
"  out_color = vec4(v_color); \n"
"} \0"
;

const char *texture_vertex_shader = 
"#version 330 core \n"

"layout(location = 0) in vec3 pos; \n"
"layout(location = 1) in vec2 texture_coord; \n"

"uniform mat4 RE_proj; \n"
"uniform mat4 RE_model; \n"

"out vec2 v_texture_coord; \n"

"void main() { \n"
"  gl_Position = RE_proj * RE_model * vec4(pos, 1.0f); \n"
"  v_texture_coord = texture_coord; \n"
"} \0"
;

const char *texture_fragment_shader = 
"#version 330 core \n"

"out vec4 out_color; \n"
"in vec2 v_texture_coord; \n"

"uniform sample2D image; \n"

"void main() { \n"
"  out_color = texture(image, v_texture_coord); \n"
"} \0"
;

#endif
