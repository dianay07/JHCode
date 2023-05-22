#include <iostream>
#include <stack>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

// 입력
int N;
stack<int> board1;
stack<int> board2;
stack<int> board3;

// 출력
int cnt = 1;

void move(int from, int to)
{
	cout << from << " " << to << '\n';
}

void hanoi(int n, int from, int by, int to)
{
	if (n == 0) return;
	cnt++;

	hanoi(n - 1, from, to, by);
	move(from, to);
	hanoi(n - 1, by, from, to);
}

int main()
{
	fastio;
	cin >> N;

	for(int i = N; i > 0; i--)
	{
		board1.push(i);
	}

	for (int i = 0; i < N; i++)
		cnt *= 2;

	cout << cnt - 1 << "\n";
	hanoi(N, 1, 2, 3);

	return 0;
}