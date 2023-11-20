#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
     map<int, int> input;

    // map 입력
    for (int i = 0; i < nums.size(); i++)
    {
        input[nums[i]]++;
    }

    answer = min(input.size(), nums.size() / 2);
    
    return answer;
}