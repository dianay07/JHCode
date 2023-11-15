#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n, r, c;
int ans;

// 행 = r , 열 = c
void Z(int row, int column, int size)
{
    if (row == r && column == c)
    {
        cout << ans << '\n';
        return;
    }

    if (r < row + size && r >= row && c < column + size && c >= column)
    {
        Z(row, column, size / 2);
        Z(row, column + size / 2, size / 2);
        Z(row + size / 2, column, size / 2);
        Z(row + size / 2, column + size / 2, size / 2);
    }
    else
    {
        ans += size * size;
    }
}
int main()
{
    fastio;

    cin >> n >> r >> c;
    Z(0, 0, (1 << n));
    return 0;
}