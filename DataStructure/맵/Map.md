Map
===

백준 3052, 2577

중복되는 원소의 갯수나 종류를 찾는데 효율적,
종류가 필요없을때는 set을 사용 : 들어가는 원소가 키 하나라 데이터 사용량이 적음 ( 사실 그러라고 만든 set )

* map<type1, type2> map;
type1, type2 모두 사용자가 자료형 지정 가능

Map의 요소 접근(Acess)
---
1) map[key 값] 
    -> key 값에 대한 요소 접근 ( 범위 검사 x )
    -> 예외 처리가 아닌 VC++, g++의 디버깅이 발생

2) map.at(key 값)
    -> key 값에 대한 요소 접근 ( 범위 검사 o ) 
    -> 범위 이외의 값이 오면 out_of_range 발생

Map의 삽입, 삭제
---
1) insert(), emplace()
    -> emplace는 내부에서 생산자를 호출해 데이터를 직접 삽입, 때문에 pair<> 없이 가능
    -> https://hwan-shell.tistory.com/119 참고

2) emplace_hint()
    -> map 변수에서 요소 값 하나를 지정 후 해당 위치에 데이터를 삽입하는 것
    -> map은 tree로 구성되어 있어 처음 위치에서 순차적으로 삽입할 위치를 찾으나 hint사용시 해결
    -> tree 특성상 O(n log(n))이라 차이는 크지 않음

3) Clear()
    -> map에 대한 데이터를 전부 지우지만 capacity()는 남아 있음
    -> c++은 직접 메모리 관리를 해야하기 때문에 빈 map을 이용한 swap을 통해 capacity를 0으로 만들 수 있음
        => 이방법은 다른 구조도 사용 가능

Map의 기능
---
1) find()
    -> key값에 위치를 찾은 후 반환

2) count()
    -> 해당 key값에 있는 변수 갯수를 반환




TEMP
---
-> map[value]++;
return 값 => std::map<int,int>::mapped_type = int

-> map.insert(make_pair(key, value));
return => map<<int,int>::iterator, bool>
