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
    void sortColors(vector<int> &nums)
    {
        int zero = 0, two = nums.size() - 1;
        int left = 0, right = nums.size() - 1;
        for (int cur = 0; cur <= right; ++cur)
        {
            if (nums[cur] == 0)
            {
                swap(nums[left], nums[cur]);
                left++;
            }
            else if (nums[cur] == 2)
            {
                swap(nums[right], nums[cur]);
                cur--;
                right--;
            }
        }
    }
};