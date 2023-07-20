#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

long long n, k;

long long GetCount(long long mid)
{
	long long ret = 0;
	for(int i = 1; i <= n; i++)
	{
		ret += min(n, (long long)mid / i);
		if (i > mid)
			break;
	}

	return ret;
}

void Solution()
{
	long long left = 1;
	long long right = n * n;

	int answer = 0;

	while(left <= right)
	{
		long long mid = (left + right) / 2;

		if(GetCount(mid) < k)
		{
			left = mid + 1;
		}
		else if(GetCount(mid) >= k)
		{
			right = mid - 1;
			answer = mid;
		}
	}

	cout << answer;
}

int main()
{
	fastio;

	cin >> n >> k;

	Solution();

	return 0;
}