#include<iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int num[1000001];
int dp[100001];

int main()
{
	fastio;

	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	int answer = num[0];
	dp[0] = num[0];

	for(int i =1; i < N; i++)
	{
		dp[i] = max(dp[i - 1] + num[i], num[i]);
		answer = max(dp[i], answer);
	}

	cout << answer;

	return 0;
}