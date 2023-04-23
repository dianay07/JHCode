#include <string>
#include <queue>
#include <vector>

using namespace std;

bool visited[200] = { false };

void bfs(int num, vector<vector<int>> graph)
{
    queue<int> que;
    que.push(num);

    while (!que.empty())
    {
        int next = que.front();
        que.pop();

        for(int i = 0; i < graph[next].size(); i++)
        {
            if (visited[i] == false && graph[next][i] == 1)
            {
                visited[i] = true;
                que.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<vector<int>> graph;
	graph.resize(n);


    for(int i = 0; i < computers.size(); i++)
    {
	    for(int j = 0; j < computers[i].size(); j++)
	    {
            graph[i].push_back(computers[i][j]);
	    }
    }

    // bfs
    for (int i = 0; i < computers.size(); i++)
    {
        for (int j = 0; j < computers[i].size(); j++)
        {
           if(graph[i][j] == 1 && visited[j] == false)
           {
               bfs(j, graph);
               answer++;
           }
        }
    }

    return answer;
}