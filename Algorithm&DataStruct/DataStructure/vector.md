Vector ( 2022. 03 .12 )
===============================

> 1) Vector
---------------------------
    - 가변 크기 배열
    - 꽉차면 다른공간에 capacity를 늘린후 원소를 이동시킴
    - 그렇게 이동시킨 전 공간에 적절히 들어온 다른 크기의 데이터 저장후
    남는 공간 = 메모리 단편화

```c++
// 크기가 0인 벡터
std::vector<int> vec;
// 지정한 초깃값으로 이루어진 크기가 5인 벡터
std::vector<int> vec = {1, 2, 3, 4, 5};
// 크기가 10인 벡터
std::vector<int> vec(10);
// 크기가 10이고, 모든 원소가 5로 초기화된 벡터
std::vector<int> vec(10, 5);
```
----------------------------
    - push_back() : 벡터의 맨 마지막에 새로운 원소 추가
        -> 자주 사용되며 매우 빠르게 동작
        -> 공간이 남아있다면 O(1), 없다면 모든 원소를 복사/이동해 O(n)
        -> 공간이 부족하다면 벡터 용량을 두배로 늘림

    - Insert() : 삽입할 위치를 나타내는 반복자를 첫 인자로 받아 원하는 위치에 추가
        -> 지정 위치 다음의 모든 원소를 이동시키는 연산이 필요, O(n)
        -> 반복자 타입의 인자를 받음

    * 둘 모두 추가 할 경우 추가원소를 임시로 생성 후, 벡터 버퍼 내부 위치로 복사 또는 이동을 수행*

    - emplace_back(), emplace() : 같은 기능이나 새 원소 위치에 곧바로 객체가 생성,함수 성능 향상에 도움됨. 이때 생성자에 필요한 매개변수가 전달되야 함
    - pop_back() : 맨 마지막 원소 제거, 결과 벡터 크기는 1만큼 줄어듬
        -> 위치 조정이 필요없어 매우 빠르게 동작 O(1)
    - erase() : 반복자 하나를 인자로 받아 해당 위치 원소를 제거하거나 시작과 끝을 받아 끝 바로 앞 원소를 제거
        -> 삭제후 뒤쪽 원소들을 모두 앞으로 이동 O(n)
    - clear() : 모든 원소를 제거, 완전 비어있는 벡터로 만듬
    - reserve(capacity) : 벡터에 사용할 용량을 지정, 변수가 현재보다 크면 매개변수 크기만큼 재할당
    - shrink_tofit() : 여분의 메모리 공간을 해제하는 용도로 사용


> 2) std::vector 할당자
