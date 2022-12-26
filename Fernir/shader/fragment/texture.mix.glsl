#version 410 core
in vec2 v_TextCord;

out vec4 FragColor;

uniform sampler2D m_Texture0;
uniform sampler2D m_Texture1;

void main()
{
	FragColor = mix(texture(m_Texture1, v_TextCord), texture(m_Texture0, v_TextCord), 0.6);
}