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
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";
        if (strs.size() == 0)
            return prefix;
        for (int i = 0; i < strs[0].size(); i++)
        {
            int j = 1;
            for (; j < strs.size() && strs[j].size() > i; j++)
                if (strs[j][i] != strs[0][i])
                    return prefix;
            if (j == strs.size())
                prefix += strs[0][i];
        }
        return prefix;
    }
};