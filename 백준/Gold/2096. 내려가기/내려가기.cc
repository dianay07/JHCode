#include<iostream>
#include <algorithm>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N;
int board[3];
int Big[3][2];
int Small[3][2];

int main()
{
	fastio;

	cin >> N;

	for(int i = 0; i < 3; i++)
	{
		cin >> board[i];

		Big[i][0] = board[i];
		Small[i][0] = board[i];
	}

	for(int i = 1; i < N; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cin >> board[j];

			if(j == 0)
			{
				// 칸 , 전후
				Big[j][1] = max(Big[j][0], Big[j + 1][0]) + board[j];
				Small[j][1] = min(Small[j][0], Small[j + 1][0]) + board[j];
			}
			else if(j == 1)
			{
				// 1[big[0][0], 2[big[1][0], 3[big[2][0]
				Big[j][1] = max(max(Big[j - 1][0], Big[j][0]), Big[j + 1][0]) + board[j];
				Small[j][1] = min(min(Small[j - 1][0], Small[j][0]), Small[j + 1][0]) + board[j];
			}
			else if (j == 2)
			{
				Big[j][1] = max(Big[j - 1][0], Big[j][0]) + board[j];
				Small[j][1] = min(Small[j - 1][0], Small[j][0]) + board[j];
			}
		}

		for(int j = 0; j < 3; j++)
		{
			Big[j][0] = Big[j][1];
			Small[j][0] = Small[j][1];
		}
	}

	const int AnswerBig = max(max(Big[0][0], Big[1][0]), Big[2][0]);
	const int AnswerSmall = min(min(Small[0][0], Small[1][0]), Small[2][0]);

	cout << AnswerBig << " " << AnswerSmall;

	return 0;
}