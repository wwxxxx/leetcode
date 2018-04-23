#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int getSum(int a, int b)
    {
        int sum = a;
        while (b != 0)
        {
            sum = a ^ b;      // sum without carry
            b = (a & b) << 1; // carry
            a = sum;
        }
        return sum;
    }
};