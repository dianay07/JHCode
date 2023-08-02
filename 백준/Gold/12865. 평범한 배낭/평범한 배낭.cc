#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int dp[101][100001];		// dp 배열 [ 물건수] [버틸수있는 무게]
int N, K;					// 물품의 수 N, 버틸수 있는 무게 K
int W[101];					// 무게
int V[101];					// 가치

int main()
{
	fastio;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			// 가능 무게 보다 물건 무게가 작을 때
			if (j >= W[i])   
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			// 반대로 못 넣을 때
			else 
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}