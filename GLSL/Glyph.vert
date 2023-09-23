#version 450 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec2 inTexCoord;

layout(location = 0) out vec2 outTexCoord;

uniform mat4 projection;

void main()
{
	gl_Position = projection * vec4(inPosition, 1.0f);
	outTexCoord = inTexCoord;
}