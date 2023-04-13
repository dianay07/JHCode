#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout. tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

long long K; // the number of lan lines you already have
long long N; // Number of LAN cables required

vector<long long> vec;

long long solution (long long left, long long right)
{
    long long sum = 0;
    long long returnValue = 0;

    while (left <= right)
    {
        long long pivot = (left + right) / 2;
        long long sum = 0;

        for (long long i = 0; i < K; i++)
        {
            sum += vec[i] / pivot;
        }

        if (sum >= N)
        {
            returnValue = pivot;
            left = pivot + 1;
        }
        else
        {
            right = pivot - 1;
        }
    }

    return returnValue;
}

int main()
{
    fastio;

    cin >> K >> N;

    for(long long i = 0; i < K; i++)
    {
        long long input;
        cin >> input;

        vec.push_back(input);
    }

    sort(vec.begin(), vec.end());

    cout << solution(1, vec[K-1]) << "\n";

    return 0;
}
