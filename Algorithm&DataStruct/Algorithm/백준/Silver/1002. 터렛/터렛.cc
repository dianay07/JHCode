#include <iostream>
#include <math.h>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int T;
int X1, Y1, R1;
int X2, Y2, R2;

int solution(int x1, int y1, int r1, int x2, int y2, int r2)
{
    double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double big = 0;
    double small = 0;

    if (r1 > r2)
    {
        big = r1;
        small = r2;
    }
    else
    {
        big = r2;
        small = r1;
    }

    // 동심원
    if (x1 == x2 && y1 == y2 && r1 == r2)
        return -1;

    // return 2
    if (big - small < distance && big + small > distance)
        return 2;

    // return 1
    if (small + big == distance || big - small == distance)
        return 1;

    // return 0
    if (small + big < distance || distance < big - small || distance == 0)
        return 0;

    return -1;
}

int main()
{
    fastio;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> X1 >> Y1 >> R1;
        cin >> X2 >> Y2 >> R2;

        cout << solution(X1, Y1, R1, X2, Y2, R2) << "\n";
    }


    return 0;
}