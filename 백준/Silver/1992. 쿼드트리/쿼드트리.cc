#include <iostream>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N;
vector<vector<int>> vec;

void Solution(int X, int Y, int length)
{
	int value = vec[X][Y];

	for(int i = X; i < X + length; i++)
	{
		for(int j = Y; j < Y + length; j++)
		{
			if(vec[i][j] != value)
			{
				cout << "(";
				Solution(X, Y, length / 2);								// 1
				Solution(X, Y + length / 2, length / 2);				// 2
				Solution(X + length / 2, Y, length / 2);				// 3
				Solution(X + length / 2, Y + length / 2, length / 2);	// 4
				cout << ")";
				return;
			}
		}
	}

	cout << value;
}

int main()
{
	fastio;

	cin >> N;

	// 입력
	vec.resize(N);
	for(int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for(int j = 0; j < N; j++)
		{
			vec[i].push_back(str[j] - '0');
		}
	}

	Solution(0, 0, N);

	return 0;
}