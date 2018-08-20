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
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int ret = 0;
        for (int i = 1; i < prices.size(); ++i)
            if (prices[i] > prices[i - 1])
                ret += prices[i] - prices[i - 1];
        return ret;
    }
};