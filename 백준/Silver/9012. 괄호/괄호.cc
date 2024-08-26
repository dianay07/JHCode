#include <iostream>
#include <stack>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int main()
{
    fastio;

    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        stack<char> tack;
        string str;
        bool value = false;

        cin >> str;

    	for(int j = 0; j < str.size(); j++)
        {
            if (str[j] == '(')
                tack.push(str[j]);
            else if (str[j] == ')')
            {
                if (tack.empty() == false)
                {
                    tack.pop();
                    value = true;
                }
                else
                {
                    value = false;
                    break;
                }
            }
        }

        if (value == false)
            cout << "NO" << "\n";
        else
        {
            if (tack.empty() == true)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
            
    }

    return 0;
}