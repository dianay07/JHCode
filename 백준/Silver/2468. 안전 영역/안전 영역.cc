#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

vector<vector<int>> board;
vector<vector<bool>> visited;
int N;
int temp = 0, best = 0;
// 상, 하, 좌, 우
int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { -1, 1, 0,0 };

void bfs(int x, int y, int level)
{
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (q.empty() == false)
	{
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = X + dirX[i];
			int nextY = Y + dirY[i];

			if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
				continue;

			if(visited[nextX][nextY] == false && board[nextX][nextY] > level)
			{
				visited[nextX][nextY] = true;
				q.push({ nextX, nextY});
			}
		}
	}
}

int main()
{
	fastio;

	cin >> N;
	board.resize(N, vector<int>(N));
	visited.resize(N, vector<bool>(N));

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	int level = -1;
	while (++level < 101)
	{
		temp = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				visited[i][j] = false;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if(board[i][j] > level && visited[i][j] == false)
				{
					bfs(i, j, level);
					temp++;
				}
			}
		}

		best = max(temp, best);
		/*if (best > temp)
			break;*/
	}

	cout << best;

	return 0;
};