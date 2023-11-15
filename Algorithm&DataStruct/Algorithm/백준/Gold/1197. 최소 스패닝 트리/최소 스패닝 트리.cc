#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)

int v, e;

struct Kruskal
{
	int a;
	int b;
	int distance;
};

bool compare(Kruskal d1, Kruskal d2)
{
	return d1.distance < d2.distance;
}

int parent[10002];
int retValue;
bool check;

vector<Kruskal> graph;

int Find(int value)
{
	if (value == parent[value])
		return value;

	return parent[value] = Find(parent[value]);
}

void Union(int a, int b)
{
	check = false;
	a = Find(a);
	b = Find(b);

	if (a == b)
		return;

	parent[a] = b;
	check = true;
}

int main()
{
    fastio;

	cin >> v >> e;

	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for(int i = 0; i < e; i++)
	{
		Kruskal newKS;
		cin >> newKS.a >> newKS.b >> newKS.distance;

		graph.push_back(newKS);
	}

	sort(graph.begin(), graph.end(), compare);

	for(int i = 0; i < e; i++)
	{
		Union(graph[i].a, graph[i].b);

		if (check)
			retValue += graph[i].distance;
	}

	cout << retValue;
	
    return 0;
}