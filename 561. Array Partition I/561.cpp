#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
	int arrayPairSum(vector<int> &nums)
	{
		int ret = 0;
		/*
		一般的方法是对nums进行排序，然后从nums[0]开始隔项相加。
		hash方法可提供很高的效率。flag的作用是使第偶数个数不算进sum里，
		有偶数个相同的数时不叠加，例如<1,2> <2,3>和<1,1> 都是只加一次
		*/
		bool flag = true;
		array<int, 20001> hash{0};
		for (int num : nums)
			hash[num + 10000]++;
		for (int i = 0; i < 20001;)
		{
			if (hash[i] > 0)
			{
				if (flag)
				{
					flag = false;
					ret += i - 10000;
					hash[i]--;
				}
				else
				{
					flag = true;
					hash[i]--;
				}
			}
			else
				i++;
		}
		return ret;
	}
};