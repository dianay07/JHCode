#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

struct Data
{
	int start;
	int dest;
	int dist;
};

const int MAX = 100001;

int TC, N, M, W;
int S, E, T;
vector<Data> table;
vector<int> dist;

bool Calc(int InStart)
{
	dist[InStart] = 0;

	for(int i = 1; i < N; i++)
	{
		for(int j = 0; j < table.size(); j++)
		{
			int start = table[j].start;
			int dest = table[j].dest;
			int distance = table[j].dist;

			if(dist[dest] > dist[start] + distance)
				dist[dest] = dist[start] + distance;
		}
	}

	for (int j = 0; j < table.size(); j++)
	{
		int start = table[j].start;
		int dest = table[j].dest;
		int distance = table[j].dist;

		if (dist[dest] > dist[start] + distance)
			return true;
	}

	return false;
}

int main()
{
	fastio;
	cin >> TC;

	while (TC--)
	{
		// 정리
		table.clear();
		dist.clear();

		cin >> N >> M >> W;

		// 거리 최대설정
		for(int i = 0; i <= N; i++)
			dist.push_back(MAX);

		// 일반 경로
		for(int i = 0; i < M; i++)
		{
			cin >> S >> E >> T;
			table.push_back({ S, E, T });
			table.push_back({ E, S, T });
		}

		// 웜홀
		for(int i =0; i < W; i++)
		{
			cin >> S >> E >> T;
			table.push_back({ S, E, -T });
		}

		if (Calc(1) == false)
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
	}

	return 0;
}