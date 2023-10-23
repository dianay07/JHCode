#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int n, c;
vector<int> house;

int Solution()
{
	int left = 0;
	int right = *(house.end() - 1);
	int answer = -1;

	while (left <= right)
	{
		int pivot = (left + right) / 2;		// 최대 거리구해야하니까 가능한한 멀리부터
		int i = 0;
		int count = 1;						// 설치한 공유기
		for(int j = 0; j < n; j++)
		{
			int gap = house[j] - house[i];

			if (gap >= pivot)
			{
				count++;
				i = j;
			}
		}


		if (count >= c)					// 공유기 다 설치했으면
		{
			if (answer < pivot)
			{
				answer = pivot;
				left = pivot + 1;
			}
		}
		else
			right = pivot - 1;
	}

	return answer;
}

int main()
{
	fastio;

	cin >> n >> c;

	for(int i = 0; i < n; i++)
	{
		int distance;
		cin >> distance;

		house.push_back(distance);
	}

	sort(house.begin(), house.end());

	cout << Solution();

	return 0;
}