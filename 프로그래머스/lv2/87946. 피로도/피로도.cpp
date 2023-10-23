#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool visited[8] = {false};

void dfs(int k, vector<vector<int>> &dungeons, int count) {
    if (count > answer) answer = count;
    
    for (int i=0; i<dungeons.size(); i++)
    {
        if (visited[i] == false && dungeons[i][0] <= k)
        {
            visited[i] = true;
            dfs(k - dungeons[i][1], dungeons, count + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, dungeons, 0);
    
    return answer;
}