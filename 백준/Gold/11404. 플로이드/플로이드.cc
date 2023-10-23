#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n, m;
vector<vector<pair<int, int>>> bus;
int cost[101][101];

void Solution()
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
}

int main()
{
	fastio;

	cin >> n >> m;
	bus.resize(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 시작과 도착이 같은 경우
			if (i == j)
				cost[i][j] = 0;
			else
				cost[i][j] = 10000001;
		}
	}

	for(int i = 0; i < m; i++)
	{
		int start, dest;
		int value;

		cin >> start >> dest >> value;
		cost[start - 1][dest - 1] = min(value, cost[start-1][dest-1]);
	}

	Solution();

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (cost[i][j] == 10000001)
				cout << 0 << " ";
			else
				cout << cost[i][j] << " ";
		}

		cout << "\n";
	}

	return 0;
}