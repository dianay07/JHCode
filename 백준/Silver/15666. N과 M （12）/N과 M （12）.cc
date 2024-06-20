#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ)

int N, M;
vector<int> board;

void DFS(int count, int length, vector<int>& input)
{
    if (length >= M)
    {
        for (int i = 0; i < input.size(); i++)
            cout << input[i] << " ";

        cout << "\n";
        return;
    }

    int recent = 0;
    for (int i = count; i < board.size(); i++)
    {
        if (recent != board[i])
        {
            input.push_back(board[i]);
            recent = board[i];
            DFS(i, length + 1, input);
            input.pop_back();
        }
    }
}

int main()
{
    fastio;

    cin >> N >> M;

    board.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    sort(board.begin(), board.end());

    vector<int> output;
    DFS(0, 0, output);

    return 0;
}
