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
    int searchInsert(vector<int> &nums, int target)
    {
        // std::lower_bound in c++ stl returns an iterator pointing to
        // the first element that does not less than target.
        // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};