#version 450 core

layout(location = 0) in vec2 inTexCoord;

layout(location = 0) out vec4 color;

uniform sampler2D screenFramebuffer;

uniform bool bEnableBlur;
uniform bool bEnableColorEffect;
uniform bool bEnableInversion;
uniform bool bEnableGrayScale;

uniform float blurBias;
uniform float redBias;
uniform float greenBias;
uniform float blueBias;

vec4 CalculateBlurEffect();
vec4 CalculateColorEffect();
vec4 CalculateInversionEffect();
vec4 CalculateGrayScaleEffect();

void main()
{
	if(bEnableBlur)
	{
        color = CalculateBlurEffect();
	}
    else if(bEnableColorEffect)
    {
        color = CalculateColorEffect();
    }
    else if(bEnableInversion)
    {
        color = CalculateInversionEffect();
    }
    else if(bEnableGrayScale)
    {
        color = CalculateGrayScaleEffect();
    }
    else
    {
        color = texture(screenFramebuffer, inTexCoord);
    }
}

vec4 CalculateBlurEffect()
{
    float offset = 1.0f / blurBias;

	vec2 offsets[9] = vec2[](
        vec2(-offset,  offset), // top-left
        vec2( 0.0f,    offset), // top-center
        vec2( offset,  offset), // top-right
        vec2(-offset,  0.0f),   // center-left
        vec2( 0.0f,    0.0f),   // center-center
        vec2( offset,  0.0f),   // center-right
        vec2(-offset, -offset), // bottom-left
        vec2( 0.0f,   -offset), // bottom-center
        vec2( offset, -offset)  // bottom-right
    );

    float kernel[9] = float[](
        1.0 / 16.0f, 2.0 / 16.0f, 1.0 / 16.0f,
        2.0 / 16.0f, 4.0 / 16.0f, 2.0 / 16.0f,
        1.0 / 16.0f, 2.0 / 16.0f, 1.0 / 16.0f
    );

    vec3 sampleRGB[9];
    for(int i = 0; i < 9; i++)
    {
        sampleRGB[i] = texture(screenFramebuffer, inTexCoord.st + offsets[i]).rgb;
    }

    vec3 colorRGB = vec3(0.0);
    for(int i = 0; i < 9; i++)
    {
        colorRGB += sampleRGB[i] * kernel[i];
    }

    return vec4(colorRGB, 1.0f);
}

vec4 CalculateColorEffect()
{
    vec4 colorRGBA = texture(screenFramebuffer, inTexCoord);
    return vec4(redBias * colorRGBA.r, greenBias * colorRGBA.g, blueBias * colorRGBA.b, colorRGBA.a);
}

vec4 CalculateInversionEffect()
{
    vec4 colorRGBA = texture(screenFramebuffer, inTexCoord);
    vec3 inversionRGB = 1.0f - colorRGBA.rgb;
    return vec4(inversionRGB, colorRGBA.a);
}

vec4 CalculateGrayScaleEffect()
{
    vec4 colorRGBA = texture(screenFramebuffer, inTexCoord);
    float scale = (0.2126f * colorRGBA.r + 0.7152f * colorRGBA.g + 0.0722f * colorRGBA.b);
    return  vec4(scale, scale, scale, colorRGBA.a);
}