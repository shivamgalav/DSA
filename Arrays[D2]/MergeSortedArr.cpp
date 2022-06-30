#include <bits/stdc++.h>
using namespace std;

void merge(int nums1[], int nums2[], int n, int m)
{
    int i, k;
    for (i = 0; i < n; i++)
    {
        if (nums1[i] > nums2[0])
        {
            int temp = nums1[i];
            nums1[i] = nums2[0];
            nums2[0] = temp;
        }
        int tmp = nums2[0];
        for (k = 1; k < m && nums2[k] < tmp; k++)
        {
            nums2[k - 1] = nums2[k];
        }
        nums2[k - 1] = tmp;
    }
}

int main()
{
}