#include <iostream>
#include <string>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int main()
{
	fastio;

	string str;
	cin >> str;

	int sum = 0;
	int during = 0;
	int beforeCount = 0;

	bool beforeOperatorMinus = false;

	// 입력받은 문자열 순서대로 체크
	for (int i = 0; i < str.size(); i++)
	{
		// 수가 아닌 연산자 입력시 + 마지막 도착 시 수 끊어내기
		if(str[i] == '+' || str[i] == '-' || i == str.size() - 1)
		{
			int ret = 0;

			// 연산자 없이 단일 수 나오면 따로 처리
			if(i == str.size() - 1)
			{
				ret = stoi(str.substr(beforeCount, str.size()));
			}
			else
			{
				ret = stoi(str.substr(beforeCount, i));
			}
			beforeCount = i + 1;

			// 합할 것 뺄 것 구분
			if (beforeOperatorMinus == false)
				sum += ret;
			else
				during += ret;

			if (str[i] == '-')
				beforeOperatorMinus = true;
		}
	}

	sum = sum - during;
	cout << sum;

	return 0;
}