#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N, M;

vector<int> board;

void DFS(int count, int length, vector<int> vec)
{
	if(length >= M)
	{
		for(int i = 0; i < length; i++)
		{
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}

	for(int i = count; i < board.size(); i++)
	{
		vec.push_back(board[i]);
		DFS(i, length + 1, vec);
		vec.pop_back();
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

		board.push_back(temp);
	}

	sort(board.begin(), board.end());

	vector<int> newVec;
	DFS(0, 0, newVec);
	

	return 0;
}