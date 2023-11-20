#include<iostream>
#include <queue>
#include <cstring>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int map[1001][1001];
bool visited[1001][1001][2];
int n, m;

int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { -1, 1, 0, 0 };

typedef struct board
{
	int x;			// x 좌표
	int y;			// x 좌표
	int dist;	// 거리
	bool breakWall;	// 벽 부순 여부
};

int Solution()
{
	queue<board> q;
	q.push({ 0,0, 1, false });
	visited[0][0][0] = true;

	while(!q.empty())
	{
		board cur = q.front();
		q.pop();

		if (cur.x == m - 1 && cur.y == n - 1)
			return cur.dist;

		for (int i = 0; i < 4; i++)
		{
			// 배열의 x와 y를 뒤집어서 계산
			int nx = cur.x + dirX[i];
			int ny = cur.y + dirY[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

			// 벽을 마주쳣는데 벽을 안꺳을때
			if (map[ny][nx] == 1 && cur.breakWall == 0)
			{
				// 벽 깨고 거리 계산
				visited[ny][nx][cur.breakWall + 1] = true;
				q.push({ nx,ny, cur.dist + 1, true });
			}
			// 벽없이 갈수 있는길인데 벽 안깻을때
			else if(map[ny][nx] == 0 && visited[ny][nx][cur.breakWall] == false)
			{
				// 계속 전진
				visited[ny][nx][cur.breakWall] = true;
				q.push({ nx,ny,cur.dist + 1, cur.breakWall });
			}
			// 이도 저도 아니면 이동 종료
		}
	}

	return -1;
}

int main(void)
{
    fastio;

	cin >> n >> m;
	memset(map, -1, sizeof(map));

	for(int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		for(int j = 0; j < m; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	cout << Solution();

 	return 0;
}