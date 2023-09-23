#version 450 core

layout(location = 0) in vec2 inTexCoord;

layout(location = 0) out vec4 color;

uniform sampler2D glyphAtlas;
uniform vec3 glyphColor;

void main()
{
	float alpha = texture(glyphAtlas, inTexCoord).r;
	color = vec4(glyphColor.rgb, alpha);
}