#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    if (nums.empty())
        return res;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        long long int t2 = target - nums[i];
        for (int j = i + 1; j < n; j++)
        {
            long long int t3 = t2 - nums[j];
            long long int st = j + 1;
            long long int ed = n - 1;
            while (st < ed)
            {
                long long int tmp = nums[st] + nums[ed];
                if (tmp < t3)
                {
                    st++;
                }
                else if (tmp > t3)
                {
                    ed--;
                }
                else
                {
                    vector<int> tempans(4, 0);
                    tempans[0] = nums[i];
                    tempans[1] = nums[j];
                    tempans[2] = nums[st];
                    tempans[3] = nums[ed];
                    res.push_back(tempans);
                    while (st < ed && nums[st] == tempans[2])
                    {
                        ++st;
                    }
                    while (st < ed && nums[ed] == tempans[3])
                    {
                        --ed;
                    }
                }
            }
            while (j + 1 < n && nums[j + 1] == nums[j])
            {
                ++j;
            }
        }
        while (i + 1 < n && nums[i + 1] == nums[i])
        {
            ++i;
        }
    }
    return res;
}