#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int integerBreak(int n)
    {
        /*
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        if (n == 5) return 6;
        if (n == 6) return 9;
        return 3 * integerBreak(n - 3);
        */
        if (n < 0)
            return 0;
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++)
            for (int j = 1; j < i; j++)
                dp[i] = max(dp[i], max(j * (i - j), max(dp[j] * dp[i - j], dp[j] * (i - j))));
        return dp[n];
    }
};