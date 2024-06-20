#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

struct school
{
    int start;
    int end;
    int distance;
};

int N, M;
char type[1010];
int parent[1010];
vector<school> board;

bool compare(school a, school b)
{
    return a.distance < b.distance;
}

int Find(int input)
{
    if (input == parent[input])
        return input;

    return parent[input] = Find(parent[input]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    fastio;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        char temp;
        cin >> temp;

        type[i] = temp;
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int tempStart, tempEnd, tempDist;
        cin >> tempStart >> tempEnd >> tempDist;

        // M과 W가 연결된 간선은 의미없음
        if (type[tempStart] != type[tempEnd])
            board.push_back({ tempStart, tempEnd, tempDist });
    }

    sort(board.begin(), board.end(), compare);

    int answer = 0, count = 0;
    for(auto edge : board)
    {
        // 부모가 같지 않을때 = 사이클이 이뤄지지 않았을때
        if (Find(edge.start) != Find(edge.end))
        {
            Union(edge.start, edge.end);
            answer += edge.distance;
            count++;
        }
    }

    if (count < N - 1)
        cout << -1;
    else
        cout << answer;

    return 0;
}
