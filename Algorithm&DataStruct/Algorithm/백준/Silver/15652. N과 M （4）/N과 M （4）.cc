#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

/*
 * 3	4
 * 1	2
 *
 * 1	1 1		1 3
 * 2	1 2		1 4
 * 3	1 3		2 2
 */

int N, M;
int arr[10];

void bfs(int count, int len)
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

	for (int i = count; i <= N; i++)
	{
		arr[len] = i;
		bfs(i, len + 1);
	}
}

int main()
{
	fastio;

	cin >> N >> M;
	bfs(1, 0);

	return 0;
}