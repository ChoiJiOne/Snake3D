#version 450 core

layout(location = 0) in vec3 inWorldPosition;
layout(location = 1) in vec3 inNormal;

layout(location = 0) out vec4 color;

struct DirectionalLight
{
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	vec3 direction;
};

struct Material
{
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	float specularPower;
};

uniform vec3 viewPosition;

uniform DirectionalLight directionalLight;
uniform Material material;

void main()
{
	// ambient
	vec4 ambient = directionalLight.ambient * material.ambient;

	// diffuse
	vec3 norm = normalize(inNormal);
	vec3 lightDirection = normalize(-directionalLight.direction);
	float diff = max(dot(norm, lightDirection), 0.0f);
	vec4 diffuse = directionalLight.diffuse * (diff * material.diffuse);

	// specular
	vec3 viewDirection = normalize(viewPosition - inWorldPosition);
	vec3 reflectDirection = reflect(-lightDirection, norm);
	float spec = pow(max(dot(viewDirection, reflectDirection), 0.0f), material.specularPower);
	vec4 specular = directionalLight.specular * (spec * material.specular);

	color = ambient + diffuse + specular;
}