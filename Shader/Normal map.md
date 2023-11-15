Normalmap
==========

> 1) 노말맵
----------
- 실제 디테일이 없는 부분을 디테일이 있는 것처럼 보이게 만들기 위한 눈속임 맵
- 일반적으로 푸른색을 띄고 빛을 속여 다수의 폴리곤으로 이루어진것처럼 보이게 하기 위한 벡터 데이터들로 이루어진 텍스쳐 파일

> 2) .Shader 코드
------------
```c#
Shader "Custom/normalmap"
{
    Properties
    {
        _MainTex("Albedo (RGB)", 2D) = "white" {}
        _Metallic("Metallic", Range(0,1)) = 0.0
        _Smoothness("Smoothness", Range(0,1)) = 0.5
        _BumpMap("Normalmap", 2D) = "bump"{}
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" }
        LOD 200

        CGPROGRAM
        // Physically based Standard lighting model, and enable shadows on all light types
        #pragma surface surf Standard fullforwardshadows

        sampler2D _MainTex;
        sampler2D _BumpMap;
        float _Metallic;
        float _Smoothness;

        struct Input
        {
            float2 uv_MainTex;
            float2 uv_BumpMap;
        };

        void surf (Input IN, inout SurfaceOutputStandard o)
        {
            fixed4 c = tex2D (_MainTex, IN.uv_MainTex);
            // x와 y에 특정 수를 더해주면 NormalMap의 강도 조절이 가능
            fixed3 n = UnpackNormal(tex2D(_BumpMap, IN.uv_BumpMap));
            o.Normal = float3(n.x * 2, n.y * 2, n.z);
            o.Albedo = c.rgb;
            o.Metallic = _Metallic;
            o.Alpha = c.a;
        }
        ENDCG
    }
    FallBack "Diffuse"
}
```

> 3) UnpackNormal 함수
----------------------
- Normalmap의 파일 포맷은 일반적인 텍스처의 압축에 의한 NormalMap품질의 저하를 막기위해 만든 AG 포맷이라 따로 함수를 적용함
- Normalmap의 Rrhk G의 퀄리티를 최대한 A와 G에 넣어 저장해 보전하고 이것을 X와 Y로 계산해 Z는 삼각함수를 이용해 수학적으로 추출함