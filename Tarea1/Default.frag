#version 330

in vec3 InterpolatedColor;

out vec4 FragColor;

uniform vec2 Resolution;

void main(){

	FragColor = vec4(InterpolatedColor, 1.0f);
	}