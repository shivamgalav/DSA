#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<vector<int>> getTreeTraversal(Node *root)
{
    vector<int> ans;
    vector<int> pre;
    vector<int> post;
    vector<int> in;
    if (root == NULL)
    {
        return {{}, {}, {}};
    }
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        Node *node = it.first;
        int val = it.second;
        if (val == 1)
        {
            pre.push_back(node->data);
            val++;
            st.push({node, val});
            if (node->left != NULL)
            {
                st.push({node->left, 1});
            }
        }
        else if (val == 2)
        {
            in.push_back(node->data);
            val++;
            st.push({node, val});
            if (node->right != NULL)
            {
                st.push({node->right, 1});
            }
        }
        else
        {
            post.push_back(node->data);
        }
    }
    return {in, pre, post};
}