#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int N, M;
int dirX[3] = { 1, 0, 1 };
int dirY[3] = { 0, 1, 1 };
int maze[1001][1001];
int best[1001][1001];

int main()
{
	fastio;

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
		}
	}

	best[0][0] = maze[0][0];

	for(int i = 1; i < N; i++)
		best[i][0] = best[i - 1][0] + maze[i][0];

	for(int i = 1; i < M; i++)
		best[0][i] = best[0][i - 1] + maze[0][i];

	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j < M; j++)
		{
			best[i][j] = max(max(best[i - 1][j], best[i][j - 1]), best[i][j - 1])
				+ maze[i][j];
		}
	}

	cout << best[N - 1][M - 1];

	return 0;
};