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
        if (prices.empty())
            return 0;
        int size = prices.size();
        vector<int> buy(size + 1);
        vector<int> sell(size + 1);
        buy[1] = -prices[0];
        for (int i = 2; i <= size; ++i)
        {
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i - 1]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i - 1]);
        }
        return sell[size];
    }
};