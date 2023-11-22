#include<iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)


int main()
{
	fastio;

	string input, output;
	cin >> input;

	stack<char> oper;

    for (int i = 0; i < input.length(); i++) 
    {
        // 그냥 문자면
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            output += input[i];
            continue;
        }

        // 열린 괄호 
        if (input[i] == '(')
            oper.push(input[i]);
        // 닫힌 괄호 => 저장 시점
        else if (input[i] == ')')
        {
            // 스택이 비거나 ( 이 아니면 연산자 출력
            while (!oper.empty() && oper.top() != '(')
            {
                output += oper.top();
                oper.pop();
            }
            oper.pop();
        }
        // 곱, 나눗이면 높은 우선수이라 + - 저장되어있으면 출력 후 저장
        else if (input[i] == '*' || input[i] == '/') 
        {
            while (oper.empty() == false && (oper.top() == '*' || oper.top() == '/')) 
            {
                output += oper.top();
                oper.pop();
            }
            oper.push(input[i]);
        }
        // 비교없이 ( 이 아닐때만 저장
        else if (input[i] == '+' || input[i] == '-')
        {
            while (oper.empty() == false && oper.top() != '(') 
            {
                output += oper.top();
                oper.pop();
            }
            oper.push(input[i]);
        }
    }

    // 뒷처리
    while (!oper.empty()) 
    {
        output += oper.top();
        oper.pop();
    }

    cout << output;

    return 0;
}