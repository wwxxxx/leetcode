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
    vector<int> getRow(int rowIndex)
    {
        vector<int> ret(rowIndex + 1);
        ret[0] = 1;
        for (int i = 0; i <= rowIndex; ++i)
            for (int j = i; j > 0; --j)
                ret[j] += ret[j - 1];
        return ret;
    }
};