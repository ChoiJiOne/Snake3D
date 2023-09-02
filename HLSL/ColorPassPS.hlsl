struct PS_INPUT
{
    float4 Position : SV_Position;
    float4 Color : COLOR;
};

struct PS_OUTPUT
{
    float4 Color : SV_Target0;
};

PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output;
    
    output.Color = input.Color;
    
    return output;
}