#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int board[22][22];
int dist[22][22];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int returnValue = 0, sharkSize = 2;
int n, x, y;
int eatfish = 0;

int main()
{
	fastio;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				x = i;
				y = j;
			}
		}
	}

	while (true)
	{
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				dist[i][j] = -1;

		dist[x][y] = 0;
		board[x][y] = 0;
		queue<pair<int, int>> q;
		vector<pair<int, int>> fish;

		if (eatfish >= sharkSize)
		{
			eatfish -= sharkSize;
			sharkSize++;
		}

		q.push({x, y});

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

				if (dist[nx][ny] != -1) continue;
				if (board[nx][ny] > sharkSize) continue;
				if (board[nx][ny] == sharkSize || board[nx][ny] == 0)
				{
					dist[nx][ny] = dist[cur.first][cur.second] + 1;
					q.push({nx, ny});
				}
				else if (board[nx][ny] < sharkSize && board[nx][ny] >= 1)
				{
					dist[nx][ny] = dist[cur.first][cur.second] + 1;
					fish.push_back({nx, ny});
					q.push({nx, ny});
				}
			}
		}
		if (fish.size() == 0)
		{
			cout << returnValue << "\n";
			return 0;
		}
		if (fish.size() == 1)
		{
			x = fish[0].first;
			y = fish[0].second;
			board[x][y] = 0;
			eatfish++;
			returnValue += dist[x][y];
		}
		else
		{
			int mindist = 1e5;
			for (auto& x : fish)
			{
				mindist = min(mindist, dist[x.first][x.second]);
			}

			int mincnt = 0;
			vector<pair<int, int>> minfish;
			for (auto& x : fish)
			{
				if (mindist == dist[x.first][x.second])
				{
					minfish.push_back({x.first, x.second});
				}
			}

			if (minfish.size() == 1)
			{
				x = minfish[0].first;
				y = minfish[0].second;
				board[x][y] = 0;
				returnValue += dist[x][y];
				eatfish++;
			}
			else
			{
				sort(minfish.begin(), minfish.end());
				x = minfish[0].first;
				y = minfish[0].second;
				returnValue += dist[x][y];
				board[x][y] = 0;
				eatfish++;
			}
		}
	}
}
