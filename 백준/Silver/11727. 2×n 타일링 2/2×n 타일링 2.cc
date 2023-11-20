#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n;
long dp[1001];

int main(void)
{
    fastio;

	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;

	cout << dp[n];

	return 0;
}