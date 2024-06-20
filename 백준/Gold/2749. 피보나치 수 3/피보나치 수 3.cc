#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	long long n;

	cin >> n;

	vector<int> fibo;

	fibo.push_back(0);
	fibo.push_back(1);

	for (int i = 2; i < 1500000; i++)
		fibo.push_back((fibo[i - 1] + fibo[i - 2]) % 1000000);

	cout << fibo[n % 1500000];

	return 0;
}