#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;

    // 귤 갯수 넣고 많은 수 대로 정렬
    map<int, int> m;
    for (int i = 0; i < tangerine.size(); i++)
        m[tangerine[i]]++;

    vector<pair<int, int>> n(m.begin(), m.end());
    sort(n.begin(), n.end(), cmp);

    // 계산
    for(int i = 0; i < n.size(); i++)
    {
        // 남은 k가 0이 되면 끝
        if(k <= 0)
        {
            break;
        }

        k -= n[i].second;
        answer += 1;
    }
    
    return answer;
}