#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);


string str;
stack<char> list;

int main()
{
    fastio;

    cin >> str;
    int sum = 0;
    int temp = 1;

    for (int i = 0; i < str.size(); i++) 
    {
        if (str[i] == '(') 
        {
            list.push(str[i]);
            temp *= 2;
        }
        else if (str[i] == '[') 
        {
            list.push(str[i]);
            temp *= 3;
        }
        else if (str[i] == ')') 
        {
            if (list.empty() || list.top() != '(') {
                cout << 0;
                return 0;
            }
            else if (str[i - 1] == '(') 
                sum += temp;

            list.pop();
            temp /= 2;
        }
        else if(str[i] == ']')
        {
            if (list.empty() || list.top() != '[') 
            {
                cout << 0;
                return 0;
            }
            else if (str[i - 1] == '[') 
                sum += temp;

            list.pop();
            temp /= 3;
        }
    }

    if (list.empty()) 
        cout << sum;
    else 
        cout << 0;

    return 0;
}