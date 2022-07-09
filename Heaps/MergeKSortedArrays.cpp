#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < kArrays[i].size(); j++)
        {
            minheap.push(kArrays[i][j]);
        }
    }
    vector<int> res;
    while (minheap.size() > 0)
    {
        res.push_back(minheap.top());
        minheap.pop();
    }
    return res;
}
