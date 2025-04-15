#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	int N, M;
	cin >> N;

	vector<int> want(N);
	for (int i = 0; i < N; i++)
		cin >> want[i];

	cin >> M;

	int answer = 0, left = 0, right = *max_element(want.begin(), want.end());
	while (left <= right)
	{
		// 기준값
		int mid = (left + right) / 2;

		long sum = 0;
		for(int i = 0; i < N; i++)
		{
			// 원하는 예산값이 기준값보다 작으면 원래 값 더하기
			if (want[i] <= mid)
				sum += want[i];
			// 아니면 기준값 더하기
			else
				sum += mid;
		}

		// 총 예산이 최대값보다 크면
		if (sum > M)
		{
			// 오른쪽 조정
			right = mid - 1;
		}
		else
		{
			answer = mid;
			left = mid + 1;
		}
	}

	cout << answer;

    return 0;
}