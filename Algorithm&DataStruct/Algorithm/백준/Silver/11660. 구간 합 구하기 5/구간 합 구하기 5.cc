#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n, m;
int startX, startY;
int endX, endY;

int sum[1025][1025];

int main(void)
{
	fastio;

	cin >> n >> m;

	sum[0][0] = 0;

	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= n; j++)
		{
			int temp;
			cin >> temp;

			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + temp;
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> startX >> startY;
		cin >> endX >> endY;

		cout << sum[endX][endY] - sum[startX - 1][endY] - sum[endX][startY - 1] + sum[startX - 1][startY - 1] << '\n';
	}

	return 0;
}