#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N, M;
vector<int> vec;

int main()
{
	fastio;

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;

		int up = upper_bound(vec.begin(), vec.end(), temp) - vec.begin();
		int down = lower_bound(vec.begin(), vec.end(), temp) - vec.begin();
		cout << up - down << " ";
	}

	return 0;
}