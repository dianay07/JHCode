#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	int N, K;
	cin >> N >> K;

	vector<int> level(N);
	for (int i = 0; i < N; i++)
		cin >> level[i];

	int MIN = 1, MAX = 1000000001;
	int answer = 0;

	while (MIN <= MAX)
	{
		int mid = (MIN + MAX) / 2;

		long sum = 0;
		for(int i = 0; i < N; i++)
		{
			if (level[i] < mid)
				sum += mid - level[i];
		}

		if (K < sum)
			MAX = mid - 1;
		else
		{
			answer = mid;
			MIN = mid + 1;
		}
	}

	cout << answer;
    return 0;
}