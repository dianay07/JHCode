#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int t;
int x, z;

// 유클 호제
int calc(int a, int b)
{
    int tempA = a;
    int tempB = b;

    int c;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return tempA * tempB / a;
}

int main()
{
    fastio;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> z;
        cout << calc(x, z) << "\n";
    }

    return 0;
}