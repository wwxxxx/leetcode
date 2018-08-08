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
    void helper(vector<vector<int>> &ret, vector<int> vec, vector<int> &nums, int start)
    {
        ret.push_back(vec);
        for (int i = start; i < nums.size(); ++i)
        {
            vec.push_back(nums[i]);
            helper(ret, vec, nums, i + 1);
            vec.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> vec;
        helper(ret, vec, nums, 0);
        return ret;
    }

    /*
    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret(1, vector<int>());
        for (int i = 0; i < nums.size(); ++i)
        {
            int n = ret.size();
            for (int j = 0; j < n; ++j)
            {
                ret.push_back(ret[j]);
                ret.back().push_back(nums[i]);
            }
        }
        return ret;
    }
    */
};