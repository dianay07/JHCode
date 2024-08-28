#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

long long dp[91];

int main()
{
	fastio;

	int N;
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for(int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N];

	return 0;
}