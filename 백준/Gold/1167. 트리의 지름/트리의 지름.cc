#include<iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

vector<vector<pair<int, int>>> tree;
bool visited[100001];
int V, far;
int answer = 0;

void DFS(int sum, int start)
{
	visited[start] = true;
	if(sum > answer)
	{
		answer = sum;
		far = start;
	}
		
	for(int i = 0; i < tree[start].size(); i++)
	{
		if(visited[tree[start][i].first] == false)
		{
			DFS(sum + tree[start][i].second, tree[start][i].first);
		}
	}
}

int main()
{
	fastio;

	cin >> V;
	tree.resize(V + 1);

	// 입력
	int start = 0, dest = 0, distance = 0;
	for (int i = 1; i <= V; i++)
	{
		cin >> start;
		cin >> dest;

		while (dest != -1)
		{
			cin >> distance;
			tree[start].push_back({ dest, distance });
			cin >> dest;
		}
	}

	DFS(0, 1);
	memset(visited, 0, sizeof(visited));
	DFS(0, far);

	cout << answer;
	return 0;
}