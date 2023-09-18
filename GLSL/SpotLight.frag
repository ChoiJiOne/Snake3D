#version 450 core

layout(location = 0) in vec3 inWorldPosition;
layout(location = 1) in vec3 inNormal;

layout(location = 0) out vec4 color;

struct SpotLight
{
	vec3 position;
	vec3 direction;

	float innerCutOff;
	float outerCutOff;

	vec4 ambient;
	vec4 diffuse;
	vec4 specular;

	float constant;
	float linear;
	float quadratic;
};

struct Material
{
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	float specularPower;
};

uniform vec3 viewPosition;

uniform SpotLight spotLight;
uniform Material material;

void main()
{
	// ambient
	vec4 ambient = spotLight.ambient * material.ambient;

	// diffuse
	vec3 norm = normalize(inNormal);
	vec3 lightDirection = normalize(spotLight.position - inWorldPosition);
	float diff = max(dot(norm, lightDirection), 0.0f);
	vec4 diffuse = spotLight.diffuse * (diff * material.diffuse);

	// specular
	vec3 viewDirection = normalize(viewPosition - inWorldPosition);
	vec3 reflectDirection = reflect(-lightDirection, norm);
	float spec = pow(max(dot(viewDirection, reflectDirection), 0.0f), material.specularPower);
	vec4 specular = spotLight.specular * (spec * material.specular);

	// intensity
	float theta = dot(lightDirection, -spotLight.direction);
	float epsilon = (spotLight.innerCutOff - spotLight.outerCutOff);
	float intensity = clamp((theta - spotLight.outerCutOff) / epsilon, 0.0f, 1.0f);

	// attenuation
	float dist = length(spotLight.position - inWorldPosition);
	float attenuation = 1.0f / (spotLight.constant + spotLight.linear * dist + spotLight.quadratic * dist * dist);

	ambient *= attenuation;
	diffuse *= (intensity * attenuation);
	specular *= (intensity * attenuation);

	color = ambient + diffuse + specular;
}