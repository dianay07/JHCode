#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0);	

int main()
{
	fastio;

	string a;
	cin >> a;

	for (int i = 0; i < 26; i++)
	{
		int answer = 0;

		for (int j = 0; j < a.size(); j++)
		{

			if (a[j] == 'a' + i)
			{
				answer = j;
				break;
			}
			else
			{
				answer = -1;
			}
		}

		cout << answer << " ";
	}
}