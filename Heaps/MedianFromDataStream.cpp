#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        // Dividing elements into 2 heaps;
        if (maxheap.empty() || maxheap.top() > num)
            maxheap.push(num);
        else
            minheap.push(num);

        if (minheap.size() + 1 < maxheap.size())
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if (minheap.size() > 1 + maxheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {
        if (maxheap.size() > minheap.size())
        {
            return maxheap.top();
        }
        else if (maxheap.size() < minheap.size())
        {
            return minheap.top();
        }
        else
        {
            return (minheap.top() + maxheap.top()) / 2.0;
        }
    }
};