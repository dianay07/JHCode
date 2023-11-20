#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n, m;
vector<int> arr;

vector<int> answer;
bool visited[9];

void Solution(int count, int length)
{
	if(length >= m)
	{
		for (int i = 0; i < m; i++)
			cout << answer[i] << " ";

		cout << "\n";
		return;
	}


	for(int i = 0; i < arr.size(); i++)
	{
		if(visited[i] == false)
		{
			visited[i] = true;
			answer.push_back(arr[i]);
			Solution(i + 1, length + 1);
			answer.erase(answer.end() - 1);
			visited[i] = false;
		}
	}
}

int main(void)
{
	fastio;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	Solution(0, 0);

	return 0;
}