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
    int mySqrt(int x)
    {
        double ret = x;
        double delta = 0.0001;
        while (fabs(ret * ret - x) > delta)
            ret = (ret + x / ret) / 2;
        return ret;
    }
};