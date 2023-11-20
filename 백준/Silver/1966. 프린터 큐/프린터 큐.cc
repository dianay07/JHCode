#include <iostream>
#include <queue>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int T;
int N, M;

int main(void)
{
	fastio;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int cnt = 0;
		queue<pair<int, int>>q;
		priority_queue<int>printer;
		cin >> N >> M;

		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			q.push({ j, temp });
			printer.push(temp);
		}

		while (!printer.empty())
		{
			int idx = q.front().first;		
			int prior = q.front().second;		
			q.pop();
			if (printer.top() == prior)		
			{
				cnt++;
				printer.pop();
				if (idx == M)		
				{
					cout << cnt << '\n';
					break;
				}
			}
			else		
				q.push({ idx,prior });
		}
	}
	return 0;
}