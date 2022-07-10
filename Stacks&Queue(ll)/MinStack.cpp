#include <bits/stdc++.h>
using namespace std;
class MinStack
{
    stack<long long> st;
    long long mini;

public:
    MinStack()
    {
        mini = INT_MAX;
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            mini = val;
        }
        else
        {
            if (val < mini)
            {
                st.push((long long)2 * val - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        long long el = st.top();
        st.pop();
        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        if (st.top() < mini)
        {
            return mini;
        }
        return st.top();
    }

    int getMin()
    {
        return mini;
    }
};