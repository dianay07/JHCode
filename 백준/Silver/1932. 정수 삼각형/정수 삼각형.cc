#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

vector<vector<int>> tri;
vector<vector<int>> cache;
int N;

int	solution(int y, int x)
{
	// 기저
	if (y == N)
		return 0;

	// 캐시
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	// 풀이
	return ret = tri[y][x] + max(solution(y + 1, x), solution(y+1,x+1));
}

int main()
{
	fastio;

	cin >> N;

	cache = vector<vector<int>>(N, vector<int>(N, -1));

	tri.resize(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int x;
			cin >> x;

			tri[i].push_back(x);
		}
	}

	int ret = solution(0, 0);
	cout << ret << "\n";

	return 0;
}