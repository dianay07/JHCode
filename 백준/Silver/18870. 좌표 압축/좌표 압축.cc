#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int N;
vector<int> line;
vector<int> sortLine;

int main(void)
{
    fastio;

	cin >> N;

	int temp;
	for(int i = 0; i < N; i++)
	{
		cin >> temp;
		line.push_back(temp);
		sortLine.push_back(temp);
	}

	sort(sortLine.begin(), sortLine.end());
	sortLine.erase(unique(sortLine.begin(), sortLine.end()), sortLine.end());

	for(int i = 0; i < N; i++)
	{
		cout << lower_bound(sortLine.begin(), sortLine.end(), line[i]) - sortLine.begin() << "\n";
	}

	return 0;
}