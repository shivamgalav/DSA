#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void Pre(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    ans.push_back(root->val);
    Pre(root->left, ans);
    Pre(root->right, ans);
}
vector<int> PreTraversal(TreeNode *root)
{
    vector<int> ans;
    Pre(root, ans);
    return ans;
}