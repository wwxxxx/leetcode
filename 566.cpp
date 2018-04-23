#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int m = nums.size(), n = nums[0].size();
        if (r * c != m * n)
            return nums;
        vector<vector<int>> vec(r, vector<int>(c, 0));
        for (int i = 0; i < r * c; i++)
            vec[i / c][i % c] = nums[i / n][i % n];
        return vec;
    }
};