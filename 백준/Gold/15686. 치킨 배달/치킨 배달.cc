#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ);

using namespace std;
const int INF = 2e9;
const int inf = 1e9;

struct a {
	int x;
	int y;
};

vector<a> tmpV;
vector<a> home;
vector<a> chicken;
int homeDistance[101];
int ans = INF;

void checkDistance(int m, int homeSize) {
	for (int i = 0; i < homeSize; i++) {
		homeDistance[i] = INF;
	}

	for (int i = 0; i < homeSize; i++) {
		for (int j = 0; j < m; j++) {
			homeDistance[i] = min(homeDistance[i], abs(home[i].x - tmpV[j].x) + abs(home[i].y - tmpV[j].y));
		}
	}
	int summ = 0;
	for (int i = 0; i < homeSize; i++) {
		summ += homeDistance[i];
	}
	ans = min(ans, summ);
}

void DFS(int m, int cnt, int idx, int homeSize, int chickenSize) {
	if (m == cnt) {
		checkDistance(m, homeSize);
		return;
	}

	for (int i = idx; i < chickenSize; i++) {
		tmpV.push_back({ chicken[i].x, chicken[i].y });
		DFS(m, cnt + 1, i + 1, homeSize, chickenSize);
		tmpV.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 101; i++) {
		homeDistance[i] = INF;
	}

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			if (k == 1) {
				home.push_back({ i, j });
			}
			else if (k == 2) {
				chicken.push_back({ i, j });
			}
		}
	}

	int homeSize = home.size();
	int chickenSize = chicken.size();

	DFS(m, 0, 0, homeSize, chickenSize);

	cout << ans;
	return 0;
}