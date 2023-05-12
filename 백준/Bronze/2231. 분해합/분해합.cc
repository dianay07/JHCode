#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int GetDivideSum(int x)
{
	int ret = 0;

	for(int i = 1; i < x; i++)
	{
		int num = i;
		int sum = 0;

		while(num != 0)
		{
			sum += num % 10;
			num = num / 10;
		}

		if (sum + i == x)
		{
			ret = i;
			break;
		}
	}

	return ret;
}

int main()
{
	fastio;
	int x;
	cin >> x;

	cout << GetDivideSum(x);

	return 0;
}