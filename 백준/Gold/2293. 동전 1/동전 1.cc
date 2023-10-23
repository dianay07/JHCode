#include <iostream>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n, k;
int dp[11000];

int main()
{
	fastio;
	cin >> n >> k;

	vector<int> arr;

	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		arr.push_back(temp);
	}

	dp[0] = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = arr[i]; j <= k; j++)
		{
			dp[j] = dp[j] + dp[j - arr[i]];
		}
	}

	cout << dp[k];

	return 0;
}