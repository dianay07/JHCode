#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N, M;
vector<vector<int>> board;
bool visited[501][501];
int answer;

int dirX[4] = { 0, 1, 0, -1 };
int dirY[4] = { 1, 0, -1, 0 };

// 첫입력이 세로, 두번째가 가로

void brute(int X, int Y)
{
	// ㅗ
	if (X + 1 < N && Y + 2 < M)
		answer = max(answer, board[X][Y] + board[X][Y + 1] + board[X][Y + 2] + board[X + 1][Y + 1]);
	// ㅏ
	if (X + 2 < N && Y + 1 < M)
		answer = max(answer, board[X][Y] + board[X + 1][Y] + board[X + 1][Y + 1] + board[X + 2][Y]);
	// ㅜ
	if (X - 1 >= 0 && Y + 2 < M)
		answer = max(answer, board[X][Y] + board[X][Y + 1] + board[X][Y + 2] + board[X - 1][Y + 1]);
	// ㅓ
	if (X + 2 < N && Y - 1 >= 0)
		answer = max(answer, board[X][Y] + board[X + 1][Y] + board[X + 1][Y - 1] + board[X + 2][Y]);
}

void Solution(int X, int Y, int length, int sum)
{
	if (length == 4)
	{
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextX = X + dirX[i];	
		int nextY = Y + dirY[i];	

		if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M)
			continue;

		if(visited[nextX][nextY] == true)
			continue;

		visited[nextX][nextY] = true;
		Solution(nextX, nextY, length + 1, sum + board[nextX][nextY]);
		visited[nextX][nextY] = false;
	}
}

int main()
{
	fastio;

	cin >> N >> M;

	board.resize(N);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			int temp;
			cin >> temp;

			board[i].push_back(temp);
		}
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			brute(i, j);

			visited[i][j] = true;
			Solution(i, j, 1, board[i][j]);
			visited[i][j] = false;
		}
	}

	cout << answer;

	return 0;
}