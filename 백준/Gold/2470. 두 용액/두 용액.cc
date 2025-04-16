#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	int N;
	cin >> N;

	vector<int> liquid(N);
	for (int i = 0; i < N; i++)
		cin >> liquid[i];

	sort(liquid.begin(), liquid.end());

	int offset = INT_MAX;
	int left = 0, right = liquid.size() - 1;
	int minAnswer, maxAnswer;

	while (left < right)
	{
		int mid = (liquid[left] + liquid[right]);

		if (offset > abs(mid))
		{
			offset = abs(mid);

			minAnswer = liquid[left];
			maxAnswer = liquid[right];
		}

		if (mid < 0)
			left++;
		else
			right--;;
	}

	cout << minAnswer << " " << maxAnswer;

    return 0;
}