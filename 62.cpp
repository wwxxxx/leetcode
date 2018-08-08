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
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> vec(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
        return vec[m - 1][n - 1];
    }
};