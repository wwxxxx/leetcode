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
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> vec;
        int carry = 1;
        int sum;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            sum = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            vec.push_back(sum);
        }
        if (carry != 0)
            vec.push_back(carry);
        reverse(vec.begin(), vec.end());
        return vec;

        /*
        vector<int> vec(digits);
        int len = vec.size() - 1;
        while (len >= 0 && vec[len] == 9)
        {
            vec[len] = 0;
            len--;
        }
        if (len < 0)
            vec.insert(vec.begin(), 1);
        else
            vec[len]++;
        return vec;
        */
    }
};