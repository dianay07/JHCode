#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> q;
    int size = progresses.size();

    for(int i = 0; i < size; i++)
    {
        q.push(i);
    }

    while (q.empty() == false)
    {
        int count = 0;
    	for (int i = 0; i < size; i++)
        {
            progresses[i] += speeds[i];
        }

        while(q.empty() == false && progresses[q.front()] >= 100)
        {
            count++;
            q.pop();
        }

        if (count != 0)
            answer.push_back(count);
    }

    return answer;
}

int main()
{
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1, 30, 5 };

    solution(progresses, speeds);

    return 0;
}