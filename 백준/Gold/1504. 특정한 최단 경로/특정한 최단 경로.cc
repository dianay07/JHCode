#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)
#define INF 98765432

int N, E;
vector<vector<pair<int,int>>> graph;
int dist[801];
int must1, must2;

void BFS(int A)
{
	memset(dist, INF, sizeof(dist));

	priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
	pq.push({0, A});
	dist[A] = 0;

	while (pq.empty() == false)
	{
		int next = pq.top().second;
		int distance = pq.top().first;
		pq.pop();

		// 중복 가능하니까 방문체크 X, 거리 비교
		if (dist[next] < distance) continue;

		for (int i = 0; i < graph[next].size(); i++)
		{
			int nextX = graph[next][i].first;
			int nextDist = graph[next][i].second;

			if (dist[nextX] > dist[next] + nextDist)
			{
				dist[nextX] = dist[next] + nextDist;
				pq.push({ dist[nextX], nextX });
			}
		}
	}
}

int main()
{
	fastio;
	cin >> N >> E;

	graph.resize(N + 1);

	for(int i = 0; i < E; i++)
	{
		int Start, End, Dist;
		cin >> Start >> End >> Dist;

		graph[Start].push_back({ End, Dist });
		graph[End].push_back({ Start, Dist });
	}

	cin >> must1 >> must2;

	BFS(1);
	int distanceNTo1 = dist[must1];
	int distanceNTo2 = dist[must2];

	BFS(must1);
	int distance1To2 = dist[must2];
	int distance1ToN = dist[N];

	BFS(must2);
	int distance2ToN = dist[N];

	int answer;
	if (INF < distanceNTo1 + distance1To2 + distance2ToN)
		answer = INF;
	else
		answer = distanceNTo1 + distance1To2 + distance2ToN;

	if (answer < distanceNTo2 + distance1To2 + distance1ToN)
		answer = answer;
	else
		answer = distanceNTo2 + distance1To2 + distance1ToN;

	if (answer >= INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}
