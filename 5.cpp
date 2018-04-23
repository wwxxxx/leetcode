#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        if (len <= 1)
            return s;
        int minBegin = 0, maxLen = 1;
        for (int i = 0; i < len;)
        {
            if (len - i <= maxLen / 2)
                break;
            int left = i, right = i;
            // 对称轴跳过重复
            while (right < len - 1 && s[right] == s[right + 1])
                right++;
            i = right + 1;
            while (left > 0 && right < len - 1 && s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }
            if (right - left + 1 > maxLen)
            {
                minBegin = left;
                maxLen = right - left + 1;
            }
        }
        return s.substr(minBegin, maxLen);
    }
};