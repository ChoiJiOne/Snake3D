#version 450 core

layout(location = 0) in vec3 inWorldPosition;
layout(location = 1) in vec3 inNormal;

layout(location = 0) out vec4 color;

struct DirectionalLight
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	vec3 direction;
};

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float specularPower;
};

uniform vec3 viewPosition;

uniform DirectionalLight directionalLight;
uniform Material material;

void main()
{
	// ambient
	vec3 ambient = directionalLight.ambient * material.ambient;

	// diffuse
	vec3 norm = normalize(inNormal);
	vec3 lightDirection = normalize(-directionalLight.direction);
	float diff = max(dot(norm, lightDirection), 0.0f);
	vec3 diffuse = directionalLight.diffuse * (diff * material.diffuse);

	// specular
	vec3 viewDirection = normalize(viewPosition - inWorldPosition);
	vec3 reflectDirection = reflect(-lightDirection, norm);
	float spec = pow(max(dot(viewDirection, reflectDirection), 0.0f), material.specularPower);
	vec3 specular = directionalLight.specular * (spec * material.specular);

	vec3 colorRGB = ambient + diffuse + specular;
	color = vec4(colorRGB, 1.0f);
}