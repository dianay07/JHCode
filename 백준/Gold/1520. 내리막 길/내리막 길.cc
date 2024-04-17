#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int board[501][501];
int dp[501][501];

int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { -1, 1, 0, 0 };

int M, N;

// 풀이
int DFS(int startX, int startY)
{
	// 목적지 도착
	if (startX >= M - 1 && startY >= N - 1)
		return 1;

	if (dp[startX][startY] != -1)
		return dp[startX][startY];

	dp[startX][startY] = 0;

	for (int i = 0; i < 4; i++)
	{
		int nextX = startX + dirX[i];
		int nextY = startY + dirY[i];

		if (nextX < 0 || nextY < 0 || nextX >= M || nextY >= N)
			continue;

		if (board[startX][startY] <= board[nextX][nextY])
			continue;

		dp[startX][startY] += DFS(nextX, nextY);
	}

	return dp[startX][startY];
}

int main()
{
	fastio;

	cin >> M >> N;

	// 입력
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	cout << DFS(0, 0);

	return 0;
}