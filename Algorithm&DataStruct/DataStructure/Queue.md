Queue 종류
======================================================================================================

# Deque
1) Deque
---
    - 양방향 큐(double-ended queue)의 약자
    - 양방향으로 매우 빠르게 확장할 수 있어야 하며, 모든 원소에 임의 접근을 제공
    - 중간에서의 삽입 또는 삭제에 대한 시간 복잡도는 벡터와 동일하나, 실제로는 약간 빠르게 동작

2) 멤버 함수
---
    - push_front(), push_back(), insert(), emplace_front(), emplace_back()
    - pop_front(), pop_back(), erase()
    - shrink_to_fit()

3) 기타
---
    - vector와 마찬가지로 사용자 정의 할당자를 지정 가능, 할당자가 객체의 일부가 아니라 타입의 일부
        -> 서로 다른 할당자를 사용하는 두 개의 Vector, Dequeue는 서로 비교할수 없음
    - 마찬가지로 할당 또는 복사 생성자를 사용할 수도 없음

=======================================================

# Priority-Queue
1) Priority-Queue
---
    - 먼저 집어넣은 순서대로 나오는(FIFO) 큐와 다르게 사용자가 정한 우선순위에 따라 순서가 정해져 나오는 큐
    - 두 요소의 우선 순위가 같으면 삽입 순서에 따라 저장
    - STL 내부적으로 Heap을 사용
```c++ 
    template
    <
        class T,
        class Container = std::vector<T>,
        class Compare = std::less<typename Container::value_type>
    > class priority_queue;
```
    - 삽입과 삭제는 O(logN), 정렬은 O(NlogN)

    - T : 저장할 원소의 타입형
    - Container : 원소를 저장할 자료구조
                : front(), push_back(), pop_back()의 기능을 가지고 있어야함 
                ( vector랑 deque가 갖고)
    - Compare : 비교 조건을 저장, True로 반환되는 값이 우선순위가 낮아짐
    

[참조](https://en.cppreference.com/w/cpp/container/priority_queue)
