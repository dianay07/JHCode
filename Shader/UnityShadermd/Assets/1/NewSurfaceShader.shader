﻿Shader "Custom/NewShader"
{
    Properties
    {
        _Red("Red", Range(0,1)) = 0
        _Green("Green", Range(0,1)) = 0
        _Blue("Blue", Range(0,1)) = 0
        _BrightDark ("Brightness $ Darkness", Range(-1,1)) = 0
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" }

        CGPROGRAM
        #pragma surface surf Standard fullforwardshadows

        struct Input
        {
            float4 color : COLOR;
        };

        float _Red;
        float _Green;
        float _Blue;
        float _BrightDark;

        void surf (Input IN, inout SurfaceOutputStandard o)
        {
            float4 test = float4(1, 0, 0, 1);

            o.Albedo = float3(_Red, _Green, _Blue) + _BrightDark;
            //o.Metallic = _Metallic;
            //o.Smoothness = _Glossiness;
            o.Alpha = 1;
        }
        ENDCG
    }
    FallBack "Diffuse"
}
