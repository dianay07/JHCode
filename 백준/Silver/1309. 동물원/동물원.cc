#include <iostream>
#include <algorithm>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	int N;
	cin >> N;

	int dp[100002];
	dp[1] = 3;
	dp[2] = 7;

	for(int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i-2] + 2 * dp[i-1]) % 9901;
	}

	cout << dp[N];

	return 0;
}