#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int n;
long num[46];

long fibonacci(int n)
{
	if (n < 2)
		return num[n];

	num[n] = num[n - 1] + num[n - 2];
	return num[n];
}

int main()
{
	num[0] = 0;
	num[1] = 1;

	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		fibonacci(i);
	}

	cout << num[n];

    return 0;
}