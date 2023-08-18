struct VS_INPUT
{
    float3 Position : POSITION;
    float4 Color : COLOR;
};

struct VS_OUTPUT
{
    float4 Position : SV_Position;
    float4 Color : COLOR;
};

cbuffer cbEveryFrame : register(b0)
{
    matrix world;
    matrix view;
    matrix projection;
}

VS_OUTPUT main(VS_INPUT input)
{
    VS_OUTPUT output;
    
    output.Position = mul(float4(input.Position, 1.0f), world);
    output.Position = mul(output.Position, view);
    output.Position = mul(output.Position, projection);
    
    output.Color = input.Color;
    
    return output;
}