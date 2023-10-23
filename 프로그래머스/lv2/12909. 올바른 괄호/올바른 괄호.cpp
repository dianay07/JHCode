#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> stack;

    for(int i = 0; i <= s.length(); i++)
    {
        if(s[i] == '(')
        {
            stack.push(s[i]);
        }
        else if(s[i] == ')')
        {
	        if(stack.empty() == false)
	        {
                stack.pop();
	        }
            else
            {
                answer = false;
                return answer;
            }
        }
    }

        if (stack.empty() == false)
        return answer = false;

    return answer;
}
int main()
{
    string s = "()()";
    cout << solution(s);

    return 0;
}