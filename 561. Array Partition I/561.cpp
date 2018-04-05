#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int ret = 0;
		/*һ��ķ����Ƕ�nums��������Ȼ���nums[0]��ʼ������ӡ�
		hash�������ṩ�ܸߵ�Ч�ʡ�
		flag��������ʹ��ż���������sum���ż������ͬ����ʱ����
		�ӣ�����<1,2> <2,3>��<1,1> ����ֻ��һ��	
		*/
		bool flag = true;				
		array<int, 20001> hash{ 0 };
		for (int num : nums)
			hash[num + 10000]++;
		for (int i = 0; i < 20001;) {
			if (hash[i] > 0) {
				if (flag) {
					flag = false;
					ret += i - 10000;
					hash[i]--;
				}
				else {
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