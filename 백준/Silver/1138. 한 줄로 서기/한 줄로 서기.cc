#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	int N;
	cin >> N;

	vector<int> num(N);
	vector<int> answer(N);

	for(int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	for(int i = 0; i < N; i++)
	{
		int position = 0;		// 현재 위치

		// 왼쪽에 자기보다 큰사람이 잇어야되면
		while(num[i] != 0)
		{
			// 자리에 사람이 없다 -> 자리 이동
			if (answer[position] == 0)
				num[i]--;

			position++;		// 한칸 앞으로
		}

		// 이미 사람이 있으면 자리 이동
		while (answer[position] != 0) position++; 
		// 착석, 0부터 시작이니까 1더하기
		answer[position] = i + 1;
	}

	for (int i = 0; i < N; i++)
		cout << answer[i] << " ";


    return 0;
}