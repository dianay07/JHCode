#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        pair<int, int> home, rockFes;
        cin >> home.first >> home.second;

        vector<pair<int, int>> locate;
        locate.push_back(home);

        for (int i = 0; i < n; i++)
        {
            pair<int, int> conv;
            cin >> conv.first >> conv.second;
            locate.push_back(conv);
        }

        cin >> rockFes.first >> rockFes.second;
        locate.push_back(rockFes);

        // BFS를 사용하여 도달 가능 여부를 확인
        queue<pair<int, int>> q;
        vector<bool> visited(n + 2, false);
        q.push(home);
        visited[0] = true;

        bool canReach = false;

        while (!q.empty())
        {
            pair<int, int> current = q.front();
            q.pop();

            // 현재 위치가 락 페스티벌 위치인지 확인
            if (current == rockFes)
            {
                canReach = true;
                break;
            }

            // 모든 위치를 탐색
            for (int i = 0; i < n + 2; i++)
            {
                if (!visited[i])
                {
                    int dist = abs(locate[i].first - current.first) + abs(locate[i].second - current.second);
                    if (dist <= 1000) // 1000m 이내에 도달 가능
                    {
                        visited[i] = true;
                        q.push(locate[i]);
                    }
                }
            }
        }

        if (canReach)
            cout << "happy" << "\n";
        else
            cout << "sad" << "\n";
    }

    return 0;
}