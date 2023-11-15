#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N, M;
const int MAX = 987654321;

int main(void)
{
    fastio;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(N, MAX));

	for(int i = 0; i < N; i++)
		board[i][i] = 0;

	for(int i = 0; i < M; i++)
	{
		int start, dest;
		cin >> start >> dest;

		board[start - 1][dest - 1] = 1;
		board[dest - 1][start - 1] = 1;
	}

	// 플로이드-워셜
	for(int k = 0; k < N; k++)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
			}
		}
	}

	int minCost = MAX;
	int minNumber = -1;

	for(int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = 0; j < N; j++)
			sum += board[i][j];

		if(sum < minCost)
		{
			minCost = sum;
			minNumber = i + 1;
		}
	}

	cout << minNumber;
	
	return 0;
}