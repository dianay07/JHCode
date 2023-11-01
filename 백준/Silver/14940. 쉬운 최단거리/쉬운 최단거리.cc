#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int n, m;
int board[1001][1001];
int value[1001][1001];

int dirX[4] = { -1, 1, 0, 0 };
int dirY[4] = { 0, 0, -1, 1 };

void Solution(int startX, int startY)
{
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    value[startX][startY] = 0;

    while (!q.empty())
    {
        int X = q.front().first;
        int Y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = X + dirX[i];
            int nextY = Y + dirY[i];

            if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m)
                continue;

            if (value[nextX][nextY] == - 1)
            {
                if (board[nextX][nextY] == 0)
                    continue;
                
            	value[nextX][nextY] = value[X][Y] + 1;
            	q.push({ nextX, nextY });
            }
        }
    }
}

int main()
{
    fastio;

    cin >> n >> m;

    int sX = 0, sY = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            value[i][j] = -1;

            if (board[i][j] == 2)
            {
                sX = i;
                sY = j;
            }
        }
    }

    Solution(sX, sY);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
                cout << 0 << " ";
            else
				cout << value[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}
