#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

unsigned long long N;
unsigned long long M;
unsigned long long H;

unsigned long long sum = 0;
unsigned long long start = 0;
unsigned long long last = 2000000000;

vector<unsigned long long> vec;

int solution(unsigned long long alStart, unsigned long long alLast)
{
	while(alStart <= alLast)
	{
		unsigned long long mid = (alStart + alLast) / 2;
		sum = 0;

		for(unsigned long long i = 0; i < N; i++)
		{
			if (vec[i] > mid)
				sum += (vec[i] - mid);
		}

		if(sum == M)
		{
			H = mid;
			break;
		}
		else if(sum > M)
		{
			if (H < mid)
				H = mid;

			alStart = mid + 1;
		}
		else
		{
			alLast = mid - 1;
		}
	}

	return H;
}

int main()
{
	fastio;

	cin >> N >> M;

	for(unsigned long long i = 0; i < N; i++)
	{
		unsigned long long a;
		cin >> a;

		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());
	last = *(vec.end() - 1);

	solution(start, last);

	cout << H << "\n";

	return 0;
}