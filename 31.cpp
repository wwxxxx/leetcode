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
    void nextPermutation(vector<int> &nums)
    {
        // next_permutation(nums.begin(), nums.end());
        int k = -1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                k = i;
                break;
            }
        }
        if (k == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int l = -1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] > nums[k])
            {
                l = i;
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
        return;
    }
};