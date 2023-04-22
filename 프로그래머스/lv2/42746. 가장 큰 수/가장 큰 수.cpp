#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
     vector<string> temp;

    // 스트링으로 변환해서 temp에 저장
    for (int element : numbers)
    {
        temp.push_back(std::to_string(element));
    }

    // 비교구문으로 각 원소끼리 정렬
    sort(temp.begin(), temp.end(), comp);

    for (string str : temp)
    {
        answer += str;
    }
    
      if (answer[0] == '0')
        answer = '0';

    return answer;
}