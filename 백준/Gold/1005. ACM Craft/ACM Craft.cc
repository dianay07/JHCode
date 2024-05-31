#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int T;
int N, K;
int W;

int main()
{
    fastio;

	cin >> T;

    while (T--) 
    {
        cin >> N >> K;

        vector<int> Time;                             // 건설 시간
        vector<int> Degree(N + 1, 0);       // 차수 백터
        vector<vector<int>> Building(N + 1);    // 건물 그래프
        vector<int> Result(N + 1, 0);       // 최소 시간 저장 메모이제이션

        // 건설 시간 입력
        Time.push_back(0);              // 번호 맞추기
        for (int i = 1; i <= N; i++) 
        {
            int value;
            cin >> value;

            Time.push_back(value);
        }

        // 건물 그래프, 차수 입력
        for (int i = 0; i < K; i++)
        {
            int X, Y;
            cin >> X >> Y;

            Building[X].push_back(Y);
            Degree[Y]++;
        }

        // 최종 목적지 건물 입력
        cin >> W;


        // 위상 정렬 시작
        queue<int> q;
        // 진입 차수가 0인 노드를 큐에 삽입
        for (int i = 1; i <= N; i++) 
        {
            if (Degree[i] == 0) 
            {
                q.push(i);
                Result[i] = Time[i]; // 초기 건물 시간 저장
            }
        }

        while (!q.empty()) 
        {
            int current = q.front();
            q.pop();

            for (int i = 0; i < Building[current].size(); i++) 
            {
                int next = Building[current][i];
                Result[next] = max(Result[next], Result[current] + Time[next]); //  최소 시간 갱신
                Degree[next]--;

                if (Degree[next] == 0) 
                    q.push(next);
            }
        }

        cout << Result[W] << '\n'; 
    }
    return 0;
}
