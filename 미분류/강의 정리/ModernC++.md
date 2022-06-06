# ModernC++ (C++11)

auto
---
형식 연역 ( type deduction ) -> 컴파일러가 타입의 추론을 맡김

*주의
기본 auto는 const, & 무시 => 필요하다면 직접 &를 붙여줘야함
-> 타이핑이 길어지는 경우 사용
-> 가독성으로 위해 일반적으로 놔두는게 안전


중괄호 초기화
---
type a = 0;
type b(0);
type c{ 0 }; <- 

변수, 타입마다 초기화 방법이 다른 점이 불편해서~
)) 장점
1) Vector등 container과 잘 어울림
Vector<int> v{1, 2, 3, 4, 5}; -> 가능
initializer_list 라는 것을 사용해서 초기화

2) 축소 변환 방지
int x = 0; -> double y { x }; 안됨

)) 단점
비슷한 모양의 다른 생성자를 무시할 정도로 우선 순위가 높음 -> 문법의 혼란이 발생


nullptr *
---
nullptr전의 null 표현법 = NULL ( #define NULL 0 ) -> 직접적으로 0을 넣어준 경우

매개 변수로 int를 받는 것과 void*를 받는 것 두가지가 있을경우 기존 NULL은 0이기 때문에 int를 받는 함수를 호출함 -> 의도하지 않는 문제

1) 오동작 방지
위 문제를 nullptr이 해결함

2) 가독성의 향상
변수가 포인터인지, 정수나 실수형인지 확실히 알 수 있음


using *
---
typedef == using
typedef __int64 = id; <=> using id = __int64;

1) 직관성 향상
typedef void (*MyFunc)();
-> using MyFunc = void(*);

2) 템플릿
template<typename T>
typedef std::list<T>List; -> 안됨

template<typename T>
struct List
{
    typedef std::list<T> type;
}
-> 옛날 방법

template<typename T>
using List = std::list<T>; -> 됨


enum class ( scoped enum )
---
1) 이름공간 관리 (scoped)
다른 enum에도 같은 정의명이 있을때 사용 할 수 없어 별도의 이름을 사용해야 했는데 enum class가 해결

2) 암묵적 변환 금지
고전 enum은 지정된 정수값으로 암묵적 변환이 가능했으나 enum class가 방지
-> 하려면 static_cast<> 씀


delete (삭제된 함수)
---
컴파일러가 자동으로 만들어 주는 기능 중 사용하지 않아야 할 함수등을 막는 방법

-> 고전의 '정의되지 않은 private 함수'
void operator=(const Knight& k);

->현대의 delete
void operator=(const Knight& k) = delete;


override, final
---
override ( C#에서는 기본 )
자식이 처음 만든 함수인지, 저 멀리 부모 클래스가 먼저 만든 함수인지 virtual 함수가 알 수 없을때, 혹은 virtual 함수에서 새로운 키워드가 추가되어 달라졌을때 무엇이 원형인지 모호함

-> 대충 vitual 함수의 원형이 아님을 한눈에 알 수 있게 해주는 키워드
ex) virtual void Attack() 'override';

final
override를 쭉 한 함수들을 더이상 override하지 않겟다는 선언
ex) virtual void Attack() 'final';
-> 더이상 자식 함수들이 재정의 할수 없게됨