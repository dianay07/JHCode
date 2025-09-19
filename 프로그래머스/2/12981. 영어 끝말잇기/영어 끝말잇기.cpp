#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    map<string, int> save;
    save[words[0]]++;

    for (int i = 1; i <= words.size() -1; i++)
    {
        // 끝과 시작이 다르면 컷
        if (*(words[i - 1].end() - 1) != *(words[i].begin()))
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
        else
        {
            // 같아도 중복이면 컷
            if (save[words[i]] == 1)
            {
                answer.push_back(i % n + 1);
                answer.push_back(i / n + 1);
                break;
            }
            else
            {
                save[words[i]]++;
            }
        }

        if (i == words.size() - 1)
        {
            answer.push_back(0);
            answer.push_back(0);
        }
    }

    return answer;
}