#include <bits/stdc++.h>
using namespace std;
// O(N) with O(1) space complexity
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
}