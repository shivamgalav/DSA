#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
    stack<int> input, output;

public:
    MyQueue() {}

    void push(int x)
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        input.push(x);

        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }

    int pop()
    {
        if (input.empty())
        {
            return -1;
        }
        int val = input.top();
        input.pop();
        return val;
    }

    int peek()
    {
        if (input.empty())
        {

            return -1;
        }
        return input.top();
    }

    bool empty()
    {
        return input.empty();
    }
};