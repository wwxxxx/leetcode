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
    vector<string> letterCombinations(string digits)
    {
        vector<string> ret;
        if (digits.empty())
            return ret;
        static const vector<string> numMap = {"", "", "abc", "def",
                                              "ghi", "jkl", "mno",
                                              "pqrs", "tuv", "wxyz"};
        ret.push_back("");
        for (int i = 0; i < digits.size(); i++)
        {
            int num = digits[i] - '0';
            if (num < 0 || num > 9)
                break;
            if (numMap[num].empty())
                continue;
            vector<string> t;
            for (int j = 0; j < numMap[num].size(); j++)
                for (int k = 0; k < ret.size(); k++)
                    t.push_back(ret[k] + numMap[num][j]);
            ret.swap(t);
        }
        return ret;
    }
};