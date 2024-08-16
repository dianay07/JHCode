#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int L, C;
bool visited[16];
vector<char> alpha;
vector<char> answer;

void dfs(int count, int start)
{
	if(count >= L)
	{
		int A = 0, B = 0;

		for (char temp : answer)
		{
			if(temp == 'a' || temp == 'e' || temp == 'i' ||
				temp == 'o' || temp == 'u')
				A++;
			else
				B++;
		}

		if(A >= 1 && B >= 2)
		{
			for (char temp : answer)
				cout << temp;

			cout << endl;
		}


		return;
	}

	for(int i = start; i < C; i++)
	{
		if(visited[i] == false)
		{
			visited[i] = true;
			answer.push_back(alpha[i]);
			dfs(count + 1, i + 1);
			answer.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	fastio;

	cin >> L >> C;

	for(int i = 0; i < C; i++)
	{
		char temp;
		cin >> temp;

		alpha.push_back(temp);
	}
	sort(alpha.begin(), alpha.end());

	dfs(0, 0);

	return 0;
}