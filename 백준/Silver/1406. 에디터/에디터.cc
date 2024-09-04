#include<iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	string str;
	cin >> str;
	int N = str.length();

	list<char> list;
	for(int i = 0; i < N; i++)
	{
		list.push_back(str[i]);
	}

	auto cursor = list.end();

	int M;
	cin >> M;

	while (M--)
	{
		char command;
		cin >> command;

		if(command == 'L')
		{
			if (cursor != list.begin())
				cursor--;
		}
		else if(command == 'D')
		{
			if (cursor != list.end())
				cursor++;
		}
		else if(command == 'B')
		{
			if (cursor != list.begin())
			{
				cursor--;
				cursor = list.erase(cursor);
			}
		}
		else if(command == 'P')
		{
			char input;
			cin >> input;

			list.insert(cursor, input);
		}
	}

	for (char temp : list)
		cout << temp;

	return 0;
}