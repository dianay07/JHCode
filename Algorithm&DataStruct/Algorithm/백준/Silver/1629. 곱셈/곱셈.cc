#include<iostream>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int Solution(int a, int b, int c)
{
	if (b > 1)
	{
		long long ret = Solution(a, b / 2, c);

		if (b % 2)
			return ((ret * ret) % c * a) % c;
		else
			return (ret * ret) % c;
	}
	else
		return a;
		
}

int main(void)
{
    fastio;

	int a, b, c;
	cin >> a >> b >> c;

	cout << Solution(a % c, b, c);

	return 0;
}