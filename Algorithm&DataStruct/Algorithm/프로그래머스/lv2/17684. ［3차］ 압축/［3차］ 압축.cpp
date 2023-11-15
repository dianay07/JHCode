#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    int lastNum = 26;

    string temp;
    string w;
    string c;
    int count = 0;

    // 사전 세팅
    map<string, int> dictionary;
    for(int i = 1; i <= 26; i++)
    {
        string temp;
        temp += (char)(i + 64);

        dictionary.insert({temp, i});
    }

    while (count <= msg.size())
    {
        c = msg[count];

        if (dictionary.find(w + c) != dictionary.end())
        {
            w = w + c;
        }
        else
        {
            answer.push_back(dictionary.find(w)->second);
            dictionary.emplace(w + c, ++lastNum);
            w = c;
        }
        count++;
    }

    return answer;
}

int main()
{
    string msg = "TOBEORNOTTOBEORTOBEORNOT";
    solution(msg);

    return 0;
}