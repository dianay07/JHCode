#include <iostream>
#include <queue>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int N;

int main()
{
	fastio;

	queue<int> que;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		que.push(i + 1);
	}

	while (que.size() > 1)
	{
		que.pop();
		int temp = que.front();

		que.pop();
		que.push(temp);
	}

	cout << que.front() << "\n";

	return 0;
}