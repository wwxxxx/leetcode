#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int addDigits(int num)
    {
        /*
        while (num / 10)
        {
            int sum = 0, t = num;
            while (t / 10) {
                sum += t % 10;
                t /= 10;
            }
            sum += t;
            num = sum;
        }
        return num;
        */
        return 1 + (num - 1) % 9;
    }
};