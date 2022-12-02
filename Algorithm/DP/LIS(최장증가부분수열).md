# LIS ( 최장 증가 부분 수열 )
    ( Longest Increasing Subsequence )

LIS
---
    - 원소가 n개인 배열의 일부 원소를 골라 만든 '부분 수열'중, 그 길이가 최대인 부분 수열을 '최장 증가 부분 수열'이라 함
    - 가장 간단한 풀이 방법이 DP

개념
---
    - 주어진 수열에서 첫 원소의 순서부터 순회, 맞는 조건에 도달 시 해답에 필요한 행동을 취함
    - LIS 뿐만 아닌 '구해진 수열의 합', '감소 수열' 등 베리에이션이 많음

```c++
int LIS(int a)
{
	int& ret = cache[a];
	if (ret != -1)
		return ret;

    // ret = 1;
	// ret = list[a];

	for (int next = a + 1; next < list.size(); next++)
	{
		if (list[a] < list[next])
		{
            // ret = max(ret, 1 + LIS(next));
			// ret = max(ret, list[a] + LIS(next));
		}
	}

	return ret;
}

int main()
{
	fastio;

	int N;
	cin >> N;

	//list.resize(N);
	::memset(cache, -1, sizeof(cache));

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		list.push_back(x);
	}

	int ret = 0;
	for (int pos = 0; pos < list.size(); pos++)
	{
		ret = max(ret, LIS(pos));
	}

	return 0;
}
```