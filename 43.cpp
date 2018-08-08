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
    string multiply(string num1, string num2)
    {
        string sum(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                int temp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = temp % 10 + '0';
                carry = temp / 10;
            }
            sum[i] += carry;
        }

        size_t startpos = sum.find_first_not_of('0');
        if (string::npos != startpos)
            return sum.substr(startpos);
        return "0";
    }
};