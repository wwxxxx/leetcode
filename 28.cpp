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
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        int i = 0, j = 0, m = haystack.size(), n = needle.size();
        while (i < m && j < n)
        {
            if (haystack[i] == needle[j])
                i++, j++;
            else
                i -= j - 1, j = 0;
        }
        return (i - j > m - n) ? -1 : i - j;
    }
};