#include <iostream>
#include <queue>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

string board[50];
int N, M;

char boardW[8][8] =
{
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};

char boardB[8][8] =
{
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};

// 두종류 정답 체스판 통채로 비교
// 이것들과 모양이 다른 부분을 카운트
int WBCalc(int x, int y)
{
	int count = 0;

	for (int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if (board[x + i][y + j] != boardW[i][j])
				count++;
		}
	}

	return count;
}

int BWCalc(int x, int y)
{
	int count = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[x + i][y + j] != boardB[i][j])
				count++;
		}
	}

	return count;
}

int main()
{
	fastio;

    int answer = 1234;

    cin >> N >> M;

	for (int i = 0; i < N; i++)
        cin >> board[i];

	for (int i = 0; i + 8 <= N; i++)
	{
		for (int j = 0; j + 8 <= M; j++)
		{
			int temp;
			temp = min(WBCalc(i, j), BWCalc(i, j));

			if (temp < answer)
				answer = temp;
		}
	}

    cout << answer;

	return 0;
}