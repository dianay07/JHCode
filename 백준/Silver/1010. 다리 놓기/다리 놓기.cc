#include <iostream>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int T;
int N;
int M;

vector<int> vec;

int solution(int a, int b)
{
    int ret = 1;
    int tmp = 1;

    // 29 16
    for(int i = b; i > b -a; --i)
    {
        ret = ret * i;
        ret = ret / tmp++;
    }

    return ret;
}

int main()
{
    fastio;

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> N >> M;

    	cout << solution(N, M) << "\n";
    }

    return 0;
}