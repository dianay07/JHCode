#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	int n, x;
	cin >> n;

	vector<int> vec(n);

	for(int i = 0; i < n; i++)
		cin >> vec[i];

	cin >> x;

	sort(vec.begin(), vec.end());

	int start = 0;
	int end = n - 1;
	int answer = 0;

	while(start < end)
	{
		if (vec[start] + vec[end] == x)
		{
			answer++;
			end--;
		}
		else if (vec[start] + vec[end] > x)
			end--;
		else
			start++;
	}

	cout << answer;

	return 0;
}