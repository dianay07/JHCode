#include <iostream>
#include<stack>
#include<string>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int main()
{
	fastio;

	string S; // 문자열 S
	getline(cin, S);
	S += ' ';
 
	stack<char> s;
 
	string result; // 결과물
 
	int i = 0;
	int cnt = S.length();
 
	while (i <= cnt)
	{
		if (S[i] == '<')
		{
			if (!s.empty())
			{
				while (!s.empty()) {
					result += s.top();
					s.pop();
				}
				result += '<';
				i++;
			}
			
			while (S[i] != '>')
			{
				result += S[i++];
			}
			result += S[i++];
		}
		else
		{
			s.push(S[i]);
 
			if (S[i] == ' ')
			{
				s.pop();				
				while (!s.empty())
				{
					result += s.top();
					s.pop();
				}
				result += ' ';
			}
			i++;
 
		}
	}
 
	for (int j = 0; j < cnt; j++)
	{
		cout << result[j];
	}
 
	return 0;
}