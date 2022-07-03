#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;
    int dead;
    int profit;
};
bool static cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, cmp);
    int maxDeadline = arr[0].dead;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }
    int slots[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++)
    {
        slots[i] = -1;
    }
    int cntJobs = 0;
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slots[j] == -1)
            {
                slots[j] = i;
                cntJobs++;
                profit += arr[i].profit;
                break;
            }
        }
    }
    vector<int> ans;
    ans.push_back(cntJobs);
    ans.push_back(profit);
    return ans;
}