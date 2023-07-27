#include<iostream>
#include <vector>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)
using namespace std;

int main(void)
{
    fastio;

	int n, m;
	cin >> n >> m;
	vector<long> dp(n + 1);

	dp[0] = 0;

	for (int i = 1; i <= n; i++) 
	{
		long num;
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}

	for (int i = 0; i < m; i++) 
	{
		int start, end;
		cin >> start >> end;

		cout << dp[end] - dp[start - 1] << '\n';
	}


	return 0;
}