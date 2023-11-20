#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

// 상 하 좌 우
int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { -1, 1, 0, 0 };

int n, k;		// 행의 갯수, 바이러스 종류
int s, x, y;	// 진행 초 수, 찾을 위치 좌표

vector<vector<int>> board;
// 바이러스 전파 큐
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

void Spread()
{
	while(s > 0)
	{
		s--;

		int count = pq.size();
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> SubPQ;

		for(int i =0; i < count; i++)
		{
			SubPQ.push(pq.top());
			pq.pop();
		}

		while(!SubPQ.empty())
		{
			pair<int, pair<int, int>> data;
			data = SubPQ.top();
			SubPQ.pop();

			int virusSpecies = data.first;
			int X = data.second.first;
			int Y = data.second.second;

			for(int i = 0; i < 4; i++)
			{
				int nextX = X + dirX[i];
				int nextY = Y + dirY[i];

				if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= n) continue;
				//if (visited[nextX][nextY] == true) continue;
				
				if(board[nextX][nextY] == 0)
				{
					board[nextX][nextY] = virusSpecies;
					//visited[nextX][nextY] = true;

					pq.push({ virusSpecies, {nextX, nextY} });
				}
			}
		}

	}
}

int main()
{
	fastio;
	cin >> n >> k;

	board.resize(n);
	//visited.resize(n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;

			board[i].push_back(temp);

			if (temp > 0 && temp <= k)
				pq.push({ temp, {i,j} });
		}
	}

	cin >> s >> x >> y;

	Spread();
	cout << board[x - 1][y - 1] << "\n";

	return 0;
}