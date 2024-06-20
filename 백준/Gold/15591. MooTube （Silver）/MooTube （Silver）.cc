#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N, Q;
int p1, q1, r1;
bool visited[5001];

long BFS(long k1, long v1, const vector<vector<pair<int, int>>>& vec)
{
	long answer = 0;

	// 방문체크 초기화
	int size = vec.size();
	for (int i = 1; i <= size; i++)
		visited[i] = false;

	visited[v1] = true;

	queue<int> q;
	q.push(v1);

	while (q.empty() == false)
	{
		int current = q.front();
		q.pop();

		const int vecSize = vec[current].size();
		for(int i = 0; i < vecSize; i++)
		{
			int next = vec[current][i].first;
			int nextUSADO = vec[current][i].second;

			if(visited[next] == true) continue;
			if(nextUSADO < k1) continue;

			answer++;
			visited[next] = true;
			q.push(next);
		}
	}

	return answer;
}

int main()
{
	fastio;

	//  소의 수, 질문 수
	cin >> N >> Q;

	vector<vector<pair<int, int>>> USADO(N + 1);

	for(int i = 0; i < N - 1; i++)
	{
		cin >> p1 >> q1 >> r1;

		USADO[p1].push_back({q1, r1});
		USADO[q1].push_back({ p1, r1 });
	}

	int k1, v1;
	while (Q--)
	{
		cin >> k1 >> v1;

		cout << BFS(k1, v1, USADO) << "\n";
	}

	return 0;
}