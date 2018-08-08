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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        if (nums.size() < 3)
            return ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back)
            {
                int sum = nums[front] + nums[back];

                // finding answer which start from number num[i]
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else
                {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    ret.push_back(triplet);

                    // processing duplicates of number2
                    // rolling the front pointer to the next different number forwards
                    while (front < back && nums[front] == triplet[1])
                        front++;
                    while (front < back && nums[back] == triplet[2])
                        back--;
                }
            }

            // processing duplicates of number1
            while (i + 1 < nums.size() - 2 && nums[i + 1] == nums[i])
                i++;
        }
        return ret;
    }
};