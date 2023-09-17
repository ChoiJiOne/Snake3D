#version 450 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;

layout(location = 0) out vec3 outWorldPosition;
layout(location = 1) out vec3 outNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(inPosition, 1.0f);

	outWorldPosition = vec3(model * vec4(inPosition, 1.0f));
	outNormal = mat3(transpose(inverse(model))) * inNormal;
}