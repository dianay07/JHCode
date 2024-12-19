#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int dirX[6] = { -2, -2, 0, 0, 2, 2 };
int dirY[6] = { -1, 1, -2, 2, -1, 1 };

int N;
pair<int, int> start;
pair<int, int> dest;

int value[201][201];
bool visited[201][201];

int main()
{
	fastio;

	cin >> N;

	// 보드판
	vector<pair<int,int>> board(N);

	// 좌표 입력
	cin >> start.first >> start.second >> dest.first >> dest.second;

	queue<pair<int, int>> q;
	q.push({ start.first, start.second });
	visited[start.first][start.second] = true;

	while (q.empty() == false)
	{
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();

		for(int i = 0; i < 6; i++)
		{ 
			int nextX = X + dirX[i];
			int nextY = Y + dirY[i];

			if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
				continue;

			if(visited[nextX][nextY] == false)
			{
				visited[nextX][nextY] = true;
				value[nextX][nextY] = max(value[X][Y] + 1, value[nextX][nextY]);
				q.push({ nextX, nextY });
			}
		}
	}

	if (value[dest.first][dest.second] == 0)
		cout << -1;
	else
		cout << value[dest.first][dest.second];

    return 0;
}