#version 410 core
in vec4 v_Color;

out vec4 FragColor;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	FragColor = v_Color;
}