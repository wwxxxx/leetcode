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
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<vector<int>> vec;
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                if (matrix[i][j] == 0)
                    vec.push_back({i, j});
        for (auto iter = vec.begin(); iter != vec.end(); ++iter)
        {
            for (int i = 0; i < matrix[0].size(); ++i)
                matrix[(*iter)[0]][i] = 0;
            for (int i = 0; i < matrix.size(); ++i)
                matrix[i][(*iter)[1]] = 0;
        }
    }
};