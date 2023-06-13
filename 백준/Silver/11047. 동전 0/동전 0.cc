#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N, K;
int coin[11];

int main()
{
	cin >> N >> K;

	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		coin[i] = temp;
	}

	int count = 0;

	for(int i = N - 1; i >= 0; i--)
	{
		if (K / coin[i] == 0)
			continue;
		else if(K / coin[i] != 0)
		{
			count += (K / coin[i]);
			K = (K - coin[i] * (K / coin[i]));
		}
	}

	cout << count;

	return 0;
}