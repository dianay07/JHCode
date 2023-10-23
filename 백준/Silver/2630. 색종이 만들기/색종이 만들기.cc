#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N;
int board[129][129];

int countW = 0;
int countB = 0;

void sol(int X, int Y, int len)
{
	int color = board[X][Y];

	if(color == 0)
	{
		for(int i = X; i < X + len; i++)
		{
			for(int j = Y; j < Y + len; j++)
			{
				if(board[i][j] == 1)
				{
					sol(X, Y, len / 2);
					sol(X + len / 2, Y, len / 2);
					sol(X, Y + len / 2, len / 2);
					sol(X + len / 2, Y + len / 2, len / 2);
					return;
				}
			}
		}

		countW++;
	}
	else if (color == 1)
	{
		for (int i = X; i < X + len; i++)
		{
			for (int j = Y; j < Y + len; j++)
			{
				if (board[i][j] == 0)
				{
					sol(X, Y, len / 2);
					sol(X + len / 2, Y, len / 2);
					sol(X, Y + len / 2, len / 2);
					sol(X + len / 2, Y + len / 2, len / 2);
					return;
				}
			}
		}

		countB++;
	}

}

int main()
{
	fastio;

	cin >> N;

	// 입력
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;

			board[i][j] = temp;
		}
	}

	sol(0, 0, N);
	cout << countW << "\n";
	cout << countB << "\n";

	return 0;
}