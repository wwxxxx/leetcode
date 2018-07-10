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
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string re = countAndSay(n - 1);
        string ret;
        int cnt = 1;
        for (int i = 0; i < re.size() - 1; i++)
        {
            if (re[i + 1] == re[i])
                cnt++;
            else
            {
                ret.push_back(cnt + '0');
                ret.push_back(re[i]);
                cnt = 1;
            }
        }
        ret.push_back(cnt + '0');
        ret.push_back(re[re.size() - 1]);
        return ret;
    }
};