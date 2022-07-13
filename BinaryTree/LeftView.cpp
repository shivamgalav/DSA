#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void left(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (res.size() == level)
    {
        res.push_back(root->data);
    }
    left(root->left, level + 1, res);
    left(root->right, level + 1, res);
}
vector<int> leftView(Node *root)
{
    vector<int> res;
    left(root, 0, res);
    return res;
}