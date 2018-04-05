#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
			return 0;
		int minp = prices[0], maxp = 0;
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] > prices[i - 1])
				maxp = max(maxp, prices[i] - minp);
			else
				minp = min(minp, prices[i]);
		}
		return maxp;
	}
};