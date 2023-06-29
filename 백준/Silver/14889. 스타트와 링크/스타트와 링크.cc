#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N;
vector<vector<int>> member;
bool hasTeam[20];

vector<int> startMember;
int startValue = 0;
vector<int> linkMember;
int linkValue = 0;
int answer = INT_MAX;

int CalculateValue(vector<int> team)
{
	int ret = 0;

	for (int i = 0; i < team.size(); i++)
	{
		int self = team[i];

		for (int j = i + 1; j < team.size(); j++)
		{
			int teammate = team[j];

			ret += member[self][teammate] + member[teammate][self];
		}
	}

	return ret;
}

void Solution(int count, int next ,vector<int> start)
{
	// 종료 조건 : start 팀 다 구해짐
	if (count >= N / 2)
	{
		for (int i = 0; i < N; i++)
		{
			if (hasTeam[i] == false)
			{
				linkMember.push_back(i);
			}
		}

		// start팀 구해졌으니 링크팀 전력 계산
		startValue = CalculateValue(startMember);
		linkValue = CalculateValue(linkMember);

		answer = min(answer, abs(startValue - linkValue));
		linkMember.clear();
		return;
	}

	for (int i = next; i < N; i++)
	{
		if (hasTeam[i] == false)
		{
			startMember.push_back(i);
			hasTeam[i] = true;

			Solution(count + 1, i + 1,startMember);

			startMember.pop_back();
			hasTeam[i] = false;
		}
	}

}

int main()
{
	fastio;

	cin >> N;
	member.resize(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int stat;
			cin >> stat;

			member[i].push_back(stat);
		}
	}

	Solution(0, 0, startMember);
	cout << answer;

	return 0;
}