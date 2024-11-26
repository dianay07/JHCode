#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int main()
{
	fastio;

	string s;
	cin >> s;

	set<string> set; 

	// 모든 부분 문자열을 생성
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j <= s.size(); j++)
		{
			set.insert(s.substr(i, j - i));
		}
	}

	cout << set.size();

	return 0;
};