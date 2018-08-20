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
    int longestValidParentheses(string s)
    {
        if (s.size() <= 1)
            return 0;
        int ret = 0;
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                stk.push(i);
            else
            {
                if (!stk.empty())
                {
                    if (s[stk.top()] == '(')
                        stk.pop();
                    else
                        stk.push(i);
                }
                else
                    stk.push(i);
            }
        }
        if (stk.empty())
            ret = s.size();
        else
        {
            int right = s.size(), b = 0;
            while (!stk.empty())
            {

                int len = right - stk.top() - 1;
                ret = max(ret, len);
                right = stk.top();
                stk.pop();
            }
            ret = max(ret, right);
        }
        return ret;
    }
};