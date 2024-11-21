#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int main()
{
	fastio;

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
        cin >> B[i];

    // A를 오름차순 정렬하고 B를 내림차순 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    int answer = 0;
    for (int i = 0; i < N; i++)
        answer += A[i] * B[i];

    cout << answer;

	return 0;
};