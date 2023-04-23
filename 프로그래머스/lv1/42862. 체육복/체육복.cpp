#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for(int i = 0; i < lost.size(); i++)
    {
	    for(int j = 0; j < reserve.size(); j++)
	    {
		    if(lost[i] == reserve[j])
		    {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                j--;
		    }
	    }
    }

    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] + 1 == reserve[j] || lost[i] - 1 == reserve[j])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                j--;
                break;
            }
        }
    }

    return answer = n - lost.size();
}