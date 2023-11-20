#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int main()
{
	fastio;

	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> v;

	int x;
	cin >> x;

	for (int i = 0; i < x; i++)
	{
		int b;
		cin >> b;

		pq.push(b);
	}
	
	int size = pq.size();
	int answer = 0;
	while (size--)
	{
		v.push_back(pq.top());
		pq.pop();
	}

	int sum = 0;
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		answer = answer + *i;
		sum += answer;
	}

	cout << sum;


	return 0;
}