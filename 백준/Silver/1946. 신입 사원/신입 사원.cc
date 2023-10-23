#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int t, n;
vector<pair<int, int>> rankVec;

int main(void)
{
    fastio;

	cin >> t;

	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int ret = 1;				// 첫번째 1등은 무조건 합격
		int bigRank = 0;	

		for(int j = 0; j < n; j++)
		{
			int rank1, rank2;
			cin >> rank1 >> rank2;

			rankVec.push_back({ rank1, rank2 });
		}

		sort(rankVec.begin(), rankVec.end(), less<pair<int, int>>());

		// 첫 사람 빼고 계산
		for(int j = 1; j < n; j++)
		{
			// 두번째 성적이 큰사람이 나타나면 큰 값 교체
			if(rankVec[bigRank].second > rankVec[j].second)
			{
				ret++;
				bigRank = j;
			}
		}

		cout << ret << "\n";
		rankVec.clear();
	}

	return 0;
}