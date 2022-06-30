#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B)
{
    unordered_map<int, int> mp;
    long long int cnt = 0;
    long long int prefixXOR = 0;
    for (int i = 0; i < A.size(); i++)
    {
        prefixXOR ^= A[i];
        if (prefixXOR == B)
            cnt++;
        int tmp = prefixXOR ^ B;
        if (mp.find(tmp) != mp.end())
        {
            cnt += mp[tmp];
        }
        mp[prefixXOR]++;
    }
    return cnt;
}