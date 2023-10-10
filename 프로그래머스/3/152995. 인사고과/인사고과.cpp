#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;

    int score = scores[0][0] + scores[0][1];

    sort(scores.begin() + 1, scores.end(), [](vector<int> vec1, vector<int> vec2)
        {
            return vec1[0] + vec1[1] > vec2[0] + vec2[1];
        });

    for(int i = 1; i < scores.size(); ++i)
    {
        if (scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1])
            return -1;

        int sum = scores[i][0] + scores[i][1];

    	if (score < sum)
            ++answer;
        else
            break;
    }

    int target = answer;
    for(int i = 2; i < target; ++i)
    {
	    for(int j = 1; j < i; ++j)
	    {
            if (scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1])
            {
                --answer;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> scores = { {{2,2},{1,4},{3,2},{3,2},{2,1}} };
    cout << solution(scores);

    return 0;
}