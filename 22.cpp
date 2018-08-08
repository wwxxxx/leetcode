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
    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        int left = n, right = 0;
        add(ret, "", left, right);
        return ret;
    }

    void add(vector<string> &vec, string str, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            vec.push_back(str);
            return;
        }
        if (left > 0)
            add(vec, str + "(", left - 1, right + 1);
        if (right > 0)
            add(vec, str + ")", left, right - 1);
    }
};