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
    void recurse(vector<vector<int>> &results, vector<int> result, int size, int pos)
    {
        if (pos == size - 1)
        {
            results.push_back(result);
            return;
        }
        for (int i = pos; i < size; i++)
        {
            if (i != pos && result[i] == result[pos])
                continue;
            swap(result[i], result[pos]);
            recurse(results, result, size, pos + 1);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> results;
        vector<int> result(nums);
        sort(result.begin(), result.end());
        recurse(results, result, result.size(), 0);
        return results;
    }
};