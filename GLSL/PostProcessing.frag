#version 450 core

layout(location = 0) in vec2 inTexCoord;

layout(location = 0) out vec4 color;

uniform sampler2D screenFramebuffer;

uniform bool bEnableBlur;
uniform float blurBias;

void main()
{
	if(bEnableBlur)
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

        color = vec4(colorRGB, 1.0f);
	}
    else
    {
        color = texture(screenFramebuffer, inTexCoord);
    }
}