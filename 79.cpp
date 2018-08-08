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
    int rows, cols;
    bool helper(vector<vector<char>> &board, string word, int row, int col, int pos)
    {
        if (board[row][col] != word[pos] || board[row][col] == ' ')
            return false;
        else if (pos == word.size() - 1)
            return true;
        char c = board[row][col];
        board[row][col] = ' ';
        bool next_exist = row > 0 && helper(board, word, row - 1, col, pos + 1) ||
                          row < rows - 1 && helper(board, word, row + 1, col, pos + 1) ||
                          col > 0 && helper(board, word, row, col - 1, pos + 1) ||
                          col < cols - 1 && helper(board, word, row, col + 1, pos + 1);
        board[row][col] = c;
        return next_exist;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        rows = board.size(), cols = board[0].size();
        for (int row = 0; row < rows; ++row)
            for (int col = 0; col < cols; ++col)
                if (helper(board, word, row, col, 0))
                    return true;
        return false;
    }
};