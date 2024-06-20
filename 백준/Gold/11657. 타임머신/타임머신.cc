#include<iostream>
#include <algorithm>
#include <vector>
#include <limits.h>


using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

struct CITY
{
	int start;
	int dest;
	long long time;
};

const long long MAX = 987654321;
int N, M;
int A, B, C;
vector<CITY> table;
vector<long long> value;

bool Calc(int start)
{
	value[start] = 0;

	for (int k = 1; k < N; k++)
	{
		for (int i = 0; i < table.size(); i++)
		{
			int start = table[i].start;
			int dest = table[i].dest;
			long long dist = table[i].time;

			if (value[start] == MAX) continue;

			if (value[dest] > value[start] + dist)
				value[dest] = value[start] + dist;
		}
	}

	for (int i = 0; i < table.size(); i++)
	{
		int start = table[i].start;
		int dest = table[i].dest;
		long long dist = table[i].time;

		if (value[start] == MAX) continue;

		if (value[dest] > value[start] + dist)
		{
			return true;
		}
	}

	return false;
}


int main()
{
	fastio;
	cin >> N >> M;

	for (int i = 0; i <= N; i++)
		value.push_back(MAX);

	for(int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		table.push_back({ A, B, C });
	}

	if(Calc(1) == true)
	{
		cout << -1;
		return 0;
	}
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (value[i] != MAX)
				cout << value[i] << "\n";
			else
				cout << -1 << "\n";
		}
	}
	

	return 0;
}