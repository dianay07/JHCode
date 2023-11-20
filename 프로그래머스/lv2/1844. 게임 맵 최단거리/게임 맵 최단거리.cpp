#include <vector>
#include <queue>
using namespace std;

int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { 1, -1, 0, 0 };

int board[100][100];
bool visited[100][100];
int value[100][100] = {1};

void bfs(int curX, int curY, int column, int row)
{
    queue<pair<int, int>> que;
    que.push({ curX, curY });

    while(!que.empty())
    {
        int X = que.front().first;
        int Y = que.front().second;
        que.pop();

        if (X == row && Y == column)
            return;

        for (int i = 0; i < 4; i++)
        {
            int nextX = X + dirX[i];
            int nextY = Y + dirY[i];

            if (nextX < 0 || nextY < 0 || nextX >= column || nextY >= row)
                continue;

            if(visited[nextX][nextY] == false && board[nextX][nextY] == 1)
            {
                visited[nextX][nextY] = true;
                que.push({ nextX, nextY });
                value[nextX][nextY] = value[X][Y] + 1;
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = -1;

    int N = maps.size();
    int M = maps[0].size();

    for(int i = 0; i < N; i++)
    {
	    for(int j = 0; j < M; j++)
	    {
            board[i][j] = maps[i][j];
	    }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(board[i][j] == 1 && visited[i][j] == false)
            {
                bfs(0, 0, maps.size(), maps[0].size());
            }
        }
    }

    if (value[N - 1][M - 1] == 0)
        answer = -1;
    else
        answer = value[N - 1][M - 1];

    return answer;
}