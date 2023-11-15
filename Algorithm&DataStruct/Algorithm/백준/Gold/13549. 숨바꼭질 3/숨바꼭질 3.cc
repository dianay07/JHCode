#include<iostream>
#include <vector>
#include <queue>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n, k;
int p[100001]{ };

int minWeight;

void Solution()
{
	queue<int> que;
	que.push(n);
	p[n] = 0;

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		if(cur == k)
		{
			minWeight = p[cur];
			return;
		}

		if(cur * 2 < 100001 && p[cur * 2] > p[cur])
		{
			p[cur * 2] = p[cur];
			que.push(cur * 2);
		}

		if(cur + 1 < 100001 && p[cur + 1] > p[cur] + 1)
		{
			p[cur + 1] = p[cur] + 1;
			que.push(cur + 1);
		}

		if (cur - 1 < 100001 && p[cur - 1] > p[cur] + 1)
		{
			p[cur - 1] = p[cur] + 1;
			que.push(cur - 1);
		}
	}
}

int main(void)
{
    fastio;

	cin >> n >> k;

	for(int i = 0; i < 100001; i++)
		p[i] = 1000000;

	Solution();

	cout << minWeight;

	return 0;
}