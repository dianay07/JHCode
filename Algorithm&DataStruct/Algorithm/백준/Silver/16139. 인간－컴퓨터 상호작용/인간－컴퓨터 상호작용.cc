#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

string S;
int q;

int main()
{
	fastio;

	cin >> S >> q;

	for(int i = 0; i < q; i++)
	{
		char a;
		int l, r;
		int count = 0;

		cin >> a >> l >> r;

		string temp;

		for(int j = l; j <= r; j++)
		{
			if (S[j] == a)
				count++;
		}

		cout << count << "\n";
	}

	return 0;
}