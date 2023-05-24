#include <iostream>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

int N, M;
int parent[1000001];

int find(int a)
{
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
	int aRoot = find(a);
	int bRoot = find(b);

	if (aRoot == bRoot) return;
	parent[aRoot] = bRoot;
}

int main()
{
	fastio;

	cin >> N >> M;

	for(int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}

	while(M--)
	{
		int c, a, b;
		cin >> c >> a >> b;
		if(c == 0)
		{
			Union(a, b);
		}
		else
		{
			if(find(a) == find(b))
			{
				cout << "YES" << "\n";
			}
			else
			{
				cout << "NO" << "\n";
			}
		}
	}

	return 0;
}