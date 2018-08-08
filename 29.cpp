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
    int divide(int dividend, int divisor)
    {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        if (!dividend)
            return 0;
        if (divisor == 1)
            return dividend;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1, ret = 0;
        long long dvd = labs(dividend), dvs = labs(divisor);
        while (dvs <= dvd)
        {
            long long tmp = dvs, doubles = 1;
            while ((tmp << 1) <= dvd)
            {
                tmp <<= 1;
                doubles <<= 1;
            }
            dvd -= tmp;
            ret += doubles;
        }
        return sign * ret;
    }
};