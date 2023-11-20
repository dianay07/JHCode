#include <iostream>
#include <queue>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int main()
{
	fastio;

	priority_queue<int, vector<int>, greater<int>> pq;

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		std::cin >> x;

		if (x == 0)
		{
			if (!pq.empty())
			{
				std::cout << pq.top() << "\n";
				pq.pop();
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else
			pq.push(x);
	}

	return 0;
}