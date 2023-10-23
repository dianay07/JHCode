#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

string N;
int B;

int main()
{
    // 54
    cin >> N >> B;

	int len = N.length();
	int tmp = 1;
	int result = 0;

	for (int i = len - 1; i >= 0; i--) {
		int num;

		if (N[i] >= '0' && N[i] <= '9') {
			num = N[i] - '0';
		}
		else {
			num = N[i] - 'A' + 10;
		}

		num *= tmp;
		result += num;
		tmp *= B;
	}

	cout << result << '\n';

    return 0;
}