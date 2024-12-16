#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

vector<int> vec;

int main()
{
    fastio;

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    vec.resize(F + 1, -1);

    queue<int> q;
    q.push(S);
    vec[S] = 0;

    while (q.empty() == false)
    {
        int cur = q.front();
        q.pop();

        // 도착
        if(cur == G)
        {
            cout << vec[cur] << endl;
            return 0;
        }

        // U만큼 올랏을때 F 안넘고 안 들린곳이면
        if(cur + U <= F && vec[cur + U] == -1)
        {
            vec[cur + U] = vec[cur] + 1;
            q.push(cur + U);
        }

        // D만큼 내렸을 때 1보다 크고 안 들린곳이면
        if(cur - D >= 1 && vec[cur - D] == -1)
        {
            vec[cur - D] = vec[cur] + 1;
            q.push(cur - D);
        }
    }

    cout << "use the stairs" << endl;

    return 0;
}