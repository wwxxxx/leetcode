#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
	int maxSubArray(vector<int> &nums)
	{
		int curMax = nums[0], preMax = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			preMax = max(preMax + nums[i], nums[i]);
			curMax = max(curMax, preMax);
		}
		return curMax;
	}
};