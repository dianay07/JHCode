#include<iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int T, n;
string p;
deque<int> deq;

int main()
{
	fastio;

    cin >> T;

    while (T--)
    {
        cin >> p >> n;

        string input;
        cin >> input;

        deq.clear();

        int num = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (isdigit(input[i]))
            {
                num = num * 10 + (input[i] - '0');
                if (!isdigit(input[i + 1]))
                {
                    deq.push_back(num);
                    num = 0;
                }
            }
        }

        bool isReversed = false;
        bool isError = false;
        for (char chr : p)
        {
            if (chr == 'R')
                isReversed = !isReversed;
            else
            {
                if (deq.size() < 1)
                {
                    cout << "error\n";
                    isError = true;
                    break;
                }

                if (isReversed)
                    deq.pop_back();
                else
                    deq.pop_front();
            }
        }

        if (isError)
            continue;

        if (isReversed)
            reverse(deq.begin(), deq.end());

        cout << '[';
        for (int i = 0; i < deq.size(); i++)
        {
            cout << deq[i];
            if (i != deq.size() - 1)
                cout << ',';
        }
        cout << ']' << "\n";
    }

	return 0;
}