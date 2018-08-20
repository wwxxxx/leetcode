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
    int numDistinct(string s, string t)
    {
        int m = t.size(), n = s.size();
        vector<int> dp(m + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= n; ++j)
        {
            int pre = 1;
            for (int i = 1; i <= m; ++i)
            {
                int temp = dp[i];
                dp[i] += s[j - 1] == t[i - 1] ? temp : 0;
                pre = temp;
            }
        }
        return dp[m];
    }
};