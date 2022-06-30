#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> merged;
    for (int i = 0; i < n; i++)
    {
        if (merged.empty() || intervals[i][0] > merged.back()[1])
        {
            vector<int> tmp = {
                intervals[i][0],
                intervals[i][1]};
            merged.push_back(tmp);
        }
        else
        {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
    }
    return merged;
}

int main()
{
}