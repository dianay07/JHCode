#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int graph[100][100][100];
int dir[6][3]{ {1,0,0},{0,1,0},{-1,0,0},{0,-1,0},{0,0,1},{0,0,-1} };
int R, C, H;
queue<pair<pair<int, int>, int>> q;

void bfs()
{
	int cnt = 0;

	while (!q.empty())
	{
		int size = q.size();
		cnt++;

		for (int i = 0; i < size; i++)
		{
			int r = q.front().first.first;
			int c = q.front().first.second;
			int h = q.front().second;

			q.pop();
			for (int j = 0; j < 6; j++) 
			{
				int nextR = r + dir[j][0];
				int nextC = c + dir[j][1];
				int nextH = h + dir[j][2];

				if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C && nextH >= 0 && nextH < H 
					&& graph[nextH][nextR][nextC] == 0)
				{
					q.push({ {nextR,nextC} ,nextH });
					graph[nextH][nextR][nextC] = 1;
				}
			}
		}
	}
	
	for (int i = 0; i < H; i++) 
	{
		for (int j = 0; j < R; j++)
		{
			for (int k = 0; k < C; k++)
			{
				if (graph[i][j][k] == 0)
				{
					cout << -1;
					return;
				}
			}
		}
	}
	
	cout << cnt - 1;
}

int main()
{
	fastio;

	cin >> C >> R >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < R; j++) 
		{
			for (int k = 0; k < C; k++) 
			{
				cin >> graph[i][j][k];
				if (graph[i][j][k] == 1) 
				{
					q.push({ {j,k},i });
				}
			}
		}
	}

	bfs();

	return 0;
}