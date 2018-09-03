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
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); ++i)
        {
            if (s[i - 1] > '0' && s[i - 1] <= '9')
                dp[i] = dp[i - 1];
            if (i > 1 && ((s[i - 1] <= '9' && s[i - 2] == '1') ||
                          (s[i - 1] <= '6' && s[i - 2] == '2')))
                dp[i] += dp[i - 2];
        }
        return dp[s.size()];
    }
};