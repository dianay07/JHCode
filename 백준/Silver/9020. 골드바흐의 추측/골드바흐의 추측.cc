#include<iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int check[9999];

void che()
{
	for(int i = 2; i <= 9999; i++)
		check[i] = i;

	for(int i = 2; i <= sqrt(9999); i++)
	{
		if(check[i] == 0)
			continue;

		for (int j = i * i; j <= 9999; j += i)
			check[j] = 0;
	}
}

int main()
{
	fastio;

	int T;
	cin >> T;

	che();

	while (T--)
	{
		int n;
		cin >> n;

		int left = 0, retLeft = 0;
		int right = 0, retRight = 0;
		int mid = 0, minMid = 9999;

		for(int i = 2; i <= n / 2; i++)
		{
			left = i;
			right = n - i;

			if(check[left] != 0 && check[right] != 0)
			{
				mid = right - left;

				if(minMid > mid)
				{
					retLeft = left;
					retRight = right;
					minMid = mid;
				}
			}
		}

		cout << retLeft << " " << retRight << "\n";
	}



	return 0;
}