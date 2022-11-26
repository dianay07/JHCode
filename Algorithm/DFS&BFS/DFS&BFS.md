# 개요
    - 그래프 탐색 ( 하나의 정점으로 시작해 차례대로 모든 정점들을 한 번씩 방문 ) 의 일종

# DFS ( Deep-First Search ) : 깊이 우선 탐색

개념
---
    - 루트 노드에서 부터 다음 정점을 넘어가기 전에 해당 정점을 완벽하게 탐색
    - 넓게 탐색 전에, 깊게 탐색하는 것
    - 모든 노드를 방문하려 할 떄 선택
    - BFS 보다 조금 간단, 단순 검색 속도는 조금 느림

특징
---
    - 자기 자신을 호출하는 순환 알고리즘의 형태
    - 트리 순회(pre, in, post)는 DFS의 종류임
    - 탐색의 경우 어떤 노드를 방문했었는지 여부를 반드시 검사해야 함

구현
---
```c++
vector<vector<int>> vec;        // 이중 벡터 배열
vector<bool> visit;             // 방문 체크

void dfs(int input)             // dfs 
{
	visit[input] = true;
	cout << input << " ";

	for (int i = 0; i < vec[input].size(); i++)
	{
		// sort(vec[input].begin(), vec[input].end());
		int next = vec[input][i];
		if(visit[next] == false)
			dfs(next);
	}
}
```

시간 복잡도
---
    정점의 수 : N // 간선의 수 : E
    - 인접 리스트로 표현된 그래프 : O(N + E)
    - 인접 행렬로 표현된 그래프 : O(N^2)

# BFS ( Breadth-Frist Search) : 너비 우선 탐색

개념
---
    - 루트 노드에서 시작, 인접 노드를 먼저 탐색하는 방법
    - 깊게 탐색하기 전, 넓게 탐색
    - '두 노드 사이의 최단 경로', '임의의 경로' 탐색에 유용

특징
---
    - 재귀적으로 동작하지 않음
    - 방문 체크 필수
    - Queue를 사용한 반복적 형태로의 구현
    & Prim, Dijkstra

구현
---
```c++
void bfs(int input)
{
	queue<int> que;
	que.push(input);
	visit[input] = true;

	while (!que.empty())
	{
		int now = que.front();
		que.pop();
		cout << now << " ";

		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i];
			if (visit[next] == false)
			{
				visit[next] = true;
				que.push(next);
			}
		}
	}

}
```

시간 복잡도
---
    정점의 수 : N // 간선의 수 : E
    - 인접 리스트로 표현된 그래프 : O(N + E)
    - 인접 행렬로 표현된 그래프 : O(N^2)