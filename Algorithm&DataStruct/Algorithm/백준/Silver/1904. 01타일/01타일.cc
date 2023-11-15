#include <iostream>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int N;
vector<long long> answer = { 0,1,2 };

void solution()
{
    long long temp;

    for (int i = 3; i <= N; i++)
    {
        temp = 0;
        temp = answer[i - 1] + answer[i - 2];
        answer.push_back(temp % 15746);
    }
}

int main()
{
    fastio;

    cin >> N;
    solution();

    cout << answer[N] % 15746;
}