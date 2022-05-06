#include <Numeric> 헤더
=======================
참조) https://docs.microsoft.com/ko-kr/cpp/standard-library/numeric-functions?view=msvc-170


> 1) accumulate
---------
    - First => 첫번쨰 인자, Last => 두번째 인자, init => 리턴할 합계의 초기값
    - 매개 변수로 입력받은 first와 last 두 숫자 사이 범위의 모든 수의 합계를 리턴해줌.
    - 범위를 초과하는 값을 더할떄는 초기값의 타입을 잘 지정해줘야 한다.
        -> long long 타입을 쓴다면 OLL 을

```C++
template <class InputIterator, class Type>
Type accumulate(
    InputIterator first,
    InputIterator last,
    Type init);

template <class InputIterator, class Type, class BinaryOperation>
Type accumulate(
    InputIterator first,
    InputIterator last,
    Type init,
    BinaryOperation binary_op);
```