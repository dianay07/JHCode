#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    vector<int> splitArray;

    for(int i = 0; i < commands.size(); i++)
    {
        for (int start = commands[i][0]; start <= commands[i][1]; start++)
        {
            splitArray.push_back(array[start - 1]);
        }

        sort(splitArray.begin(), splitArray.end());
        answer.push_back(splitArray[commands[i][2] - 1]);
        splitArray.clear();
    }

    return answer;
}