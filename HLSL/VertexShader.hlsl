struct VS_INPUT
{
    float3 position : POSITION;
    float4 color : COLOR;
};

struct VS_OUTPUT
{
    float4 position : SV_Position;
    float4 color : COLOR;
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
    
    output.position = mul(float4(input.position, 1.0f), world);
    output.position = mul(output.position, view);
    output.position = mul(output.position, projection);
    
    output.color = input.color;
    
    return output;
}