#include <iostream>
#include <vector>
#include <cmath>
#include <memory.h>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int M;
int N;
vector<int> vec;
bool prime[10001] = { true, };

void isPrime()
{
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (prime[i] == false)
			continue;

		for (int j = i + i; j <= N; j += i)
			prime[j] = false;
	}
}

int main()
{
	fastio;

	cin >> M >> N;
	memset(prime, true, sizeof(prime));
	prime[1] = false;

	isPrime();

	for (int i = M; i <= N; i++)
	{
		if (prime[i] == true)
			vec.push_back(i);
	}

	if(vec.empty())
	{
		cout << -1;
	}
	else
	{
		int sum = 0;
		for (auto i : vec)
			sum += i;

		cout << sum << "\n";
		cout << vec.front() << "\n";
	}

	return 0;
}