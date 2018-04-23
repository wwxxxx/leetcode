#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int hammingDistance(int x, int y)
    {
        /*
        int ans = 0;
        while (x || y) {
            if ((x & 1) ^ (y & 1))
                ans++;
            x >>= 1;
            y >>= 1;
        }
        return ans;
        */
        int n = x ^ y, ans = 0;
        while (n)
        {
            ans++;
            n &= n - 1; // 减一位1, 例如：1100 & 1011 = 1000
        }
        return ans;
    }
};