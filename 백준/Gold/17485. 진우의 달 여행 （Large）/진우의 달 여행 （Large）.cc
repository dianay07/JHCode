#include<iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int road[1001][1001];
int dp[1001][1001][4]; // 0 : 왼쪽, 1 : 중앙, 2 : 오른쪽 
int N, M;

int DP(int x, int y, int dir)
{
    if (x == N)
        return 0;

    if (dp[x][y][dir] != INT_MAX)
        return dp[x][y][dir];

    // 왼쪽
    if (dir != 0 && y - 1 >= 0)
        dp[x][y][dir] = DP(x + 1, y - 1, 0) + road[x][y];

    // 중앙 
    if (dir != 1)
        dp[x][y][dir] = min(dp[x][y][dir], DP(x + 1, y, 1) + road[x][y]);

    // 오른쪽
    if (dir != 2 && y + 1 < M)
        dp[x][y][dir] = min(dp[x][y][dir], DP(x + 1, y + 1, 2) + road[x][y]);

    return dp[x][y][dir];
}

int main(void)
{
    fastio;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> road[i][j];

            for (int k = 0; k < 4; k++)
            {
                dp[i][j][k] = INT_MAX;
            }
        }
    }

    int Min = INT_MAX;
    for (int i = 0; i < M; i++)
    {
        Min = min(Min, DP(0, i, 3));
    }

    cout << Min;

    return 0;
}

