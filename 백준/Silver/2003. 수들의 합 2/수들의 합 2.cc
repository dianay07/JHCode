#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N;
long M;

int main(void)
{
    fastio;

	vector<long> arr;
	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		arr.push_back(temp);
	}
	arr.push_back(0);

	int start = 0, end = 0;
	int answer = 0;
	long sum = arr[0];

    while (end < N)
    {
		if(sum < M)
			sum += arr[++end];

		if(sum >= M)
		{
			if (sum == M)
				answer++;

			sum -= arr[start++];
		}
    }

	cout << answer;

	return 0;
}