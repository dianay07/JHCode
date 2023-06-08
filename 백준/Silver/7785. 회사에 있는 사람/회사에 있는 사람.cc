#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N;
set<string> arr;

int main()
{
	fastio;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		string name;
		//getline(cin, name);
		cin >> name;

		string order;
		cin >> order;

		if (order == "enter")
			arr.insert(name);
		else if (order == "leave")
			arr.erase(name);
	}

	for(auto it = arr.rbegin(); it != arr.rend(); ++it)
	{
		cout << *it << "\n";
	}

	return 0;
}