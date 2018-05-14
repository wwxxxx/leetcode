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
    bool isValid(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else
            {
                if (stk.empty())
                    return false;
                if ((stk.top() == '(' && s[i] == ')') ||
                    (stk.top() == '[' && s[i] == ']') ||
                    (stk.top() == '{' && s[i] == '}'))
                {
                    stk.pop();
                    continue;
                }
                return false;
            }
        }
        return stk.empty() ? true : false;
    }
};