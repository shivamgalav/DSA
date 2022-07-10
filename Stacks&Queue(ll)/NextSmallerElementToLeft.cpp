#include <bits/stdc++.h>
using namespace std;
vector<int> prevSmaller(vector<int> &A)
{
    int n = A.size();
    vector<int> nse(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= A[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            nse[i] = st.top();
        }
        st.push(A[i]);
    }
    return nse;
}