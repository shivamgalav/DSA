#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int n = heights.size();
    int maxA = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int h = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
            {
                width = i;
            }
            else
            {
                width = i - st.top() - 1;
            }
            maxA = max(maxA, h * width);
        }
        st.push(i);
    }
    return maxA;
}