#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool solveTree(vector<int> &ans, TreeNode *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(root->val);
    if (root->val == target)
    {
        return true;
        ;
    }
    if (solveTree(ans, root->left, target) || solveTree(ans, root->right, target))
    {
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> solve(TreeNode *A, int B)
{
    vector<int> ans;
    bool ch = solveTree(ans, A, B);
    return ans;
}