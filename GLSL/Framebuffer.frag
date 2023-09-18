#version 450 core

layout(location = 0) in vec2 inTexCoord;

layout(location = 0) out vec4 color;

uniform sampler2D screenFramebuffer;

void main()
{
	color = texture(screenFramebuffer, inTexCoord);
}