#version 450 core

layout(location = 0) in vec3 inTexCoord;

layout(location = 0) out vec4 color;

uniform samplerCube skybox;

void main()
{
	color = texture(skybox, inTexCoord);
}