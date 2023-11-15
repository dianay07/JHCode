#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int current, int sum, vector<int> numbers, int target)
{
    if (current >= numbers.size())
    {
        if (sum == target)
            answer++;

        return;
    }

    dfs(current + 1, sum + numbers[current], numbers, target);
    dfs(current + 1, sum - numbers[current], numbers, target);
}

int solution(vector<int> numbers, int target) {

    int sum = 0;

    dfs(1, sum + numbers[0], numbers, target);
    dfs(1, sum - numbers[0], numbers, target);

    return answer;
}