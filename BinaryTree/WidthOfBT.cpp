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
int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    int ans = 0;
    queue<pair<TreeNode *, long long int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int currMin = q.front().second;
        int left = 0;
        int right = 0;
        for (int i = 0; i < size; i++)
        {
            int cur_id = q.front().second - currMin;
            TreeNode *temp = q.front().first;
            q.pop();
            if (i == 0)
            {
                left = cur_id;
            }
            else if (i == size - 1)
            {
                right = cur_id;
            }
            if (temp->left)
                q.push({temp->left, (long long)cur_id * 2 + 1});
            if (temp->right)
                q.push({temp->right, (long long)cur_id * 2 + 2});
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}