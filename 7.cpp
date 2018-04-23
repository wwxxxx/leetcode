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
    int reverse(int x)
    {
        long long ret = 0, temp = x;
        while (temp)
        {
            ret = ret * 10 + temp % 10;
            temp /= 10;
        }
        return (abs(ret) > INT_MAX) ? 0 : ret;
    }
};