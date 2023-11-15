#include<iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n;
int jump[1001];

int bestJump = 0;

int main(void)
{
	fastio;

	cin >> n;

	jump[1] = 1;

	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;

		if (jump[i] == 0)
			break;

		for (int j = 1; j <= num; ++j)
		{
			if (i + j > 1000)
				break;

			if (jump[i + j] > jump[i] + 1 || jump[i + j] == 0) 
				jump[i + j] = jump[i] + 1;
		}
	}

	if (jump[n] == 0)
		cout << -1;
	else
		cout << jump[n] - 1;

	return 0;
}