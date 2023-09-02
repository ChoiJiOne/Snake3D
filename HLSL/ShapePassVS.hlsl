struct VS_INPUT
{
    float3 position : POSITION;
};

struct VS_OUTPUT
{
    float4 position : SV_Position;
};

cbuffer cbEveryFrame : register(b0)
{
    matrix view; // 2D 렌더링 수행할 경우 유닛(단위) 행렬로 설정
    matrix projection;
}

VS_OUTPUT main(VS_INPUT input)
{
    VS_OUTPUT output;
    
    output.position = mul(float4(input.position, 1.0f), view);
    output.position = mul(output.position, projection);
    
    return output;
}