#include<iostream>
#include <algorithm>
#include <map>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N, M;

map<string, string> password;

int main()
{
	fastio;

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		string address, word;
		cin >> address >> word;

		password.insert({ address, word });
	}

	for(int i = 0; i < M; i++)
	{
		string find;
		cin >> find;

		if(password.find(find) != password.end())
		{
			cout << password.find(find)->second << "\n";
		}
	}

	return 0;
}