#include <bits/stdc++.h>
using namespace std;

class NumArray
{
  public:
    vector<int> vec;
    int tmp = 0;
    NumArray(vector<int> nums)
    {
        vec.push_back(tmp);
        for (int num : nums)
        {
            // vec.push_back(vec.back() + num);
            tmp += num;
            vec.push_back(tmp);
        }
    }

    int sumRange(int i, int j)
    {
        return vec[j + 1] - vec[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */