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
    bool isPalindrome(const string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void dfs(int index, const string &s, vector<string> &vec, vector<vector<string>> &ret)
    {
        if (index == s.size())
        {
            ret.push_back(vec);
            return;
        }
        for (int i = index; i < s.size(); ++i)
        {
            if (isPalindrome(s, index, i))
            {
                vec.push_back(s.substr(index, i - index + 1));
                dfs(i + 1, s, vec, ret);
                vec.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ret;
        vector<string> vec;
        dfs(0, s, vec, ret);
        return ret;
    }
};