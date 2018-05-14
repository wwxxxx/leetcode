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
    int removeDuplicates(vector<int> &nums)
    {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
        /*
        int cnt = 0, len = nums.size();
        for (int i = 1; i < len; i++)
        {
            if (nums[i] == nums[i - 1])
                cnt++;
            else
                nums[i - cnt] = nums[i];
        }
        return len - cnt;
        */
    }
};