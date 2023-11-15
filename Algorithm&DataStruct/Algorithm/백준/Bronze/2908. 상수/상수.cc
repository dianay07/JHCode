#include <iostream>
using namespace std;
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0);	

//if (x < 0 || y < 0 || x >= m || y >= n)
//	return;

int calc(int num)
{
	int temp[3];
	for (int i = 0; i < 3; i++)
	{
		temp[i] = num % 10;
		num = num / 10;
	}

	return temp[0] * 100 + temp[1] * 10 + temp[2];
}

int main()
{
	fastio;

	int a;		// 734
	int b;		// 893

	cin >> a >> b;

	if (calc(a) < calc(b))
		cout << calc(b) << "\n";
	else
		cout << calc(a) << "\n";
}