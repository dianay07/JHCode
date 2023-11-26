#include<iostream>
#include <algorithm>
#include <vector>


using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

typedef vector<vector<long long>> matrix;
const int NUMBER = 1000000007;

matrix operator*(matrix& a, matrix& b)
{
	matrix temp(2, vector<long long>(2));
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			for(int k = 0; k <2; k++)
			{
				temp[i][j] += a[i][k] * b[k][j];
			}
			temp[i][j] %= NUMBER;
		}
	}

	return temp;
}

int main()
{
	fastio;
	long long n;
	cin >> n;

	matrix answer = { {1, 0}, {0, 1} };
	matrix a = { {1, 1}, {1, 0} };

	while (n > 0)
	{
		if (n % 2 == 1) 
			answer = answer * a;

		a = a * a; 
		n /= 2;
	}

	cout << answer[0][1];

	return 0;
}