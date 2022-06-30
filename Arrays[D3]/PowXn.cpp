#include <bits/stdc++.h>
using namespace std;
double myPow(double x, long n)
{
    long n1 = (long)n;
    bool check = false;
    n = n1;
    if (n < 0)
    {
        check = true;
        n = -n1;
    }
    if (x == 1 || n == 0)
    {
        return 1;
    }
    double ans = 1;
    while (n)
    {
        if (n % 2 != 0)
        {
            ans *= x;
            n--;
        }
        else
        {
            x = x * x;
            n = n / 2;
        }
    }
    if (check)
    {
        return 1 / ans;
    }
    return ans;
}