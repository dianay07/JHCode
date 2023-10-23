#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int N;
queue<int> que;

int main()
{
    fastio;
    string str;
	int data;

	cin >> N;


	for (int i = 0; i < N; i++)
	{
		cin >> str;

		if (str == "push")
		{
			cin >> data;
			que.push(data);
		}
		else if (str == "pop")
		{
			if (que.size() == 0)
				cout << "-1\n";
			else {
				data = que.front();
				que.pop();
				cout << data << "\n";
			}
		}
		else if (str == "size")
		{
			cout << que.size() << "\n";
		}
		else if (str == "empty") 
		{
			cout << que.empty() << "\n";
		}
		else if (str == "front") 
		{
			if (que.size() == 0) 
				cout << "-1\n";
			else cout << que.front() << "\n";
		}
		else if (str == "back") 
		{
			if (que.size() == 0) 
				cout << "-1\n";
			else cout << que.back() << "\n";
		}
	}
	return 0;

}