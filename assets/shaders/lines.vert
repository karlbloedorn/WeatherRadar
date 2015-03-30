#version 330 core

in vec3 in_Position;

uniform mat4 projectionMatrix;

void main(void) {
	gl_Position = projectionMatrix * vec4(in_Position, 1.0);
}