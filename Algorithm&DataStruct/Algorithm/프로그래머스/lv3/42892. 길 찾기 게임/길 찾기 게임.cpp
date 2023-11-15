#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Tree
{
    int index;
    int x;
    int y;
    Tree* left;
    Tree* right;
};

bool compare(Tree a, Tree b)
{
    if(a.y == b.y)
    {
        return a.x < b.x;
    }
    else
    {
        return a.y > b.y;
    }
}

void SetParent(Tree* parent, Tree* child)
{
	if(parent->x > child->x)
	{
		if(parent->left == NULL)
		{
            parent->left = child;
            return;
		}

        SetParent(parent->left, child);
	}
    else
    {
	    if(parent->right == NULL)
	    {
            parent->right = child;
            return;
	    }

        SetParent(parent->right, child);
    }
}

void PreOrder(Tree* pos, vector<int>& out)
{
    out.push_back(pos->index);
    if (pos->left != nullptr) PreOrder(pos->left, out);
    if (pos->right != nullptr) PreOrder(pos->right, out);
}

void PostOrder(Tree* pos, vector<int>& out)
{
    if (pos->left != nullptr) PostOrder(pos->left, out);
    if (pos->right != nullptr) PostOrder(pos->right, out);
    out.push_back(pos->index);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;

    vector<Tree> tree;

    for(int i = 0; i < nodeinfo.size(); i++)
    {
    	tree.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1], nullptr, nullptr });
    }
    std::sort(tree.begin(), tree.end(), compare);

    Tree* root = &tree[0];
    for (int i = 1; i < tree.size(); i++)
        SetParent(root, &tree[i]);

    vector<int> Pre;
    PreOrder(root, Pre);

    vector<int> Post;
    PostOrder(root, Post);

    answer.push_back(Pre);
    answer.push_back(Post);

    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo = { {5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2} };
    solution(nodeinfo);

    return 0;
}