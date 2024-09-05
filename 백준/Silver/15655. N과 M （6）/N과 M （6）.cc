#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N, M;
vector<int> vec;
vector<int> answer;
bool visited[9];

void dfs(int count, int length)
{
	if(length == M)
	{
		for (int temp : answer)
			cout << temp << " ";

		cout << "\n";
		return;
	}

	for(int i = count; i < vec.size(); i++)
	{
		answer.push_back(vec[i]);
		dfs(i + 1, length + 1);
		answer.erase(answer.end() - 1);
	}
}

int main()
{
	fastio;

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	dfs(0, 0);

	return 0;
}