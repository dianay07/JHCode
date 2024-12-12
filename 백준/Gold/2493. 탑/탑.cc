#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int main()
{
    fastio;

    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; i++)
        cin >> heights[i];

    stack<int> s;                   // 높이 저장할 스택
    vector<int> answer(N, 0);   // 출력 벡터

    for (int i = 0; i < N; i++)
    {
        // 광선 먼저 쏘는 놈의 제일 먼저 걸리는 탑 체크
        while (s.empty() == false && heights[s.top()] < heights[i])
        {
            // 걸리면 높이 제거
            s.pop();
        }

        // 안걸리면 높이 추가
        if (s.empty() == false)
        {
            answer[i] = s.top() + 1;
        }

        s.push(i);
    }

    for (int i = 0; i < N; i++)
        cout << answer[i] << " ";

    return 0;
}
