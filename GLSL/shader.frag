#version 450 core

layout(location = 0) in vec3 inWorldPosition;
layout(location = 1) in vec3 inNormal;

layout(location = 0) out vec4 color;

struct Material
{
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	float specularPower;
};

uniform vec3 lightPosition;
uniform vec4 lightColor;
uniform vec3 viewPosition;
uniform Material material;

void main()
{
	// ambient
	vec4 ambient = lightColor * material.ambient;

	// diffuse
	vec3 norm = normalize(inNormal);
	vec3 lightDirection = normalize(lightPosition - inWorldPosition);
	float diff = max(dot(norm, lightDirection), 0.0f);
	vec4 diffuse = lightColor * (diff * material.diffuse);

	// specular
	vec3 viewDirection = normalize(viewPosition - inWorldPosition);
	vec3 reflectDirection = reflect(-lightDirection, norm);
	float spec = pow(max(dot(viewDirection, reflectDirection), 0.0f), material.specularPower);
	vec4 specular = lightColor * (spec * material.specular);

	color = ambient + diffuse + specular;
}