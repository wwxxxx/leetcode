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
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int ret = 0, temp = x;
        while (temp)
        {
            ret = ret * 10 + temp % 10;
            temp /= 10;
        }
        return ret == x;
    }
};