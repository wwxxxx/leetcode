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
    int removeElement(vector<int> &nums, int val)
    {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[ret++] = nums[i];
        return ret;
    }
};