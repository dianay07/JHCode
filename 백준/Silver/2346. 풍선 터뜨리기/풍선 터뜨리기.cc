#include<iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

deque<pair<int, int>> dq;
int number = 0;

int main()
{
	fastio;

	int N;
	cin >> N;

	// 입력
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		dq.push_back({ i, temp });
	}

	int count = 0;
	int current = 0;

	while(dq.empty() == false)
	{
		current = dq.front().second;
		cout << dq.front().first + 1 << " ";
		dq.pop_front();

		if (dq.empty() == true)
			break;

		if(current > 0)
		{
			for(int i = 0; i < current - 1; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			for(int i = 0; i < (-1)*current; i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}

	return 0;
}