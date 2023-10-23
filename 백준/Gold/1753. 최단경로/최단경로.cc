#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

#define INF INT_MAX
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

// 그래프
vector<vector<pair<int, int>>> vec;

int V, E, K;

vector<int> solution(int start)
{
	vector<int> dist(V + 1, INF);
	vector<bool> visited(V + 1, false);
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
	//pq.push({ start, dist[start] });
	pq.push({ dist[start], start });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (visited[node] == true)
			continue;

		visited[node] = true;

		for (int i = 0; i < vec[node].size(); i++)
		{
			int nextNode = vec[node][i].first;
			int nextCost = vec[node][i].second;

			dist[nextNode] = min(dist[nextNode], (dist[node] + nextCost));
			pq.push({dist[nextNode], nextNode });
		}
	}

	return dist;
}

int main()
{
	fastio;

	// 정점, 간선 입력
	// 시작 정점 입력
	cin >> V >> E >> K;

	vec.resize(V + 1);
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		vec[u].push_back({ v, w });
	}
	
	vector<int> answer = solution(K);

	for (int i = 1; i <= V; i++)
	{
		if (answer[i] == INF)
			cout << "INF" << "\n";
		else
			cout << answer[i] << "\n";
	}

	return 0;
}