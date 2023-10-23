#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int N, M;
vector<int> vec;
int answer = 0;

int main()
{
	fastio;

	cin >> N;
		
	for (int i = 0; i < N; i++)
	{
		int b;
		cin >> b;
		vec.push_back(b);
	}
	sort(vec.begin(), vec.end());

	cin >> M;

	for(int i = 0; i < M; i++)
	{
		int a;
		cin >> a;

		bool exist = binary_search(vec.begin(), vec.end(), a);

		if (exist == true)
			answer = 1;
		else
			answer = 0;

		cout << answer << "\n";
	}

	return 0;
}