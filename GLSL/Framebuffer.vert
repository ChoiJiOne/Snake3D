#version 450 core

layout(location = 0) in vec2 inPosition;
layout(location = 1) in vec2 inTexCoord;

layout(location = 0) out vec2 outTexCoord;

void main()
{
	gl_Position = vec4(inPosition, 0.0f, 1.0f);
	outTexCoord = inTexCoord;
}