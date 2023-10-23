#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n;
vector<long long> dist;
long long remainDistance;
vector<long long> price;
long long ret = LONG_MAX;

int main(void)
{
    fastio;

	cin >> n;

	long temp;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> temp;

		dist.push_back(temp);
		remainDistance += temp;
	}

	for(int i = 0; i < n; i++)
	{
		cin >> temp;

		price.push_back(temp);
	}

	int priceTemp = 0;
	for(int i = 0; i < n - 1; i++)
	{
		ret = min(ret, priceTemp + price[i] * remainDistance);
		priceTemp = priceTemp + (price[i] * dist[i]);
		remainDistance -= dist[i];
	}

	cout << ret;

	return 0;
}