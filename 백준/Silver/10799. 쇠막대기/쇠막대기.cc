#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int main()
{
	fastio;

	stack<char> st;
	string line;
	cin >> line;

	int size = line.size();
	int answer = 0;

	for(int i = 0; i < size; i++)
	{
		if(line[i] == '(')
		{
			st.push(line[i]);
		}
		else if (line[i] == ')' && line[i - 1] == '(')
		{
			// 레이저 등장, 쇠막대기 추가했던거 제거
			st.pop();
			// 쇠막대기 갯수만큼 증식
			answer += st.size();
		}
		else
		{
			// 쇠막대기의 끝, 쇠막대기 제거
			st.pop();
			answer++;
		}
	}
	
	cout << answer;

	return 0;
};