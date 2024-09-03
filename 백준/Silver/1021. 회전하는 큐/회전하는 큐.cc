#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int main()
{
    fastio;

    int N, M;
    cin >> N >> M;

    deque<int> dq;

    for (int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }

    int answer = 0;
    while (M--)
    {
        int target;
        cin >> target;

        int index = find(dq.begin(), dq.end(), target) - dq.begin();
        int left = index;
        int right = dq.size() - index;

        if (left <= right)
        {
            for (int i = 0; i < left; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                answer++;
            }
        }
        else
        {
            for (int i = 0; i < right; i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                answer++;
            }
        }

        dq.pop_front();
    }

    cout << answer;

    return 0;
}
