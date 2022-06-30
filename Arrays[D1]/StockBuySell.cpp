#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int buy = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        profit = max(profit, prices[i] - buy);
        buy = min(prices[i], buy);
    }
    return profit;
}