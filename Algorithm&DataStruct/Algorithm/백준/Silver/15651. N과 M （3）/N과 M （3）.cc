#include <iostream>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int N, M;
int arr[8];

void bfs(int len)
{
	if(len == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}

		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		arr[len] = i;
		bfs(len + 1);
	}
}

int main()
{
	fastio;
	cin >> N >> M;
	bfs(0);

	return 0;
}