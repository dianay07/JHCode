#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
	    if(sizes[i][0] < sizes[i][1])
	    {
            swap(sizes[i][0], sizes[i][1]);
	    }
    }

    vector<int> column;
    vector<int> row;
    for (int i = 0; i < sizes.size(); i++)
    {
        column.push_back(sizes[i][0]);
        row.push_back(sizes[i][1]);
    }

    sort(column.begin(), column.end(), greater<int>());
    sort(row.begin(), row.end(), greater<int>());

    answer = column.front() * row.front();

    return answer;
}