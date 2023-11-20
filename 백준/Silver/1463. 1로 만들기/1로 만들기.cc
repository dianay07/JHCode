#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int dp[10000001] = { -1 };

void m(int n)
{
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++)
	{
		// 1 뺴기
		dp[i] = dp[i - 1] + 1;

		// 2 나누기
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		// 3 나누기
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
	}
}

int main()
{
	fastio;

	/* 차장보고 */ // fill in ??
	memset(dp, -1, sizeof(dp));

	int x;
	cin >> x;

	m(x);

	cout << dp[x];

	return 0;
}