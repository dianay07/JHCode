UnityShader 코드구조
====================

> 1) 개요
---------
- 유니티 쉐이더는 'ShaderLab' 이라는 자체 스크립트 언어를 이용
- 유니티가 멀티 플랫폼 제작이 자동으로 지원되는 엔진, 다양한 환경마다 쉐이더가 달라야 하기 때문에 스크립트를 사용
- ShaderLab( 기초 ), SurfaceShader( 복잡한 부분은 스크립트를 이용 ), Vertex&Fragment Shader( 본격적인 쉐이더 작성법 )


> 2) SurfaceShader 구성
-----------------------
![screenshot](/%EC%9D%B4%EB%AF%B8%EC%A7%80/UnityShader_%EC%BD%94%EB%93%9C%20%EA%B5%AC%EC%A1%B0.png)


- (1) Properties 부분
    - _Name ("display name", Range(min, max)) = numbers 의 형태로 선언가능
    - 쉐이더의 인스펙터창에 " " 안의 이름으로 Range 부분의 자료형이나 범위로 초기화 가능

- (3) CG 언어 부분
    - 서피스 쉐이더의 특징, 스크립트와 CG 언어를 같이 섞어 쓰는 부분
    - Snippet이라 부르는 설정부분, 엔진으로부터 받아와야 할 데이터 구조체 부분, 변수 선언 공간, 색상이나 이미지가 출력되는 surf부분


> 3) SurfaceOutputStandard o
----------------------------
```c++
struct SurfaceOutputStandard
{
    fixed3 Albedo;
    fixed3 Normal;
    fixed3 Emission;
    half Metallic;
    half Smoothness;
    half Occlusion;
    half Alpha;
}
```

