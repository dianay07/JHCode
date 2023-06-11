#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int N;				// 계단 수
int dp[301];		// 합 
int stair[301];		// 계단 별 점수

int main()
{
	fastio;

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >> x;

		stair[i] = x;
	}

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

	// 계단 2개나 1개
	for (int i = 4; i <= N; i++)
	{
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}

	cout << dp[N];
	return 0;
}