#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF,BUFSIZ)
using namespace std;

map<int, int> BST;

void postOrder(const vector<int>& arr, int start, int end)
{
    if (start > end) return;

    int root = arr[start];
    int next_idx = end + 1;

    for (int i = start + 1; i <= end; ++i)
    {
        if (arr[i] > root) {
            next_idx = i;
            break;
        }
    }

    postOrder(arr, start + 1, next_idx - 1);
    postOrder(arr, next_idx, end);
    cout << root << '\n';
}

int main()
{
    fastio;

    int input;
    vector<int> arr;

    while (cin >> input)
    {
        arr.push_back(input);
    }

    postOrder(arr, 0, arr.size() - 1);

    return 0;
}
