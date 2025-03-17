#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	int n;
	cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	vector<int> dp(n, 1);

	int count = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vec[i] > vec[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}

			count = max(count, dp[i]);
		}
	}

	cout << count;

    return 0;
}