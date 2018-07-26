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
    void helper(int n, int k, vector<vector<int>> &ret, vector<int> &vec, int last)
    {
        vec.push_back(last);
        int len = vec.size();
        if (len == k)
        {
            ret.push_back(vec);
            return;
        }
        for (int i = last + 1; i <= n - k + len + 1; ++i)
        {
            helper(n, k, ret, vec, i);
            vec.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        if (k == 0)
            return {};
        vector<vector<int>> ret;
        vector<int> vec;
        for (int i = 1; i <= n - k + 1; ++i)
        {
            helper(n, k, ret, vec, i);
            vec.pop_back();
        }
        return ret;
    }
};
