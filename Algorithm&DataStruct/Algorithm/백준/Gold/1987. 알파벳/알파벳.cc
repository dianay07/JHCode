#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

// 상 하 좌 우
int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { -1, 1, 0, 0 };

int r, c;
char board[21][21];
bool visited[26];
int value[21][21];

int ret = 1;
int countNum = 1;

void Solution(int x, int y)
{
	visited[board[0][0] - 'A'] = true;

	for(int i = 0; i < 4; i++)
	{
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if(nextX < 0 || nextY < 0 || nextX >= r || nextY >= c) continue;
		if(visited[board[nextX][nextY] - 'A'] == true) continue;

		visited[board[nextX][nextY] - 'A'] = true;
		value[nextX][nextY] = value[x][y] + 1;
		Solution(nextX, nextY);
		visited[board[nextX][nextY] - 'A'] = false;
		ret = max(ret, value[nextX][nextY]);
	}
}

int main(void)
{
    fastio;

	cin >> r >> c;

	for(int i = 0; i < r; i++)
	{
		string str;
		cin >> str;

		for(int j = 0; j < c; j++)
		{
			board[i][j] = str[j];
		}
	}

	value[0][0] = 1;
	Solution(0 ,0);

	cout << ret;

	return 0;
}