#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n < 3)
    {
        return res;
    }
    for (int i = 0; i < n; i++)
    {
        int target = -nums[i];
        int st = i + 1;
        int ed = n - 1;
        while (st < ed)
        {
            int tempSum = nums[st] + nums[ed];
            if (tempSum > target)
            {
                ed--;
            }
            else if (tempSum < target)
            {
                st++;
            }
            else
            {
                vector<int> temp(3, 0);
                temp[0] = nums[i];
                temp[1] = nums[st];
                temp[2] = nums[ed];
                res.push_back(temp);
                while (st < ed && temp[1] == nums[st])
                {
                    st++;
                }
                while (st < ed && temp[2] == nums[ed])
                {
                    ed--;
                }
            }
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
        {
            i++;
        }
    }
    return res;
}