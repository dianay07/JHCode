#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    queue<pair<int, int>> q;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

    for(int i = 0; i < priorities.size(); i++)
    {
        q.push({ priorities[i], i });
        pq.push({ priorities[i], i });
    }

    while(pq.empty() == false)
    {
        pair<int, int> max = pq.top();
        pair<int, int> top = q.front();

        q.pop();

        if (max.first == top.first)
        {
            pq.pop();
            answer++;

            if (top.second == location)
                break;
        }
        else
            q.push(top);
    }

    return answer;
}

int main()
{
    vector<int> priorites = { 1, 1, 9, 1, 1, 1 };
    int location = 0;

    cout << solution(priorites, location);

    return 0;
}