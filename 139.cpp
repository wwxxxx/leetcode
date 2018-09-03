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
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (wordDict.empty())
            return false;
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i < s.size() + 1; ++i)
        {
            for (int j = 0; j < wordDict.size(); ++j)
            {
                if (dp[i])
                {
                    string str = s.substr(i, wordDict[j].size());
                    if (str == wordDict[j])
                        dp[i + wordDict[j].size()] = true;
                }
            }
        }
        return dp[s.size()];
    }
};