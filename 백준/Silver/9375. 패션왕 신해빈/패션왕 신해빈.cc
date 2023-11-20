#include<iostream>
#include <algorithm>
#include <map>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int T, n;
map<string, int> cloths;

int main()
{
	fastio;
	cin >> T;

	while(T--)
	{
		int answer = 1;
		cin >> n;

		for(int i = 0; i < n; i++)
		{
			string item, kinds;
			cin >> item >> kinds;

			cloths[kinds]++;
		}

		for(auto itr = cloths.begin(); itr != cloths.end(); itr++)
		{
			// ( 한 종류 옷 가짓 수 + 안입는 경우) * ( .... )
			answer *= (itr->second + 1);
		}

		// 다 안입은 경우만 제외
		cout << answer - 1 << "\n";
		cloths.clear();
	}


	return 0;
}