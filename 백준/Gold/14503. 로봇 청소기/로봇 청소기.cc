#include <iostream>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int N, M;
int startX, startY, dir;
vector<vector<int>> map(50, vector<int>(50));
vector<vector<int>> visited(50, vector<int>(50));

// 위, 오른쪽, 아래, 왼쪽
int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

void dfs(int x, int y, int d, int sum)
{
    // 현재 위치 청소
    visited[x][y] = 1;

    // 왼쪽부터 반시계 방향으로 탐색
    for (int i = 0; i < 4; i++)
    {
        int nextDir = (d + 3 - i) % 4; // 반시계 방향으로 회전
        int nextX = x + dirX[nextDir];
        int nextY = y + dirY[nextDir];

        // 범위를 벗어나거나 벽인 경우
        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M || map[nextX][nextY] == 1)
            continue;

        // 청소하지 않은 공간이 존재
        if (visited[nextX][nextY] == 0 && map[nextX][nextY] == 0) 
        {
            dfs(nextX, nextY, nextDir, sum + 1);
            return; // 청소 후 종료
        }
    }

    // 후진 로직
    int backDir = (d + 2) % 4; // 현재 방향의 반대 방향
    int backX = x + dirX[backDir];
    int backY = y + dirY[backDir];

    // 후진할 수 있는지 확인
    if (backX >= 0 && backX < N && backY >= 0 && backY < M && map[backX][backY] == 0)
    {
        dfs(backX, backY, d, sum); // 한 칸 후진
    }
    else 
    {
        // 후진할 수 없으면 현재 청소한 칸의 수 출력
        cout << sum << endl;
        exit(0);
    }
}

int main()
{
    fastio;

    cin >> N >> M;
    cin >> startX >> startY >> dir;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cin >> map[i][j];
            visited[i][j] = 0; // 방문 배열 초기화
        }
    }

    dfs(startX, startY, dir, 1); // 청소 시작

    return 0;
}
