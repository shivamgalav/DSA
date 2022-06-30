#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    if (nums.empty())
    {
        return 0;
    }
    set<int> hash;
    for (auto it : nums)
    {
        hash.insert(it);
    }
    int maxStreak = INT_MIN;
    for (auto it : nums)
    {
        if (!hash.count(it - 1))
        {
            int curr = it;
            int streak = 1;
            while (hash.count(curr + 1))
            {
                curr++;
                streak++;
            }
            maxStreak = max(maxStreak, streak);
        }
    }
    return maxStreak;
}