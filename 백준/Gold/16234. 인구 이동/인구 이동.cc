#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n, l, r;
vector<vector<int>> country;
bool visited[101][101];


int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { -1, 1, 0, 0 };

int ret = 0;

bool Solution()
{
	memset(visited, false, sizeof(visited));

	bool flag = false;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == true) continue;

			vector<pair<int, int>> open;
			queue<pair<int, int>> que;
			que.push({ i, j });
			open.push_back({ i,j });
			visited[i][j] = true;

			while (!que.empty())
			{
				int X = que.front().first;
				int Y = que.front().second;
				que.pop();

				for (int k = 0; k < 4; k++)
				{
					int nextX = X + dirX[k];
					int nextY = Y + dirY[k];

					if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= n) continue;
					if (visited[nextX][nextY] == true) continue;

					int distance = abs(country[X][Y] - country[nextX][nextY]);

					if (l <= distance && distance <= r)
					{
						visited[nextX][nextY] = true;
						open.push_back({ nextX, nextY });
						que.push({ nextX, nextY });
					}
				}
			}

			if (open.size() > 1)
			{
				flag = true;

				int sum = 0;
				for (int k = 0; k < open.size(); k++)
				{
					sum += country[open[k].first][open[k].second];
				}

				int value = sum / open.size();
				for (int k = 0; k < open.size(); k++)
				{
					country[open[k].first][open[k].second] = value;
				}
			}
		}
	}

	if (flag == true)
	{
		ret++;
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	fastio;

	cin >> n >> l >> r;
	country.resize(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;

			country[i].push_back(temp);
		}
	}

	bool loop = Solution();
	while (loop == true)
	{
		loop = Solution();
	}

	cout << ret;

	return 0;
}
