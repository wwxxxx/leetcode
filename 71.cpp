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
    string simplifyPath(string path)
    {
        string ret, tmp;
        vector<string> stk;
        stringstream ss(path);
        while (getline(ss, tmp, '/'))
        {
            if (tmp == "" || tmp == ".")
                continue;
            if (tmp != "..")
                stk.push_back(tmp);
            else if (!stk.empty())
                stk.pop_back();
        }
        for (auto str : stk)
            ret += "/" + str;
        return ret.empty() ? "/" : ret;
    }
};