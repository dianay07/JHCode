#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	int N, S, M;
	cin >> N >> S >> M;

	// 곡 순서, 볼륨값 = 연주가능여부
	bool dp[51][1001] = { false };
	dp[0][S] = true;

	vector<int> volume(N);
	for (int i = 0; i < N; i++)
		cin >> volume[i];

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= M; j++)
		{
			// 연주 가능하면
			if(dp[i][j] == true)
			{
				// 볼륨값이 M보다 안커지면
				if (j + volume[i] <= M)
					dp[i + 1][j + volume[i]] = true;
				// 볼륨값이 0보다 안작아지면
				if (j - volume[i] >= 0)
					dp[i + 1][j - volume[i]] = true;
			}
		}
	}

	int answer = -1;
	for(int i = 0; i <= M; i++)
	{
		if (dp[N][i])
			answer = i;
	}

	cout << answer;

    return 0;
}