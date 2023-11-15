#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

vector<vector<int>> gear;		// 톱니바퀴
int K;							// 회전 횟수
int number;						// 회전시킬 톱니바퀴의 번호
int direction;					// 1 = 시계, -1 = 반시계
bool visited[4];

void RotateGear(int target, int dir)
{
    visited[target] = true;

    // 좌측 비교
	int left = target - 1;
    if (left >= 0 && gear[target][6] != gear[left][2] && visited[left] == false)
    {
        RotateGear(left, -1 * dir);
    }

    // 우측 비교
	int right = target + 1;
    if (right < 4 && gear[target][2] != gear[right][6] && visited[right] == false)
    {
    	RotateGear(right, -1 * dir);
    }

    // 시계방향 
    if (dir == 1)
    {
		rotate(gear[target].begin(), gear[target].end() - 1, gear[target].end());
    }
    // 반시계방향 
    else
    {
		rotate(gear[target].begin(), gear[target].begin() + 1, gear[target].end());
    }
}

int main()
{
	fastio;

	gear.resize(4);

	for (int i = 0; i < gear.size(); i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < 8; j++)
		{
			gear[i].push_back((int)(str[j] - '0'));
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		memset(visited, 0, sizeof(bool) * 4);

		cin >> number >> direction;

		RotateGear(number - 1, direction);
	}

	int answer = 0;
	for (int i = 0; i < 4; i++)
	{
		if (gear[i][0] == 1)
		{
			if (i == 0)
				answer = answer + 1;
			else if (i == 1)
				answer = answer + 2;
			else if (i == 2)
				answer = answer + 4;
			else if (i == 3)
				answer = answer + 8;
		}
	}

	cout << answer << "\n";

	return 0;
}