#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int st = 0;
    int ed = rows * cols - 1;

    while (st <= ed)
    {
        int mid = st + (ed - st) / 2;
        int element = matrix[mid / cols][mid % cols];

        if (element == target)
            return true;

        else if (element < target)
            st = mid + 1;

        else
            ed = mid - 1;
    }
    return false;
}