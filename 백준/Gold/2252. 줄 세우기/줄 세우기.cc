#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N, M, A, B;

int main()
{
    fastio;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> num(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int first, second;
        cin >> first >> second;

        graph[first].push_back(second);
        num[second]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (num[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();

        cout << idx << " ";

        for (int neighbor : graph[idx])
        {
            if (--num[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return 0;
}
