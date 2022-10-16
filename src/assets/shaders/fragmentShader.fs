#version 330 core

in vec4 fColor;
in vec2 fTexCo;

out vec4 color;

uniform float uTime;
uniform sampler2D texture1;

void main() {
    color =    texture(texture1, fTexCo) * sin(uTime) * fColor;

}