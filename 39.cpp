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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> combination;
        helper(candidates, target, ret, combination, 0);
        return ret;
    }

    void helper(vector<int> &candidates, int target, vector<vector<int>> &ret, vector<int> &combination, int begin)
    {
        if (!target)
        {
            ret.push_back(combination);
            return;
        }
        for (int i = begin; i < candidates.size() && target >= candidates[i]; i++)
        {
            combination.push_back(candidates[i]);
            helper(candidates, target - candidates[i], ret, combination, i);
            combination.pop_back();
        }
    }
};