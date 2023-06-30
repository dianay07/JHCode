#include <iostream>
#include <cmath>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

long N;
int T;

bool IsPrimeNumber(long input)
{
	if (input <= 1)
		return false;

	if (input == 2 || input == 3)
		return true;

	if (input % 2 == 0)
		return false;

	for(long long i = 3; i <= sqrt(input); i += 2)
	{
		if (input % i == 0)
			return false;
	}

	return true;
}

void Solution(long X)
{
	long offset = 1;

	while(true)
	{
		if (IsPrimeNumber(X))
		{
			cout << X << "\n";
			return;
		}
		else
			X = X + offset;
	}
}

int main()
{
	fastio;

	// 테스트 케이스 갯수
	cin >> T;

	for(int i = 0; i < T; i++)
	{
		cin >> N;
		Solution(N);
	}

	return 0;
}