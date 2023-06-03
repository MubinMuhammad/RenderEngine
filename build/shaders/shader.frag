#version 330 core

out vec4 output_color;
in vec4 v_color;

void main() {
    output_color = vec4(v_color);
}
