#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int ok = nums.size() - 1; //the last element is always ignored
        for (int i = ok - 1; i >= 0; i--)
        {
            if (i + nums[i] >= ok)
                ok = i;
            return ok == 0;
        }
    }
};