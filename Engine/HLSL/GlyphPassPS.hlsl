struct PS_INPUT
{
    float4 position : SV_Position;
    float2 uv : TEXCOORD;
};

struct PS_OUTPUT
{
    float4 color : SV_Target0;
};

cbuffer cbTextColor : register(b0)
{
    float4 textColor;
}

Texture2D<float> glyphAltas : register(t0);
SamplerState linearSamplerState : register(s0);

PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output;
    
    float textAlpha = glyphAltas.Sample(linearSamplerState, input.uv);
    output.color = float4(textColor.r, textColor.g, textColor.b, textAlpha);
    
    return output;
}