#version 410 core
in vec2 v_TextCord;

out vec4 FragColor;

uniform sampler2D m_Texture0;

void main()
{
	FragColor = texture(m_Texture0, v_TextCord);
}