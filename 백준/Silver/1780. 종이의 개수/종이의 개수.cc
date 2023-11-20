#include <iostream>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N;
vector<vector<int>> vec;
int countMinus = 0;
int countZero = 0;
int countPlus = 0;

void Solution(int X, int Y, int length)
{
	int value = vec[X][Y];

	for(int i = X; i < X + length; i++)
	{
		for(int j = Y; j < Y + length; j++)
		{
			if(vec[i][j] != value)
			{
				int size = length / 3;
				// 상단부
				Solution(X, Y, size);
				Solution(X, Y + size, size);
				Solution(X, Y + size * 2, size);

				// 중단부
				Solution(X + size, Y, size);
				Solution(X + size, Y + size, size);
				Solution(X + size, Y + size * 2, size);

				// 하단부
				Solution(X + size * 2, Y, size);
				Solution(X + size * 2, Y + size, size);
				Solution(X + size * 2, Y + size * 2, size);
				return;
			}
		}
	}

	if (value == -1)
		countMinus++;
	else if (value == 0)
		countZero++;
	else
		countPlus++;
}

int main()
{
	fastio;
	cin >> N;

	vec.resize(N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;

			vec[i].push_back(temp);
		}
	}

	Solution(0, 0, N);

	cout << countMinus << "\n";
	cout << countZero << "\n";
	cout << countPlus << "\n";

	return 0;
}