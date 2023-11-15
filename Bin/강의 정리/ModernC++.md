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

오른값 참조, std::move * 어려움
---
왼값(lvalue) vs 오른값 (rvalue)
-왼값 : 단일식을 넘어서 계속 지속되는 개체
-오른값 : lvalue가 아닌 나머지 ( 임시 값, 열거형, 람다, i++ 등..)

ex) RValueRef(Class&& name) {};
-> 일반적인 왼값 사용하지 못함
-> 임시값, 객체 참조 가능
-> 실질적으로 원본의 주소를 넘겨받는것 대충 LValue와 비슷하게 돌아감

=> 왼값 참조를 넘겨주는 것은 거즘 모든 권한을 주는 것이지만, 오른값 참조는 원본 객체의 읽고 쓰기, '이동 대상'이 되었다는 힌트를 줌 : 원본데이터가 더이상 필요없다

** 이동생성자, 이동 대입 연산자
복사는 무거우니까 이동으로 해결

 std::move -> 같은 의미 ( 오른값 참조로 캐스팅 )
 

전달 참조 ( forwarding reference )
---
// 보편참조
// 전달참조

1) 전달참조?
&& -> 오른값 참조를 나타내는 연산자만이 아님

넘겨받는 타입의 형태를 컴파일러가 추론해야 할때->

ex) auto&& k2 = k1;
에서 k2의 타입은 왼값참조로 바뀌어있다.
ex) auto&& k3 = std::move(k1);
에서 k3의 타입은 오른값참조로 바뀌어있다.

=> 공통점 : 형식 연역 (type deduction)이 일어날때

템플릿을 이용한 참조 함수를 만들때, 또 그 함수의 매개변수로 2개 이상이 들어갈 때, 왼값과 오른값의 갯수로 파생되는 함수의 숫자를 줄여줌

2) 전달 참조를 구별하는 방법
오른값 vs 오른값 참조
왼값이 아니다 = 단일식에서 벗어나면 사용 x
오른값만 참조할 수 있는 참조 타입

template<typename T>
void Test_ForwardingRef(T&& param)
같은 함수가 있을때 매개변수로 들어감 param이 타입 디덕션이 발생할 때 왼값 참조로도, 오른값 참조로도 들어갈 수 있고 함수 내에서도 무작정 이동 생성자, 이동복사연산자 같은 행동을 지정하면 문제가 생김

-> 함수 내에서 왼값, 오른값 참조인 경우따라 행동 지정을 해야함

std::forward -> 왼값참조인지 오른값참조인지 리턴해줌 ex) Test_Copy(std::forward<T>(param));ss
=> 전달참조는 std::forward() 써라


람다 표현식
---
함수 객체를 빠르게 만드는 문법

[캡처](인자) {구현부} = 람다 표현식

캡처 : 함수 객체 내부에 변수를 저장하는 개념과 유사
.기본 캡처 모드 : 값(복사) 방식(=) / 참조 방식(&)
..변수마다 캡처 모드를 지정해서 사용 가능 : 값 방식(name) / 참조 방식 (&name)

*캡처 내의 타입이나 이름을 지정해서 적어주면, 프로그래머 입장에서 조심해야 하는 부분 사용 변수들의  시인성이 좋아짐

auto name 으로 받아서 이름 지정 가능
인자와 구현부 사이에 ( -> typename )을 지정하면 리턴값의 타입 설정가능

```C++
// ex)
auto FindByItemIdLamda = [=](Item& item) -> int
{
    return item._itemId == itemId;
}
```

스마트 포인터
---

포인터를 알맞는 정책에 따라 관리하는 객체 ( 포인터를 래핑해서 사용 )

- shared_ptr : 레퍼런스 카운트( 참조 카운트 )를 관리, 이 포인터를 몇이나 참조하고 있는지 관리한다. -> 삭제시 이 포인터를 참조하고 있지 않을때 삭제
-> 서로 포인터끼리 보고 있을때 사이클 문제를 조심

```c++
class RefCountBlock
{
public:
    int _refCount = 1;
}


template<typename T>
class SharedPtr
{
public:
    SharedPtr() { }
    SharedPtr(T* ptr) : _ptr(ptr)
    {
        if(_ptr != nullptr)
        {
            _block = new RefCountBlock();
            cout << "RefCount : " << _block->refCount << endl;
        }
    }

    SharedPtr(const SharedPtr& sptr) : _ptr(sptr._ptr), _block(sptr._block)
    {
        if(_ptr != nullptr)
        {
            _block->_refCount++;
            cout << "RefCount : " << _block->_refCount << endl;
        }
    }

    ~SharedPtr()
    {
        if(_ptr != nullptr)
        {
            _block->_refCount--;
            cout << "RefCount : " << _block->_refCount << endl;

            if(_block->_refCount == 0)
            {
                delete _ptr;
                delete _block;
                cout << "Delete Data" << endl;
            }
        }
    }

public:
    T* _ptr = nullptr;
    RefCountBlock* _block = nullptr;
} 
```
- weak_ptr : 
Shared_ptr을 사용시 발생할 수 있는 사이클 문제를 해결할 수 있는 포인터

RefCountBlock에 int _weakCount = 1; 이 추가됨
Shared_ptr처럼 객체의 생명주기에 직접적인 영향은 없지만 객체가 사라졋는지를 확인하는 용도로 활용

_name.expired() -> 사라졌는지 아닌지 체크하는 기능
_name.lock() -> shared_ptr을 반환

장점 : 생명주기에서 자유로워 짐, 순환구조 해결
단점 : 사용하기 위해선 명시적으로 weak_ptr의 유무를 체크 후 shared_ptr로 반환시켜야함

- unique_ptr : 
    프로그램 상에서 오직 하나의 포인터만 있어야할 떄