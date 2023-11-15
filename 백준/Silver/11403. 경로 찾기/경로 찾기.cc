#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	int N;
	cin >> N;

	vector<vector<int>> graph;
	graph.resize(N);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;

			if (temp != 1)
				graph[i].push_back(10001);
			else
				graph[i].push_back(temp);
		}	
	}

	for(int k = 0; k < N; k++)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j] == 10001)
				cout << 0 << " ";
			else
				cout << 1 << " ";
		}
		cout << "\n";
	}

	return 0;
}