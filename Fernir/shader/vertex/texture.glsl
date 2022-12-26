#version 410 core
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TextCord;

out vec2 v_TextCord;

uniform mat4 model;
uniform mat4 proj;

void main()
{
	gl_Position = proj * model * vec4(a_Position, 1.0);
	v_TextCord = a_TextCord;
}