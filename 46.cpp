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
    void recurse(vector<vector<int>> &results, vector<int> &result, int size, int pos)
    {
        if (pos == size - 1)
            return;
        else
        {
            for (int i = pos; i < size; i++)
            {
                if (i != pos)
                {
                    swap(result[i], result[pos]);
                    recurse(results, result, size, pos + 1);
                    results.push_back(result);
                    swap(result[i], result[pos]);
                }
                else
                    recurse(results, result, size, pos + 1);
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> results;
        vector<int> result(nums);
        results.push_back(result);
        recurse(results, result, nums.size(), 0);
        return results;
    }
};