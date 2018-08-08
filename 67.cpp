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
    string addBinary(string a, string b)
    {
        string ret = "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry == 1)
        {
            carry += i >= 0 ? a[i--] - '0' : 0;
            carry += j >= 0 ? b[j--] - '0' : 0;
            ret = char(carry % 2 + '0') + ret;
            carry /= 2;
        }
        return ret;
    }
};