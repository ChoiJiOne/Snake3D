#version 450 core

layout(location = 0) in vec3 inWorldPosition;
layout(location = 1) in vec3 inNormal;

layout(location = 0) out vec4 color;

struct PointLight
{
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float specularPower;
};

uniform vec3 viewPosition;

uniform PointLight pointLight;
uniform Material material;

void main()
{
	// ambient
	vec3 ambient = pointLight.ambient * material.ambient;

	// diffuse
	vec3 norm = normalize(inNormal);
	vec3 lightDirection = normalize(pointLight.position - inWorldPosition);
	float diff = max(dot(norm, lightDirection), 0.0f);
	vec3 diffuse = pointLight.diffuse * (diff * material.diffuse);

	// specular
	vec3 viewDirection = normalize(viewPosition - inWorldPosition);
	vec3 reflectDirection = reflect(-lightDirection, norm);
	float spec = pow(max(dot(viewDirection, reflectDirection), 0.0f), material.specularPower);
	vec3 specular = pointLight.specular * (spec * material.specular);

	// attenuation
	float dist = length(pointLight.position - inWorldPosition);
	float attenuation = 1.0f / (pointLight.constant + pointLight.linear * dist + pointLight.quadratic * dist * dist);

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	vec3 colorRGB = ambient + diffuse + specular;
	color = vec4(colorRGB, 1.0f);
}