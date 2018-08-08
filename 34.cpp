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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size(), start = 0, end = 0;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        start = l;
        l = 0, r = nums.size();
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[m] <= target)
                l = m + 1;
            else
                r = m;
        }
        end = l;
        return start == end ? vector<int>{-1, -1} : vector<int>{start, end - 1};
    }
};