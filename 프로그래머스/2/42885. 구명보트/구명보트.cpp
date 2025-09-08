#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    
    sort(people.begin(), people.end());

    int start = 0;
    int end = people.size() - 1;

    while (start <= end)
    {
        int sum = people[start] + people[end];

        if (sum <= limit)
        { 
            start++;
            end--;
        }
        else if(sum > limit)
        {
            end--;
        }

        answer++;
    }
    
    return answer;
}
