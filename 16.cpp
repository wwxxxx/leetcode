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
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ans, left, right, sum;
        sort(nums.begin(), nums.end());
        ans = nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3];
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            left = i + 1;
            right = nums.size() - 1;

            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if (sum > target)
                    right--;
                else if (sum < target)
                    left++;
                else
                    return target;
                if (abs(ans - target) > abs(sum - target))
                    ans = sum;
            }
        }
        return ans;
    }
};