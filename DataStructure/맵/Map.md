Map
===

백준 3052번

중복되는 원소의 갯수나 종류를 찾는데 효율적,
종류가 필요없을때는 set을 사용 : 들어가는 원소가 키 하나라 데이터 사용량이 적음 ( 사실 그러라고 만든 set )

* map<type, type> name;

-> map[value]++;
return 값 => std::map<int,int>::mapped_type = int

-> map.insert(make_pair(key, value));
return => map<<int,int>::iterator, bool>
