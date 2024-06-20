#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N;
vector<int> num;
int LEFT[1001];
int RIGHT[1001];

int main()
{
	fastio;

	cin >> N;
	for(int i =0; i < N; i++)
	{
		int temp;
		cin >> temp;

		num.push_back(temp);
	}

	fill_n(LEFT, 1001, 1);
	fill_n(RIGHT, 1001, 1);

	// 왼쪽에서 가장 긴 증가하는 수열
	for (int i = 0; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if(num[j] < num[i] && LEFT[i] < LEFT[j] + 1)
			{
				LEFT[i] = LEFT[j] + 1;
			}
		}
	}

	// 오른쪽에서 가장 긴 증가하는 수열
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = i+ 1; j < N; j++)
		{
			if (num[j] < num[i] && RIGHT[i] < RIGHT[j] + 1)
			{
				RIGHT[i] = RIGHT[j] + 1;
			}
		}
	}

	int answer = 0;
	for(int i = 0; i < N; i++)
	{
		answer = max(answer, LEFT[i] + RIGHT[i]);
	}

	// 중복되는 하나뺌
	cout << answer - 1;
	return 0;
}