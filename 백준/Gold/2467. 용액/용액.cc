#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int main()
{
    fastio;

    int N;
    cin >> N;

    vector<int> liquid(N);

    for(int i = 0; i < N; i++)
        cin >> liquid[i];

    int start = 0, end = N - 1;
    int temp = INT_MAX;
    pair<int, int> answer;

    while(start < end)
    {
        int pivot = liquid[start] + liquid[end];

        // 딱뎀
        if(pivot == 0)
        {
            answer = { liquid[start], liquid[end] };
            break;
        }

    	// 점점 작아지는중
    	if(temp >= abs(pivot))
        {
            answer = { liquid[start], liquid[end] };
            temp = abs(pivot);
        }

        if (pivot > 0)
            end--;
        else
            start++;
    }

    cout << answer.first << " " << answer.second;

    return 0;
}
