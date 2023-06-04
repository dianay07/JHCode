#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int houseCost[1001][3];

int main()
{
	fastio;

    int N;
    int a, b, c;
    houseCost[0][0] = 0;
    houseCost[0][1] = 0;
    houseCost[0][2] = 0;

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a >> b >> c;
        houseCost[i][0] = min(houseCost[i - 1][1], houseCost[i - 1][2]) + a;
        houseCost[i][1] = min(houseCost[i - 1][0], houseCost[i - 1][2]) + b;
        houseCost[i][2] = min(houseCost[i - 1][1], houseCost[i - 1][0]) + c;
    }
    cout << min(houseCost[N][2], min(houseCost[N][0], houseCost[N][1]));

	return 0;
}