#include <algorithm>
#include<iostream>
#include <map>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n, m;

map<int, int> arr;
vector<int> answer;

void Solution(int length)
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
		if(arr[i] > 0)
		{
			arr[i]--;
			answer.push_back(i);
			Solution(length + 1);
			answer.erase(answer.end() - 1);
			arr[i]++;
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

		arr[temp]++;
	}

	Solution(0);

	return 0;
}