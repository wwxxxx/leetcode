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
    static const int FRONT = -1;
    bool isMatch(string s, string p)
    {
        return myMatch(s, s.size() - 1, p, p.size() - 1);
    }

    bool myMatch(string s, int i, string p, int j)
    {
        if (j == FRONT)
            if (i == FRONT)
                return true;
            else
                return false;
        if (p[j] == '*')
        {
            if (i > FRONT && (p[j - 1] == '.' || p[j - 1] == s[i]))
                if (myMatch(s, i - 1, p, j))
                    return true;
            return myMatch(s, i, p, j - 2);
        }
        if (p[j] == '.' || p[j] == s[i])
            return myMatch(s, i - 1, p, j - 1);
        return false;
    }
};