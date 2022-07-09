#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &s, int num)
{
    if (s.empty() || (!s.empty() && s.top() < num))
    {
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    insert(s, num);
    s.push(n);
}
void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    sortStack(st);
    insert(st, temp);
}