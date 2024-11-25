#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int main()
{
	fastio;

	int K;
	cin >> K;

	stack<int> st;
	int temp;

	while (K--)
	{
		cin >> temp;

		if (temp != 0)
			st.push(temp);
		else
			st.pop();
	}

	int answer = 0;
	while (st.empty() == false)
	{
		answer += st.top();
		st.pop();
	}

	cout << answer;

	return 0;
};