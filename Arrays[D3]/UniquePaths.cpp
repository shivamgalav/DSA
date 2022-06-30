#include <bits/stdc++.h>
using namespace std;

int solve(int m, int n, vector<vector<int>> &dp)
{
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int right = solve(m, n - 1, dp);
    int down = solve(m - 1, n, dp);
    return dp[m][n] = right + down;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int num = solve(m - 1, n - 1, dp);
    if (m == 1 && n == 1)
    {
        return num;
    }
    return dp[m - 1][n - 1];
}