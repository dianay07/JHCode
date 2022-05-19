VertexColor - 마스킹
===========
- 버텍스 안에 저장되어 있는 기본 정보 -> 
    위치(Position), UV(Texcoord), 컬러 (Color), 노멀 (Normal), 탄젠트 (Tangent) 중
    컬러값을  사용해 하나의 오브젝트에 다수 Material을 적용하는 방법.

```C#
Shader "Custom/vertexcolor"
{
    Properties
    {
        _MainTex ("Albedo (RGB)", 2D) = "white" {}
        _MainTex2("Albedo (RGB)", 2D) = "white" {}
        _MainTex3("Albedo (RGB)", 2D) = "white" {}
        _MainTex4("Albedo (RGB)", 2D) = "white" {}
    }
    SubShader
    {
        Tags { "RenderType"="Opaque" }
        LOD 200

        CGPROGRAM
        #pragma surface surf Standard noambient

        sampler2D _MainTex;
        sampler2D _MainTex2;
        sampler2D _MainTex3;
        sampler2D _MainTex4;

        struct Input
        {
            float2 uv_MainTex;
            float2 uv_MainTex2;
            float2 uv_MainTex3;
            float2 uv_MainTex4;
            float4 color:COLOR;
        };

        void surf (Input IN, inout SurfaceOutputStandard o)
        {
            fixed4 c = tex2D (_MainTex, IN.uv_MainTex);
            fixed4 d = tex2D(_MainTex2, IN.uv_MainTex);
            fixed4 e = tex2D(_MainTex3, IN.uv_MainTex);
            fixed4 f = tex2D(_MainTex4, IN.uv_MainTex);
            o.Albedo = lerp(c.rgb, d.rgb, IN.color.r);
            o.Albedo = lerp(o.Albedo, e.rgb, IN.color.g);
            o.Albedo = lerp(o.Albedo, f.rgb, IN.color.b);
            o.Alpha = c.a;
        }
        ENDCG
    }
```
----------------

* Surf() 해석
    - Properties에 나타낼 텍스쳐 지정
    - 지정한 텍스쳐들을 R값으로 첫장에 그려낸후 그렇게 그려진것 위에 G, B 값 순서대로 lerp