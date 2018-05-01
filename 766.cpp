#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int M = matrix.size(), N = matrix[0].size();
        for (int i = 1; i < M; i++)
            for (int j = 1; j < N; j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        return true;
    }
};