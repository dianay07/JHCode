#include<iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	int N;
	priority_queue<int> maxQ;
	priority_queue<int, vector<int>, greater<int>> minQ;

	cin >> N;

	int temp;
	for(int i = 0; i < N; i++)
	{
		cin >> temp;

		if (maxQ.empty() == true)
			maxQ.push(temp);
		else
		{
			if (maxQ.size() > minQ.size())
				minQ.push(temp);
			else
				maxQ.push(temp);

			if (maxQ.top() > minQ.top())
			{
				int tempMax = maxQ.top();
				int tempMin = minQ.top();

				maxQ.pop();
				minQ.pop();

				maxQ.push(tempMin);
				minQ.push(tempMax);
			}
		}

		cout << maxQ.top() << "\n";
	}

	return 0;
}