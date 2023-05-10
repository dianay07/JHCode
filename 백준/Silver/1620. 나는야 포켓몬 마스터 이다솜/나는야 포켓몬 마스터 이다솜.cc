#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int N, M;
map<string, int> stringMap;
map<int, string> intMap;

int main()
{
	fastio;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		stringMap.insert({ str, i + 1 });
		intMap.insert({ i + 1, str });
	}

	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;

		if(stringMap.find(str) != stringMap.end())
		{
			cout << stringMap.find(str)->second << "\n";
		}
		else if(intMap.find(stoi(str)) != intMap.end())
		{
			cout << intMap.find(stoi(str))->second << "\n";
		}
		
	}

	return 0;
}