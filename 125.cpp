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
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string str = "";
        for (int i = 0; i < s.size(); ++i)
            if (isalnum(s[i]))
                str += s[i];
        int begin = 0;
        int end = str.size() - 1;
        while (begin < end)
        {
            if (str[begin] != str[end])
                return false;
            ++begin;
            --end;
        }
        return true;
    }
};