#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 color;

uniform mat4 RE_proj;
uniform mat4 RE_model;

out vec4 v_color;

void main() {
  gl_Position = RE_proj * RE_model * vec4(pos, 1.0f);
  v_color = color;
}
