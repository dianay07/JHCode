#include <iostream>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0);	

struct Node
{
	bool isInfected;
	vector<int> nearNode = vector<int>();
};

struct Node computer[100];
int answer = 0;

void dfs(int input)
{
	computer[input].isInfected = true;
	answer++;

	for (int i = 0; i < computer[input].nearNode.size(); i++)
	{
		int next = computer[input].nearNode[i];
		if (computer[next].isInfected == false)
			dfs(next);
	}
}

int main()
{
	fastio;	

	// 노드 // 자식 쌍 갯수
	int a;
	int b;
	cin >> a >> b;

	for (int i = 0; i < b; i++)
	{
		int c, d;
		cin >> c >> d;

		computer[c].nearNode.push_back(d);
		computer[d].nearNode.push_back(c);
	}

	dfs(1);
	cout << answer -1  << endl;
}