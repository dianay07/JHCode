#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int N;
vector<int> vec;
vector<int> sum;
bool visited[9] = { false, };
int ret = 0;

void dfs(int count = 0)
{
	if(count == N)
	{
		int temp = 0;
		for(int i = 0; i < sum.size() - 1; i++)
			temp += abs(sum[i] - sum[i + 1]);

		ret = max(ret, temp);
	}

	for(int i = 0; i < N; i++)
	{
		if(visited[i] == false)
		{
			visited[i] = true;
			sum.push_back(vec[i]);
			dfs(count + 1);
			sum.pop_back();
			visited[i] = false;
		}
	}

	
}

int main()
{
	fastio;
	cin >> N;

	vec.resize(N);
	for(int i = 0; i < N; i ++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());
	dfs();

	cout << ret;

	return 0;
};