#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &A, int pages, int student)
{
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (sum + A[i] > pages)
        {
            cnt++;
            sum = A[i];
            if (sum > pages)
                return false;
        }
        else
        {
            sum += A[i];
        }
    }
    if (cnt < student)
    {
        return true;
    }
    return false;
}
int books(vector<int> &A, int B)
{
    if (B > A.size())
    {
        return -1;
    }
    int low = A[0];
    int high = 0;
    for (int i = 0; i < A.size(); i++)
    {
        high = high + A[i];
        low = min(low, A[i]);
    }
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible(A, mid, B))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}