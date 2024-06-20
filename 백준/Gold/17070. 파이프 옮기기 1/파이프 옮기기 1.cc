#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N;
int board[16][16];
int dirX[3] = { 0, 1, 1 };
int dirY[3] = { 1, 0, 1 };
int answer = 0;

void Move(int x, int y, int dir)
{
	if (x == N - 1 && y == N - 1)
	{
		answer++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if((dir == 0 && i == 1) || (dir == 1 && i == 0))
			continue;

		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		// 범위 밖
		if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
			continue;

		// 벽
		if (board[nextX][nextY] == 1)
			continue;

		// 대각선 이동 시 벽 체크
		if (i == 2 && (board[x + 1][y] == 1 || board[x][y + 1] == 1))
			continue;

		Move(nextX, nextY, i);
	}
}

int main()
{
	fastio;
	cin >> N;

	// 벽지 세팅
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	Move(0, 1, 0);
	cout << answer;

	return 0;
}
