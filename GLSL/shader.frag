#version 450 core

layout(location = 0) in vec3 outNormal;

layout(location = 0) out vec4 color;

void main()
{
	color = vec4(0.5f, 0.2f, 0.2f, 1.0f);
}