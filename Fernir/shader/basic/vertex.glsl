#version 410 core
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;

out vec4 v_Color;

uniform mat4 model;
// uniform mat4 view;
uniform mat4 proj;

void main()
{
	gl_Position = proj * model * vec4(a_Position, 1.0);
	v_Color = a_Color;
}