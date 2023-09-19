#version 450 core

layout(location = 0) in vec3 inPosition;

layout(location = 0) out vec3 outTexCoord;

uniform mat4 projection;
uniform mat4 view;

void main()
{
	vec4 ndcPosition = projection * view * vec4(inPosition, 1.0f);

	gl_Position = ndcPosition.xyww;

	outTexCoord = inPosition;
}