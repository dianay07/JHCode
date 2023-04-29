#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int dirX[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dirY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

struct Position
{
    int x;
    int y;
};

int N;
string kingPos;
string stonePos;

Position king;
Position stone;

int main ()
{
    fastio;
    string direction;
    cin >> kingPos >> stonePos;

    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            king.y = kingPos[i] - 'A';
            stone.y = stonePos[i] - 'A';
        }
        else
        {
            king.x = '8' - kingPos[i];
            stone.x = '8' - stonePos[i];
        }
    }

    cin >> N;
    int dir = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> direction;

        if (direction == "R") dir = 0;
        else if (direction == "L") dir = 1;
        else if (direction == "B") dir = 2;
        else if (direction == "T") dir = 3;
        else if (direction == "RT") dir = 4;
        else if (direction == "LT") dir = 5;
        else if (direction == "RB") dir = 6;
        else if (direction == "LB") dir = 7;

        int nextKingX = king.x + dirX[dir];
        int nextKingY = king.y + dirY[dir];

        if (nextKingX < 0 || nextKingX >= 8 || nextKingY < 0 || nextKingY >= 8) 
            continue;

        if (nextKingX == stone.x && nextKingY == stone.y)
        {
            int nextStoneX = stone.x + dirX[dir];
            int nextStoneY = stone.y + dirY[dir];

            if (nextStoneX < 0 || nextStoneX >= 8 || nextStoneY < 0 || nextStoneY >= 8)
                continue;

            stone.x = nextStoneX; stone.y = nextStoneY;
        }
        king.x = nextKingX; king.y = nextKingY;
    }

    cout << (char)(king.y + 'A') << 8 - king.x << '\n';
    cout << (char)(stone.y + 'A') << 8 - stone.x << '\n';

    return 0;
}