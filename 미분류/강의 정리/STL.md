# STL
= Standard Template Library
프로그래밍할 때 필요한 자료구조/알고리즘들을 템플릿으로 제공하는 라이브러리

컨테이너 (Container) : 데이터를 저장하는 객체 ( 자료구조 data structure )


Vector ( 동적 배열 )
---
- vector의 동작 원리 (size/capacity)
    size : 실제 사용 데이터 갯수
    vector<type>.resize : 사이즈 강제 조정
        -> 이런식으로 강제를 늘릴경우 push_back은 늘려진 끝부터 사용함
    capacity : 여유분을 포함한 용량 갯수
    vector<type>.reserve : 캐퍼시티 강제 조정

-> 미리 reserve로 용량을 키워놓고 작업한다면 push_back할때마다 등장한 복사 이동 작업이 불필요해짐

// 동적 배열은 어떤 식으로 배열을 유동적으로 사용하나

1) (여유분을 두고) 메모리를 할당
2) 여유분까지 꽉 차면, 메모리를 추가함
    -> 기존 영역을 없애고 다른 영역으로 확장

의문 1) 여유분은 얼만큼이 적당한가
    -> 1.5배 내지 2배씩 늘리는데 이는 원소를 추가할때 마다 발생하는 원소 복사 비용의 절감을 위해
의문 2) 확장은 얼마나 해야 하나
의문 3) 기존의 데이터를 어떻게 처리하는가

// vector<type>.size()의 리턴값이 unsigned_int기 때문에 빌드시 warning이 뜨는데, 이는 for문의 시작지점 타입을 int가 아닌 vector<int>::size_type으로 자동완성 시켜주면 사라짐     ->     자료구조책에서 많이 보던 모양이 왜 그랫는지, C++11문법이랗

- 중간 삽입/삭제 ( BAD )
    -> c++ 실력의 척도가 될수 있는 개념
    -> 원소가 하나의 메모리 블록에 '연속하게' 저장되야 한다는 규칙을 지켜야함
    -> 중간에서 이러는게 비효율적인건 확실   
- 처음/끝 삽입/삭제 ( BAD / GOOD )
    -> 맨 마지막 원소를 가지고 행동하는건 효율적
    -> push_back, pop_back 인터페이스가 지원되는 이유

- 임의 접근 ( Random Access )
    -> 연속하게 저장됨이 보장되면 찾을수 있음
    -> i 번째에 접근하고 싶다 할때 1번째 주소에서 출발할 수 있으면 계산이 빠르기때문에 

- 쭉 스캔하면서, 임의의 데이터를 일괄 삭제하고 싶다?
    -> iter를 이용한 for문을 쓸때 포인터 주소로 작용하기 때문에 잘 생각해야댐


리스트 ( 연결 리스트 )
---
- list의 동작 원리 
    단일 , 이중 , 원형
    벡터와 달리 원소끼리 다음 원소의 위치만 알고 연속되어있을 필요는 없음
- 중간 삽입/삭제
- 처음/끝 삽입/삭제
- 임의 접근

Deque ( Sequence Container )
---
- 동작 원리
    벡터와 마찬가지로 배열 기반으로 동작, 다만 메모리 할당 정책이 다름

    앞뒤로 할당된 메모리 크기를 늘릴수있다?

- 중간 삽입/삭제
    벡터와 마찬가지로 연속성이 유지되어야 해서 느림
- 처음/끝 삽입/삭제
    빠름 / 빠름
- 임의 접근
    이터레이터 코드 내부를 보면 각자 주소를 다른 테이블로 관리하고 있어 하나하나 순환할 필요가없음

Map
---
벡터의 데이터를 줄지어 관리하는 특징에서 발생하는 '원하는 조건에 해당하는 데이터를 빠르게 찾을 수 없다'는 단점을 해소할 구조
" 연관 컨테이너 "

균형 이진 트리 ( AVL ) 기반의 구조
key, value를 페어로써 받음
원소 검색이 빠름

[ map.erase() ] 는 반환값이 bool 값이라 삭제되면 1을 반환되고, 어떤 사유로 인해 삭제가 실패하면 0을 반환해서 삭제할 원소가 없다해도 에러가 나지않음.

[ map.insert() ] 는 똑같은 key값에 value값을 고치겟다고 같은 key값에 두번하면 두번째 요청이 무시됨.

value값을 고치고 싶다면 키를 찾아들어가 value에 수정을 가함
Map에 Insert시 없으면 자동으로 key와 value를 pair로 생성해서 추가해줌

!! 없으면 추가, 있으면 수정 !!
map[i] = xxx; 
-> 맵에 해당 키가 없으면 추가하고, 없으면 추가해주지만 대입을 하지않더라도 (key, value) 형태에서 기본값이 0인 상태로 데이터가 추가되기 떄문에 데이터를 찾고싶다면 Find() 함수를 활용 

-Map 순회
데이터가 벡터처럼 연속해서 붙어있지 않기때문에 iterator를 이용해 순회함

(insert, []) / (erase) / (find, []) / (map::iterator) (*it) pair<key, value>&


set, multimap, multiset
---
연관 컨테이너 친척들

Map을 사용할 때, Key값과 Value값이 일치하게 쓰고싶을때 -> set<type> ..;

추가 : insert(i)
삭제 : erase(i)
검색 : 
set<int>::iterator findit = s.find(i);
if(findit == s.end())
{
    ... 못 찾음
}
else
{
    ... 찾음
}
순회 : map이랑 똑같은데 키 = value라 하나만 쓰면댐

map에서 중복 키를 허용하는 것이 -> multimap
    키값 삭제시 해당 키 값의 벨류가 다 삭제됨
    하나만 삭제하고 싶으면 그 하나를 찾고 삭제
    equal_range() => 키값이 같은 데이터들을 묶어 iterator로 사용가능
    lower_bound = 해당 키값의 시작
    upper_bound = 해당 키값의 끝

set에서 중복 키를 허용하는 것이 -> multiset

Algorithm
---
특정 구조를 이용해 만든 그 구조에 묶여버린 코드 ( Vector를 사용햇다 만들었다가 모종의 여유로 list로 바꾸면 구동되지 않는 코드들 ) 를 해결하기 위한 library

-데이터를 찾거나, 갯수를 찾거나
) find(first, last, value) : return iter
) find_if(first, last, 조건) : return iter
) count(first, last, value) : return int
) count_if(first, last, 조건) : return int

-모든 데이터를 대상으로 조건에 비교 (return bool)
) all_of(first, last, 조건) : 모든 데이터가 조건에 충족하는가
) any_of(first, last, 조건) : 조건에 충족하는 데이터가 하나라도 있는가
) none_of(first, last, 조건) : 모든 데이터가 조건에 부합하는가

-모든 데이터에 대해 뭔가를 행할때
) for_each(first, last, 하고싶은 기능) : return 바꿔진 구조

*-삭제*
) remove(first, last, value)
) remove_if(first, last, 조건) : 조건에 합당한 남겨줘야할 데이터를 구조의 첫 자리에 '복사'하기 때문에 불필요한 데이터가 삭제되는게 아님 -> 조건에 따라 순서를 재조정하고 남은 크기만큼 쓰레기값이 들어감
    -> 반환된 iter에서 끝까지 erase를 한번더 거치면 원하던 내용이 

v.erase(remove_if(v.begin(), b.end(), IsOdd()), v.end());s