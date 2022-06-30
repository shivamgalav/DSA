#include <bits/stdc++.h>
using namespace std;

int maxsum(vector<int> &nums)
{
    int sum = 0, mx = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        mx = max(sum, mx);
        if (sum < 0)
            sum = 0;
    }
    return mx;
}