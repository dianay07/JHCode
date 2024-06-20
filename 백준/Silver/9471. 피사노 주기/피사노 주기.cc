#include<iostream>
#include <algorithm>
#include <vector>

// 백준 2749번 풀기

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	int P;
	cin >> P;

	// 나머지가 0, 1이 연속으로 나오면 주기 시작
	// 갯수, 나머지 1, 나머지 2
	int count, r1, r2;
	for(int i = 0; i < P; i++)
	{
		int num, m;
		cin >> num >> m;

		count = 0;
		r1 = 0;			// 피보나치 0번 0
		r2 = 1;			// 피보나치 1번 1

		while (true)
		{
			if (r1 == 0 && r2 == 1 && count != 0)
				break;

			int temp = r1;
			r1 = r2;
			r2 = (temp + r1) % m;

			count++;
		}

		cout << num << " " << count << "\n";
	}

	return 0;
}