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
    int myAtoi(string str)
    {
        if (str.empty())
            return 0;
        string sub;
        int opnum = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (opnum > 1)
                return 0;
            if (str[i] == '+' || str[i] == '-')
            {
                if (str[i + 1] - '0' < 0 || str[i + 1] - '0' > 9)
                    return 0;
                opnum++;
                sub += str[i];
            }
            else if (str[i] == ' ' && sub.size() == 0)
                continue;
            else if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
                sub += str[i];
            else
                break;
        }
        long long ret = 0;
        bool neg = false;
        if (sub[0] == '-')
            neg = true;
        for (int i = opnum; i < sub.size(); i++)
        {
            if (ret * 10 + sub[i] - '0' > INT_MAX)
                return neg ? INT_MIN : INT_MAX;
            ret = ret * 10 + sub[i] - '0';
        }
        return neg ? -ret : ret;
    }
};