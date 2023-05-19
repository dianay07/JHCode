#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int N;
vector<int> arr;
vector<int> CalcResult;
vector<char> OPER;

int MIN = INT_MAX;
int MAX = -1000000000;

void solution()
{
	int ret = 0;

	for(int i = 0; i < N - 1; i++)
	{
		if(i == 0)
		{
			switch (OPER[i])
			{
			case '+':
				ret = arr[i] + arr[i + 1];
				break;
			case '-':
				ret = arr[i] - arr[i + 1];
				break;
			case '*':
				ret = arr[i] * arr[i + 1];
				break;
			case '/':
				ret = arr[i] / arr[i + 1];
				break;
			}
		}
		else
		{
			switch (OPER[i])
			{
			case '+':
				ret = ret + arr[i + 1];
				break;
			case '-':
				ret = ret - arr[i + 1];
				break;
			case '*':
				ret = ret * arr[i + 1];
				break;
			case '/':
				ret = ret / arr[i + 1];
				break;
			}
		}
	}

	MAX = max(ret, MAX);
	MIN = min(ret, MIN);
}

void dfs(int result, int count, vector<char> oper)
{
	if (count == N - 1)
	{
		solution();
		return;
	}

	for(int i = count; i < N - 1; i++)
	{
		swap(OPER[count], OPER[i]);
		dfs(result, count + 1, OPER);
		swap(OPER[count], OPER[i]);
	}
}

int main()
{
	fastio;

	cin >> N;

	// 정수 입력
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	// 연산자 갯수 입력
	for (int i = 0; i < 4; i++)
	{
		int temp;
		cin >> temp;

		switch (i)
		{
		case 0:
			for (int j = 0; j < temp; j++)
				OPER.push_back('+');
			break;

		case 1:
			for (int j = 0; j < temp; j++)
				OPER.push_back('-');
			break;

		case 2:
			for (int j = 0; j < temp; j++)
				OPER.push_back('*');
			break;

		case 3:
			for (int j = 0; j < temp; j++)
				OPER.push_back('/');
			break;
		}
	}

	dfs(0, 0, OPER);

	cout << MAX << "\n";
	cout << MIN << "\n";

	return 0;
}