#include<iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n;
vector<vector<pair<int,int>>> tree;
bool visited[10001];
int answer, far;

void DFS(int sum, int start)
{
	visited[start] = true;

	if (sum > answer)
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
	cin >> n;
	tree.resize(n + 1);

	for(int i = 0; i < n - 1; i++)
	{
		int start, dest, dist;
		cin >> start >> dest >> dist;

		tree[start].push_back({ dest, dist });
		tree[dest].push_back({ start, dist });
	}

	DFS(0, 1);
	memset(visited, 0, sizeof(visited));
	DFS(0, far);

	cout << answer;

	return 0;
}