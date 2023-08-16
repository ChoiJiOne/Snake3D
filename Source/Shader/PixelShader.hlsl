struct PS_INPUT
{
    float4 Position : SV_Position;
};

struct PS_OUTPUT
{
    float4 Color : SV_Target0;
};

PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output;
    
    output.Color = float4(1.0f, 1.0f, 0.0f, 1.0f);
    
    return output;
}