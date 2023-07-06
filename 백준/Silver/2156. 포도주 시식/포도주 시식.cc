#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N;
int wine[10001];
int dp[10001];

int main()
{
	fastio;
	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;

		wine[i] = temp;
	}

	dp[0] = 0;
	dp[1] = wine[1];				// 6
	dp[2] = wine[1] + wine[2];		//

	for(int i = 3; i <= N; i++)
	{
		dp[i] = max(max(dp[i - 1], dp[i - 2] + wine[i]), dp[i - 3] + wine[i - 1] + wine[i]);
	}

	cout << dp[N];

	return 0;
}