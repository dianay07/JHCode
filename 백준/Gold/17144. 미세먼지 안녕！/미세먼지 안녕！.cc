#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int R, C, T;
int Board[51][51];
int NewBoard[51][51];
pair<int, int> AirPos[2];

// 상하 좌우
int dirX[4] = { 0, 0, -1, 1 };
int dirY[4] = { -1, 1, 0, 0 };

void Spread()
{
    // 원본 복사
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            NewBoard[i][j] = Board[i][j];
        }
    }

    // 먼지 확산
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            // 먼지 있으면
            if (Board[i][j] > 0)
            {
                int divideCount = 0;
                int value = Board[i][j] / 5;

                for (int k = 0; k < 4; k++)
                {
                    int nextX = i + dirX[k];
                    int nextY = j + dirY[k];

                    if (nextX < 0 || nextY < 0 || nextX >= R || nextY >= C)
                        continue;

                    // 
                    if (Board[nextX][nextY] != -1)
                    {
                        NewBoard[nextX][nextY] = NewBoard[nextX][nextY] + value;
                        divideCount++;
                    }
                }
                NewBoard[i][j] = NewBoard[i][j] - (divideCount * value);
            }
        }
    }

    // 전달
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            Board[i][j] = NewBoard[i][j];
        }
    }
}

void Clean()
{
    for (int index = 0; index < 2; index++)
    {
        if (index == 0)
        {
            for (int i = AirPos[index].first - 1; i > 0; i--)
            {
                Board[i][0] = Board[i - 1][0];
            }

            for (int i = 0; i < C - 1; i++)
            {
                Board[0][i] = Board[0][i + 1];
            }

            for (int i = 1; i <= AirPos[index].first; i++)
            {
                Board[i - 1][C - 1] = Board[i][C - 1];
            }

            for (int i = C - 1; i > 1; i--)
            {
                Board[AirPos[index].first][i] = Board[AirPos[index].first][i - 1];
            }
            Board[AirPos[index].first][1] = 0;
        }
        else
        {
            for (int i = AirPos[index].first + 1; i < R - 1; i++)
            {
                Board[i][0] = Board[i + 1][0];
            }

            for (int i = 0; i < C - 1; i++)
            {
                Board[R - 1][i] = Board[R - 1][i + 1];
            }

            for (int i = R - 1; i > AirPos[index].first; i--)
            {
                Board[i][C - 1] = Board[i - 1][C - 1];
            }

            for (int i = C - 1; i > 1; i--)
            {
                Board[AirPos[index].first][i] = Board[AirPos[index].first][i - 1];
            }
            Board[AirPos[index].first][1] = 0;
        }
    }
}

int main()
{
    fastio;
    cin >> R >> C >> T;

    int PosIndex = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> Board[i][j];

            // 공기청정기면
            if (Board[i][j] == -1)
            {
                AirPos[PosIndex].first = i;
                AirPos[PosIndex].second = j;
                PosIndex++;
            }
        }
    }

    while (T--)
    {
        Spread();
        Clean();
    }

    int answer = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (Board[i][j] == -1) continue;

            answer += Board[i][j];
        }
    }

    cout << answer;

    return 0;
}
