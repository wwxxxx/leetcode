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
    int maxArea(vector<int> &height)
    {
        int ret = INT_MIN, lo = 0, hi = height.size() - 1;
        while (lo < hi)
        {
            int h = min(height[lo], height[hi]);
            ret = max(ret, (hi - lo) * h);
            while (height[lo] <= h && lo < hi)
                lo++;
            while (height[hi] <= h && lo < hi)
                hi--;
        }
        return ret;
    }
};