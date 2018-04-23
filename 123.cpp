#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int h1 = INT_MIN, h2 = INT_MIN;
        int r1 = 0, r2 = 0;
        for (int i : prices)
        {
            r2 = max(r2, h2 + i); //sold 2
            h2 = max(h2, r1 - i); //buy 2
            r1 = max(r1, h1 + i); //sold 1
            h1 = max(h1, -i);     //buy 1
        }
        return r2;
    }
};