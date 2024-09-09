#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N, S;
int answer = 0;
vector<int> number;

void dfs(int count, int sum)
{
	// 합 구하기
	sum += number[count];

	// 목표 도달
	if (sum == S)
		answer++;

	// 최대 갯수일때 반복 중지
	if (count == N)
		return;

	// 시작 수 부터 조합 생성
	for(int i = count + 1; i < number.size(); i++)
		dfs(i, sum);
}

int main()
{
	fastio;

	cin >> N >> S;

	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		number.push_back(temp);
	}

	// 부분 수열이니까 모든 조합이 가능하기 때문에
	for(int i = 0; i < N; i++)
		dfs(i, 0);

	cout << answer;

	return 0;
}