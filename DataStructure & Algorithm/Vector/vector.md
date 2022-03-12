연속된 자료구조 vs 연결된 자료구조 ( 2022. 03 .11 )
===============================

> 1) 연속된 자료구조
-------------------
    - 모든 원소를 단일 메모리 청크(Chunk)에 저장
    - 각각의 원소는 모두 같은 타입(Type), 같은 크기의 메모리 사용
    - i번쨰 원소의 위치 : BA + i * sizeof(type)
    - 데이터 접근 시간은 항상 일정 => O(1)

    - 정적 배열(Static Array) : 선언된 블록이 끝나면 소멸
        스택에 할당되기 때문에 함수를 벗어날 때 자동으로 해제
    - 동적 배열(Dynamic Array) : 프로그래머가 생성할 시점과 해제할 시점을 자유롭게 결정
        힙 영역에 할당되어 사용자가 직접 해제하기 전까지 유지
    >   >   > 두가지 모두 다양한 연산에서 동일한 성능

    - 정적 배열 => int arr[size];
    - C 동적 배열 => int* arr = (int*)malloc(size * sizeof(int));
    - C++ 동적 배열 => int* arr = new int[size];

##### 캐시 지역성( Cache Locality )
    - 각 원소는 서로 인접해 있어 하나의 원소에 접근할 때 주변 원소도 함께 캐시(Cache)로 가져옴
      그로인해 다시 주변 원소에 접근할 때 해당 원소를 캐시에서 가져와 매우 빠르게 동작
    - 연산의 점근적 시간 복잡도 계산에는 영향을 주지 않지만 원소에 매우 빠르게 접근한다는 '큰 장점'


> 2) 연결된 자료 구조
--------------------

    - 노드(Node)라 하는 여러 개의 메모리 청크에 메모리를 저장, 서로 다른 메모리 위치에 데이터가 저장됨
    - 각각의 노드는 저장할 '데이터'와 다음 노드를 가리키는 '포인터'로 구성
    - 원소에 접근시 next 포인터를 따라 이동 => O(n)
    - 삽입 또는 삭제를 매우 빠르게 수행 가능
    - 모든 원소를 차례대로 방문하는 작업은 이론적으로 같으나 연결 리스트보다 성능이 조금 떨어짐

> 3) 비교
---------

     연속된 자료 구조                       ||                    연결된 자료 구조
    모든 데이터가 연속적으로 저장                       노드에 저장, 메모리 곳곳에 흩어질수 있음
    원소에 즉각적으로 접근 가능                         임의 원소 접근은 선형 시간 복잡도로 느린편
    연속적으로 저장, 캐시지역성 효과 보유                캐시지역성 효과 미보유, 순회 느린편
    크기만큼 메모리 사용                                노드에서 포인터 저장을 위해 여분의 메모리 사용