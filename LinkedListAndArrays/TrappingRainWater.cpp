#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    int left = 0;
    int right = n - 1;
    int lmx = 0;
    int rmx = 0;
    int res = 0;
    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= lmx)
            {
                lmx = height[left];
            }
            else
            {
                res += lmx - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] >= rmx)
            {
                rmx = height[right];
            }
            else
            {
                res += rmx - height[right];
            }
            right--;
        }
    }
    return res;
}