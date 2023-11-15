//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);
//	
//int N, M, cnt;
//vector<vector<int>> vec;
//queue<int> route;
//bool visited[201];
//
//void solution(int k)
//{
//	visited[k] = true;
//	
//	for (int element : vec[k])
//	{
//		if (!visited[element]) 
//		{
//			solution(element);
//		}
//	}
//
//	return;
//}
//int main()
//{
//	fastio;
//	cin >> N;
//	cin >> M;
//
//	// 벡터 생성
//	vec.resize(N + 1);
//
//	// 길 입력
//	for(int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			int temp;
//			cin >> temp;
//
//			if(temp == 1)
//			{
//				vec[i].push_back(j);
//				vec[j].push_back(i);
//			}
//		}
//	}
//
//	// 여행 경로 입력
//	for (int i = 0; i < M; i++) 
//	{
//		int x;
//		cin >> x;
//		if (visited[x] == false) 
//		{
//			cnt++;
//			solution(x);
//		}
//	}
//
//	if (cnt == 1) 
//		cout << "YES";
//	else 
//		cout << "NO";
//
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int N, M, cnt;
int parent[201];
int path[1005];
int x;

int find(int a)
{
	if (parent[a] == a)
		return a;
	else
		return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot == bRoot)
		return;

	parent[aRoot] = bRoot;
}

int main()
{
	fastio;
	cin >> N;
	cin >> M;

	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> x;
			if(x)
			{
				Union(i, j);
			}
		}
	}

	for (int i = 0; i < M; i++) 
		cin >> path[i];

	bool isTrue = true;

	int root = find(path[0]);
	for (int i = 1; i < M; i++) 
	{
		if (root != find(path[i])) 
		{
			isTrue = false;
			break;
		}
	}

	if (isTrue) cout << "YES";
	else cout << "NO";

	return 0;
}