#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    double myPow(double x, int n)
    {
        double ret = 1;
        unsigned long long p = 0;
        if (n < 0)
        {
            p = -n;
            x = 1 / x;
        }
        else
            p = n;
        while (p)
        {
            if (p & 1)
                ret *= x;
            x *= x;
            p >>= 1;
        }
        return ret;

        /*
        long nn = n;
        if (x == 0.0)
            return 0.0;
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;
        if (n < 0)
        {
            x = 1 / x;
            return n % 2 == 0 ? myPow(x * x, -(n / 2)) : myPow(x * x, -(n/2)) * x;
        }
        return nn % 2 == 0 ? myPow(x * x, n / 2) : myPow(x * x, n / 2) * x;
        */
    }
};