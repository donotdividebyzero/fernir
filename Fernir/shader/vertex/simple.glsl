#version 410 core
layout(location = 0) in vec3 a_Position;

uniform mat4 proj;
uniform mat4 model;

void main()
{
	gl_Position = proj * model * vec4(a_Position, 1.0);
}