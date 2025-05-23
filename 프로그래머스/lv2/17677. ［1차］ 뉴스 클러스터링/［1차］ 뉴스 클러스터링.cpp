#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define MUL 65536

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    // 대문자로 변환
    transform(str1.begin(), str1.end(),str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(),str2.begin(), ::toupper);
    
    // key:value = 문자 : 문자개수
    unordered_map<string,int> mapA;
    unordered_map<string,int> mapB;
    // 모든 문자 중복없이 저장하는 set
    unordered_set<string> strCollector;

    string temp;
    // str1의 문자 map 생성
    for(int i=0;i<str1.length()-1;i++){
        // 연속된 두 문자가 알파벳일 경우
        if((str1[i]>='A' && str1[i]<='Z') && (str1[i+1]>='A' && str1[i+1]<='Z')){
            // 문자 생성
            temp = str1.substr(i,2);
            // map에 해당 문자 개수 1 증가
            mapA[temp]++;
            strCollector.insert(temp);
        }
    }

    // str2의 문자 map 생성
    for(int i=0;i<str2.length()-1;i++){
        if((str2[i]>='A' && str2[i]<='Z') && (str2[i+1]>='A' && str2[i+1]<='Z')){
            temp = str2.substr(i,2);
            mapB[temp]++;
            strCollector.insert(temp);
        }        
    }
    
    int inter = 0; // 교집합 개수
    int un = 0;    // 합집합 개수
    for(auto iter:strCollector){
        inter += min(mapA[iter],mapB[iter]);
        un += max(mapA[iter],mapB[iter]);
    }
    
    if(inter==0 && un==0) return MUL;
    answer = MUL*inter/un;
    return answer;
}