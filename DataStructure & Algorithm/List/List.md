Forward_list ( 2022. 03 .14 )
===============================

> 1) Forward_list
-----------------
    - 데이터 중간에 자료를 추가하거나 삭제하는 비효율적인 작업을 해결한 구조
    - 성능유지를 위해 전체 리스트의 크기를 반환하거나 첫 번째 원소를 제외한 나머지
      원소에 직접 접근하는 기능을 제공하지 않음
    - vector와 마찬가지로 두 번째 템플릿 매개변수에 사용자 지정 할당자 지정 가능


> 2) 원소의 삽입과 삭제
---------------------
    - push_front(), insert_after() : 리스트 맨 앞에 새로운 원소를 삽입
    - 삽입은 노드의 포인터 조작으로 구현되어 배열 기반 구조보다 빠름
    - vector의 emplace_front()와 emplace_after() 제공, 더 효율적
    - pop_front(), erase_after()

> 3) 기타 멤버 함수
-------------
    - remove() : 타입에 정의된 등호 연산자를 사용하여 전달된 값과 일치하는 모든 원소
                    찾아 삭제
    - remove_if() : 데이터 원소 하나를 인자로 받아 bool값이 true를 반환하면 삭제



List ( 2022. 03 .17 )
===============================

> 1) List
-----------------
    - Forward_lsit는 메모리를 적게 쓰고 빠른 성능을 유지하기위해 적은 기능을 지원하지만 
    List는 이런 단점을 보완함
    - 이중 연결 리스트(doubly-linked list)구조로 이루어져 있음

```c++
 struct doubly_linked_list_node
 {
     int data;
     doubly_linked_list_node* next;
     doubly_linked_list_node* prev;
 };
```

>2) 멤버 함수
--------------
    - std::forward_list의 함수와 같거나 유사, 약간의 차이가 있음. ex) _after로 끝나는 함수는 _after를 뺌
    - push_back(), emplace_back(), pop_back()

