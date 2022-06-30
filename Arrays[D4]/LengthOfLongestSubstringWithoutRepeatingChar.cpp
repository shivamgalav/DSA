#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string str)
{
    vector<int> mp(256, -1);

    int left = 0, right = 0, maxLen = 0;
    while (right < str.length())
    {
        char curr_char = str[right];
        if (mp[str[right]] != -1)
        {
            left = max(left, mp[str[right]] + 1);
        }
        mp[str[right]] = right;
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}