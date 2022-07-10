#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 2)
                q.push({i, j});
            if (grid[i][j] == 1)
                fresh++;
        }
    }
    if (fresh == 0)
        return 0;
    int ans = 0;
    // This is how BFS look like
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            pair<int, int> temp = q.front();
            q.pop();
            int i = temp.first;
            int j = temp.second;

            if (j - 1 >= 0 && grid[i][j - 1] == 1)
            {
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
                fresh--;
            }
            if (i - 1 >= 0 && grid[i - 1][j] == 1)
            {
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
                fresh--;
            }
            if (j + 1 < c && grid[i][j + 1] == 1)
            {
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
                fresh--;
            }
            if (i + 1 < r && grid[i + 1][j] == 1)
            {
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
                fresh--;
            }
        }
        ans++;
    }
    if (fresh)
        return -1;
    return ans - 1;
}