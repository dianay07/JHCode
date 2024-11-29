#include <iostream>
#include <string>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

long long dp[101][10];

int main()
{
	fastio;

	int N;
	cin >> N;

    for (int i = 1; i < 10; i++) // 0은 제외하고 1부터 9까지
        dp[1][i] = 1;
   
    for (int i = 2; i <= N; i++) 
    {
        dp[i][0] = dp[i - 1][1]; // 0으로 시작할 수 있는 경우
        dp[i][9] = dp[i - 1][8]; // 9로 시작할 수 있는 경우

        for (int j = 1; j < 9; j++) // 1부터 8까지
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }

    int answer = 0;
    for (int i = 0; i < 10; i++)
        answer = (answer + dp[N][i]) % 1000000000;

    cout << answer;

	return 0;
};