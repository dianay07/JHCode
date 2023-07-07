#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N;
int M;
vector<vector<pair<int, int>>> vec;

vector<int> Solution(int index)
{
	vector<int> dist(N + 1, INT_MAX);
	vector<bool> visited(N + 1, false);
	dist[index] = 0;

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
	pq.push({ dist[index], index });

	while (!pq.empty())
	{
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

	cin >> N >> M;

	vec.resize(N + 1);
	
	for(int i = 0; i < M; i++)
	{
		int start, dest, value;
		cin >> start >> dest >> value;

		// 출발, 도착지, 거리
		vec[start].push_back({ dest, value });
	}

	int start, dest;
	cin >> start >> dest;

	vector<int> answer = Solution(start);
	cout << answer[dest];

	return 0;
}