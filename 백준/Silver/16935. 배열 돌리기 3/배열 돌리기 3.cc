#include <iostream>
#include<string.h>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int board[101][101];
int temp[101][101];
int N, M;
int R;

void Command1()			// 상하 반전
{
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			temp[i][j] = board[N - 1 - i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			board[i][j] = temp[i][j];
		}
	}
}

void Command2()			// 좌우 반전
{
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			temp[i][j] = board[i][M - 1 - j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			board[i][j] = temp[i][j];
		}
	}
}

void Command3()	// 오른쪽 90도 회전
{
	memset(temp, 0, sizeof(temp));

	int value = N;

	swap(N, M);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			temp[i][j] = board[value - 1 - j][i];
		}
	}
		
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = temp[i][j];
		}
	}
}

void Command4()	// 왼족 90도 회전
{
	memset(temp, 0, sizeof(temp));

	int value = M;

	swap(N, M);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			temp[i][j] = board[j][value - 1 - i];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = temp[i][j];
		}
	}
}

void Command5()
{
	memset(temp, 0, sizeof(temp));

	int splitN = N / 2;
	int splitM = M / 2;

	// 원본 1번 그룹 이동
	for (int i = 0; i < splitN; i++)
	{
		for (int j = 0; j <splitM; j++)
		{
			temp[i][j + splitM] = board[i][j];
		}
	}

	// 원본 2번 그룹 이동
	for (int i = 0; i < splitN; i++)
	{
		for (int j = 0; j < splitM; j++)
		{
			temp[i + splitN][j + splitM] = board[i][j + splitM];
		}
	}

	// 원본 3번 그룹 이동
	for (int i = 0; i < splitN; i++)
	{
		for (int j = 0; j < splitM; j++)
		{
			temp[i + splitN][j] = board[i + splitN][j + splitM];
		}
	}

	// 원본 4번 그룹 이동
	for (int i = 0; i < splitN; i++)
	{
		for (int j = 0; j < splitM; j++)
		{
			temp[i][j] = board[i + splitN][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = temp[i][j];
		}
	}
}

void Command6()
{
	memset(temp, 0, sizeof(temp));

	int splitN = N / 2;
	int splitM = M / 2;

	// 원본 1번 그룹 이동
	for (int i = 0; i < splitN; i++)
	{
		for (int j = 0; j < splitM; j++)
		{
			temp[i + splitN][j] = board[i][j];
		}
	}

	// 원본 2번 그룹 이동
	for (int i = 0; i < splitN; i++)
	{
		for (int j = 0; j < splitM; j++)
		{
			temp[i][j] = board[i][j + splitM];
		}
	}

	// 원본 3번 그룹 이동
	for (int i = 0; i < splitN; i++)
	{
		for (int j = 0; j < splitM; j++)
		{
			temp[i][j + splitM] = board[i + splitN][j + splitM];
		}
	}

	// 원본 4번 그룹 이동
	for (int i = 0; i < splitN; i++)
	{
		for (int j = 0; j < splitM; j++)
		{
			temp[i + splitN][j + splitM] = board[i + splitN][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = temp[i][j];
		}
	}
}

void solution(int num)
{
	switch (num)
	{
		// 상하 반전
	case 1 :
			Command1();
		break;
		// 좌우 반전
	case 2:
		Command2();
		break;
		// 오른쪽 90도 회전
	case 3:
		Command3();
		break;
		// 왼쪽 90도 회전
	case 4:
		Command4();
		break;
		// N/2, M/2 4개의 부분배열, 1->2, 2->3, 3->4, 4->1
	case 5:
		Command5();
		break;
		// 1->4, 2->1, 3->2, 4->3
	case 6:
		Command6();
		break;
	}
}

int main()
{
	fastio;

	cin >> N >> M >> R;

	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < R; i++)
	{
		int type;
		cin >> type;

		solution(type);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << board[i][j] << " ";
		}

		cout << "\n";
	}

	return 0;
}