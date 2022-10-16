#version 330 core

in vec4 fColor;
out vec4 color;

uniform float uTime;

void main() {
    color = sin(uTime) * fColor;

}