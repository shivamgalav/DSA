#include <bits/stdc++.h>
using namespace std;
static bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(make_pair(start[i], end[i]));
    }
    // sorting according to ending time
    sort(vec.begin(), vec.end(), sortbysec);
    int ans = 1;
    int lim = vec[0].second;
    for (int i = 1; i < n; i++)
    {
        if (vec[i].first > lim)
        {
            lim = vec[i].second;
            ans++;
        }
    }
    return ans;
}