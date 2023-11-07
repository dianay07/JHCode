#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main(void)
{
    fastio;

	int n, m;
	int board[101][101];

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				board[i][j] = 0;
			else
				board[i][j] = 10000001;
	

	for(int i = 0; i < m; i++)
	{
		int tempA, tempB, value;
		cin >> tempA >> tempB >> value;

		board[tempA - 1][tempB - 1] = min(value, board[tempA - 1][tempB - 1]);
	}

	for(int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 10000001)
				cout << 0 << " ";
			else
				cout << board[i][j] << " ";
		}

		cout << "\n";
	}

	return 0;
}