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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;
        int len = nums.size();
        if (len < 4)
            return ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target)
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                return ret;

            for (int j = i + 1; j < len - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target)
                    continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;

                int k = j + 1, l = len - 1;
                while (k < l)
                {
                    if (nums[i] + nums[j] + nums[k] + nums[l] > target)
                        l--;
                    else if (nums[i] + nums[j] + nums[k] + nums[l] < target)
                        k++;
                    else
                    {
                        vector<int> tmp(4, 0);
                        tmp = {nums[i], nums[j], nums[k], nums[l]};
                        ret.push_back(tmp);
                        do
                        {
                            l--;
                        } while (k < l && nums[l] == nums[l + 1]);
                        do
                        {
                            k++;
                        } while (k < l && nums[k] == nums[k - 1]);
                    }
                }
            }
        }
        return ret;
    }
};