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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> vec(m + 1, vector<int>(n + 1, 0));
        vec[0][1] = 1;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (obstacleGrid[i - 1][j - 1] == 0)
                    vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
        return vec[m][n];

        /*
        if (obstacleGrid[0][0] == 1)
            return 0;
        vector<int> vec(obstacleGrid[0].size(), 0);
        vec[0] = 1;
        for (int i = 1; i < vec.size(); ++i)
            vec[i] = obstacleGrid[0][i] == 1 ? 0 : vec[i - 1];
        for (int i = 1; i < obstacleGrid.size(); ++i)
        {
            vec[0] = obstacleGrid[i][0] == 1 ? 0 : vec[0];
            for (int j = 1; j < obstacleGrid[0].size(); ++j)
                vec[j] = obstacleGrid[i][j] == 1 ? 0 : vec[j] + vec[j - 1];
        }
        return vec.back();
        */
    }
};