#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        vector<string> vec(numRows, "");
        int len = s.size(), i = 0;
        while (i < len)
        {
            for (int j = 0; j < numRows && i < len; j++)
                vec[j].push_back(s[i++]);
            for (int j = numRows - 2; j >= 1 && i < len; j--)
                vec[j].push_back(s[i++]);
        }
        string zigzag;
        for (auto i : vec)
            zigzag += i;
        return zigzag;
    }
};