#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++)
        {
            int t = target - nums[i];
            if (map.find(t) != map.end())
            {
                vec.push_back(map[t]);
                vec.push_back(i);
                return vec;
            }
            map[nums[i]] = i;
        }
        return vec;
    }
};