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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return {};
        int cols = matrix[0].size();
        int rows = matrix.size();
        vector<int> ret(cols * rows);
        int up = 0;
        int down = rows - 1;
        int left = 0;
        int right = cols - 1;
        int i = 0;
        while (true)
        {
            for (int col = left; col <= right; col++)
                ret[i++] = matrix[up][col];
            if (++up > down)
                break;
            for (int row = up; row <= down; row++)
                ret[i++] = matrix[row][right];
            if (--right < left)
                break;
            for (int col = right; col >= left; col--)
                ret[i++] = matrix[down][col];
            if (--down < up)
                break;
            for (int row = down; row >= up; row--)
                ret[i++] = matrix[row][left];
            if (++left > right)
                break;
        }
        return ret;
    }
};