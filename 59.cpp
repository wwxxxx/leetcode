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
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ret(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int cur = 0;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; ++i)
                ret[top][i] = ++cur;
            if (++top > bottom)
                break;
            for (int i = top; i <= bottom; ++i)
                ret[i][right] = ++cur;
            if (--right < left)
                break;
            for (int i = right; i >= left; --i)
                ret[bottom][i] = ++cur;
            if (--bottom < top)
                break;
            for (int i = bottom; i >= top; --i)
                ret[i][left] = ++cur;
            ++left;
        }
        return ret;
    }
};