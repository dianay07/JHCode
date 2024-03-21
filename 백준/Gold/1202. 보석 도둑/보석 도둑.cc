#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> jewel;	// 보석 정보 배열
	vector<int> backSize;			// 가방 사이즈 배열

	// 보석 정보
	for(int i = 0; i < N; i++)
	{
		int M, V;
		cin >> M >> V;

		jewel.push_back({ M, V });
	}

	// 사이즈 작은 순으로 정렬
	sort(jewel.begin(), jewel.end());	

	// 가방 사이즈
	for(int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;

		backSize.push_back(temp);
	}

	// 사이즈 작은 순으로 정렬
	sort(backSize.begin(), backSize.end());


	long long answer = 0;
	int index = 0;
	priority_queue<int> candidate;

	// 가방 갯수만큼
	for(int i = 0; i < K; i++)
	{
		while (index < N && jewel[index].first <= backSize[i])
		{
			candidate.push(jewel[index].second);
			index++;
		}

		if (candidate.empty() == false)
		{
			answer += candidate.top();
			candidate.pop();
		}
	}

	cout << answer;

	return 0;
}