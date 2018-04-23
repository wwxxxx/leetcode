#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int countNumbersWithUniqueDigits(int n)
    {
        int ans = 0;
        for (int i = n; i >= 1; --i)
        {
            int part = 9;
            for (int j = 0; j < i - 1; j++)
                part *= 9 - j;
            ans += part;
        }
        return ans + 1;
    }
};