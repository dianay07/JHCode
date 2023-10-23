#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> map;

    for (vector<string> cloth : clothes)
    {
        // 옷의 종류를 key로 옷의 갯수 구하기
        map[cloth[1]]++;
    }

    // 리그 경기 구하는 공식이랑 똑같음
    for(auto it = map.begin(); it != map.end(); it++)
    {
        answer *= it->second + 1;
    } 

    return answer - 1;
}