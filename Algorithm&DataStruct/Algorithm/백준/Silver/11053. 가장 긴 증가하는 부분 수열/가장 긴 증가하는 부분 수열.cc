#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <cmath>
#include <memory.h>

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

vector<int> list;
int cache[1001];

int LIS(int a)
{
	int& ret = cache[a];
	if (ret != -1)
		return ret;

	ret = 1;
	
	for (int next = a + 1; next < list.size(); next++)
	{
		if (list[a] < list[next])
			ret = max(ret, 1 + LIS(next));
	}

	return ret;
}

int main()
{
	fastio;

	int N;
	cin >> N;

	::memset(cache, -1, sizeof(cache));

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		list.push_back(x);
	}

	int ret = 0;
	for (int pos = 0; pos < list.size(); pos++)
		ret = max(ret, LIS(pos));
    
    cout << ret;

	return 0;
}