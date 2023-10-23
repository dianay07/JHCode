#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int A, B, C;
int DP[21][21][21];

int func(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	if (a > 20 || b > 20 || c > 20)
		return func(20, 20, 20);

	if (DP[a][b][c])
		return DP[a][b][c];

	if (a < b && b < c)
		return DP[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);

	return DP[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
}

int main()
{
	fastio;

	while(true)
	{
		cin >> A >> B >> C;

		if (A == -1 && B == -1 && C == -1)
			break;

		cout << "w(" << A << ", " << B << ", " << C << ")" << " = " << func(A,B,C) << "\n";
	}
	

	return 0;
}