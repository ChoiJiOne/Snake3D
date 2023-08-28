struct PS_INPUT
{
    float4 position : SV_Position;
};

struct PS_OUTPUT
{
    float4 color : SV_Target0;
};

cbuffer cbColorMaterial : register(b0)
{
    float4 color;
}

PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output;
    
    output.color = color;
    
    return output;
}