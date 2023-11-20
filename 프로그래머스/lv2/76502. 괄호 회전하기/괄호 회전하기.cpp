#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = 0;

    for (int i = 0; i < s.length(); i++) 
    {
        stack<char> rotation;
        bool Check = false;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            {
                Check = true;
                rotation.push(s[i]);
            }
            else 
            {
                if (s[i] == ']' && rotation.top() == '[')
                    rotation.pop();

                if (s[i] == '}' && rotation.top() == '{')
                    rotation.pop();

                if (s[i] == ')' && rotation.top() == '(')
                    rotation.pop();
            }
        }

        if (rotation.empty() && Check == true) 
            answer++;

        char ch = s.front();
        s.erase(s.begin());
        s.push_back(ch);
    }

    return answer;
}

int main()
{
	string s = "[](){}";
	cout << solution(s);

	return 0;
}