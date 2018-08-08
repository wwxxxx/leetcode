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
    int lengthOfLastWord(string s)
    {
        int ret = 0;
        int tail = s.size() - 1;
        while (tail >= 0 && s[tail] == ' ')
            tail--;
        while (tail >= 0 && s[tail] != ' ')
        {
            ret++;
            tail--;
        }
        return ret;
    }
};