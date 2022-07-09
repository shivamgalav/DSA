#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    // min-heap
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    return pq.top();
}