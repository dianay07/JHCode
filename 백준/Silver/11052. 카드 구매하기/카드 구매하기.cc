#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int main()
{
    fastio;

    int N;
    cin >> N;

    vector<int> price(N + 1);

	for (int i = 1; i <= N; ++i) 
        cin >> price[i];

    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; ++i) 
    {
        for (int j = 1; j <= i; ++j) 
        {
            dp[i] = max(dp[i], dp[i - j] + price[j]);
        }
    }

    cout << dp[N] << endl;

    return 0;
}
